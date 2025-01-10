# A Simple Web Server

This is a simple web server built using C++.

## Getting Started

### Prerequisites

Before running the server, ensure you have the following installed:

- **C++ Compiler**: A C++ compiler like g++ or clang++.
- **CMake**: For building the project.

Development Environment:
- **Operating System**: Mac OS 15.1.1 (You can also build the project on Linux)
- **Compiler**: clang++

### Installation

1.	Clone the repository:
```sh
git clone https://github.com/TonyYin0418/SimpleWebServer.git
cd SimpleWebServer
```
2.	Build the project:
```sh
mkdir build
cd build
cmake ..
make
```
3. Move the executable to the root directory:
```sh
mv webServer ..
```

4. Run the server from the root directory:
```sh
cd ..
./webServer
```

5. Access the server in your browser by visiting:
```sh
http://localhost:7890/
```
## Frontend

The frontend of this project is powered by Element Plus, a Vue 3.0 based component library. The HTML templates are located in the `view` directory and are rendered by the server.

## Backend

The backend of this project is built using C++ and includes the following components:

- **HTTP Server**: Handles incoming HTTP requests and sends responses.
- **Router**: Routes requests to the appropriate controller based on the URL and HTTP method.
- **Controller**: Contains the business logic for handling requests and generating responses.
- **Service**: Encapsulates business logic and interacts with the DAO to retrieve and process data.
- **DAO (Data Access Object)**: Handles data access and manipulation, such as reading from CSV files.
- **JSON Processing**: Uses the nlohmann JSON library to handle JSON data.

The backend processes requests, interacts with the data layer, and returns the appropriate HTML or JSON responses to the client.


## Project Structure

```
.
├── README.md
├── MyRouter.cpp
├── MyRouter.h
├── http_server.cpp
├── http_server.h
├── framework/
│   ├── main.cpp
│   ├── controller.cpp
│   ├── controller.h
│   ├── router.cpp
│   └── router.h
├── controller/
│   ├── CoursesController.cpp
│   ├── CoursesController.h
│   ├── MainPageController.cpp
│   ├── MainPageController.h
│   ├── ScoresController.cpp
│   ├── ScoresController.h
│   ├── StudentsController.cpp
│   └── StudentsController.h
├── service/
│   ├── CoursesService.cpp
│   ├── CoursesService.h
│   ├── ScoresService.cpp
│   ├── ScoresService.h
│   ├── StudentsService.cpp
│   └── StudentsService.h
├── dao/
│   ├── CoursesDao.cpp
│   ├── CoursesDao.h
│   ├── ScoresDao.cpp
│   └── ScoresDao.h
├── view/
├── public/
└── nlohmann
    └── json.hpp
```
