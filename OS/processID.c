#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid; //declare a variable of type pid_t to store the PId
	pid = getpid();
	
	printf("This process Id (PID) of this program is : %d\n",pid);
	
	return 0;
}