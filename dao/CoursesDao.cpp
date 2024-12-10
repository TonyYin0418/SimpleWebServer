#include "CoursesDao.h"

#include <limits.h>  // Required for PATH_MAX
#include <unistd.h>  // Required for getcwd

#include <fstream>
#include <iostream>
#include <sstream>
std::vector<CoursesDao::Course> CoursesDao::getAllCourses() {
    return parseCSV(filename);
}

std::vector<CoursesDao::Course> CoursesDao::parseCSV(const std::string &filePath) {
    std::vector<Course> courses;
    std::ifstream file(filePath);
    std::string line;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working dir: " << cwd << std::endl;
    }
    if (file.is_open()) {
        // 跳过第一行（标题行）
        std::getline(file, line);

        // 解析每一行
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            Course course;
            std::getline(ss, course.name, ',');
            std::getline(ss, course.instructor, ',');
            ss >> course.credits;
            courses.push_back(course);
        }
    } else {
        std::cerr << "Could not open the file " << filePath << std::endl;
    }

    return courses;
}
