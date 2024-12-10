#ifndef COURSES_SERVICE_H
#define COURSES_SERVICE_H

#include "../dao/CoursesDao.h"
#include <vector>
#include <string>
using namespace std;

class CoursesService {
public:
    CoursesService(CoursesDao &dao);
    string getCoursesJson();

private:
    CoursesDao &dao;
};

#endif /* COURSES_SERVICE_H */
