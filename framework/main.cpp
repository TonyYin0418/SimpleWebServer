#include "../MyRouter.h"

int main() {
    MyRouter router;
    router.setupRouting();

    // Simulating HTTP requests
    router.handle("GET", "/index");
    router.handle("GET", "/scores");
    router.handle("GET", "/courses");
    router.handle("GET", "/nonexistent");

    return 0;
}
