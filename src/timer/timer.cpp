#include"timer.h"

/* Return the current time and put it in *TIMER if TIMER is not NULL.  */
void Timer::setTime(){
    time(&timep);
}

std::string Timer::getTimeStringFormet(){
    time (&timep);
    return asctime(gmtime(&timep));
}




