// C Program for Message Queue (Reader Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

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
	 
	int msgid,i; 

	
	msgid = msgget(317, 0666 | IPC_CREAT); 

	// msgrcv to receive message 
	msgrcv(msgid,message, sizeof(message[0])*5, 0, 0); 

       for(i=0;i<5;i++)
       {
      //  printf(" %d-%d\n",i+1, message[i].marks);
        result.average = result.average + message[i].marks;
        if(message[i].marks >= 40)
          { result.grades[i] = 'S'; }
          else if(message[i].marks >= 30)
          { result.grades[i] = 'A'; }
          else if(message[i].marks >= 20)
          { result.grades[i] = 'B'; }
          else
          {
            result.grades[i] = 'E';
          }
        }
        result.mesg_type = 6;
        result.average = result.average/5;
        msgsnd(msgid, &result, sizeof(result), 0);

	return 0; 
} 

