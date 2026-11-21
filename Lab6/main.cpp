#include "BudgetStudent.h"
#include "Course.h"
#include "ForeignStudent.h"
#include "PaidStudent.h"
#include "Professor.h"

#include <iostream>
#include <vector>

namespace {

void printCourse(const Course& course) {
    std::cout << course.getName() << " (Prof. "
              << course.getProfessor()->getName() << ")\n";
    std::cout << "  Topics: " << course.getTopics().size() << '\n';
    for (const std::string& topic : course.getTopics()) {
        std::cout << "  - " << topic << '\n';
    }
    std::cout << "  Students: " << course.getStudentCount() << '\n';
    for (const Student* student : course.getStudents()) {
        std::cout << "  - " << student->getName() << '\n';
    }
}

void enroll(Student& student, Course& course) {
    student.enroll(&course);
    course.enrollStudent(&student);
}

}  // namespace

int main() {
    Professor ivanov("Ivanov");
    Professor petrova("Petrova");

    Course oop("OOP", &ivanov);
    Course math("Mathematics", &petrova);
    Course physics("Physics", &ivanov);

    oop.addTopic("Classes and objects");
    oop.addTopic("Constructors");
    oop.addTopic("Rule of three");
    math.addTopic("Limits");
    math.addTopic("Derivatives");
    physics.addTopic("Mechanics");
    physics.addTopic("Thermodynamics");
    physics.addTopic("Electromagnetism");

    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);
    BudgetStudent gleb("Gleb", 1200);
    ForeignStudent chen("Chen", "China");

    enroll(alice, oop);
    enroll(alice, math);
    enroll(bob, physics);
    enroll(gleb, oop);
    enroll(gleb, physics);
    enroll(chen, math);
    enroll(chen, physics);
    enroll(alice, oop);
    oop.enrollStudent(nullptr);

    std::vector<Student*> all = {&alice, &bob, &gleb, &chen};

    std::cout << "=== Students through Student* ===\n";
    for (Student* student : all) {
        std::cout << student->getName() << " (" << student->getStatus()
                  << "), tuition: " << student->getTuition() << '\n';
        for (const Course* course : student->getCourses()) {
            std::cout << "  " << course->getName() << " (Prof. "
                      << course->getProfessor()->getName() << ")\n";
        }
    }

    std::cout << "\n=== Courses ===\n";
    printCourse(oop);
    printCourse(math);
    printCourse(physics);

    int baseScholarshipTotal = 0;
    for (Student* student : all) {
        baseScholarshipTotal += student->getScholarship();
    }
    std::cout << "\nExperiment 2, scholarship through Student*: "
              << baseScholarshipTotal << '\n';

    std::cout << "\n=== Concrete objects ===\n";
    std::cout << alice.getName() << " (" << alice.getStatus()
              << "), scholarship: " << alice.getScholarship() << '\n';
    std::cout << bob.getName() << " (" << bob.getStatus()
              << "), tuition: " << bob.getTuition() << '\n';
    std::cout << gleb.getName() << " (" << gleb.getStatus()
              << "), scholarship: " << gleb.getScholarship() << '\n';
    std::cout << chen.getName() << " (" << chen.getStatus()
              << "), country: " << chen.getCountry()
              << ", tuition: " << chen.getTuition() << '\n';

    const int actualTuition = bob.getTuition() + chen.getTuition();
    std::cout << "\nActual total tuition: " << actualTuition << '\n';

    return 0;
}
