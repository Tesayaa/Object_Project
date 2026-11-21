#pragma once

#include <string>

class Professor {
public:
    explicit Professor(const std::string& name);

    const std::string& getName() const;

private:
    std::string name_;
};
