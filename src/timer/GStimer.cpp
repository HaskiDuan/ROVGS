#include"GStimer.h"

/* Return the current time and put it in *TIMER if TIMER is not NULL.  */
void Timer::setTime(){
    time(&timep);
}

std::string Timer::getTimeStringFormet(){
    time (&timep);
    return asctime(gmtime(&timep));
}

/*
int makeTimer(timer_t *timerID, int expireMS, int intervalMS){
    Sigevent te;
    Itimerspec its;
    Sigaction sa;
    int sigNo = SIGRTMIN;  //a minimal signal with no predefined meaning

    // Set up the signal handler
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = timerHandler;
    sigemptyset(&sa.sa_mask);
    if(sigaction(sigNo, &sa, NULL) == -1){
        perror("sigaction");
    }

    //set and enable the alarm
    te.sigev_notify = SIGEV_SIGNAL;
    te.sigev_signo = sigNo;

    te.sigev_value.sival_ptr = timerID;
    timer_create(CLOCK_REALTIME, &te, timerID);

    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = intervalMS * 1000000;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = expireMS * 1000000;
    timer_settime(*timerID, 0, &its, NULL);

    return 1;

}
*/





