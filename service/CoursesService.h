#ifndef COURSES_SERVICE_H
#define COURSES_SERVICE_H

#include <string>
#include <vector>

#include "../dao/CoursesDao.h"
using namespace std;

class CoursesService
{
   public:
    CoursesService(CoursesDao &dao);
    string getCoursesJson();

   private:
    CoursesDao &dao;
};

#endif /* COURSES_SERVICE_H */
