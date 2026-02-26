#include<stdio.h>

int main() {
    int length, a, b, smallestIndex, tempValue;

    printf("Enter number of elements: ");
    scanf("%d", &length);

    int list[length];

    for(a = 0; a < length; a++) {
        printf("Enter value: ");
        scanf("%d", &list[a]);
    }

    for(a = 0; a < length - 1; a++) {
        smallestIndex = a;

        for(b = a + 1; b < length; b++) {
            if(list[b] < list[smallestIndex])
                smallestIndex = b;
        }

        tempValue = list[a];
        list[a] = list[smallestIndex];
        list[smallestIndex] = tempValue;
    }

    printf("Sorted list: ");
    for(a = 0; a < length; a++)
        printf("%d ", list[a]);

    return 0;
}
