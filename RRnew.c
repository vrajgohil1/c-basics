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
int t = 0;
bool done = false;
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
    int task[5][6];
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


	// Keep traversing processes in round robin manner
	// until all of them are not done.
	while (1)
	{
		bool done = true;

		// Traverse all processes one by one repeatedly
		for (int i = 0 ; i < n; i++)
		{
			// If burst time of a process is greater than 0
			// then only need to process further
			if (rem_bt[i] > 0)
			{
				done = false; // There is a pending process

				if (rem_bt[i] > quantum)
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum;

					// Decrease the burst_time of current process
					// by quantum
					rem_bt[i] -= quantum;
				}

				// If burst time is smaller than or equal to
				// quantum. Last cycle for this process
				else
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_bt[i];

					// Waiting time is current time minus time
					// used by this process
					wt[i] = t - bt[i];

					// As the process gets fully executed
					// make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}

		// If all processes are done
		if (done == true)
		break;
	}
    // display_queue();
//calculating CT,TAT & WT

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







// C++ program for implementation of RR scheduling
#include<iostream>
using namespace std;

// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n,
			int bt[], int wt[], int quantum)
{
	// Make a copy of burst times bt[] to store remaining
	// burst times.
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];

	int t = 0; // Current time

	// Keep traversing processes in round robin manner
	// until all of them are not done.
	while (1)
	{
		bool done = true;

		// Traverse all processes one by one repeatedly
		for (int i = 0 ; i < n; i++)
		{
			// If burst time of a process is greater than 0
			// then only need to process further
			if (rem_bt[i] > 0)
			{
				done = false; // There is a pending process

				if (rem_bt[i] > quantum)
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum;

					// Decrease the burst_time of current process
					// by quantum
					rem_bt[i] -= quantum;
				}

				// If burst time is smaller than or equal to
				// quantum. Last cycle for this process
				else
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_bt[i];

					// Waiting time is current time minus time
					// used by this process
					wt[i] = t - bt[i];

					// As the process gets fully executed
					// make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}

		// If all processes are done
		if (done == true)
		break;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[],
									int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	// Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt, quantum);

	// Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	// Display processes along with all details
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	// process id's
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	// Burst time of all processes
	int burst_time[] = {10, 5, 8};

	// Time quantum
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}
