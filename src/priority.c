#include <stdio.h>

struct Processo {
    int id;
    int burst;
    int prioridade;
    int tempo_espera;
    int turnaround;
};

int main() {
    int n;

    printf("Quantidade de processos: ");
    scanf("%d", &n);

    struct Processo p[n];

    // Entrada dos processos
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcesso %d\n", p[i].id);
        printf("Tempo de execucao (burst time): ");
        scanf("%d", &p[i].burst);

        printf("Prioridade (quanto menor, maior prioridade): ");
        scanf("%d", &p[i].prioridade);
    }

    // Ordenação por prioridade
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[j].prioridade < p[i].prioridade) {
                struct Processo temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


