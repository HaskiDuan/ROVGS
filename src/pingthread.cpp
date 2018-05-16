#include "src/pingthread.h"
PingThread::PingThread(void){

}

PingThread::~PingThread(void){
    std::cout << "destructing the PingThread class object and free the memory" << std::endl;
}

void PingThread::startSystem(){
    keepRunning = true;
    start();
}

void PingThread::stopSystem(){
    keepRunning = false;
    join();
}

double parsePingResults(std::string s){
    //20008 bytes from localhost (127.0.0.1): icmp_req=1 ttl=64 time=0.075ms
    size_t pos = s.find("time=");
    int found = 0;
    float ms;
    if(pos != std::string::npos)  //npos is the end point of string
        //get the network ping time
        found = sscanf(s.substr(pos).c_str(),"time=%f",&ms); //c_str() return the standard c point, use this to make C library compatible

    if(1 == found && pos != std::string::npos)
        return ms;
    else
        return 10000;
}

void PingThread::run(){
    std::cout << "Starting the network conrtol thread: ping thread." << std::endl;

    //20000 bytes and 500 bytes
    sprintf(pingCommand20000,"ping -c 1 -s 20000 -w 1 192.168.0.102");
    sprintf(pingCommand500,"ping -c 1 -s 500 -w 1 192.168.0.102");
    FILE *p;

    measure = true;

    while(keepRunning){
        if(measure){
            p = popen(pingCommand500,"r");  //popen start a progress by creating a pipeline, and call the shell to excute ping command
            char* temp;
            temp = fgets(line1,200,p);
            temp = fgets(line1,200,p);
            if(temp == NULL){
#ifdef QT_DEBUG
                printf("set command error!\n");
#endif
            }
            pclose(p);

            //sleep 1s
            sleep(1000);
            if(!keepRunning) break;
            sleep(1000);
            if(!keepRunning) break;

            p = popen(pingCommand500,"r");
            temp = fgets(line2,200,p);
            temp = fgets(line2,200,p);
            if(temp == NULL){
#ifdef QT_DEBUG
                printf("set command error!\n");
#endif
            }
            pclose(p);


            double res500 = parsePingResults(line1);
            double res20000 = parsePingResults(line2);
#ifdef QT_DEBUG
            std::cout << "new ping values: 500 ->" << res500 << " 20000 ->" << res20000 << std::endl;
#endif
            //clip between 10 and 1000.
            res500 = std::min(1000.0,std::max(10.0,res500));
            res20000 = std::min(1000.0,std::max(10.0,res20000));

            //update
            p500 = 0.7 * p500 + 0.3 * res500;
            p20000 = 0.7 * p20000 + 0.3 * res20000;

            //send
            //snpringf(line1,200,"pings %d %d", (int)p500,(int)p20000);
            //if(robotThread != NULL)
            if(gui != NULL) gui->setPings((int)p500,(int)p20000);



            sleep(1000);
            if(!keepRunning) break;
            sleep(1000);
            if(!keepRunning) break;


        }
    }

    std::cout << "Exiting Ping thread" << std::endl;
}
