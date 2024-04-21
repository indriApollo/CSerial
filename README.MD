# C Serial

A small sample to interact with a serial port on Linux.

The program will try to connect to a USBTin on port `/dev/ttyACM0`,  
send the `v[CR]` command and read the returned version string.

Expected output :
```
Open port
Set port access to exclusive
Configure port
Port is ready :)
Read 6 bytes
v0108[CR]
Release exlusive port access
Close port
```

https://linux.die.net/man/3/termios  
https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/  
https://github.com/dotnet/runtime/blob/cb978a59424d37958e5e10a1a417afd599c59a5d/src/native/libs/System.IO.Ports.Native/pal_termios.c  
https://stackoverflow.com/a/38318768  
https://stackoverflow.com/a/26006680  
https://stackoverflow.com/a/57155531
