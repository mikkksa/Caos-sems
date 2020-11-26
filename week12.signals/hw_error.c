// From https://stackoverflow.com/questions/14233464/can-a-c-program-continue-execution-after-a-signal-is-handled

#define _GNU_SOURCE /* Bring REG_XXX names from /usr/include/sys/ucontext.h */

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <ucontext.h>

static void sigaction_segv(int signal, siginfo_t *si, void *arg)
{
    ucontext_t *ctx = (ucontext_t *)arg;

    /* We are on linux x86, the returning IP is stored in RIP (64bit) or EIP (32bit).
       In this example, the length of the offending instruction is 6 bytes.
       So we skip the offender ! */
    #if __WORDSIZE == 64
        printf("Caught SIGSEGV, addr %p, RIP 0x%lx\n", si->si_addr, ctx->uc_mcontext.gregs[REG_RIP]);
        ctx->uc_mcontext.gregs[REG_RIP] += 6;
    #else
        printf("Caught SIGSEGV, addr %p, EIP 0x%x\n", si->si_addr, ctx->uc_mcontext.gregs[REG_EIP]);
        ctx->uc_mcontext.gregs[REG_EIP] += 6;
    #endif
}

int main(void)
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = sigaction_segv;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    /* Generate a seg fault */
    *(int *)NULL = 0;

    printf("Back to normal execution.\n");

    return 0;
}
