#pragma once
#include "../Model/Student.h"
#include <span>
#include <string>

class View {
public:
    void showMenu()                              const;
    void showAll(std::span<const Student> list)  const;
    void showOne(const Student& s)               const;
    void showMessage(const std::string& msg)     const;
    void showError(const std::string& msg)       const;

    int         promptMenuChoice()                        const;
    std::string promptString(const std::string& label)   const;
    int         promptInt(const std::string& label)      const;
    double      promptDouble(const std::string& label)   const;
};
