#include<stdio.h>

int main() {
    int size, index, target, position = -1;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int numbers[size];

    for(index = 0; index < size; index++) {
        printf("Enter value: ");
        scanf("%d", &numbers[index]);
    }

    printf("Enter value to search: ");
    scanf("%d", &target);

    for(index = 0; index < size; index++) {
        if(numbers[index] == target) {
            position = index;
            break;
        }
    }

    if(position != -1)
        printf("Value found at index %d", position);
    else
        printf("Value not found");

    return 0;
}
