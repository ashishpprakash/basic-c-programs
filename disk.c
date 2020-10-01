

#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

void fcfs();
void look();
void scan();
void cscan();
void clook();
void sstf();

int main(){

	int ans;
	

    printf("-----------------------------------\n");
    printf("1:FCFS \n ");
    printf("2:SSTF \n ");
    printf("3:SCAN  \n");
    printf("4:CSCAN \n ");
    printf("5:LOOK  \n");
    printf("6:CLOOK  \n");
    printf("-----------------------------------\n");
    printf("\nSelect your option: \n");
	scanf("%d",&ans);
	

	switch(ans){

		case 1: fcfs();
		break;

		case 2: sstf();
		break;
		
		case 3: scan();
		break;

		case 4: cscan();
		break;

		case 5: look();
		break;

		case 6: clook();
		break;


	}


}
void fcfs()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
            printf("Enter the number of request\n");
            scanf("%d",&n);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
	    printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            scanf("%d",&queue[i]);
            queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("%d -> %d \n",queue[j],queue[j+1]);
            }
            printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %f\n",avg);
            
}



void look(){


	int queue[20], head, q_size, i,j, seek=0, diff, max, temp, queue1[20], queue2[20], temp1=0, temp2=0;
	  float avg;

	  printf("%s\t", "Input the number of disk locations");
	  scanf("%d", &q_size);

	  printf("%s\t", "Enter initial head position");
	  scanf("%d", &head);

	  printf("%s\n", "Enter disk positions to read");

	  for(i=0; i<q_size; i++){
		scanf("%d", &temp);
		//queue1 - elems greater than head
		if(temp >= head){
		    queue1[temp1] = temp;
		    temp1++;
		} else {
		    queue2[temp2] = temp;
		    temp2++;
		}
	  }

	  //sort queue1 - increasing order
	  for(i=0; i<temp1-1; i++){
	   for(j=i+1; j<temp1; j++){
		   if(queue1[i] > queue1[j]){
		     temp = queue1[i];
		     queue1[i] = queue1[j];
		     queue1[j] = temp;
		   }
		}
	  }

	  //sort queue2 - decreasing order
	  for(i=0; i<temp2-1; i++){
		for(j=i+1; j<temp2; j++){
		  if(queue2[i] < queue2[j]){
		      temp = queue2[i];
		      queue2[i] = queue2[j];
		      queue2[j] = temp;
		  }
		}
	  }

	  if(abs(head-LOW) >= abs(head-HIGH)){

		  for(i=1,j=0; j<temp1; i++,j++){
		      queue[i] = queue1[j];
		  }

		  for(i=temp1+1, j=0; j<temp2; i++, j++){
		      queue[i] = queue2[j];
		  }

	  } else {

		  for(i=1,j=0; j<temp2; i++,j++){
		      queue[i] = queue2[j];
		  }

		  for(i=temp2+1, j=0; j<temp1; i++, j++){
		      queue[i] = queue1[j];
		  }

	  }

	  queue[0] = head;

	  for(j=0; j<q_size; j++){
		  diff=abs(queue[j+1] - queue[j]);
		    seek += diff;
		    printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

	  }

	  printf("Total seek time is %d\n", seek);
	  avg = seek/(float)q_size;
	  printf("Average seek time is %f\n", avg);

	  //return 0;


}

void scan()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],
                        temp1=0,temp2=0;
            float avg;
            printf("Enter the max range of disk\n");
            scanf("%d",&max);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            printf("Enter the size of queue request\n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]<queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            queue[i]=queue1[j];
            queue[i]=max;
            for(i=temp1+2,j=0;j<temp2;i++,j++)
            queue[i]=queue2[j];
            queue[i]=0;
            queue[0]=head;
            for(j=0;j<=n+1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("%d -> %d\n",queue[j],queue[j+1]);
            }
            printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %f\n",avg);
}

