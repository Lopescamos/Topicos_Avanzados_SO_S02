#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    int m1 = getfreemem();
    printf("Memoria libre inicial: %d bytes\n", m1);
    char *ptr = sbrk(4096 * 10); // Solicitar 10 paginas
    (void)ptr;
    int m2 = getfreemem();
    printf("Memoria libre tras sbrk(10 paginas): %d bytes\n", m2);
    printf("Diferencia de memoria: %d bytes\n", m1 - m2);
    sbrk(-4096 * 10); // Liberar 10 paginas
    printf("Memoria libre tras liberar: %d bytes\n", getfreemem());
    exit(0);
}