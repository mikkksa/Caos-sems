Теперь перед нами CISC система с перемнной длинной команд. Допускаются
операции всех видов, кроме память-память.

Будем использовать AT&T синтаксис: все вычисления проводятся слева-направо
и результат кладется в последний аргумент.

Полезный плагин для отладки через gdb: [peda](https://github.com/longld/peda).
Установка:
```
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit
echo "set disassembly-flavor att" >> ~/.gdbinit
echo "DONE! debug your program with gdb and enjoy"
```

Calling convention для x86 ассемблера:

![Calling convention](calling_conv_x86.jpeg)
