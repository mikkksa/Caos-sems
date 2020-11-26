#include <unistd.h>
#include <sys/types.h>
#include <sched.h>

int main() {
    int fds_pair[2];
    pipe(fds_pair);
    
    if ( 0!=fork() )  // теперь у нас существует неявная копия файловых дескрипторов
    {
        // немного записываем в буфер
        static const char Hello[] = "Hello!";
        write(fds_pair[1], Hello, sizeof(Hello));
        //close(fds_pair[1]);
    
        // а теперь читаем обратно
        char buffer[1024];
        read(fds_pair[0], buffer, sizeof(buffer)); // получаем dead lock!
    }
    else while (1) sched_yield();
}
