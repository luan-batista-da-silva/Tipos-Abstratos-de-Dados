#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define SUCESSO 1
#define FALHA 0
#define TOPO 1
#define BASE 0

// =============================================================
// ================= ARQUIVO "pilhas.h" ========================
// =============================================================
typedef struct p Pilhas;
int create(Pilhas* P);
int isEmpty(Pilhas* P);
int push(Pilhas* P, long int x);
unsigned long int pop(Pilhas* P);
long int size(Pilhas* P);
int isEqual(Pilhas* P1, Pilhas* P2);
void show(Pilhas* P, int ordem);
int copy(Pilhas* P1, Pilhas* P2);
int destroyPilhas(Pilhas* P);

// =============================================================
// ================= ARQUIVO "pilhas.c" ========================
// =============================================================

struct p {
    long int* elements;
    long int size;
};

// +----------------------------------+
// | Cria uma Pilha Vazia             |
// +----------------------------------+
int create(Pilhas* P) {
    if (P != NULL) {
        P->elements = NULL;
        P->size = 0;
        return SUCESSO;
    }
    else {
        return FALHA;
    }
}

// +----------------------------------+
// | Cria uma Pilha Vazia             |
// +----------------------------------+
int isEmpty(Pilhas* P) {
    if (P == NULL || P->elements == NULL || P->size == 0) {
        return true;
    }
    else {
        return false;
    }
}

// +----------------------------------+
// | Destroi as Pilhas                |
// +----------------------------------+
int destroyPilhas(Pilhas* P) {
    if (P != NULL) {
        if (P->size > 0) {
            free(P->elements);
        }
        free(P);
        return SUCESSO;
    }
    else {
        return FALHA;
    }
}

// +----------------------------------+
// | Inserindo elemento na Pilha      |
// +----------------------------------+
int push(Pilhas* P, long int x) {
    int tamanho = P->size;

    if (tamanho == 0) {
        P->elements = (long int*)malloc(sizeof(long int));
        P->elements[0] = x;
        P->size++;

        return SUCESSO;
    }
    else {
        tamanho++;
        P->elements = (long int*)realloc(P->elements, tamanho * sizeof(long int));
        P->elements[tamanho - 1] = x;
        P->size++;

        return SUCESSO;
    }

    return FALHA;
}

// +----------------------------------+
// | Excluindo elemento na Pilha      |
// +----------------------------------+
unsigned long int pop(Pilhas* P) {
    int tamanho = P->size;
    int retorno = isEmpty(P);

    if (retorno == true) {
        puts("A pilha e vazia!");
        return FALHA;
    }
    else {
        P->elements[tamanho - 1] = NULL;
        tamanho--;
        P->elements = (long int*)realloc(P->elements, tamanho * sizeof(long int));
        P->size--;
        return SUCESSO;
    }

    return FALHA;
}

// +----------------------------------+
// | Cardinalidade da Pilha           |
// +----------------------------------+
long int size(Pilhas* P) {
    return P->size;
}

