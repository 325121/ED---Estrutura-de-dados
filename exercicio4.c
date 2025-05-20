#include <stdio.h>

void abrir_megasena(const char* nome) {
    // Usa int em vez de char, e inicializa corretamente todos com 0
    int contadores[60] = {0};

    FILE* arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO\n");
        return;
    }

    int numero;
    // Lê todos os números do arquivo
    while (fscanf(arquivo, "%d", &numero) == 1) {
        if (numero >= 1 && numero <= 60) {
            contadores[numero - 1]++;
        }
    }

    fclose(arquivo);  

   
    for (int i = 0; i < 60; i++) {
        if (contadores[i] > 0) {
            printf("Número %d apareceu %d vezes\n", i + 1, contadores[i]);
        }
    }
}

int main() {
    const char* arquivo = "megasena.txt";
    abrir_megasena(arquivo);
    return 0;
}

