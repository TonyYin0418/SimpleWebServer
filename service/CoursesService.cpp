#include "CoursesService.h"

#include <string>
#include <vector>

CoursesService::CoursesService(CoursesDao &dao) : dao(dao) {}

nlohmann::json CoursesService::getCoursesJson()
{
    vector<CoursesDao::Course> courses = dao.getAllCourses();

    // 将课程列表转换为 JSON 格式
    nlohmann::json j;
    for (const auto &course : courses) {
        j.push_back({{"id", course.number},
                     {"name", course.name},
                     {"time", course.time},
                     {"teacher", course.teacher},
                     {"location", course.location}});
    }

    return j;  // 转换为字符串
}
