#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Check if power by two of integer
bool isPowerOfTwo(int n) {
    if(n < 0 ) {
        return false;
    }

    int count_ones = 0;

    /** bitwise operation to check whether there is a 1 bit that occurs exactly once.
     * Thus indicating a power of two because it's a positive Integer.
     */
    while (n != 0) {
        count_ones += n & 1;
        n = n >> 1;
    }

    return count_ones == 1;
}

// Gets the most significant 1 bit index of an Integer
int getMostSignificantBitIndex(int n) {
    int count = 0;

    while (n != 0) {
        count += 1;
        n = n >> 1;
    }

    return count - 1;
}

int getSizeOfArray() {
    int size_of_input;

    printf("Enter size of input:\n");
    scanf("%d", &size_of_input);

    if (size_of_input <= 0) {
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

int main() {
    int size_of_array = getSizeOfArray();
    int *numbers_array_pointer = getNumbersArrayPointerFromInput(size_of_array);

    printNumbersOfPowerByTwoInfo(numbers_array_pointer, size_of_array);

    free(numbers_array_pointer);

    return 0;
}
