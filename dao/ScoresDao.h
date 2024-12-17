//
//  ScoresDao.hpp
//  main
//
//  Created by TonyYin on 2024/12/17.
//

#ifndef ScoresDao_h
#define ScoresDao_h

#include <string>
#include <vector>

class ScoresDao
{
   public:
    struct Score
    {
        std::string stu_id;
        std::string course_id;
        std::string score;
    };

    std::vector<Score> getAllScores();
    std::string filename = "../../../../../public/scores.csv";  // For Xcode
    //    std::string filename = "../public/scores.csv"; //For Cmake

   private:
    std::vector<Score> parseCSV(const std::string &filePath);
};

#endif /* ScoresDao_h */
