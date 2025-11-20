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

