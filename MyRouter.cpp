#include "MyRouter.h"

#include "Controller/CoursesController.h"
#include "Controller/MainPageController.h"
#include "Controller/ScoresController.h"

void MyRouter::setupRouting() {
    addRouting("GET", "/index", new MainPageController(),
               (CTRL_FUN)&MainPageController::f0);
    addRouting("GET", "/scores", new ScoresController(),
               (CTRL_FUN)&ScoresController::f0);
    addRouting("GET", "/courses", new CoursesController(),
               (CTRL_FUN)&CoursesController::f0);
    //    REGISTER_CTRL_FUN("GET", "/courses", CoursesController, 0)
}
