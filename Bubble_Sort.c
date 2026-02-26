#include<stdio.h>

int main() {
    int total, outer, inner, swapTemp;

    printf("Enter number of elements: ");
    scanf("%d", &total);

    int values[total];

    for(outer = 0; outer < total; outer++) {
        printf("Enter value: ");
        scanf("%d", &values[outer]);
    }

    for(outer = 0; outer < total - 1; outer++) {
        for(inner = 0; inner < total - outer - 1; inner++) {
            if(values[inner] > values[inner + 1]) {
                swapTemp = values[inner];
                values[inner] = values[inner + 1];
                values[inner + 1] = swapTemp;
            }
        }
    }

    printf("Sorted list: ");
    for(outer = 0; outer < total; outer++)
        printf("%d ", values[outer]);

    return 0;
}
