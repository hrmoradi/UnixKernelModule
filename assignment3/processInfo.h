    //info and times about a single process
    struct proc_time {
        pid_t pid; // pid of the process
        char name[16]; // file name of the program executed
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


asmlinkage long sys_getproctimes(pid_t pid, struct proctimes *time);
