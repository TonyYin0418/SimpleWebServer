#ifndef MYROUTER_H
#define MYROUTER_H

#include "framework/router.h"

class MyRouter : public Router
{
   public:
    void setupRouting() override;
    //    private:
    //     CoursesDao courses_dao;
    //     CoursesService courses_service;
    //     CoursesController courses_controller;
    //     ScoresDao scores_dao;
    //     ScoresService scores_service;
    //     ScoresController scores_controller;
    //     MainPageController mainpage_controller;
};

#endif  // MYROUTER_H
