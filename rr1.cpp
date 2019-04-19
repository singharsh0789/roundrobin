#include<stdio.h> 
#include<iostream>
using namespace std;
int np;

	char pname[20];
int count,at[10],bt[10],qt,rt[10],tt=0,wt=0,flag=0,time,remain;
int faculty_queue(int np)
  {
  
      remain=np;
  	  for(count = 0; count < np; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", pname);

        printf("Arrival Time : ");
        scanf("%d", &at[count]);

        printf("Burst Time : ");
        scanf("%d", &bt[count]);
        puts("");
        rt[count]=bt[count]; 
    }
    printf("Now, enter the quantum time for FACULTY queue : ");
    scanf("%d", &qt);
     for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=qt && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=qt; 
      time+=qt; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wt+=time-at[count]-bt[count]; 
      tt+=time-at[count]; 
      flag=0; 
    } 
    if(count==np-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wt*1.0/np); 
  printf("Avg Turnaround Time = %f",tt*1.0/np);
  
  }
int student_queue(int np )
  {
  
      remain=np;
  	  for(count = 0; count < np; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", pname);

        printf("Arrival Time : ");
        scanf("%d", &at[count]);

        printf("Burst Time : ");
        scanf("%d", &bt[count]);
        puts("");
        rt[count]=bt[count]; 
    }
    printf("Now, enter the quantum time for STUDENT queue : ");
    scanf("%d", &qt);
     for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=qt && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=qt; 
      time+=qt; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wt+=time-at[count]-bt[count]; 
      tt+=time-at[count]; 
      flag=0; 
    } 
    if(count==np-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wt*1.0/np); 
  printf("Avg Turnaround Time = %f",tt*1.0/np);
  }

 
int main() 
{ 
  
int i;
printf("Please choose a queue to post your query : ");
printf("\n1. FACULTY queue.");
printf("\n2. STUDENT queue.");
    printf("\n> ");
    scanf("%d", &i);
switch (i)
{
	 case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &np);
                faculty_queue(np);
                
                
                break;

        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &np);

                student_queue(np);
                
                break;

        default : 
                printf("Please selet the correct option by running the program again.");
 } 
  return 0; 
}

