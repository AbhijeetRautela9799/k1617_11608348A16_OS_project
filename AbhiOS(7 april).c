//SATURDAY WORK(7 APRIL 2018).............................................
#include<stdio.h>
#include<conio.h>
struct process
{
	char process_name;
	int a_time,b_time,c_time,w_time,t_time;
	int priority,b_time1;
	int queue_no;
}p[20],p1[20],p2[20];
void main()
{
	printf("................OPERATING SYSTEM PROJECT............")
	struct process x;
	int n,i,j=0,k=0,n1=0,n2=0;
	printf("ENTER TOTAL NUMBER OF PROCESSES-\n");
	scanf("%d",&n);
	for(i=0;i<=(n-1);i++)
	{
		printf("ENTER PROCESS NAME-\n");
		fflush(stdin);
		scanf("%c",&p[i].process_name);
		printf("ENTER PROCESS QUEUE NUMBER(0 or 1)-\n");
		scanf("%d",&p[i].queue_no);
			if(p[i].queue_no==0)
		{
			n1++;
		}
		else
		{
			n2++;
		}
		printf("ENTER ARRIVAL TIME-\n");
		scanf("%d",&p[i].a_time);
		printf("ENTER BURST TIME-\n");
		scanf("%d",&p[i].b_time);
	}
	
	
	for(i=0;i<=(n-1);i++)
	{
		if(p[i].queue_no==0)
		{
			p1[j]=p[i];
			j++;
		}
		else
		{
			p2[k]=p[i];
			k++;
		}
	}
	printf("NUMBER PROCESSES IN FIXED PRIORITY SCHEDULLING QUEUE---");
	printf("%d",n1);
	printf("\nNUMBER PROCESSES IN ROUND ROBIN QUEUE---");
	printf("%d",n2);

	printf("\nPROCESSES IN FIXED PRIORITY SCHEDULLING QUEUE---\n");
	for(j=0;j<=(n1-1);j++)
	{
		printf("%c",p1[j].process_name);
	}
	
	printf("\nPROCESSES IN ROUND ROBIN QUEUE---\n");
	for(k=0;k<=(n2-1);k++)
	{
		printf("%c",p2[k].process_name);
	}
	
	
}
