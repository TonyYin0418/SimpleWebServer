#ifndef COURSESDAO_H
#define COURSESDAO_H

#include <string>
#include <vector>

class CoursesDao
{
   public:
    struct Course
    {
        std::string number;
        std::string name;
        std::string time;
        std::string teacher;
        std::string location;
    };

    std::vector<Course> getAllCourses();
    //    std::string filename = "../../../../../public/courses.csv";  // For Xcode
    std::string filename = "public/courses.csv";  // For Cmake

   private:
    std::vector<Course> parseCSV(const std::string &filePath);
};

#endif /* COURSESDAO_H */
