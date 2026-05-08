#pragma once
#include "Student.h"
#include <optional>
#include <span>
#include <string>
#include <vector>

class StudentModel {
public:
    int  add(std::string name, int age, double gpa);
    bool remove(int id);
    bool update(int id, std::string name, int age, double gpa);

    std::optional<Student>   find(int id) const;
    std::span<const Student> all()        const;

private:
    std::vector<Student> students_;
    int                  nextId_{ 1 };
};
