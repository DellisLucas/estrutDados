#include <stdio.h>
#include <stdlib.h>

typedef struct Voo {
    int numeroVoo;
    int dataVoo;
    int hora, minuto;
    int aeroportoSaida, aeroportoChegada;
    int rota;
    float tempoEstimado;
    int passageiros;
    struct Voo *prox;
} Voo;

Voo *inicio = NULL;

// Funções
void cadastrarVoo();
void consultaVoo();
void removeVoo();
void listarVoos();

int main() {
    int opcao;

    do {
        printf("\n1 - Cadastrar Voo\n2 - Consultar Voo\n3 - Remover Voo\n4 - Listar Voos\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarVoo(); break;
            case 2: consultaVoo(); break;
            case 3: removeVoo(); break;
            case 4: listarVoos(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarVoo() {
    Voo *novo = (Voo *)malloc(sizeof(Voo));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    printf("Número do Voo: ");
    scanf("%d", &novo->numeroVoo);
    printf("Data do Voo (1-8): ");
    scanf("%d", &novo->dataVoo);
    printf("Horário (hora e minuto): ");
    scanf("%d %d", &novo->hora, &novo->minuto);
    printf("Aeroporto de Saída (ID): ");
    scanf("%d", &novo->aeroportoSaida);
    printf("Aeroporto de Chegada (ID): ");
    scanf("%d", &novo->aeroportoChegada);
    printf("Rota (ID): ");
    scanf("%d", &novo->rota);
    printf("Tempo estimado (horas): ");
    scanf("%f", &novo->tempoEstimado);
    printf("Passageiros a bordo: ");
    scanf("%d", &novo->passageiros);

    novo->prox = inicio;
    inicio = novo;
    printf("Voo cadastrado com sucesso!\n");
}

void consultaVoo() {
    int numero;
    printf("Digite o número do voo para consulta: ");
    scanf("%d", &numero);

    Voo *atual = inicio;
    while (atual) {
        if (atual->numeroVoo == numero) {
            printf("Número: %d\nData: %d\nHorário: %02d:%02d\nSaída: %d\nChegada: %d\nRota: %d\nTempo: %.2f\nPassageiros: %d\n",
                   atual->numeroVoo, atual->dataVoo, atual->hora, atual->minuto,
                   atual->aeroportoSaida, atual->aeroportoChegada, atual->rota,
                   atual->tempoEstimado, atual->passageiros);
            return;
        }
        atual = atual->prox;
    }
    printf("Voo não encontrado!\n");
}

void removeVoo() {
    int numero;
    printf("Digite o número do voo para remover: ");
    scanf("%d", &numero);

    Voo *atual = inicio, *anterior = NULL;
    while (atual) {
        if (atual->numeroVoo == numero) {
            if (anterior) {
                anterior->prox = atual->prox;
            } else {
                inicio = atual->prox;
            }
            free(atual);
            printf("Voo removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Voo não encontrado!\n");
}

void listarVoos() {
    Voo *atual = inicio;
    if (!atual) {
        printf("Nenhum voo cadastrado.\n");
        return;
    }
    while (atual) {
        printf("Número: %d, Data: %d, Horário: %02d:%02d, Passageiros: %d\n",
               atual->numeroVoo, atual->dataVoo, atual->hora, atual->minuto, atual->passageiros);
        atual = atual->prox;
    }
}
