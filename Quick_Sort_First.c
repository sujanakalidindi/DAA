#include<stdio.h>

void quickDivide(int arrSet[], int lowIndex, int highIndex) {
    if(lowIndex < highIndex) {
        int pivotValue = arrSet[lowIndex];
        int leftPtr = lowIndex + 1;
        int rightPtr = highIndex;
        int swapHolder;

        while(leftPtr <= rightPtr) {
            while(leftPtr <= highIndex && arrSet[leftPtr] <= pivotValue)
                leftPtr++;
            while(arrSet[rightPtr] > pivotValue)
                rightPtr--;

            if(leftPtr < rightPtr) {
                swapHolder = arrSet[leftPtr];
                arrSet[leftPtr] = arrSet[rightPtr];
                arrSet[rightPtr] = swapHolder;
            }
        }

        arrSet[lowIndex] = arrSet[rightPtr];
        arrSet[rightPtr] = pivotValue;

        quickDivide(arrSet, lowIndex, rightPtr - 1);
        quickDivide(arrSet, rightPtr + 1, highIndex);
    }
}

int main() {
    int elementCount;

    printf("Enter number of elements: ");
    scanf("%d", &elementCount);

    int arrSet[elementCount];

    for(int pos = 0; pos < elementCount; pos++) {
        printf("Enter value: ");
        scanf("%d", &arrSet[pos]);
    }

    quickDivide(arrSet, 0, elementCount - 1);

    printf("Sorted list: ");
    for(int pos = 0; pos < elementCount; pos++)
        printf("%d ", arrSet[pos]);

    return 0;
}
