
#include "systemMonitor.h"

SystemMonitor::SystemMonitor():jstimeout(2){     //timeout > 2 means that the joystick is not alive, we assume that
                                               //the groundstation is not connect with a joystick

}

SystemMonitor::~SystemMonitor(){
    std::cout << "Destruct the system monitor thread" << std::endl;
}

void SystemMonitor::startSystemMonitor(){
    keepRunning = true;
    start();
}

void SystemMonitor::stopSystemMonitor(){
    keepRunning = false;
    join();
}

int SystemMonitor::initSystemMonitor(){
    bzero(&snl, sizeof(struct sockaddr_nl));
    snl.nl_family = AF_NETLINK;
    snl.nl_pid = getpid();
    snl.nl_groups = 1;

    struct timeval tv_out;
    tv_out.tv_sec = 2;
    tv_out.tv_usec = 0;

    int s = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
    if (s == -1){
        perror("socket");
        return -1;
    }
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out));

    ret = bind(s, (struct sockaddr *)&snl, sizeof(struct sockaddr_nl));
    if (ret < 0)  {
        perror("bind");
        close(s);
        return -1;
    }

    return s;
}

void SystemMonitor::run(){
    std::cout << "Starting the system monitor thread" << std::endl;
    int r;

    r = libusb_init(NULL);          //init libusb
    if(r < 0)
        perror("init usb lib failed");

    while(keepRunning){

        checkJoystick();             //checkJoystick state

        sleep(500);

        jstimeout++;

    }
    libusb_exit(NULL);
    std::cout << "End the system monitor thread" << std::endl;
}

void SystemMonitor::checkJoystick(){
    libusb_device **devs;
    ssize_t cnt;

    cnt = libusb_get_device_list(NULL,&devs);       //list the current usb device
    if(cnt < 0) return;

    for(int i = 0; devs[i];++i){
        if(JoystickMonitor(devs[i],0) == true){     //joystick is alive
            jstimeout = 0;
            break;
        }
    }
    libusb_free_device_list(devs,1);

    if(jstimeout > 0){
        std::cout << "joystick lost" << std::endl;
        isJoystickAlive = false;
        gui_p->setJoystickState(false);

    }
    else{
        std::cout << "joystick alive" <<std::endl;
        isJoystickAlive = true;
        gui_p->setJoystickState(true);
    }

}

/*JoystickMonitor
*print the usb device information and find the information of logitech extrem pro 3D
*
*/
bool SystemMonitor::JoystickMonitor(libusb_device *dev, int level){
    struct libusb_device_descriptor desc;
    libusb_device_handle *handle = NULL;
    char description[256];
    unsigned char a_string[256];
    int ret;

    ret = libusb_get_device_descriptor(dev,&desc);
    if(ret < 0){
        fprintf(stderr,"failed to get device descriptor");
        return -1;
    }

    ret = libusb_open(dev,&handle);
    if(LIBUSB_SUCCESS == ret){
        /*get the device manufacturer information*/
        if(desc.iManufacturer){
            std::cout << "Get the manufacturer of the joystick " << std::endl;
            //get the manufacturer number of the USB device
            ret = libusb_get_string_descriptor_ascii(handle,desc.iManufacturer,a_string,sizeof(a_string));
            if(ret > 0)
                snprintf(description,sizeof(description),"%s - ", a_string);
            else
                snprintf(description,sizeof(description),"%04X - ", desc.idVendor);
        }
        else{
            std::cout << "no manufacturer information" << std::endl;
            snprintf(description,sizeof(description),"%04X - ", desc.idVendor);
        }

        /*get the device producer information*/
        if (desc.iProduct) {
            std::cout << "Get the productor of the joystick " << std::endl;
            ret = libusb_get_string_descriptor_ascii(handle, desc.iProduct, a_string, sizeof(a_string));
            if (ret > 0)
                    snprintf(description + strlen(description), sizeof(description) -
                    strlen(description), "%s", a_string);
            else
                    snprintf(description + strlen(description), sizeof(description) -
                    strlen(description), "%04X", desc.idProduct);
        }
        else{
            snprintf(description + strlen(description), sizeof(description) - strlen(description), "%04X", desc.idProduct);
            std::cout << "no productor information" << std::endl;
        }

    }
    else {
                    snprintf(description, sizeof(description), "%04X - %04X",
                            desc.idVendor, desc.idProduct);
            }

    //printf("%.*sDev (bus %d, device %d): %s\n", level * 2, "                    ",
        //libusb_get_bus_number(dev), libusb_get_device_address(dev), description);

    /*detect whether the logitech extreme 3D pro is alive or not, if the joystick is not alive, show the state on GUI*/
    if(strcmp(description,joystickDeviceID) == 0) //std::cout << "joystick is alive " << std::endl;
        isJoystickAlive = true;
    else
        isJoystickAlive = false;

    if(handle){
        libusb_close(handle);
    }

    return isJoystickAlive;


}

