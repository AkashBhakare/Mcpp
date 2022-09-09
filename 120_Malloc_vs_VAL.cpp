// 120_Malloc_vs_VAL.cpp : 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void store_value(size_t size, int array[*]);

void print_array(size_t size, int array[*]);

void fill_data(int*, size_t size);
void show_data(int*, size_t size);

int main() {
    size_t size;
    printf("How many intgers do you plan to store :");
    scanf("%zu", &size);

    {
        //int a[size]; //VLA
        //store_value(size, a);
        //print_array(size, a);
    }
    //print_array(size,a);

    int* ptr;
    {
        ptr = (int*)malloc(sizeof(int) * size);
        fill_data(ptr, size);
        show_data(ptr, size);
    }
    show_data(ptr, size);
    free(ptr);
    ptr = NULL;
    return 0;
}

void store_value(size_t size, int array[size]) {
    for (size_t i = 0; i < size; ++i) {
        array[i] = i + 10;
    }


}

void print_array(size_t size, int array[size]) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d, ", array[i]);
    }
    printf("\n");

}

void fill_data(int* ptr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = i + 100;
    }
}

void show_data(int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}