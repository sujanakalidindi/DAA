#include<stdio.h>

int createPartition(int numberList[], int startIndex, int endIndex) {
    int pivotElement = numberList[endIndex];
    int smallerIndex = startIndex - 1;
    int loopIndex, tempHolder;

    for(loopIndex = startIndex; loopIndex < endIndex; loopIndex++) {
        if(numberList[loopIndex] < pivotElement) {
            smallerIndex++;
            tempHolder = numberList[smallerIndex];
            numberList[smallerIndex] = numberList[loopIndex];
            numberList[loopIndex] = tempHolder;
        }
    }

    tempHolder = numberList[smallerIndex + 1];
    numberList[smallerIndex + 1] = numberList[endIndex];
    numberList[endIndex] = tempHolder;

    return smallerIndex + 1;
}

void performQuickSort(int numberList[], int leftBoundary, int rightBoundary) {
    if(leftBoundary < rightBoundary) {
        int partitionPoint = createPartition(numberList, leftBoundary, rightBoundary);

        performQuickSort(numberList, leftBoundary, partitionPoint - 1);
        performQuickSort(numberList, partitionPoint + 1, rightBoundary);
    }
}

int main() {
    int totalElements;

    printf("Enter number of elements: ");
    scanf("%d", &totalElements);

    int numberList[totalElements];

    for(int position = 0; position < totalElements; position++) {
        printf("Enter value: ");
        scanf("%d", &numberList[position]);
    }

    performQuickSort(numberList, 0, totalElements - 1);

    printf("Sorted list: ");
    for(int position = 0; position < totalElements; position++)
        printf("%d ", numberList[position]);

    return 0;
}
