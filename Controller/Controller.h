#pragma once
#include "../Model/StudentModel.h"
#include "../View/View.h"

class Controller {
public:
    Controller(StudentModel& model, View& view);
    void run();

private:
    void handleAdd();
    void handleList();
    void handleFind();
    void handleUpdate();
    void handleRemove();

    StudentModel& model_;
    View&         view_;
};
