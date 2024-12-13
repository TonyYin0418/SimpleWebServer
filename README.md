# A Simple Web Server

This is a simple web server built using C++.

大作业

# Getting Started

## Prerequisites

Before running the server, ensure you have the following installed:
	•	C++ Compiler: A C++ compiler like g++ or clang++.
	•	CMake: For building the project.

## Installation

1.	Clone the repository:
```
git clone https://github.com/your-username/SimpleWebServer.git
cd SimpleWebServer
```
2.	Build the project:
```
mkdir build
cd build
cmake ..
make
```
3.	After building, you can run the server:
```
./webServer
```
4.	Access the server in your browser by visiting:
```
http://localhost:7890/
```

# Project Structure

```
.
├── MyRouter.cpp
├── MyRouter.h
├── http_server.cpp
├── http_server.h
├── framework
│   ├── controller.cpp
│   ├── controller.h
│   ├── framework.h
│   ├── http.cpp
│   ├── http.h
│   ├── main.cpp
│   ├── router.cpp
│   └── router.h
├── Controller
│   ├── CoursesController.cpp
│   ├── CoursesController.h
│   ├── MainPageController.cpp
│   ├── MainPageController.h
│   ├── ScoresController.cpp
│   └── ScoresController.h
├── service
│   ├── CoursesService.cpp
│   └── CoursesService.h
├── dao
│   ├── CoursesDao.cpp
│   └── CoursesDao.h
└── view
|   └── courses.html
├── public
│   ├── courses.csv
│   └── sytles.css
└── nlohmann
    └── json.hpp
```
你可以根据具体的功能和结构进一步调整和补充文档内容。如果你有其他模块或功能，记得在 Features 和 Project Structure 部分进行描述。
