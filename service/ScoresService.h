#ifndef ScoresService_h
#define ScoresService_h

#include <string>
#include <vector>

#include "../dao/ScoresDao.h"
#include "../nlohmann/json.hpp"  // 使用 nlohmann JSON 库来生成 JSON 格式的响应

using namespace std;

class ScoresService
{
   public:
    ScoresService(ScoresDao &dao);
    nlohmann::json getScoresJson_All();
    nlohmann::json getScoresJson_byStu(string stuId);
    nlohmann::json getScoresJson_byCourse(string courseID);

   private:
    ScoresDao &dao;
};

#endif /* ScoresService_h */
