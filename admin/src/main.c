#include <stdio.h>
#include "login.h"

int main() {
    if (autenticarAdmin()) {
 	printf("Bem-vindo ao sistema administrador!\n");
    }
    return 0;
}