// +-------------------------------------+
// | Verificar se P1 e P2 são Idênticas  |
// +-------------------------------------+
int isEqual(Pilhas* P1, Pilhas* P2) {
    int iguais = 0;
    long int tamanho;

    if (P1->size == P2->size) {
        tamanho = P1->size;
        for (int i = 0; i < tamanho; i++) {
            if (P1->elements[i] == P2->elements[i]) {
                iguais++;
            }
        }

        if (iguais == tamanho) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


// +-------------------------------------+
// | Mostra a Pilhas em Certa Ordem      |
// +-------------------------------------+
void show(Pilhas* P, int ordem) {
    if (ordem == TOPO) {
        puts("TOPO");
        for (int i = P->size - 1; i >= 0; i--) {
            printf(" %ld\n", P->elements[i]);
        }
        puts("BASE\n");
    }
    else if (ordem == BASE) {
        puts("BASE");
        for (int i = 0; i < P->size; i++) {
            printf(" %ld\n", P->elements[i]);
        }
        puts("TOPO\n");
    }
}

// +-------------------------------------+
// | Copiar P1 para P2                   |
// +-------------------------------------+
int copy(Pilhas* P1, Pilhas* P2) {
    int retorno = -1;
    P2->elements = (long int*)realloc(P2->elements, P1->size * sizeof(long int));
    P2->size = P1->size;

    for (int i = 0; i < P2->size; i++) {
        P2->elements[i] = P1->elements[i];
    }

    retorno = isEqual(P1, P2);

    if (retorno == true) {
        return SUCESSO;
    }
    else {
        return FALHA;
    }
        

}

// =============================================================
// ================ ARQUIVO "pilhasMain.c" =====================
// =============================================================


int main() {
    Pilhas* P1 = (Pilhas*)malloc(sizeof(Pilhas));
    Pilhas* P2 = (Pilhas*)malloc(sizeof(Pilhas));
    long int x;
    long int tamanho = -1;
    int operacao = -1;
    int retorno = -1;
    int pilhas = 0;
    int optionPilhas = 1;
    int ordem;

    while (operacao != 0) {

        puts("+-----------------------------------------------------+");
        puts("| 0 - Finalizar o Programa                            |");
        puts("| 1 - Criar uma Pilha Vazia                           |");
        puts("| 2 - Verificar se a Pilha e Vazia                    |");
        puts("| 3 - Inserir um elemento a Pilha                     |");
        puts("| 4 - Excluir um elemento a Pilha                     |");
        puts("| 5 - Verificar a Cardinalidade da Pilha              |");
        puts("| 6 - Verificar se as Pilhas P1 e P2 sao Identicas    |");
        puts("| 7 - Mostrar a Pilha                                 |");
        puts("| 8 - Copia a Pilha P1 para P2                        |");
        puts("+-----------------------------------------------------+");
        
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 1:
            if (pilhas == 0) {
                retorno = create(P1);
                pilhas++;
            }
            else {
                retorno = create(P2);
                pilhas++;
            }

            if (retorno == SUCESSO) {
                printf("A pilha P%d foi criado!\n\n", pilhas);
            }
            else if (retorno == FALHA) {
                puts("[ERROR] Nao foi possível criar a pilha!\n");
            }
            break;

        case 2:
            if (pilhas == 0) {
                puts("[ERROR] Nao existem pilhas criadas!");
                puts("Por favor, crie as pilhas antes!");
            }
            if (pilhas == 1) {
                retorno = isEmpty(P1);
            }
            else {
                printf("Qual das pilhas deseja verificar se e vazia? (Digite 1 para P1 e 2 para P2) ");
                scanf("%d", &optionPilhas);

                if (optionPilhas == 1) {
                    retorno = isEmpty(P1);
                }
                else if (optionPilhas == 2) {
                    retorno = isEmpty(P2);
                }
                else {
                    puts("[ERROR] Essa pilha nao existe!");
                    puts("Por favor, digite o numero de uma pilha existente!");
                }
            }

            if (retorno == SUCESSO) {
                printf("A pilha P%d e vazia!\n\n", optionPilhas);
            }
            else if (retorno == FALHA) {
                printf("A pilha P%d nao e vazia!\n\n", optionPilhas);
            }    
            break;

        case 3:
            if (pilhas == 0) {
                puts("[ERROR] Nao ha pilhas criadas!");
                puts("Por favor, crie pilhas antes de adicionar elementos!");
            }
            else if (pilhas == 1) {
                printf("Digite o elemento a ser adicionado: ");
                scanf("%ld", &x);

                retorno = push(P1, x);
            }
            else {
                printf("Qual pilha deseja adicionar o elemento? (Digite 1 para P1 e 2 para P2) ");
                scanf("%d", &optionPilhas);

                if (optionPilhas == 1) {
                    printf("Digite o elemento a ser adicionado: ");
                    scanf("%ld", &x);

                    retorno = push(P1, x);
                }
                else if (optionPilhas == 2) {
                    printf("Digite o elemento a ser adicionado: ");
                    scanf("%ld", &x);

                    retorno = push(P2, x);
                }
                else {
                    puts("[ERROR] Essa pilha nao existe!");
                    puts("Por favor, insira o numero de uma pilha existente!");
                }
            }

            if (retorno == SUCESSO) {
                printf("O elemento %ld foi adicionado a pilha P%d!\n\n", x, optionPilhas);
            }
            else {
                printf("[ERROR] Nao foi possivel adicionar o elemento desejado a pilha!");
            }
            break;
        
        case 4:
            if (pilhas == 0) {
                puts("[ERROR] Nao ha pilhas criadas!");
                puts("Por favor, crie pilhas e adicione elementos para poder excluir!");
            }
            else if (pilhas == 1) {
                retorno = pop(P1);
            }
            else {
                printf("De qual pilha deseja excluir um elemento? (Digite 1 para P1 e 2 para P2) ");
                scanf("%d", &optionPilhas);

                if (optionPilhas == 1) {
                    retorno = pop(P1);
                }
                else if (optionPilhas == 2) {
                    retorno = pop(P2);
                }
            }

            if (retorno == SUCESSO) {
                printf("Um elemento foi retirado da pilha P%d!\n\n", optionPilhas);
            }
            else {
                printf("[ERROR] Nao foi possivel retirar um elemento da pilha P%d\n\n", optionPilhas);
            }
            break;

        case 5:
            if (pilhas == 0) {
                puts("[ERROR] Nao ha pilhas criadas!");
                puts("Por favor, crie pilhas para saber a cardinalidade!");
            }
            else if (pilhas == 1) {
                tamanho = size(P1);
            }
            else {
                printf("De qual pilha deseja saber a cardinalidade? (Digite 1 para P1 e 2 para P2) ");
                scanf("%d", &optionPilhas);

                if (optionPilhas == 1) {
                    tamanho = size(P1);
                }
                else if (optionPilhas == 2) {
                    tamanho = size(P2);
                }
            }

            printf("Cardinalidade da Pilha P%d = %ld\n\n", optionPilhas, tamanho);

            break;

        case 6:
            if (pilhas < 2) {
                puts("[ERROR] Nao ha pilhas suficiente para comparar!");
                puts("Por favor, crie duas pilhas para serem coparadas!");
            }
            else {
                retorno = isEqual(P1, P2);
            }

            if (retorno == true) {
                puts("As pilhas P1 e P2 sao Identicas!\n");
            }
            else {
                puts("As pilhas P1 e P2 nao sao Identicas!\n\n");
            }
            break;

        case 7:
            if (pilhas == 0) {
                puts("[ERROR] Nao ha pilhas criadas!");
                puts("Por favor, crie pilhas para mostra-las!");
            }
            else if (pilhas == 1) {
                printf("Em qual ordem deseja mostrar? (Digite 1 para mostrar a partir do TOPO e 0 a partir da BASE) ");
                scanf("%d", &ordem);

                show(P1, ordem);
            }
            else {
                printf("Qual pilha deseja mostrar? (Digite 1 para P1 e 2 para P2) ");
                scanf("%d", &optionPilhas);

                printf("Em qual ordem deseja mostrar? (Digite 1 para mostrar a partir do TOPO e 0 a partir da BASE) ");
                scanf("%d", &ordem);

                if (optionPilhas == 1) {
                    show(P1, ordem);
                }
                else if (optionPilhas == 2) {
                    show(P2, ordem);
                }
            }
            break;

        case 8:
            if (pilhas < 2) {
                puts("[ERROR] Nao ha pilhas suficiente para copiar!");
                puts("Por favor, crie duas pilhas para serem copiadas!");
            }
            else {
                retorno = copy(P1, P2); 
            }

            if (retorno == true) {
                puts("A pilha P1 foi copiada para P2\n");
            }
            else {
                puts("A pilha P1 nao foi copiada para P2\n\n");
            }
            break;

        default:
            break;
        }
        optionPilhas = 1;
        retorno = -1;
    }

    if (pilhas == 1) {
        retorno = destroyPilhas(P1);
        if (retorno == SUCESSO) {
            puts("Pilha P1 destruida com Sucesso!");
        }
        else {
            puts("[ERROR] Nao foi possivel destruir a pilha P1!");
        }
    }
    else if (pilhas == 2) {
        retorno = destroyPilhas(P2);
        if (retorno == SUCESSO) {
            puts("Pilha P2 destruida com Sucesso!");
        }
        else {
            puts("[ERROR] Nao foi possivel destruir a pilha P2!");
        }

        retorno = destroyPilhas(P1);
        if (retorno == SUCESSO) {
            puts("Pilha P1 destruida com Sucesso!");
        }
        else {
            puts("[ERROR] Nao foi possivel destruir a pilha P1!");
        }
    }

    puts("Programa Finalizado!");
    

    return 0;
}
