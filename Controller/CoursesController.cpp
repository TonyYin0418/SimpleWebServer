#include "CoursesController.h"

CoursesController::CoursesController(CoursesService &service) : service(service) {}

void CoursesController::f0(string path)
{
    service.getCoursesJson();
    cout << "Displaying course information for path: " << path << endl;
}
