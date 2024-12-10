#ifndef COURSESDAO_H
#define COURSESDAO_H

#include <string>
#include <vector>

class CoursesDao
{
   public:
    struct Course
    {
        std::string name;
        std::string instructor;
        int credits;
    };

    std::vector<Course> getAllCourses();
    std::string filename = "../../../../../public/courses.csv"; //For Xcode
//    std::string filename = "../public/courses.csv"; //For Cmake

   private:
    std::vector<Course> parseCSV(const std::string &filePath);
};

#endif /* COURSESDAO_H */
