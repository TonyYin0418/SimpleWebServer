#ifndef SCORES_CONTROLLER_H
#define SCORES_CONTROLLER_H

#include <iostream>
#include <string>

#include "../framework/controller.h"

using namespace std;

class ScoresController : public Controller
{
   public:
    void f0(string path) override;
};

#endif  // SCORES_CONTROLLER_H
