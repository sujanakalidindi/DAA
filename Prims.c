#include<stdio.h>
#include<limits.h>

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = 0;

    v[0] = 1;

    int e = 0;

    printf("Edges in MST:\n");

    while(e < n - 1) {
        int min = INT_MAX;
        int s = 0, d = 0;

        for(int i = 0; i < n; i++) {
            if(v[i]) {
                for(int j = 0; j < n; j++) {
                    if(!v[j] && a[i][j]) {
                        if(min > a[i][j]) {
                            min = a[i][j];
                            s = i;
                            d = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", s, d, a[s][d]);

        v[d] = 1;
        e++;
    }

    return 0;
}
