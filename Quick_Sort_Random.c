#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randomPartition(int valueSet[], int lowLimit, int highLimit) {

    int randomIndex = lowLimit + rand() % (highLimit - lowLimit + 1);

    int tempSwap = valueSet[randomIndex];
    valueSet[randomIndex] = valueSet[highLimit];
    valueSet[highLimit] = tempSwap;

    int pivotValue = valueSet[highLimit];
    int smallerPos = lowLimit - 1;

    for(int current = lowLimit; current < highLimit; current++) {
        if(valueSet[current] < pivotValue) {
            smallerPos++;
            tempSwap = valueSet[smallerPos];
            valueSet[smallerPos] = valueSet[current];
            valueSet[current] = tempSwap;
        }
    }

    tempSwap = valueSet[smallerPos + 1];
    valueSet[smallerPos + 1] = valueSet[highLimit];
    valueSet[highLimit] = tempSwap;

    return smallerPos + 1;
}

void randomizedQuickSort(int valueSet[], int startRange, int endRange) {
    if(startRange < endRange) {
        int pivotLocation = randomPartition(valueSet, startRange, endRange);

        randomizedQuickSort(valueSet, startRange, pivotLocation - 1);
        randomizedQuickSort(valueSet, pivotLocation + 1, endRange);
    }
}

int main() {
    int elementTotal;

    srand(time(NULL));

    printf("Enter number of elements: ");
    scanf("%d", &elementTotal);

    int valueSet[elementTotal];

    for(int counter = 0; counter < elementTotal; counter++) {
        printf("Enter value: ");
        scanf("%d", &valueSet[counter]);
    }

    randomizedQuickSort(valueSet, 0, elementTotal - 1);

    printf("Sorted list: ");
    for(int counter = 0; counter < elementTotal; counter++)
        printf("%d ", valueSet[counter]);

    return 0;
}
