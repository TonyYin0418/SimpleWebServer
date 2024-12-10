#include "CoursesService.h"

#include <string>
#include <vector>

#include "../nlohmann/json.hpp"  // 使用 nlohmann JSON 库来生成 JSON 格式的响应

CoursesService::CoursesService(CoursesDao &dao) : dao(dao) {}

string CoursesService::getCoursesJson()
{
    vector<CoursesDao::Course> courses = dao.getAllCourses();

    // 将课程列表转换为 JSON 格式
    nlohmann::json j;
    for (const auto &course : courses) {
        j.push_back({{"name", course.name}, {"instructor", course.instructor}, {"credits", course.credits}});
    }

    return j.dump();  // 转换为字符串
}
