#include "StudentModel.h"
#include <algorithm>
#include <ranges>

int StudentModel::add(std::string name, int age, double gpa) {
    students_.push_back({ nextId_++, std::move(name), age, gpa });
    return students_.back().id;
}

bool StudentModel::remove(int id) {
    auto it = std::ranges::find_if(students_, [id](const Student& s) { return s.id == id; });
    if (it == students_.end()) return false;
    students_.erase(it);
    return true;
}

bool StudentModel::update(int id, std::string name, int age, double gpa) {
    auto it = std::ranges::find_if(students_, [id](const Student& s) { return s.id == id; });
    if (it == students_.end()) return false;
    *it = { id, std::move(name), age, gpa };
    return true;
}

std::optional<Student> StudentModel::find(int id) const {
    auto it = std::ranges::find_if(students_, [id](const Student& s) { return s.id == id; });
    if (it == students_.end()) return std::nullopt;
    return *it;
}

std::span<const Student> StudentModel::all() const {
    return students_;
}
