#pragma once

class Professor;

#include <string>
#include <vector>

class Course {
public:
    Course(const std::string& name, Professor* professor);
    ~Course() = default;

    void addTopic(const std::string& topic);

    const std::string& getName() const;
    const std::vector<std::string>& getTopics() const;
    const Professor* getProfessor() const;

private:
    std::string name_;
    std::vector<std::string> topics_;
    Professor* professor_;
};
