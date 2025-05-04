#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_DEPTH 10

int children_at_level[MAX_DEPTH];
int max_level = 0;

void create_tree(int level) {
    if (level > max_level) return;

    int num_children = children_at_level[level];
    printf("PID %d at level %d will create %d children\n", getpid(), level, num_children);

    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            create_tree(level + 1);
            exit(0);
        }
    }

    for (int i = 0; i < num_children; i++) {
        wait(NULL);
    }
}

void read_config(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Failed to open config file");
        exit(1);
    }

    int depth, count;
    while (fscanf(f, "%d %d", &depth, &count) == 2) {
        if (depth >= MAX_DEPTH) {
            fprintf(stderr, "Depth %d exceeds max supported depth\n", depth);
            exit(1);
        }
        children_at_level[depth] = count;
        if (depth > max_level) max_level = depth;
    }

    fclose(f);
}

int main() {
    read_config("tree.txt");

    printf("Starting tree creation from PID %d\n", getpid());
    create_tree(0);
    printf("Process %d finished\n", getpid());

    return 0;
}
