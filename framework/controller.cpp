#include "controller.h"

#include <fstream>
#include <iostream>

// 利用map，把html模板里面的{{xxxxxx}}替换掉
string Controller::renderHTML(string &templatePath, map<string, string> &placeHoldersTable)
{
    // 把template文件内容全读到std::string中，这样无需分块读取
    ifstream file(templatePath);
    if (!file.is_open()) return "打不开HTML模板\n";
    // 有构造函数string(begin_iterator, end_iterator)
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // 下面进行替换
    for (const auto &[key, value] : placeHoldersTable) {
        std::cout << "Dir: framework/controller.cpp\n";
        std::cout << "\tkey: " << key << std::endl;
        std::cout << "\tvalue: " << value << std::endl;
        size_t pos = content.find(key);
        while (pos != string::npos) {
            content.replace(pos, key.length(), value);
            pos = content.find(key, pos + value.length());
        }
    }

    return content;
}
