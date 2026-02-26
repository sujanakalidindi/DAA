#include<stdio.h>

void mergeParts(int dataSet[], int start, int midPoint, int end) {
    int leftSize = midPoint - start + 1;
    int rightSize = end - midPoint;

    int leftArray[leftSize], rightArray[rightSize];

    for(int x = 0; x < leftSize; x++)
        leftArray[x] = dataSet[start + x];

    for(int y = 0; y < rightSize; y++)
        rightArray[y] = dataSet[midPoint + 1 + y];

    int i = 0, j = 0, k = start;

    while(i < leftSize && j < rightSize) {
        if(leftArray[i] <= rightArray[j])
            dataSet[k++] = leftArray[i++];
        else
            dataSet[k++] = rightArray[j++];
    }

    while(i < leftSize)
        dataSet[k++] = leftArray[i++];

    while(j < rightSize)
        dataSet[k++] = rightArray[j++];
}

void divideArray(int dataSet[], int begin, int finish) {
    if(begin < finish) {
        int center = (begin + finish) / 2;
        divideArray(dataSet, begin, center);
        divideArray(dataSet, center + 1, finish);
        mergeParts(dataSet, begin, center, finish);
    }
}

int main() {
    int totalItems;

    printf("Enter number of elements: ");
    scanf("%d", &totalItems);

    int dataSet[totalItems];

    for(int idx = 0; idx < totalItems; idx++) {
        printf("Enter value: ");
        scanf("%d", &dataSet[idx]);
    }

    divideArray(dataSet, 0, totalItems - 1);

    printf("Sorted list: ");
    for(int idx = 0; idx < totalItems; idx++)
        printf("%d ", dataSet[idx]);

    return 0;
}
