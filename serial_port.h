//
// Created by rleroux on 4/21/24.
//

#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H
#include <termios.h>

int open_port_blocking_io(const char *file);

int close_port(int fd);

int set_port_access_exlusive(int fd);

int set_port_access_nonexclusive(int fd);

int configure_port(int fd, cc_t vtime, cc_t vmin, speed_t speed);

#endif //SERIAL_PORT_H
