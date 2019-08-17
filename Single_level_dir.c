#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
	char *dname,*fname[10];
	int n;//no.of files
}dir;

main()
{
	int i,c;
	char *f;
	dir.dname = malloc(25);
	for(i=0;i<10;i++)
	{
		dir.fname[i] = malloc(25);
	}
	printf("\nEnter name of directory: ");
	scanf("%s", dir.dname);
	dir.n = 0;
	printf("%s\n", dir.dname);
	while(1)
	{
		printf("\n\n1. Create file\n2. Delete file\n3. Search file\n4. Display files\n5. Exit\nEnter your choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("\nEnter name of the file: ");
					scanf("%s",dir.fname[dir.n]);
					dir.n++;
					break;

			case 2: printf("\nEnter name of the file: ");
					scanf("%s",f);
					for(i=0;i<dir.n;i++)
					{
						if(strcmp(f, dir.fname[i])==0)
						{
							printf("File %s is deleted ",f);
							strcpy(dir.fname[i],dir.fname[dir.n-1]);
							break;
						}
					}
					if(i==dir.n)
						printf("File %s not found",f);
					else
						dir.n--;
					break;

			case 3: printf("\nEnter name of the file: ");
					scanf("%s",f);
					for(i=0;i<dir.n;i++)
					{
						if(strcmp(f, dir.fname[i])==0)
						{
							printf("File %s is found ", f);
							break;
						}
					}
					if(i==dir.n)
					printf("File %s not found",f);
					break;

			case 4: if(dir.n==0)
						printf("\nDirectory %s is empty!", dir.dname);
					else
					{
						printf("\nThe files are:");
						for(i=0;i<dir.n;i++)
							printf("\t%s",dir.fname[i]);
					}
					break;
			case 5: exit(0);
			default: printf("Invalid choice!");
		}
	}
}