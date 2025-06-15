#include <stdio.h>

int a;
int b;
float promedio;
char* mensaje;
void imprimirSaludo(char* texto) {
printf("%d\n", texto);
}

int sumarYMostrar(int x, int y) {
int suma;
suma = (x + y);
printf("%d\n", suma);
return suma;
}

int main() {
scanf("%d", &a);
scanf("%d", &b);
mensaje = "Inicio de pruebas";
printf("%s\n", mensaje);
promedio = ((a + b) / 2);
if ((a < b)) {
printf("%s\n", "a es menor que b");
printf("%s\n", "a es mayor o igual que b");

} else {
printf("%s\n", "a es mayor o igual que b");

}sumarYMostrar(a, b);
while ((a < b)) {
printf("%d\n", a);
a = (a + 1);

}
printf("%f\n", promedio);

 return 0;
}
