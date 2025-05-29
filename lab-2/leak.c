#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createMemoryLeak() {
    size_t size = 1024 * 1024; // 1 MB

    void *ptr = malloc(size);

    if (ptr == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    
    ((char*)ptr)[0] = 0;

    // Intentionally do not free ptr to cause a memory leak
}

int main() {
    while (1) {
        createMemoryLeak();

        usleep(100000);
    }
    
    return 0;
}
