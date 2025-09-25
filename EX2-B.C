#include <stdio.h>

int main() {
    int n, i, j, pos, temp, bt[10], wt[10], tat[10], total_wt = 0, total_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) 
            if(bt[j] < bt[pos]) 
                pos = j;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) 
        wt[i] = wt[i - 1] + bt[i - 1];

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    return 0;
}
