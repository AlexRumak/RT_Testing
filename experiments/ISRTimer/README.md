# POSIX Timer in Raspberry PI

We are on the following versions of LINUX: Linux 6.6.51+rpt-rpi-v8 (Debian 12.2.0-14). In our version of LINUX,
we can create a hardware-based timer using POSIX commands like `timer_create`, `timer_settime` - and act on the timer
using `sigaction` to setup a signal handler.

## How to create a timer without POSIX?



## References


## Appendix

### Get Debian Version

```bash
$ cat /proc/version
Linux version 6.6.51+rpt-rpi-v8 (serge@raspberrypi.com) (gcc-12 (Debian 12.2.0-14) 12.2.0, GNU ld (GNU Binutils for Debian) 2.40) #1 SMP PREEMPT Debian 1:6.6.51-1+rpt3 (2024-10-08)
```

