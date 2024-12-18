#include "ScoresDao.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<ScoresDao::Score> ScoresDao::getAllScores() { return parseCSV(filename); }

std::vector<ScoresDao::Score> ScoresDao::parseCSV(const std::string &filePath)
{
    std::vector<Score> scores;
    std::ifstream file(filePath);
    std::string line;
    if (file.is_open()) {
        // 跳过第一行（标题行）
        std::getline(file, line);

        // 解析每一行
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            Score score;
            std::getline(ss, score.stu_id, ',');
            std::getline(ss, score.course_id, ',');
            std::getline(ss, score.score, ',');

            scores.push_back(score);
        }
    }
    else {
        std::cerr << "Could not open the file " << filePath << std::endl;
    }
    return scores;
}
