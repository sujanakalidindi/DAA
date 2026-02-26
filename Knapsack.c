#include<stdio.h>

int maximum(int first, int second) {
    return (first > second) ? first : second;
}

int main() {
    int itemCount, capacityLimit;

    printf("Enter number of items: ");
    scanf("%d", &itemCount);

    int profits[itemCount], weights[itemCount];

    for(int item = 0; item < itemCount; item++) {
        printf("Enter profit and weight: ");
        scanf("%d %d", &profits[item], &weights[item]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacityLimit);

    int table[itemCount + 1][capacityLimit + 1];

    for(int i = 0; i <= itemCount; i++) {
        for(int w = 0; w <= capacityLimit; w++) {
            if(i == 0 || w == 0)
                table[i][w] = 0;
            else if(weights[i - 1] <= w)
                table[i][w] = maximum(
                    profits[i - 1] + table[i - 1][w - weights[i - 1]],
                    table[i - 1][w]
                );
            else
                table[i][w] = table[i - 1][w];
        }
    }

    printf("Maximum profit: %d", table[itemCount][capacityLimit]);

    return 0;
}
