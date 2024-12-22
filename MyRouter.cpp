#include "MyRouter.h"

#include "controller/CoursesController.h"
#include "controller/MainPageController.h"
#include "controller/ScoresController.h"
#include "controller/StudentsController.h"

// MyRouter::MyRouter() :
// courses_dao(),
// scores_dao(),
// courses_service(courses_dao),
// scores_service(scores_dao),
// courses_controller(courses_service),
// scores_controller(scores_service),
// mainpage_controller()
// {}

void MyRouter::setupRouting()
{
    static CoursesDao courses_dao;
    static CoursesService courses_service(courses_dao);
    static CoursesController courses_controller(courses_service);
    static MainPageController mainpage_controller;
    static ScoresDao scores_dao;
    static ScoresService scores_service(scores_dao);
    static ScoresController scores_controller(scores_service);
    static StudentsDao students_dao;
    static StudentsService students_service(students_dao);
    static StudentsController students_controller(students_service);

    addRouting("GET", "/refresh", [this](const smatch &, const map<string, string> &) -> tuple<string, string, string> {
        system("./gen");
        return {"200 OK,", "Refresh Done", "text/plain"};
    });

    //  首页
    addRouting("GET", "/", [this](const smatch &, const map<string, string> &) -> tuple<string, string, string> {
        return mainpage_controller.getResponse();
    });

    //  课
    addRouting("GET", "/courses", [this](const smatch &, const map<string, string> &) -> tuple<string, string, string> {
        return courses_controller.getResponse();
    });

    // 成绩
    addRouting("GET", "/scores", [this](const smatch &, const map<string, string> &) -> tuple<string, string, string> {
        return scores_controller.getResponse_All();
    });

    // 成绩的动态路由
    addRouting("GET", "/students/:stuID",
               [this](const smatch &match, const map<string, string> &) -> tuple<string, string, string> {
                   return scores_controller.getResponse_byStu(match[1].str());
               });
    addRouting("GET", "/courses/:courseID",
               [this](const smatch &match, const map<string, string> &) -> tuple<string, string, string> {
                   return scores_controller.getResponse_byCourse(match[1].str());
               });

    // 学生
    addRouting("GET", "/students",
               [this](const smatch &, const map<string, string> &queryParams) -> tuple<string, string, string> {
                   return students_controller.getResponse(queryParams);
               });
}

/*
需要用正则表达式来实现动态路由，以解决：
    Query Parameters：用于传递参数 /students?agefrom=xx&ageto=xx
    Path Parameters：路径中的动态部分 /students/:studentID 实际请求时被替换为 /student/123

关于正则表达式的语法：
    regex：C++ 标准库中的正则表达式类，用于定义正则表达式模式。
    smatch：C++ 标准库中的匹配结果类，用于存储正则表达式匹配的结果。
    regex_match：用于将一个字符串与一个正则表达式进行匹配。如果匹配成功，返回 true，并将匹配结果存储在 smatch 对象中。
    regex_replace：将路径中的参数（如 :courseName）替换为正则表达式模式 ([^/]+)，以匹配路径参数。
    regex_match(path, match, pattern)：将请求路径与正则表达式模式进行匹配。如果匹配成功，match 对象将包含匹配的结果。
*/
