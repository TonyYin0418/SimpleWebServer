#ifndef StudentsService_h
#define StudentsService_h

#include <string>
#include <vector>

#include "../dao/StudentsDao.h"
#include "../nlohmann/json.hpp"  // 使用 nlohmann JSON 库来生成 JSON 格式的响应

using namespace std;

class StudentsService
{
   public:
    StudentsService(StudentsDao &dao);
    nlohmann::json getStudentsJson(const map<string, string> &queryParams);

   private:
    StudentsDao &dao;
};

#endif /* StudentsService_h */
