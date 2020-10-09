all:
	/usr/local/bin/arm-gcc/bin/arm-linux-gnueabi-gcc -marm quad.S quad.c -o quad
	qemu-arm -L /usr/local/bin/arm-sysroot/ ./quad
