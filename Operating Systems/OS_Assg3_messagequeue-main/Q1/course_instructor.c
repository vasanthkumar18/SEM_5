// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#define MAX 10 

// structure for message queue 
struct mesg_buffer { 
	long mesg_type; 
	int marks;
} message[5]; 

struct rr { 
	long mesg_type; 
	int average;
	char grades[5];
} result;
int main() 
{ 
	key_t key; 
	int i,msgid,msgid2; 

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 
	
	for(i=0;i<5;i++)
	{
           message[i].mesg_type = i+1;
           printf("Enter the marks of student no. %d: ",i+1);
           scanf("%d",&message[i].marks);       
        //   printf("\n"); 
           } 

	 

	// msgsnd to send message 
	msgsnd(msgid, message, sizeof(message[0])*5, 0); 

	msgid2 = msgget(317, 0666 | IPC_CREAT); 
       msgsnd(msgid2, message, sizeof(message[0])*5, 0); 
        msgrcv(msgid2, &result, sizeof(result), 6, 0);
        printf("\n\nThe average of all the students is %d\n",result.average);
       
        for(i=0;i<5;i++)
	{
           printf("The grade of student no. %d is: %c\n",i+1,result.grades[i]);
           
           } 

        msgctl(msgid2, IPC_RMID, NULL); 
	return 0; 
} 

