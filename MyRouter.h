#ifndef MYROUTER_H
#define MYROUTER_H

#include "framework/router.h"

class MyRouter : public Router
{
   public:
    void setupRouting() override;
};

#endif  // MYROUTER_H
