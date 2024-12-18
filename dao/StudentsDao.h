//
//  ScoresDao.hpp
//  main
//
//  Created by TonyYin on 2024/12/17.
//

#ifndef StudentsDao_h
#define StudentsDao_h

#include <string>
#include <vector>

class StudentsDao
{
   public:
    struct Student
    {
        int id;
        std::string name;
        int age;
        std::string sex;
    };

    std::vector<Student> getAllStudents();
    std::string filename = "public/students.csv";  // For Cmake

   private:
    std::vector<Student> parseCSV(const std::string &filePath);
};

#endif /* StudentsDao_h */
