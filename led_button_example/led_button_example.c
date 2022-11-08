#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    char buff[2];
    char tmp1, tmp2;
    char prev = 'r';

	int dev = open("/dev/mygpio", O_RDWR);
	if(dev == -1) {
		printf("Opening was not possible!\n");
		return -1;
	}
	printf("Opening was successfull!\n");

    while(1) {
        read(dev, &buff, 2);
        tmp1 = buff[0];
        tmp2 = buff[1];
        prev = tmp;
        tmp = buff;
        write(dev, &tmp, 1);
        if (prev != tmp)
            printf("led is %c\n", tmp);
    }

	close(dev);
	return 0;
}