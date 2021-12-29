#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include "processInfo.h"
#include<linux/syscalls.h>
#include <linux/time.h>

    //info and times about a single process
//    struct proc_time {
//        pid_t pid; // pid of the process
//        char* name;// [16]; // file name of the program executed
//        unsigned long start_time ; // start time
//        unsigned long real_time ; // real time
//        unsigned long user_time ; // user time
//        unsigned long sys_time ; // system time
//        } ;
//    struct proctimes {
 //       struct proc_time proc ; // process with pid or current process
   //     struct proc_time parent_proc ; // parent process
     //   struct proc_time oldest_child_proc ; // oldest child process
       // } ;


asmlinkage long sys_getproctimes(pid_t pid, struct proctimes *time){

    struct task_struct *proces;

    struct timeval curr_tm;

    if (pid==0){
	 pid= current->pid;
    }

    for_each_process(proces) {
     if (proces->pid==pid) {

       time->proc.pid = proces->pid;
	// no & *** stack smashing detected ***: 
       strncpy(time->proc.name,proces->comm,16);
       //int i =0;
       //for(i=0;proces->comm[i]!='\0';i++){
	//   time->proc.name[i]=proces->comm[i];
       //}
	//time->proc.name[i]='\0';
       //time->proc.name=proces->comm
       time->proc.start_time =(unsigned long) proces->start_time; //u64
       do_gettimeofday(&curr_tm);
       time->proc.real_time = curr_tm.tv_sec * 1000000 + curr_tm.tv_usec;
       time->proc.user_time = proces->utime;
       time->proc.sys_time = proces->stime;

       printk("getptoctime **BY HAMIDREZA MORADI** ");//Process: %s\n 
//          PID_Number: %ld\n \
//          Process State: %ld\n \
//          Priority: %ld\n \
//          RT_Priority: %ld\n \
//          Static Priority: %ld\n \
//          Normal Priority: %ld\n", \
//          proces->comm, \
//          (long)task_pid_nr(proces), \
//          (long)proces->state, \
//          (long)proces->prio, \
//          (long)proces->rt_priority, \
//          (long)proces->static_prio, \
//          (long)proces->normal_prio \
//    	);

	if(list_last_entry(&(proces->children), struct task_struct, sibling)){//oldest_child_proc
	// how to identify  pointer
	struct task_struct *point;
	point = list_first_entry(&(proces->children), struct task_struct,sibling);
	//	while(point->next != NULL){
	//		point=point->next;
	//	}
	       time->oldest_child_proc.pid = point->pid;
	       strncpy(time->oldest_child_proc.name,point->comm,16);
	       // for(i=0;proces->comm[i]!='\0';i++){
	       //    time->oldest_child_proc.name[i]=proces->comm[i];
	       //}
	       //time->oldest_child_proc.name[i]='\0';
		//time->oldest_child_proc.name=point->comm
	       time->oldest_child_proc.start_time =(unsigned long) point->start_time; //u64
               do_gettimeofday(&curr_tm);
	       time->oldest_child_proc.real_time = curr_tm.tv_sec * 1000000 + curr_tm.tv_usec;
	       time->oldest_child_proc.user_time = point->utime;
	       time->oldest_child_proc.sys_time = point->stime;

	};
        if(proces->parent){//parent_proc
	       time->parent_proc.pid = proces->parent->pid;
	       strncpy(time->parent_proc.name,proces->parent->comm,16);
		//for(i=0;proces->comm[i]!='\0';i++){
	          // time->parent_proc.name[i]=proces->comm[i];
       		//}
      		 //time->parent_proc.name[i]='\0';
		//time->parent_proc.name=proces->parent->comm
	       time->parent_proc.start_time =(unsigned long) proces->parent->start_time; //u64
               do_gettimeofday(&curr_tm);
	       time->parent_proc.real_time = curr_tm.tv_sec * 1000000 + curr_tm.tv_usec;
	       time->parent_proc.user_time = proces->parent->utime;
	       time->parent_proc.sys_time = proces->parent->stime;

//         printk(
//	        "Parent process: %s, \
//  	     	 PID_Number: %ld", \
//	         proces->parent->comm, \
//        	 (long)task_pid_nr(proces->parent) \
//          );
	};
       printk("\n\n");
	return 0;
   }// if
  } //for each
  return -1;
}
