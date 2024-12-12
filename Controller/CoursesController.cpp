#include "CoursesController.h"

CoursesController::CoursesController(CoursesService &service) : service(service) {}

void CoursesController::f0(string path) { cout << "Displaying course information for path: " << path << endl; }

tuple<string, string, string> CoursesController::getCourses()
{
    string data = service.getCoursesJson();
    cout << data << endl;
    return make_tuple("200 OK", data, "application/json");
}
