#include <stdio.h>

int main() {
    int n, i, tq, t = 0, bt[10], rem_bt[10], wt[10] = {0}, tat[10], total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while(1) {
        int done = 1;
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                int t_inc = rem_bt[i] > tq ? tq : rem_bt[i];
                t += t_inc;
                rem_bt[i] -= t_inc;
                if(rem_bt[i] == 0)
                    wt[i] = t - bt[i];
            }
        }
        if(done)
            break;
    }

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAvg Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAvg Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
