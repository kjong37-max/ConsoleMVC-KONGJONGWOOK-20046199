#include "View.h"
#include <format>
#include <iostream>

void View::showMenu() const {
    std::cout << "\n========== Student Manager ==========\n"
              << "  1. 학생 추가\n"
              << "  2. 전체 목록\n"
              << "  3. 학생 검색\n"
              << "  4. 학생 수정\n"
              << "  5. 학생 삭제\n"
              << "  0. 종료\n"
              << "=====================================\n"
              << "선택 > ";
}

void View::showAll(std::span<const Student> list) const {
    if (list.empty()) {
        std::cout << "  등록된 학생이 없습니다.\n";
        return;
    }
    std::cout << std::format("\n{:<5} {:<16} {:<5} {}\n", "ID", "이름", "나이", "GPA");
    std::cout << std::string(36, '-') << '\n';
    for (const auto& s : list)
        std::cout << std::format("{:<5} {:<16} {:<5} {:.2f}\n", s.id, s.name, s.age, s.gpa);
}

void View::showOne(const Student& s) const {
    std::cout << std::format("\n  [ID {}] {} | 나이: {} | GPA: {:.2f}\n",
                             s.id, s.name, s.age, s.gpa);
}

void View::showMessage(const std::string& msg) const {
    std::cout << "  >> " << msg << '\n';
}

void View::showError(const std::string& msg) const {
    std::cerr << "  [오류] " << msg << '\n';
}

int View::promptMenuChoice() const {
    int choice{};
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}

std::string View::promptString(const std::string& label) const {
    std::string val;
    std::cout << "  " << label << " > ";
    std::getline(std::cin, val);
    return val;
}

int View::promptInt(const std::string& label) const {
    int val{};
    std::cout << "  " << label << " > ";
    std::cin >> val;
    std::cin.ignore();
    return val;
}

double View::promptDouble(const std::string& label) const {
    double val{};
    std::cout << "  " << label << " > ";
    std::cin >> val;
    std::cin.ignore();
    return val;
}
