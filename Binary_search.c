#include<stdio.h>

int main() {
    int count, left, right, middle, searchKey, result = -1;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    int data[count];

    for(int k = 0; k < count; k++) {
        printf("Enter sorted value: ");
        scanf("%d", &data[k]);
    }

    printf("Enter value to search: ");
    scanf("%d", &searchKey);

    left = 0;
    right = count - 1;

    while(left <= right) {
        middle = (left + right) / 2;

        if(data[middle] == searchKey) {
            result = middle;
            break;
        }
        else if(data[middle] < searchKey)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if(result != -1)
        printf("Value found at index %d", result);
    else
        printf("Value not found");

    return 0;
}
