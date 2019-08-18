#include <stdio.h>
#include <stdbool.h>
 
main() {
    int curr[5][5], max_claim[5][5],avl[5],alloc[5] = {0, 0, 0, 0, 0},max_res[5],running[5];
    int i, j, exec, m,n,count = 0;
    bool safe = false;
 
    printf("\nEnter the number of resources: ");
    scanf("%d", &m);
 
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        running[i] = 1;
        count++;
    }
 
    printf("\nEnter Claim Vector (Maximum Resources): ");//Total resources
    for (i = 0; i < m; i++)
        scanf("%d", &max_res[i]);
 
    printf("\nEnter Allocated Resource Table: ");//Allocated resources
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &curr[i][j]);
    }
 
    printf("\nEnter Maximum Claim table: ");//Maximum claim
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &max_claim[i][j]);
    }
 
    printf("\nThe Claim Vector is: ");
    for (i = 0; i < m; i++)
        printf("%d ", max_res[i]);
 
    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }
 
    printf("\nThe Maximum Claim Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            alloc[j] += curr[i][j];
 
    printf("\nAllocated resources: ");
    for (i = 0; i < m; i++)
        printf("%d ", alloc[i]);

    printf("\nAvailable resources: ");
    for (i = 0; i < m; i++)
    {	avl[i] = max_res[i] - alloc[i];
        printf("%d ", avl[i]);
    }
    printf("\n");
 
    while (count != 0) {
        safe = false;
        for (i = 0; i < n; i++) {
            if (running[i])//process is in ready queue
            {
                exec = 1;
                for (j = 0; j < m; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;//cannot execute
                        break;
                    }
                }
 
                if (exec) {
                    printf("\nProcess%d is executing.\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < m; j++)
                        avl[j] += curr[i][j];//process releases resources after execution
                    break;
                }
            }
        }
 
        if (!safe) {
            printf("\nThe processes are in unsafe state.\n");
            break;
        }
 
        if (safe)
            printf("\nThe processes are in safe state.");
 
        printf("\nAvailable vector: ");
        for (i = 0; i < m; i++)
            printf("%d ", avl[i]);
        printf("\n");
    }
}