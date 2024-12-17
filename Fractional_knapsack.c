//WRITE A PROGRAM  TO IMPLEMENT  FRACTIONAL  KNAPSACK


#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], totalProfit = 0;
    int i, j;
    float temp;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((profit[i] / weight[i]) < (profit[j] / weight[j])) {
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > capacity) {
            break;
        } else {
            x[i] = 1;
            totalProfit += profit[i];
            capacity -= weight[i];
        }
    }

    if (i < n) {
        x[i] = capacity / weight[i];
        totalProfit += x[i] * profit[i];
    }

    printf("Total Profit: %.2f\n", totalProfit);
}

int main() {
    int n, i;
    float weight[20], profit[20], capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &weight[i]);
    }

    printf("Enter the profits of the items: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity);

    return 0;
}
