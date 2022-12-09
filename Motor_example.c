#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define SERVO 13

int main(int argc, char **argv){
    short buff;
    
    int dev = open("/dev/myMotorDriver",O_RDONLY);
    if(dev == -1){
        printf("Opening SERVO Motor Deiver FAIL...!!!\n");
        return -1;
    }
    printf("Opening SERVO Motor Deiver...!!!\n");

    buff = 100;
    write(dev, &buff,2);

    buff = 150;
    write(dev, &buff,2);    

    buff = 200;
    write(dev, &buff,2); 

    close(dev);
    return 0;
}