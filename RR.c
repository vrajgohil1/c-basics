/*
Task table schema:
P.id A.T B.T C.T T.A.T W.T
*/
#include<stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = -1;
int front = -1;
int counter_rear = 0;
int counter_front = 0;
int total_bt;
int time=0;
//insert in queue
int insert(int add_item)
{
    if (rear == MAX - 1){
        printf("Queue is Full!!!! \n");
    }
    else
    {
        if (front == - 1)

            front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

int display_queue() {
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
void swap(int xp, int yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
int main(){
    int task[5][5];
    int tq=1;
    int bt_queue[5];
    for (int i=0;i<5;i++){
        printf("Enter the arrival time and burst time for process P%d :", i);
        task[i][0]=i;
        scanf("%d %d", &task[i][1], &task[i][2]);
    }
    printf("I.D.     A.T.    B.T.");
    for (int i=0;i<5;i++){
        printf("\n %d\t %d\t %d\n", task[i][0],task[i][1],task[i][2]);
    }
    //bubble short
   for (int i = 0; i < 5-1; i++){
       // Last i elements are already in place
       for (int j = 0; j < 5-i-1; j++){
           if (task[j][1] > task[j+1][1]){
              swap(task[j][1], task[j+1][1]);
              swap(task[j][0], task[j+1][0]);
              swap(task[j][2], task[j+1][2]);
           }
       }
   }
   //copying bt queue
   for(int i=0;i<5;i++){
       bt_queue[i]=task[i][2];
       printf("BT queue : %d p.id: %d\n",bt_queue[i],task[i][0]);
   }
    int process_index=0;
   time=task[0][1];
    while(1){
        total_bt=0;
        for(int i=0;i<5;i++){
            if(task[i][1]<=time && bt_queue[i]!=0){
                insert(task[i][0]);
                counter_rear++;
            }
        }
        time+=tq;
        for(int i=counter_front;i<counter_rear;i++){
            process_index=queue_array[i];
            if(bt_queue[process_index]!=0){
                insert(task[i][0]);
                counter_front++;
                bt_queue[process_index]-=tq;
                total_bt+=bt_queue[process_index];
            }
        }
        if(total_bt==0){
            break;
        }
    }

    display_queue();
//calculating CT,TAT & WT
   int ct=task[0][1];
   for (int i=0;i<5;i++){
        //finding C.T
       ct+=task[i][2];
       task[i][3]=ct;
       //finding T.A.T
       task[i][4]=task[i][3]-task[i][1];
       //finding W.T
       task[i][5]=task[i][4]-task[i][2];

   }
   //final output
   printf("I.D.     A.T.    B.T.    C.T.    T.A.T.  W.T.");
    for (int i=0;i<5;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\n", task[i][0],task[i][1],task[i][2],task[i][3],task[i][4],task[i][5]);
    }
    //finding total W.T and T.A.T
    float totaltat=0;
    float totalwt=0;
    for(int i=0;i<5;i++){
        totaltat+=task[i][4];
        totalwt+=task[i][5];
    }
    printf("\n Average Turnaround time is : %f", totaltat/5);
    printf("\n Average waiting time is : %f\n", totalwt/5);
    return 0;
}

