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

    // Ordenação por prioridade (menor prioridade primeiro)
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[j].prioridade < p[i].prioridade) {
                struct Processo temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Cálculo dos tempos
    p[0].tempo_espera = 0;
    p[0].turnaround = p[0].burst;

    for(int i = 1; i < n; i++) {
        p[i].tempo_espera = p[i-1].tempo_espera + p[i-1].burst;
        p[i].turnaround = p[i].tempo_espera + p[i].burst;
    }

    // Exibição dos resultados
    printf("\n\n----- RESULTADOS (Priority Scheduling) -----\n");
    printf("ID\tBurst\tPrioridade\tEspera\tTurnaround\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n",
            p[i].id, p[i].burst, p[i].prioridade,
            p[i].tempo_espera, p[i].turnaround
        );
    }

    // Médias
    float mediaEspera = 0, mediaTurn = 0;
    for(int i = 0; i < n; i++) {
        mediaEspera += p[i].tempo_espera;
        mediaTurn += p[i].turnaround;
    }

    mediaEspera /= n;
    mediaTurn /= n;

    printf("\nTempo medio de espera: %.2f", mediaEspera);
    printf("\nTempo medio de retorno: %.2f\n", mediaTurn);

    return 0;
}
