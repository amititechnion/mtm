#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Check if power by two of integer
bool isPowerOfTwo(int n);

// Gets the most significant 1 bit index of an Integer
int getMostSignificantBitIndex(int n);

int getSizeOfArray();

int *getNumbersArrayPointerFromInput(int size_of_array); 

void printNumbersOfPowerByTwoInfo(int *numbers_array_pointer, int size_of_array);

int main() {
    int size_of_array = getSizeOfArray();
    int *numbers_array_pointer = getNumbersArrayPointerFromInput(size_of_array);

    printNumbersOfPowerByTwoInfo(numbers_array_pointer, size_of_array);

    free(numbers_array_pointer);

    return 0;
}

bool isPowerOfTwo(int n) {
    return (bool)(n & (n-1))
}

int getMostSignificantBitIndex(int n) {
    int count = 0;

    while (n != 1) {
        ++count;
        n = n >> 1;
    }

    return count;
}

int getSizeOfArray() {
    int size_of_input;

    printf("Enter size of input:\n");
    bool is_valid = (bool)scanf("%d", &size_of_input);

    if (!is_valid && size_of_input <= 0) {
        printf("Invalid size\n");
        exit(0);
    }

    return size_of_input;
}

int *getNumbersArrayPointerFromInput(int size_of_array) {
    int *numbers_array_pointer = (int *) malloc(size_of_array * sizeof(int));

    if (numbers_array_pointer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    printf("Enter numbers:\n");

    int i;
    for (i = 0; i < size_of_array; i++) {
        if (scanf("%d", &numbers_array_pointer[i]) != 1) {
            printf("Invalid number\n");
            exit(0);
        }
    }

    return numbers_array_pointer;
}

void printNumbersOfPowerByTwoInfo(int *numbers_array_pointer, int size_of_array) {
    int exponent_sum = 0;

    int i;
    for (i = 0; i < size_of_array; i++) {
        int current_number = numbers_array_pointer[i];
        if (isPowerOfTwo(current_number)) {
            int exponent = getMostSignificantBitIndex(current_number);

            printf("The number %d is a power of 2: %d = 2^%d\n",
                   current_number,
                   current_number,
                   exponent);

            exponent_sum += exponent;
        }
    }

    printf("Total exponent sum is %d\n", exponent_sum);
}
