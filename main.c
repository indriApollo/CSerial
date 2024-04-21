#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "serial_port.h"

int main(void) {
    printf("Open port\n");
    const int fd = open_port_blocking_io("/dev/ttyACM0");

    // try to release the port's exclusivity in case we were killed before a proper close before
    //set_port_access_nonexclusive(fd);

    printf("Set port access to exclusive\n");
    if (set_port_access_exlusive(fd) != 0)
    {
        printf("Error %i from set_port_access_exlusive: %s\n", errno, strerror(errno));
        close(fd);
        return 1;
    }

    printf("Configure port\n");
    if(configure_port(fd, 10, 0, B115200) != 0) {
        printf("Error %i from configure_port: %s\n", errno, strerror(errno));
        close(fd);
        return 2;
    }

    printf("Port is ready :)\n");

    // Connect to a USBTin and get version
    const char msg[] = "v\r";
    write(fd, msg, sizeof(msg) - 1 /* dont send string termination \0 */);

    char read_buf[256] = {0};

    // Read bytes. The behaviour of read() (e.g. does it block?,
    // how long does it block for?) depends on the configuration
    // settings above, specifically VMIN and VTIME
    const int num_bytes = read(fd, &read_buf, sizeof(read_buf));

    // n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.
    if (num_bytes < 0) {
        printf("Error reading: %s\n", strerror(errno));
        close(fd);
        return 3;
    }

    printf("Read %i bytes\n", num_bytes);
    for (int i = 0; i < sizeof(read_buf); i++) {
        const char c = read_buf[i];
        if (c == '\r') {
            printf("[CR]");
            break;
        }
        printf("%c", c);
    }
    printf("\n");

    printf("Release exlusive port access\n");
    set_port_access_nonexclusive(fd);
    printf("Close port\n");
    close(fd);

    return 0;
}
