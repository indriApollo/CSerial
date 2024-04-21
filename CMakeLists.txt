cmake_minimum_required(VERSION 3.28)
project(CSerial C)

set(CMAKE_C_STANDARD 17)

add_executable(CSerial main.c
        serial_port.c
        serial_port.h)
