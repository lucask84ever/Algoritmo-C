#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define arraySize 10

void generateRandom(int *randomNums) {
    int i;
    srand(time(NULL));
    for(i = 0; i < arraySize; i += 1) {
        randomNums[i] = rand() % 100 + 1;
    }
}

void printArray(int *array) {
    int i = 0;
    for(i = 0; i < arraySize; i += 1) {
        printf("%d\n", array[i]);
    }
}

int main()
{
    int nums[arraySize];
    generateRandom(nums);
    printArray(nums);
    return 0;
}
