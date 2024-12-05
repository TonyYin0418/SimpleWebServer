#ifndef SCORES_CONTROLLER_H
#define SCORES_CONTROLLER_H

#include "../framework/controller.h"
#include <iostream>
#include <string>

using namespace std;

class ScoresController : public Controller {
public:
  void f0(string path) override;
};

#endif // SCORES_CONTROLLER_H
