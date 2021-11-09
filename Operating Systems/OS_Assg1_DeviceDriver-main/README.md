# PROBLEM STATEMENT

Create a simple device driver (character device) for the current compiled kernel and test
it with your sample application.









# EXECUTION OF CHARACTER DEVICE DRIVER

1) ebbchar.c 

This C file contains the code of a CHARACTER DEVICE DRIVER.

Character device drivers normally perform I/O in a byte stream. Examples of devices using character drivers include tape 
drives and serial ports. Character device drivers can also provide additional interfaces not present in block drivers, 
such as I/O control (ioctl) commands, memory mapping, and device polling.

2) testebbchar.c

This C file contains the code for verification of the driver whether it is running or not and also for checking the functionality of the driver.


# MAKEFILE 

1) Makefile

This is the makefile for our character device driver. This is responsible for building objects, it is our present working 
directory. Our main objective is to make a kbuild makefile so our makefile code contain a single line command i.e 

obj-m += ebbchar.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	$(CC) testebbchar.c -o test
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm test

This tells there is a object in the directory named ebbchar.o and obj-m tells that this object should be built as a 
module.

# COMMANDS THAT ARE FOLLOWED 

--> Makesure that the terminal is in the correct directory where the source code and makefile are present.

--> To compile the modules of driver run
	command:make

--> To insert our compiled module to the kernel run
	command: sudo insmod ebbchar.ko

--> To verify wheteher module inserted or not run
	command: lsmod |grep ebb
         

--> To show list of character devices and block devices run
	command: cat /proc/devices

--> To make the device accessible run
	command: sudo mknod -m 666 /dev/ebbchar c 240 0 
         
  
--> To verify whether ebbchar is available for the given node run
	command: ls -l /dev/ebbchar
         
--> To show the system log console run 
	command: dmesg
         

--> Now in the terminal compile the test.c file using
	command: cc testbbchar.c -o testebbchar

--> Now run 
         command: sudo ./test
