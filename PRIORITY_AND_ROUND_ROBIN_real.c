#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct P
{
    char process_name;
    int a_time,b_time,c_time,w_time,t_time,bu_time;
    int priority;
}p[10],p1[10];

struct P tem;
int N,n,i,t=0,t1,t2,pst,px=0,burst_time=0,c=0,k,N2,j,flag=0,y;
float waiting_time=0,turn_around_time= 0;
float average_waiting_time,average_turnaround_time;

void getdata()
{
printf("--------------------OPERATING SYSTEM PROJECT------------------\n");
    printf("\nENTER NUMBER  OF PROCESSES---\n");
    scanf("%d",&N);
    n=N;
    for(i=0;i<=(N-1);i++)
    {
      printf("ENTER NAME OF THE PROCESS(CHARACTER ONLY) ---\n");
      fflush(stdin);
      scanf("%s",&p[i].process_name);
      
      printf("ENTER ARRIVAL TIME OF THE PROCESS---\n");
      scanf("%d",&p[i].a_time);
      
      printf("ENTER BURST TIME OF THE PROCESSES---\n");
      scanf("%d",&p[i].b_time);
      p[i].bu_time=p[i].b_time;
      
      printf("ENTER PRIORITY OF THE PROCESS---\n");
      scanf("%d",&p[i].priority);
    }
    
    printf("\nENTER TIME QUANTUM FOR FIXED PRIORITY SCHEDULLING QUEUE---\n");
    scanf("%d",&t1);
    
    printf("\nENTER TIME QUANTUM FOR ROUND ROBIN QUEUE---\n");
    scanf("%d",&t2);
    
    printf("\nPROCESS_NAME|TURN_AROUND_TIME|WAITING_TIME\n");
	
}

void processing()
{
	 for(i=0;i<N;i++)// SELECTION SORT ACCORDING TO ARRIVAL TIME
    {
        pst=i;
        for(j=i+1;j<N;j++)
        {
            if(p[j].a_time<p[pst].a_time)
                pst=j;
        }
        tem=p[i];
        p[i]=p[pst];
        p[pst]=tem;
    }//SORTING DONE
    t=p[0].a_time;
    
  }
void main()
{

	getdata();
    
    processing();
    
    printf("           ");
    printf("----FINAL INFORMATION----\n");
    printf("\n----AVERAGE WAITING TIME----%f\n",waiting_time*1.0/n); 
    printf("\n----AVERAGE TURNAROUND TIME---%f",turn_around_time*1.0/n);   
}
