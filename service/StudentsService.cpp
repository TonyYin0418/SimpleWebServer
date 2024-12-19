#include "StudentsService.h"

#include <string>
#include <vector>

StudentsService::StudentsService(StudentsDao &dao) : dao(dao) {}

nlohmann::json StudentsService::getStudentsJson(const map<string, string> &queryParams)
{
    vector<StudentsDao::Student> students = dao.getAllStudents();
    nlohmann::json j;
    int agefrom = -1;
    int ageto = 200;
    if (queryParams.count("agefrom") && queryParams.count("ageto"))
    {
        agefrom = stoi(queryParams.at("agefrom"));  
        ageto = stoi(queryParams.at("ageto"));
        // std::oi把string转为int
        // at方法适用于const类型，因为operator[]方法可能会插入新元素，访问功能和at一样
    }
    j["range"] = {
        {"agefrom", agefrom},
        {"ageto", ageto},
    };
    for (const auto &student : students) {
        if (agefrom <= student.age && student.age <= ageto) {
            j["scores"].push_back({{"id", to_string(student.id)},
                         {"name", student.name},
                         {"age", to_string(student.age)},
                         {"sex", student.sex}});
        }
    }
    return j;
}
