#include "ScoresService.h"

#include <string>
#include <vector>

ScoresService::ScoresService(ScoresDao &dao) : dao(dao) {}

nlohmann::json ScoresService::getScoresJson_All()
{
    vector<ScoresDao::Score> scores = dao.getAllScores();
    nlohmann::json j;
    for (const auto &score : scores) {
        string stu_link = "<a href='/students/" + score.stu_id + "'>" + score.stu_id + "</a>";
        j.push_back({{"stu_id", score.stu_id}, {"course_id", score.course_id}, {"score", score.score}});
    }
    return j;
}

nlohmann::json ScoresService::getScoresJson_byStu(string stuID)
{
    vector<ScoresDao::Score> scores = dao.getAllScores();
    nlohmann::json j = nlohmann::json::array();
    for (const auto &score : scores) {
        if (score.stu_id == stuID) {
            j.push_back({{"course_id", score.course_id}, {"score", score.score}});
        }
    }
    return j;
}

nlohmann::json ScoresService::getScoresJson_byCourse(string courseID)
{
    vector<ScoresDao::Score> scores = dao.getAllScores();
    nlohmann::json j = nlohmann::json::array();
    for (const auto &score : scores) {
        if (score.course_id == courseID) {
            j.push_back({{"stu_id", score.stu_id}, {"score", score.score}});
        }
    }
    return j;
}
