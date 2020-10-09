## Подготовка
Первым делом, вам необходимо поставить пакет qemu-user. Найдите в интернете
способ, как его поставить на вашу систему. Для debian ветки:
```
sudo apt install qemu-user
```

## Компиляция:
```
/usr/local/bin/arm-gcc/bin/arm-linux-gnueabi-gcc -marm prog_name.S -o prog_name
```

## Запуск:
```
qemu-arm -L /usr/local/bin/arm-sysroot/ ./prog_name
```
