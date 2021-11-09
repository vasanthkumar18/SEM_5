// C Program for Message Queue (Reader Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message queue 
struct mesg_buffer { 
	long mesg_type; 
	int marks;
} student[5]; 

int main() 
{ 
	key_t key; 
	int msgid,i; 

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 

	msgrcv(msgid, student, 5*sizeof(student[0]), 0, 0); 
	
	for(i =0; i<5; i++)
	{
	  
         printf("The marks of the student no. %d is %d\n",i+1,student[i].marks);
        }
        
        
        
	// to destroy the message queue 
	msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 