void cscan(){

	 int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],
                        temp1=0,temp2=0;
            float avg;
            printf("Enter the max range of disk\n");
            scanf("%d",&max);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            printf("Enter the size of queue request\n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]>queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            queue[i]=queue1[j];
            queue[i]=max;
            queue[i+1]=0;
            for(i=temp1+3,j=0;j<temp2;i++,j++)
            queue[i]=queue2[j];
            queue[0]=head;
            for(j=0;j<=n+1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("%d -> %d\n",queue[j],queue[j+1]);
            }
            printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %f\n",avg);
}

void clook(){


	int queue[20], head, q_size, i,j, seek=0, diff, max, min, range, temp, queue1[20], queue2[20], temp1=0, temp2=0;
	  float avg;

	  printf("%s\t", "Input the number of disk locations");
	  scanf("%d", &q_size);

	  printf("%s\t", "Enter initial head position");
	  scanf("%d", &head);

	  printf("%s\n", "Enter disk positions to read");

	  for(i=0; i<q_size; i++){
		scanf("%d", &temp);
		//queue1 - elems greater than head
		if(temp >= head){
		  queue1[temp1] = temp;
		  temp1++;
		} else {
		  queue2[temp2] = temp;
		  temp2++;
		}
	  }


	  //sort queue1 - increasing order
	  for(i=0; i<temp1-1; i++){
		for(j=i+1; j<temp1; j++){
		  if(queue1[i] > queue1[j]){
		    temp = queue1[i];
		    queue1[i] = queue1[j];
		    queue1[j] = temp;
		  }
		}
	  }

	  //sort queue2
	  for(i=0; i<temp2-1; i++){
		for(j=i+1; j<temp2; j++){
		  if(queue2[i] > queue2[j]){
		    temp = queue2[i];
		    queue2[i] = queue2[j];
		    queue2[j] = temp;
		  }
		}
	  }

	  if(abs(head-LOW) <= abs(head-HIGH)){

		for(i=1,j=temp2-1; j>=0; i++,j--){
		    queue[i] = queue2[j];
		}

		queue[i] = LOW;
		queue[i+1] = HIGH;

		for(i=temp2+3,j=temp1-1; j>=0; i++,j--){
		    queue[i] = queue1[j];
		}

	  } else {

		for(i=1,j=0; j<temp1; i++,j++){
		    queue[i] = queue1[j];
		}

		queue[i] = HIGH;
		queue[i+1] = LOW;

		for(i=temp1+3,j=0; j<temp2; i++,j++){
		    queue[i] = queue2[j];
		}


	  }
	  queue[0] = head;

	  for(j=0; j<q_size; j++){
		diff=abs(queue[j+1] - queue[j]);
		seek += diff;
		printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

	  }

	  //range = max - min;
	  //printf("Range is %d", range);
	  //seek =  seek - (max - min);

	  printf("Total seek time is %d\n", seek);
	  avg = seek/(float)q_size;
	  printf("Average seek time is %f\n", avg);

	 
}

void sstf()
{
  int queue[100], queue2[100], q_size, head, seek=0, temp;
  float avg;

  printf("%s\n", "-----SSTF Disk Scheduling Algorithm-----");

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements");
  for(int i=0; i<q_size; i++){
    scanf("%d",&queue[i]);
  }

  printf("%s\n","Enter initial head position");
  scanf("%d", &head);

  //get distance from head of elems in queue
  for(int i=0; i<q_size; i++){
    queue2[i] = abs(head-queue[i]);
  }

  //swap elems based on their distance from each other
  for(int i=0; i<q_size; i++){
      for(int j=i+1; j<q_size;j++){

        if(queue2[i]>queue2[j]){
            temp = queue2[i];
            queue2[i]=queue[j];
            queue2[j]=temp;

            temp=queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }

  }

  for(int i=1; i<q_size; i++){
    seek = seek+abs(head-queue[i]);
    head = queue[i];
	printf("%d",head);
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);
}




  

