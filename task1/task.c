#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    fcntl(pipefd[1], F_SETFL, O_NONBLOCK);

    size_t len = 1000000; 
    char *buffer = malloc(len);
    memset(buffer, 'A', len);

    ssize_t count = write(pipefd[1], buffer, len);
    
    printf("count: %zd\n", count);

    free(buffer);
    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}
