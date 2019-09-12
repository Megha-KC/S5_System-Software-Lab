#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int semaphore;
semaphore n, front=-1 ,rear =-1 ,full, empty, mutex,*buffer;
int wait(int s)
{
	//S=s;
	while(s<=0);//busy wait
	s--;
	return s;
}

int signal(int s)
{
	// S=s;
	s++;
	return s;
}

void produce()
{	
		int item;
		/* produce an item in next produced */
		if(empty == n)//empty buffer
			front=rear=0;
		else
			rear = (rear+1)%n;
		empty = wait(empty);
		// printf("Input the item: \n");
		// scanf("%d",&item);
		mutex = wait(mutex);
		printf("Enter item to be produced: \n");
		scanf("%d", &item);
		printf("...Item - %d -produced...\n", item);
		/* add next produced to the buffer */
		buffer[rear] = item;
		mutex = signal(mutex);
		full = signal(full);
}

void consume()
{
	int item;
	full = wait(full);
	mutex = wait(mutex);
	/* remove an item from buffer to next consumed */
	item = buffer[front];
	if(front == rear)//empty buffer
	{
		front = rear = -1;
	}
	else
		front = (front+1)%n;
	printf("...Item - %d - consumed...\n", item);
	mutex = signal(mutex);
	empty = signal(empty);
	/* consume the item in next consumed */
}
main()
{
	int c;
	printf("Enter the buffer size: ");
	scanf("%d", &n);
	buffer = (int *)malloc(n*sizeof(int));
	full = 0;
	empty = n;
	mutex = 1;
	do{
		printf("1.Produce an item\n2.Consume an item\n3.Exit\nEnter your choice:");
		scanf("%d", &c);
		switch(c)
		{
			case 1: if(empty!=0)
						produce();
					else
						printf("\nBuffer is full!\n");
					break;

			case 2: if(full!=0)
						consume();
					else
						printf("\nBuffer is empty!\n");
					break;

			case 3: 
			default: exit(0);
		}
	}while(true);
}