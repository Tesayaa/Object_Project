#pragma once

class Course;

#include <string>
#include <vector>

class Student {
public:
    explicit Student(const std::string& name);
    ~Student() = default;

    void enroll(Course* course);

    const std::string& getName() const;
    const std::vector<Course*>& getCourses() const;

private:
    std::string name_;
    std::vector<Course*> courses_;
};
