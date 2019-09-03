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
		
		case 2: //choosing default direction towards right
				f = 0;
				for (i = 0; i < n-1; i++)
				{
					p = i;
					for (j = i+1; j < n; j++)
					{
						if(req[j]<req[p])
						{
							p = j;
						}
					}
					t = req[i];
					req[i] = req[p];
					req[p] = t;
					if(f==0 && req[p]>=head)
					{
						f = 1;
						small = p;
					}
				}
				for (i = 0; i < n; i++)
					printf("%d\n", req[i] );
				// printf("Small = %d\n", small);
				// i=small;
				j = i-1;
				printf("\nHEAD MOVEMENTS:\n");
				printf("%d->", head);
				prev = head;
				while(i<n)
				{
					tot+=req[i]-prev;
					prev = req[i];
					printf("%d->", req[i]);
					i++;
				}
				printf("%d->", max);
				tot+=max-req[i-1];
				prev = max;
				while(j>=0)
				{
					tot+= prev - req[j];
					prev = req[j];
					if(j==0)
						printf("%d\n", req[j]);
					else
						printf("%d->", req[j]);
					j--;
				}
				printf("Total head movements = %d cylinders\n", tot);
				break;

		case 3: break;
		default: exit(0);
	}
}
