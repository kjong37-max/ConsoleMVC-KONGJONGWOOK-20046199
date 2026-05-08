#include "Controller.h"

Controller::Controller(StudentModel& model, View& view)
    : model_(model), view_(view) {}

void Controller::run() {
    bool running = true;
    while (running) {
        view_.showMenu();
        switch (view_.promptMenuChoice()) {
        case 1: handleAdd();    break;
        case 2: handleList();   break;
        case 3: handleFind();   break;
        case 4: handleUpdate(); break;
        case 5: handleRemove(); break;
        case 0: running = false; view_.showMessage("프로그램을 종료합니다."); break;
        default: view_.showError("잘못된 선택입니다."); break;
        }
    }
}

void Controller::handleAdd() {
    auto name = view_.promptString("이름");
    auto age  = view_.promptInt("나이");
    auto gpa  = view_.promptDouble("GPA (0.0 ~ 4.5)");
    int  id   = model_.add(std::move(name), age, gpa);
    view_.showMessage("추가 완료 (ID: " + std::to_string(id) + ")");
}

void Controller::handleList() {
    view_.showAll(model_.all());
}

void Controller::handleFind() {
    int id = view_.promptInt("검색할 학생 ID");
    if (auto s = model_.find(id))
        view_.showOne(*s);
    else
        view_.showError("해당 ID의 학생을 찾을 수 없습니다.");
}

void Controller::handleUpdate() {
    int id = view_.promptInt("수정할 학생 ID");
    if (!model_.find(id)) {
        view_.showError("해당 ID의 학생을 찾을 수 없습니다.");
        return;
    }
    auto name = view_.promptString("새 이름");
    auto age  = view_.promptInt("새 나이");
    auto gpa  = view_.promptDouble("새 GPA");
    model_.update(id, std::move(name), age, gpa);
    view_.showMessage("수정 완료");
}

void Controller::handleRemove() {
    int id = view_.promptInt("삭제할 학생 ID");
    if (model_.remove(id))
        view_.showMessage("삭제 완료");
    else
        view_.showError("해당 ID의 학생을 찾을 수 없습니다.");
}
