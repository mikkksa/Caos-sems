all:
	/usr/local/bin/arm-gcc/bin/arm-linux-gnueabi-gcc -marm calc.S calc.c -o calc
start:
	qemu-arm -L /usr/local/bin/arm-sysroot/ ./calc
