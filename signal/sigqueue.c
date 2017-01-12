#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/* 
sigqueue函数  向自身进程发送一个SIUSR1信号.并且带上附加信息(一个字符串数据)

 */


void 
sigHandler(int isigno,siginfo_t* info,void* context)
{
	char* pMsg = (char*)info->si_value.sival_ptr;
	printf("Receive signal number:%d\n",isigno);
	printf("Receive Message %s\n",pMsg);
}

int
main()
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction =  sigHandler;
	
	if(sigaction(SIGUSR1,&act,NULL) == -1)
	{
		printf("sigaction failure\n");
		exit(1);
	}

	
	sigval_t val;
	char pMsg[] = "T ki";
	val.sival_ptr = pMsg;
	if( sigqueue(getpid(),SIGUSR1,val) == -1 )
	{
		printf("sigqueue failed\n");
		exit(1);
	}

	sleep(3);
	return 0;
}




// typedef union sigval{
 //   int sival_int;
//    void* sival_ptr;//指向要传递的信号参数
//}sigval_t;



//  siginfo_t {
  //             int      si_signo;    /* Signal number */
   //           int      si_errno;    /* An errno value */
   //            int      si_code;     /* Signal code */
    //           int      si_trapno;   /* Trap number that caused
    //                                    hardware-generated signal
       //                                 (unused on most architectures) */
     //          pid_t    si_pid;      /* Sending process ID */
    //           uid_t    si_uid;      /* Real user ID of sending process */
//               int      si_status;   /* Exit value or signal */
   //            clock_t  si_utime;    /* User time consumed */
  //             clock_t  si_stime;    /* System time consumed */
   //            sigval_t si_value;    /* Signal value */
 //              int      si_int;      /* POSIX.1b signal */
  //             void    *si_ptr;      /* POSIX.1b signal */
     //          int      si_overrun;  /* Timer overrun count; POSIX.1b timers */
    //           int      si_timerid;  /* Timer ID; POSIX.1b timers */
 //              void    *si_addr;     /* Memory location which caused fault */
   //            long     si_band;     /* Band event (was int in
     //                                   glibc 2.3.2 and earlier) */
      //         int      si_fd;       /* File descriptor */
    //           short    si_addr_lsb; /* Least significant bit of address
     //                                   (since Linux 2.6.32) */
     //      }
