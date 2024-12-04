#include "router.framework.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// -------- Controller C1 -----------

class C1 : public Controller
{
DECLARE_CTRL_FUN(0)
DECLARE_CTRL_FUN(2)

public:
	void exec(string path)
	{
		cout << "C1 object exec() for: " << path << endl;
	}
    void process(string path)
	{
		cout << "C1 object process() for: " << path << endl;
	}
};

IMPLEMENT_CTRL_FUN(C1,0,process)
IMPLEMENT_CTRL_FUN(C1,2,exec)

// -------- Controller C2 -----------

class C2 : public Controller
{
DECLARE_CTRL_FUN(2)

public:
  void run(string path)
  {
    cout << "C2 object run() for: " << path << endl;
  }
};

IMPLEMENT_CTRL_FUN(C2,2,run)

// -------- MyRouter -----------

class MyRouter : public Router {
	virtual void setupRouting();
};

void MyRouter::setupRouting() {
	REGISTER_CTRL_FUN("GET","/students/getall",C1,0)
	REGISTER_CTRL_FUN("GET","/students/getbyage",C1,2)
	REGISTER_CTRL_FUN("GET","/courses/physics",C2,2)
}

MyRouter myRouter;
