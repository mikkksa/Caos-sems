wget http://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-linux-gnueabi/sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi.tar.xz
wget http://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-linux-gnueabi/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi.tar.xz

tar xf sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi.tar.xz
tar xf gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi.tar.xz

mv sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi /usr/local/bin/arm-sysroot
mv gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi /usr/local/bin/arm-gcc
