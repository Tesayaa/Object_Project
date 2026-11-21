#include "ForeignStudent.h"

ForeignStudent::ForeignStudent(const std::string& name, const std::string& country)
    : Student(name), country_(country) {
}

std::string ForeignStudent::getStatus() const {
    return "Foreign";
}

int ForeignStudent::getTuition() const {
    return 300000;
}

const std::string& ForeignStudent::getCountry() const {
    return country_;
}
