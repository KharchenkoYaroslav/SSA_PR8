#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int is_sorted(const int *arr, size_t size) {
    for (size_t i = 1; i < size; ++i)
        if (arr[i - 1] > arr[i]) return 0;
    return 1;
}

void generate_array(int *arr, size_t size, const char *type) {
    if (strcmp(type, "sorted") == 0) {
        for (size_t i = 0; i < size; ++i)
            arr[i] = (int)i;
    } else if (strcmp(type, "reversed") == 0) {
        for (size_t i = 0; i < size; ++i)
            arr[i] = (int)(size - i);
    } else if (strcmp(type, "constant") == 0) {
        for (size_t i = 0; i < size; ++i)
            arr[i] = 42;
    } else if (strcmp(type, "random") == 0) {
        for (size_t i = 0; i < size; ++i)
            arr[i] = rand() % 1000;
    }
}

double measure_qsort_time(int *arr, size_t size) {
    clock_t start = clock();
    qsort(arr, size, sizeof(int), compare_ints);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000;  // мс
}

void test_case(const char *label, size_t size) {
    int *arr = malloc(sizeof(int) * size);
    if (!arr) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    generate_array(arr, size, label);

    double elapsed = measure_qsort_time(arr, size);
    printf("Test: %-10s | Size: %zu | Time: %.3f ms | Sorted: %s\n",
           label, size, elapsed, is_sorted(arr, size) ? "YES" : "NO");

    free(arr);
}

int main() {
    srand((unsigned int)time(NULL));

    const char *types[] = {"sorted", "reversed", "constant", "random"};
    size_t sizes[] = {1000, 10000, 100000};

    for (size_t i = 0; i < sizeof(types) / sizeof(types[0]); ++i) {
        for (size_t j = 0; j < sizeof(sizes) / sizeof(sizes[0]); ++j) {
            test_case(types[i], sizes[j]);
        }
    }

    return 0;
}
