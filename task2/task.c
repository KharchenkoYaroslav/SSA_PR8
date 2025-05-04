#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    const char *filename = "test.bin";
    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open for write");
        exit(EXIT_FAILURE);
    }
    write(fd, data, sizeof(data));
    close(fd);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open for read");
        exit(EXIT_FAILURE);
    }

    if (lseek(fd, 3, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[4];
    ssize_t count = read(fd, buffer, 4);
    if (count == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Read %zd bytes: ", count);
    for (int i = 0; i < count; i++) {
        printf("%u ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
