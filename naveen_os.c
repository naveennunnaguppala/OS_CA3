#include<stdio.h>
#include<conio.h>
int ab1,ab2,ab3;
int r_r(int a, int b);
int fcfs(int a, int b);
int pr(int a , int b);
int wt[20];
int main()
{
	//int ab1,ab2,ab3;
	printf("\nEnter number of proes in queue 1:: ");
	scanf("%d",&ab1);
	printf("\nEnter number of proes in queue 2:: ");
	scanf("%d",&ab2);
	printf("\nEnter number of proes in queue 3:: ");
	scanf("%d",&ab3);
	int p1,p2,p3;
	
	char name[3];
	printf("\nEnter pr of queue 1:: ");
	scanf("%d",&p1);
	while(1)
	{
	printf("\nEnter pr of queue 2:: ");
	scanf("%d",&p2);
	if(p1!=p2)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	while(1)
	{
	printf("\nEnter pr of queue 3:: ");
	scanf("%d",&p3);
	if(p1!=p3&&p2!=p3)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	if (p1<p2&&p1<p3)
	{
		r_r(ab1,1);
		if(p2<p3)
		{
			pr(ab2,2);
			fcfs(ab3,3);
		}
		else
		{
			pr(ab3,3);
			fcfs(ab2,2);
		}
	}
	else if(p2<p1&&p2<p3)
	{
		r_r(ab2,2);
		if(p1<p3)
		{
			pr(ab1,1);
			fcfs(ab3,3);
		}
		else
		{
			pr(ab3,3);
			fcfs(ab1,1);
		}
	}
	else
	{
		r_r(ab3,3);
		if(p1<p2)
		{
			pr(ab1,1);
			fcfs(ab2,2);
		}
		else
		{
			pr(ab2,2);
			fcfs(ab1,1);
		}
	}
}

int r_r(int e, int f)
{
	int i, l, tot = 0, x, con = 0, tq; 
      int w_t = 0, tat = 0, a_t[10], b_t[10], temp[10]; 
      float avg_w_t, avg_tat;
      printf("applying r_r on queue no. %d ",f);
      /*printf("\nEnter tot Number of proes:\t"); 
      scanf("%d", &l);*/
	  l=e; 
      x = l; 
      for(i = 0; i < l; i++) 
      {
            printf("\nEnter Details of pro[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a_t[i]);
            printf("Burst Time:\t");
            scanf("%d", &b_t[i]); 
            temp[i] = b_t[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &tq); 
      printf("\npro ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(tot = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= tq && temp[i] > 0) 
            { 
                  tot = tot + temp[i]; 
                  temp[i] = 0; 
                  con = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - tq; 
                  tot = tot + tq; 
            } 
            if(temp[i] == 0 && con == 1) 
            { 
                  x--; 
                  printf("\npro[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, b_t[i], tot - a_t[i], tot - a_t[i] - b_t[i]);
                  w_t = w_t + tot - a_t[i] - b_t[i]; 
                  tat = tat + tot - a_t[i]; 
                  con = 0; 
            } 
            if(i == l - 1) 
            {
                  i = 0; 
            }
            else if(a_t[i + 1] <= tot) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      avg_w_t = w_t * 1.0 / l;
      avg_tat = tat * 1.0 / l;
      printf("\n\navg Waiting Time:\t%f", avg_w_t); 
      printf("\nAvg Turnaround Time:\t%f\n", avg_tat); 
      return 0; 
}
int pr(int a,int b)
{
	int b_t[20], pro[20], tat[20], pr[20];
      int i, j, l, sum = 0, pos, temp;
      float avg_w_t, avg_tat;
      printf("applying pr scheduling algorithm on queue no. %d",b);
      /*printf("Enter tot Number of proes:\t");
      scanf("%d", &l);*/
      l=a;
      int ask=1;
      printf("\nEnter Burst Time and pr For %d proes\n", l);
      if(ask=1)
      {
      	for(i = 0; i < l; i++)
      {
            printf("\npro[%d]\n", i + 1);
            printf("pro Burst Time:\t");
            scanf("%d", &b_t[i]);
            printf("pro pr:\t");
            scanf("%d", &pr[i]);
            pro[i] = i + 1;
      }
      ask=0;
	  }
      for(i = 0; i < l; i++)
      {
            pos = i;
            for(j = i + 1; j < l; j++)
            {
                  if(pr[j] < pr[pos])
                  {
                        pos = j;
                  }
            }
            temp = pr[i];
            pr[i] = pr[pos];
            pr[pos] = temp; 
            temp = b_t[i];
            b_t[i] = b_t[pos];
            b_t[pos] = temp;
            temp = pro[i];
            pro[i] = pro[pos];
            pro[pos] = temp;
      }
      wt[0] = 0;
      for(i = 1; i < l; i++)
      {
            wt[i] = 0;
            for(j = 0; j < i; j++)
            {
                  wt[i] = wt[i] + b_t[j];
            }
            sum = sum + wt[i];
      }
      avg_w_t = sum / l;
      sum = 0;
      printf("\npro ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < l; i++)
      {
            tat[i] = b_t[i] + wt[i];
            sum = sum + tat[i];
            printf("\npro[%d]\t\t%d\t\t %d\t\t %d\n", pro[i], b_t[i], wt[i], tat[i]);
      }
      avg_tat = sum / l;
      printf("\navg Waiting Time:\t%f", avg_w_t);
      printf("\navg Turnaround Time:\t%f\n", avg_tat);
      return 0;
}

int fcfs(int c, int d)
{
	float b_t[30], wt[30], tat[30];
        float avg_wt = 0.0, avg_tat = 0.0;
        int count, j, tot_pro;
        printf("applying fcfs on queue no . %d",d);
        /*printf("Enter The Number of proes To Execute:\t");
        scanf("%d", &tot_pro);*/
        tot_pro=c;
        printf("\nEnter The Burst Time of proes:\n\n");
        for(count = 0; count < tot_pro; count++)
        {
                printf("pro [%d]:", count + 1);
                scanf("%f", &b_t[count]);
        }
        wt[0] = 0;   
        for(count = 1; count < tot_pro; count++)
        {
                wt[count] = 0;
                for(j = 0; j < count; j++)
                {
                        wt[count] = wt[count] + b_t[j];
                }
        }
        printf("\npro\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < tot_pro; count++)
        {
                tat[count] = b_t[count] + wt[count];
                avg_wt = avg_wt + wt[count];
                avg_tat = avg_tat + tat[count];
                printf("\npro [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, b_t[count], wt[count], tat[count]);
        }
        printf("\n");
        avg_wt = avg_wt / count;
        avg_tat = avg_tat / count;
        printf("\navg Waiting Time = %f", avg_wt);
        printf("\navg Turnaround Time = %f", avg_tat);
        printf("\n");
        return 0;
}


