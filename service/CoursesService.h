#ifndef COURSES_SERVICE_H
#define COURSES_SERVICE_H

#include <string>
#include <vector>

#include "../dao/CoursesDao.h"
#include "../nlohmann/json.hpp"  // 使用 nlohmann JSON 库来生成 JSON 格式的响应

using namespace std;

class CoursesService
{
   public:
    CoursesService(CoursesDao &dao);
    nlohmann::json getCoursesJson();

   private:
    CoursesDao &dao;
};

#endif /* COURSES_SERVICE_H */
