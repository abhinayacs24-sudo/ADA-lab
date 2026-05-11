#include <stdio.h>

struct Item
{
    int weight, profit;
    float ratio;
};

int main()
{
    int n, i, j;
    float capacity, totalProfit = 0;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    struct Item item[n], temp;

    for(i = 0; i < n; i++)
    {
        printf("Enter weight and profit of object %d: ", i + 1);
        scanf("%d%d", &item[i].weight, &item[i].profit);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(item[j].ratio < item[j + 1].ratio)
            {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f", totalProfit);

    return 0;
}
