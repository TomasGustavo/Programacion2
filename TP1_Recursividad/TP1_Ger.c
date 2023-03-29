#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mafia(int N) {
  char* result;
  if (N == 1) {
    result = "(-.-)";
  } else if (N > 1) {
    char* subResult = mafia(N - 1);
    int length = strlen(subResult);
    result = (char*)malloc((length + 2) * sizeof(char));
    sprintf(result, "(-.%s.-)", subResult);
   
  }
  return result;
}

int main() {
  int n;
  printf("Ingrese el nivel de la reunion: ");
  scanf("%d", &n);
  char* apariencia = mafia(n);
  printf("Apariencia de la delegacion: %s\n", apariencia);
  free(apariencia);
  return 0;
}