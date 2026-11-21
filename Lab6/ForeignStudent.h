#pragma once

#include "Student.h"

class ForeignStudent : public Student {
public:
    ForeignStudent(const std::string& name, const std::string& country);

    std::string getStatus() const;
    int getTuition() const;
    const std::string& getCountry() const;

private:
    std::string country_;
};
