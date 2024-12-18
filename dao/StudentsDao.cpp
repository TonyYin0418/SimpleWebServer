#include "StudentsDao.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<StudentsDao::Student> StudentsDao::getAllStudents() { return parseCSV(filename); }

std::vector<StudentsDao::Student> StudentsDao::parseCSV(const std::string &filePath)
{
    std::vector<Student> students;
    std::ifstream file(filePath);
    std::string line;
    if (file.is_open()) {
        // 跳过第一行（标题行）
        std::getline(file, line);

        // 解析每一行
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            Student student;
            std::string tmp;

            std::getline(ss, tmp, ',');
            student.id = std::stoi(tmp);

            std::getline(ss, student.name, ',');

            std::getline(ss, tmp, ',');
            student.age = std::stoi(tmp);

            std::getline(ss, student.sex, ',');

            students.push_back(student);
        }
    }
    else {
        std::cerr << "Could not open the file " << filePath << std::endl;
    }
    return students;
}
