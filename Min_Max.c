#include<stdio.h>

int main() {
    int totalCount;

    printf("Enter number of elements: ");
    scanf("%d", &totalCount);

    int inputValues[totalCount];

    for(int counter = 0; counter < totalCount; counter++) {
        printf("Enter value: ");
        scanf("%d", &inputValues[counter]);
    }

    int smallestValue = inputValues[0];
    int largestValue = inputValues[0];

    for(int counter = 1; counter < totalCount; counter++) {
        if(inputValues[counter] < smallestValue)
            smallestValue = inputValues[counter];

        if(inputValues[counter] > largestValue)
            largestValue = inputValues[counter];
    }

    printf("Minimum value: %d\n", smallestValue);
    printf("Maximum value: %d\n", largestValue);

    return 0;
}
