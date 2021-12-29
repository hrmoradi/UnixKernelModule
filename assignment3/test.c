#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <err.h> 
#include <fcntl.h> 
#include <sysexits.h> 
#include <sys/types.h>  
#include <sys/stat.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/mman.h>
#pragma OPTIMIZATION OFF
    //info and times about a single process
    struct proc_time {
        pid_t pid; // pid of the process
        char name [16]; // file name of the program executed
        unsigned long start_time ; // start time
        unsigned long real_time ; // real time
        unsigned long user_time ; // user time
        unsigned long sys_time ; // system time
        } ;
    struct proctimes {
        struct proc_time proc ; // process with pid or current process
        struct proc_time parent_proc ; // parent process
        struct proc_time oldest_child_proc ; // oldest child process
        } ;

int main()
{
    pid_t pid;
    pid=getpid();
    struct proctimes argPass2syscall;

	unsigned long int bfsleep; 
	unsigned long int afsleep;

    printf("Invoking 'listProcessInfo' system call ->before sleep\n");
    long int ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
	 printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }
	bfsleep = argPass2syscall.proc.real_time;

	usleep(5000000);


    printf("Invoking 'listProcessInfo' system call ->after sleep\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
         printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }

	afsleep= argPass2syscall.proc.real_time;
	unsigned long int result= afsleep-bfsleep;
	printf("\nthe diff. before and after 5 sec sleep is: %lu  microsecond\n\n",result);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Invoking 'listProcessInfo' system call -> before 1 million calculation\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
	 printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }
	bfsleep = argPass2syscall.proc.real_time;

	unsigned long int i=0 ;
	long double a =1.1;
	long double b =1.0;
	
	for(i=0;i<=1000000;i++){
		a=a*a;
		
	}
	

    printf("Invoking 'listProcessInfo' system call -> after 1 million calculation\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
         printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }

	afsleep= argPass2syscall.proc.real_time;
	result= afsleep-bfsleep;
	printf("\nit toook: %lu microsecond for floating point calculation \n\n",result);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Invoking 'listProcessInfo' system call -> before 1 million calculation\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
	 printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }
	bfsleep = argPass2syscall.proc.real_time;

	i=0;
	unsigned long int c =2;
	unsigned long int d =1;
	
	for(i=0;i<=1000000;i++){
		c=c*c;
	}


    printf("Invoking 'listProcessInfo' system call -> after 1 million calculation\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
         printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }

	afsleep= argPass2syscall.proc.real_time;
	result= afsleep-bfsleep;
	printf("\nit toook: %lu microsecond for integer calculatio \n\n",result);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Invoking 'listProcessInfo' system call -> before fork\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
	 printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }
	bfsleep = argPass2syscall.proc.real_time;


	
	int pid2 = fork();
	c=c+1;
	kill(pid2, SIGKILL);

    printf("Invoking 'listProcessInfo' system call -> after after fork\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
         printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }

	afsleep= argPass2syscall.proc.real_time;
	result= afsleep-bfsleep;
	printf("\nsimple fork took: %lu microsecond  \n\n",result);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        size_t size =1024*1024*1024;
        int fd = open("/dev/zero", O_RDWR); 
        char* p = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0); 
        char * data2write= "h";
        for(i=0; i<size;i++){
        memcpy(p+i,&data2write,1);
        }
        close(fd);      



    printf("Invoking 'listProcessInfo' system call -> before fork\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
	 printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }
	bfsleep = argPass2syscall.proc.real_time;




	pid2 =fork();
	c=c+1;
        kill(pid2, SIGKILL);


    printf("Invoking 'listProcessInfo' system call -> after after fork\n");
    ret_status = syscall(333,pid,&argPass2syscall); // 333 is the syscall number
    if(ret_status == 0){
         printf("System call 'listProcessInfo' executed correctly. Use dmesg to check processInfo\n");
         printf("results are: %s,%d , %lu ,%lu ,%lu ,%lu \n",argPass2syscall.proc.name,argPass2syscall.proc.pid,argPass2syscall.proc.start_time,argPass2syscall.proc.real_time,argPass2syscall.proc.user_time,argPass2syscall.proc.sys_time);
    }else{
         printf("System call 'listProcessInfo' did not execute as expected\n");
    }

	afsleep= argPass2syscall.proc.real_time;
	result= afsleep-bfsleep;
	printf("\nfork with 1GB took: %lu microsecond\n\n",result);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    return 0;
}
//sudo dmsg
