#include<time.h>
#include<string>
#include<iostream>
#include <signal.h>


typedef struct sigevent Sigevent;
typedef struct itimerspec Itimerspec;
typedef struct sigaction Sigaction;

class Timer{
private:
    time_t timep; //get the time stamp of system

public:
    /* Get the current time and put it in *TIMER if TIMER is not NULL.  */
    void setTime(void);

    /* Return a string which shows the time in your location in the format of "Sat Oct 28 02:10:06 2000"*/
    std::string getTimeStringFormet(void);


};

//deal with the periodically tasks
//void timerHandler(int sig,siginfo_t *si, void *uc);

//initial a timer
int makeTimer(timer_t *timerID, int expireMS, int intervalMS);
