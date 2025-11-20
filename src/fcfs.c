#include <stdio.h>

/*
    - Os processos são executados na ordem de chegada.
    - Não existe preempção.
    - Calcula: Tempo de Espera e Tempo de Turnaround.

    Estrutura:
    - Cada processo tem: ID, tempo de chegada, tempo de execução.
*/

typedef struct {
    int id;               // Identificação do processo (P1, P2, …)
    int chegada;          // Tempo de chegada
    int burst;            // Tempo de execução (CPU burst)
    int espera;           // Tempo de espera
    int turnaround;       // Tempo total (espera + execução)
} Processo;

int main() {
    int n;


    printf("== Escalonamento FCFS ==\n");
    printf("Informe a quantidade de processos: ");
    scanf("%d", &n);


    Processo p[n];


    // Entrada dos dados dos processos
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;


        printf("\nProcesso P%d\n", p[i].id);
        printf("Tempo de chegada: ");
        scanf("%d", &p[i].chegada);


        printf("Tempo de execucao (burst): ");
        scanf("%d", &p[i].burst);
    }



// Garantir ordem de chegada (caso o usuário informe fora de ordem)
    // FCFS usa ordenação crescente pelo tempo de chegada
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].chegada > p[j].chegada) {
                Processo temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


    int tempoAtual = 0;


}

