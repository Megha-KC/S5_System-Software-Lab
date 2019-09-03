#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int max, head, req[25], c, n, i, tot = 0,prev, t, j, small, p, f;
	printf("Enter the maximum range of cylinders: ");
	scanf("%d", &max);
	printf("Enter the no.of requests: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &req[i]);
	printf("Enter the position of head:");
	scanf("%d", &head);
	printf("\n\n1.FCFS\n2.SCAN\n3.C-SCAN\nChoose the disk scheduling algorithm:");
	scanf("%d", &c);
	switch(c)
	{
		case 1: printf("\nHEAD MOVEMENTS:\n");
				printf("%d->", head);
				prev = head;
				for(i=0;i<n;i++)
				{
					tot += abs(req[i] - prev);
					prev = req[i];
					if(i==n-1)
						printf("%d\n", req[i]);
					else
						printf("%d->", req[i]);
				}
				
				printf("Total head movements = %d cylinders\n", tot);
				break;
		
		case 2: break;

		case 3: break;
		default: exit(0);
	}
}
