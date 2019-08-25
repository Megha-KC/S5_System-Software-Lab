#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct directory
{
	char dname[10],fname[10][10];
	int n;//no. of files
	}dir[10];

main()
{
	int i,c,m,k;
	char f[30], d[30];
	m=0;
	while(1)
	{
		printf("\n\n1.Create directory\n2.Create file\n3.Delete file\n4.Search file\n5.Display\n6.Exit\nEnter your choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("\nEnter name of the directory: ");
					scanf("%s", dir[m].dname);
					dir[m].n=0;//currently no files
					m++;
					printf("Directory created");
					break;

			case 2: printf("\n Enter name of the directory -- ");
					scanf("%s",d);
					for(i=0;i<m;i++)
					if(strcmp(d,dir[i].dname)==0)//find if the dircetory exists
					{
						printf("Enter name of the file: ");
						scanf("%s",dir[i].fname[dir[i].n]);
						dir[i].n++;
						printf("File created");
						break;
					}
					if(i==m)
					printf("Directory %s not found",d);
					break;

		case 3: printf("\nEnter name of the directory: ");
				scanf("%s",d);
				for(i=0;i<m;i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter name of the file: ");
						scanf("%s",f);
						for(k=0;k<dir[i].n;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s is deleted ",f);
								dir[i].n--;
								strcpy(dir[i].fname[k],dir[i].fname[dir[i].n]);
								goto jmp;
							}
						}
						printf("File %s not found",f);
						goto jmp;
					}
				}
				printf("Directory %s not found",d);
				jmp : break;

		case 4: printf("\nEnter name of the directory: ");
				scanf("%s",d);
				for(i=0;i<m;i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the name of the file: ");
						scanf("%s",f);
						for(k=0;k<dir[i].n;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s is found ",f);
								goto jmp1;
							}
						}
						printf("File %s not found",f);
						goto jmp1;
					}
				}
				printf("Directory %s not found",d);
				jmp1: break;

		case 5: if(m==0)
				printf("\nNo Directory's ");
				else
				{
					printf("\nDirectory\tFiles");
					for(i=0;i<m;i++)
					{
						printf("\n%s\t\t",dir[i].dname);
						for(k=0;k<dir[i].n;k++)
						printf("\t%s",dir[i].fname[k]);
					}
				}
				break;

		default:exit(0);
		}
	}
}