#include <stdio.h>
#define DIAMANTE int
#define LAVA float
#define LIBRO char*
#define ENDER if
#define CREEPER else
#define ZOMBIE while
#define LETRERO printf
#define HORNO scanf
#define PORTAL
#define TESORO return

DIAMANTE x;
DIAMANTE y;
DIAMANTE resultado;
int main() {
HORNO("%d", &x);
HORNO("%d", &y);
resultado = (x + y);
LETRERO("%s\n", "La suma es:");
LETRERO("%d\n", resultado);

 return 0;
}
