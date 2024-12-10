#include "../MyRouter.h"
#include "../http_server.h"
int main()
{
    MyRouter router;
    router.setupRouting();
    
    router.handle("GET", "/index");
    router.handle("GET", "/scores");
    router.handle("GET", "/courses");
    router.handle("GET", "/nonexistent");

    httpServer server("127.0.0.1", 9870, router);
    server.run();

    return 0;
}
