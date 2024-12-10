#ifndef COURSESDAO_H
#define COURSESDAO_H

#include <string>
#include <vector>

class CoursesDao {
public:
    struct Course {
        std::string name;
        std::string instructor;
        int credits;
    };

    std::vector<Course> getAllCourses();

private:
    std::string filename = "./courses.csv";
    std::vector<Course> parseCSV(const std::string &filePath);
};


#endif /* COURSESDAO_H */
