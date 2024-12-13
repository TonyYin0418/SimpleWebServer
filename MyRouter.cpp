#include "MyRouter.h"

#include "Controller/CoursesController.h"
#include "Controller/MainPageController.h"
#include "Controller/ScoresController.h"

void MyRouter::setupRouting()
{
    addRouting("GET", "/courses", [this]() -> tuple<string, string, string> {
        static CoursesDao courses_dao;
        static CoursesService courses_service(courses_dao);  // 注意这里必须加static!!!!!!!!
        static CoursesController courses_controller(courses_service);
        return courses_controller.getResponse();
    });
    //    addRouting("GET", "/scores", new ScoresController(), (CTRL_FUN)&ScoresController::f0);
    //    REGISTER_CTRL_FUN("GET", "/courses", CoursesController, 0)
}
