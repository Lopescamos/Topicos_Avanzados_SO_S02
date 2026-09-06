#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  char *base = sbrk(4096 * 3); // 3 paginas
  unsigned int mask = 0;

  // Acceder solo a la pagina 0 y 2
  base[0] = 'A';
  base[2 * 4096] = 'B';

  if(pgaccess(base, 3, &mask) < 0){
    printf("pgaccess fallo\n");
    exit(1);
  }

  printf("Mascara de acceso: 0x%x\n", mask);
  // Se espera: bit 0 y bit 2 en 1 -> 0x5

  // Segunda llamada: no deberian aparecer accesos nuevos
  if(pgaccess(base, 3, &mask) < 0){
    printf("pgaccess fallo\n");
    exit(1);
  }
  printf("Mascara tras limpiar: 0x%x\n", mask);
  // Se espera: 0x0

  exit(0);
}