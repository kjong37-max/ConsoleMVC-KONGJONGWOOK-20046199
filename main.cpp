#include "Controller/Controller.h"
#include "Model/StudentModel.h"
#include "View/View.h"

int main() {
    StudentModel model;
    View         view;
    Controller   controller{ model, view };
    controller.run();
    return 0;
}
