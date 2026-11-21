#include "Course.h"
#include "Professor.h"
#include "Student.h"

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
}

}  // namespace

int main() {
    std::vector<Professor> professors;
    professors.reserve(2);
    professors.emplace_back("Ivanov");
    professors.emplace_back("Petrova");

    Course oop("OOP", &professors[0]);
    Course math("Mathematics", &professors[1]);

    oop.addTopic("Classes and objects");
    oop.addTopic("Constructors");
    oop.addTopic("Aggregation and composition");
    math.addTopic("Limits");
    math.addTopic("Derivatives");

    Student student("Alexey");
    student.enroll(&oop);
    student.enroll(&math);
    student.enroll(&oop);
    student.enroll(nullptr);

    std::cout << "=== Professors and courses ===\n";
    for (const Professor& professor : professors) {
        std::cout << professor.getName() << ":\n";
        for (const Course* course : {&oop, &math}) {
            if (course->getProfessor() == &professor) {
                std::cout << "  - " << course->getName() << '\n';
            }
        }
    }

    std::cout << "\n=== Student ===\n";
    std::cout << student.getName() << " is enrolled in "
              << student.getCourses().size() << " courses:\n";
    for (const Course* course : student.getCourses()) {
        std::cout << "  - " << course->getName() << " (Prof. "
                  << course->getProfessor()->getName() << ")\n";
    }

    std::cout << "\n=== Courses ===\n";
    printCourse(oop);
    printCourse(math);

    return 0;
}
