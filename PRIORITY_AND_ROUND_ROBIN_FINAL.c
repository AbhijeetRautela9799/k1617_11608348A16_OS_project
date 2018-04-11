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
      for(i=0;N!=0;i++)//PREEPMTIVE SCHEDULING QUEUE PROCESSING
    {
    	while(c!=t1)
    	{
    		c++;
    		if(p[i].a_time<=t)
    		{
    			for(j=i+1;j<N;j++)
    			{
    				if(p[j].a_time==t && p[j].priority<p[i].priority)
    				{
    					p1[px]=p[i];
						px++;
    					for(k=i;k<N-1;k++)//DELETE THE PROCESS FROM THE QUEUE 1
    					{
    					      p[k]=p[k+1];	
					}
    					N--;
						c=0;
    					i=j-1;
    					j--;
					}
				}
			}
			t++;
			p[i].b_time--;
			if(p[i].b_time==0)
			{
				p[i].t_time=t-p[i].a_time;
				p[i].w_time=p[i].t_time-p[i].bu_time;
				printf("%c\t|\t%d\t|\t%d\n",p[i].process_name,p[i].t_time,p[i].w_time);
				waiting_time=waiting_time+t-p[i].a_time-p[i].bu_time; 
    				turn_around_time=turn_around_time+t-p[i].a_time;
    			for(k=i;k<N-1;k++)
    			{
    				p[k]=p[k+1];i--;//DELETE THE PROCESS FROM QUEUE 1 AND TRANSFER TO QUEUE 2
			}
    			N--;
				c=t1;break;
			}
		}
		c=0;
		if(p[i].b_time!=0)
		{
			p1[px]=p[i];
			px++;
			for(k=i;k<N-1;k++)
			{
				p[k]=p[k+1];
			}
    		N--;
		}
			if(i==N-1)
			{
				i=-1;	
			}
	}
	
	N2=px;//ROUND ROBIN QUEUE PROCESSING
	for(c=0;N2!=0;) 
	{ 
		if(p1[c].b_time<=t2 && p1[c].b_time>0) 
    		{ 
    			t=t+p1[c].b_time; 
    			p1[c].b_time=0; 
    			flag=1; 
    		} 
    		else if(p1[c].b_time>t2) 
    		{ 
    			p1[c].b_time=p1[c].b_time-t2; 
    			t=t+t2; 
    		} 
    	if(p1[c].b_time==0&&flag==1) 
    	{ 
    		N2--; 
    		p1[c].t_time=t-p1[c].a_time;
		p1[c].w_time=p1[c].t_time-p1[c].bu_time; 
		printf("%c\t|\t%d\t|\t%d\n",p1[c].process_name,p1[c].t_time,p1[c].w_time); 
    		turn_around_time=turn_around_time+t-p1[c].a_time; 
    		waiting_time=waiting_time+t-p1[c].a_time-p1[c].bu_time;
    		for(k=c;k<N2;k++)
    		{
    			p1[k]=p1[k+1];
			c--;
		}
    		flag=0; 
    	} 

    	if(c==N2-1) 
    	{
	    c=0; 
    	}
      		
    	else 
    	{
    		c++; 
    	} 
    	
    }
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
