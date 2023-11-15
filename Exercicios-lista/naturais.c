#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SUCESSO 1
#define FALHA 0
#define CRESCENTE 1
#define DECRESCENTE 0

// =============================================================
// =============== ARQUIVO "naturais.h" ========================
// =============================================================

typedef struct C Conjunto;

int criaConjunto(Conjunto* C);
int conjuntoVazio(Conjunto* C);
int insereElementoConjunto(long int x, Conjunto *C);
int excluirElementoConjunto(long int x, Conjunto *C);
int tamanhoConjunto(Conjunto* C);
int maior(long int x, Conjunto* C);
int menor(long int x, Conjunto* C);
int pertenceConjunto(long int x, Conjunto* C);
int conjuntosIdenticos(Conjunto* C1, Conjunto* C2);
int subconjunto(Conjunto* C1, Conjunto* C2);
Conjunto complemento(Conjunto* C1, Conjunto* C2);
Conjunto uniao(Conjunto* C1, Conjunto* C2);
Conjunto interseccao(Conjunto* C1, Conjunto* C2);
Conjunto diferenca(Conjunto* C1, Conjunto* C2);
Conjunto conjuntoPartes(Conjunto* C);
void mostraConjunto(Conjunto* C, int ordem);
int copiarConjunto(Conjunto* C1, Conjunto* C2);
int destroiConjunto(Conjunto* C);
int compara(const void *x, const void *y);


// =============================================================
// ================ ARQUIVO "naturais.c" =======================
// =============================================================

struct C {
    long int *elementos;
    int size;
};

// +----------------------------------+
// | Cria um Conjunto Vazio           |
// +----------------------------------+
int criaConjunto(Conjunto* C) {
    if (C != NULL) {
        C->elementos = NULL;
        C->size = 0;
        return SUCESSO;
    }
    else {
        return FALHA;
    }
}

// +----------------------------------+
// | Verifica se o Conjunto é Vazio   |
// +----------------------------------+
int conjuntoVazio(Conjunto* C) {
    if (C == NULL || C->elementos == NULL || C->size == 0) {
        return true;
    } 
    else {
        return false;
    }
}

// +----------------------------------+
// | Destruindo o Conjunto            |
// +----------------------------------+
int destroiConjunto(Conjunto* C) {
    if (C != NULL) {
        if (C->size > 0) {
            free(C->elementos);
        }
        free(C);
        return SUCESSO;
    }
    else {
        return FALHA;
    }
}

// +----------------------------------+
// | Insere Elementos no Conjunto     |
// +----------------------------------+
int insereElementoConjunto(long int x, Conjunto *C) {
    int tamanho = C->size;

    for (int i = 0; i < tamanho; i++) {
        if (C->elementos[i] == x) {
            puts("O elemento ja esta no conjunto!");
            return FALHA;
        }
    }

    if (C->size == 0) {
        C->elementos = (long int*)malloc(sizeof(long int));
        C->elementos[0] = x;
        C->size++;
        printf("Elemento 1 = %ld\n", C->elementos[0]);

        return SUCESSO;
    } 
    else if (C->size > 0) {
        tamanho++;
        C->elementos = (long int*)realloc(C->elementos, tamanho * sizeof(long int));
        C->elementos[tamanho - 1] = x;
        C->size++;
        
        puts("=== PRINTANDO OS ELEMENTOS ===");
        for (int i = 0; i < tamanho; i++) {
            printf("Elemento %d = %ld\n", i, C->elementos[i]);
        }

        return SUCESSO;
    }

    return FALHA;
}

// +----------------------------------+
// | Excluindo Elemento do Conjunto   |
// +----------------------------------+
int excluirElementoConjunto(long int x, Conjunto *C) {
    for (int i = 0; i < C->size; i++) {
        if (C->elementos[i] == x) {
            for (int j = i; j < C->size; j++) {
                C->elementos[j] = C->elementos[j + 1];
                if (j == C->size - 1) {
                    C->elementos[j] = NULL;
                    C->size--;
                    C->elementos = (long int*) realloc(C->elementos, C->size * (sizeof(long int)));
                    return SUCESSO;
                }
            }

        }
        else if (C->elementos[i] != x && i == C->size) {
            return FALHA;
        }
    }
}

// +----------------------------------+
// | Cardinalidade do Conjunto        |
// +----------------------------------+
int tamanhoConjunto(Conjunto* C) {
    if (C != NULL) {
        return C->size;
    }
    else if (C == NULL) {
        return 0;
    } 
}

// +----------------------------------+
// | Quantidade de Elementos Maiores  |
// +----------------------------------+
int maior(long int x, Conjunto* C) {
    int maiores = C->size;

    for (int i = 0; i < C->size; i++) {
        if (C->elementos[i] > x) {
            maiores--;
        }
    }

    if (maiores == 0) {
        return maiores;
    }
    else {
        return C->size - maiores;
    }
}

// +----------------------------------+
// | Quantidade de Elementos Menores  |
// +----------------------------------+
int menor(long int x, Conjunto* C) {
    int menores = C->size;

    for (int i = 0; i < C->size; i++) {
        if (C->elementos[i] < x) {
            menores--;
        }
    }

    if (menores == 0) {
        return menores;
    }
    else {
        return C->size - menores;
    }
}

// +---------------------------------------------+
// | Verifica se o elemento pertence ao Conjunto |
// +---------------------------------------------+
int pertenceConjunto(long int x, Conjunto* C) {
    for (int i = 0; i < C->size; i++) {
        if (C->elementos[i] == x) {
            return true;
        }
    }

    return false;
}

// +---------------------------------------------+
// | Verifica se os Conjuntos são Identicos      |
// +---------------------------------------------+
int conjuntosIdenticos(Conjunto* C1, Conjunto* C2) {
    int iguais = 0;


    if (C1->size == C2->size) {
        for (int i = 0; i < C1->size; i++) {
            for (int j = 0; j < C2->size; j++) {
                if (C1->elementos[i] == C2->elementos[j]) {
                    iguais++;
                }
            }
        }
        if (iguais == C1->size) {
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



// =============================================================
// ================ ARQUIVO "naturaisMain.c" ===================
// =============================================================

int main () {
    Conjunto *C1 = (Conjunto*)malloc(sizeof(Conjunto));;
    Conjunto *C2 = (Conjunto*)malloc(sizeof(Conjunto));;
    int conjuntos = 0;
    int optionConj = 1;
    int operacao = 1;
    int retorno = -1;
    long int x;
    int destroy;

    while (operacao != 0) {
        

        puts("+-----------------------------------------------+");
        puts("| Escolha a operacao a ser feita:               |");
        puts("|                                               |");
        puts("| 0 - Finalizar o programa                      |");
        puts("| 1 - Criar conjunto vazio                      |");
        puts("| 2 - Destruir o conjunto                       |");
        puts("| 3 - Verificar se Conjunto e Vazio             |");
        puts("| 4 - Adicionar um Elemento ao Conjunto         |");
        puts("| 5 - Exclui um Elemento do Conjunto            |");
        puts("| 6 - Cardinalidade do Conjunto                 |");
        puts("| 7 - Quantos sao maiores que:                  |");
        puts("| 8 - Quantos sao menores que:                  |");
        puts("| 9 - Pertence ao Conjunto?                     |");
        puts("| 10 - Comparar se dois Conjuntos sao identicos |");
        puts("+-----------------------------------------------+");

        scanf("%d", &operacao);

        switch (operacao)
        {
            case 1:
                if (conjuntos == 0) {
                    retorno = criaConjunto(C1);
                    conjuntos++;
                }
                else if (conjuntos == 1) {
                    retorno = criaConjunto(C2);
                    conjuntos++;
                }
                
                if (retorno == SUCESSO) {
                    printf("O conjunto C%d foi criado!\n\n", conjuntos);
                }
                else if (retorno == FALHA) {
                    puts("[ERROR] Nao foi possível criar o conjunto!\n");
                }
                break;

            case 2:

                if (conjuntos == 1) {
                    retorno = destroiConjunto(C1);
                }
                else {
                    printf("Qual Conjunto Deseja Destruir (1 para o C1 e 2 para o C2): ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = destroiConjunto(C1);
                    }
                    else if (optionConj == 2) {
                        retorno = destroiConjunto(C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.\n");
                    }
                }

                if (retorno == SUCESSO) {
                    conjuntos--;
                    printf("O conjunto C%d foi Destruido!\n\n", optionConj);
                }
                else if (retorno == FALHA) {
                    puts("O conjunto nao foi Destruido!\n");
                }
                break;

            case 3:
                if (conjuntos == 1) {
                    retorno = conjuntoVazio(C1);
                }
                else {
                    printf("Qual conjunto deseja verificar se esta vazio? (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = conjuntoVazio(C1);
                    }
                    else if (optionConj == 2) {
                        retorno = conjuntoVazio(C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.\n");
                    }
                }

                if (retorno == true) {
                    printf("O Conjunto C%d eh Vazio!\n\n", optionConj);
                }
                else if (retorno == false) {
                    puts("O Conjunto nao eh Vazio!\n");
                }
                break;

            case 4:
                if (conjuntos == 1) {
                    printf("Digite o Elemento: ");
                    scanf("%ld", &x);
                    retorno = insereElementoConjunto(x, C1);
                    puts("Elemento adicionado ao conjunto C1\n");
                }
                else {
                    printf("A qual conjunto deseja adicionar o elemento?  (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        printf("Digite o Elemento: ");
                        scanf("%ld", &x);
                        retorno = insereElementoConjunto(x, C1);
                    }
                    else if (optionConj == 2) {
                        printf("Digite o Elemento: ");
                        scanf("%ld", &x);
                        retorno = insereElementoConjunto(x, C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.");
                    }
                }

                if (retorno == SUCESSO) {
                    printf("Elemento adicionado ao conjunto C%d\n\n", optionConj);
                }
                else if (retorno == FALHA) {
                    puts("O elemento nao foi adicionado!");
                }
                break;

            case 5:
                printf("Digite o Elemento a ser Excluido: ");
                scanf("%ld", &x);

                if (conjuntos == 1) {
                    retorno = excluirElementoConjunto(x, C1);
                }
                else {
                    printf("De qual conjunto deseja excluir o elemento? (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = excluirElementoConjunto(x, C1);
                    }
                    else if (optionConj == 2) {
                        retorno = excluirElementoConjunto(x, C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.");
                    }
                }

                if (retorno == SUCESSO) {
                    printf("O elemento %ld foi excluido do conjunto C%d!\n\n", x, optionConj);
                }
                else if (retorno == FALHA) {
                    puts("O elemento nao foi excluido!");
                }
                break;
            
            case 6:
                if (conjuntos == 1) {
                    retorno = tamanhoConjunto(C1);
                }
                else {
                    printf("De qual conjunto deseja saber o tamanho? (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = tamanhoConjunto(C1);
                    }
                    else if (optionConj == 2) {
                        retorno = tamanhoConjunto(C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.");
                    }
                }

                if (retorno != -1) {
                    printf("Tamanho do conjunto C%d = %d\n\n", optionConj, retorno);
                }
                break;
            
            case 7:
                printf("Digite o numero a ser comparado: ");
                scanf("%ld", &x);

                if (conjuntos == 1) {
                    retorno = maior(x, C1);
                }
                else {
                    printf("De qual conjunto deseja comparar como maior valor? (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = maior(x, C1);
                    }
                    else if (optionConj == 2) {
                        retorno = maior(x, C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.");
                    }
                }
                
                printf("Temos %d elementos maiores que %ld no conjunto C%d! (0 indica que todos elementos sao maiores)\n\n", retorno, x, optionConj);
                break;
            
            case 8:
                printf("Digite o numero a ser comparado: ");
                scanf("%ld", &x);

                if (conjuntos == 1) {
                    retorno = menor(x, C1);
                }
                else {
                    printf("De qual conjunto deseja comparar como menor valor? (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = menor(x, C1);
                    }
                    else if (optionConj == 2) {
                        retorno = menor(x, C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.");
                    }
                }
                
                printf("Temos %d elementos menores que %ld no conjunto C%d! (0 indica que todos elementos sao menores)\n\n", retorno, x, optionConj);
                break;

            case 9:
                printf("Digite o numero a ser analisado: ");
                scanf("%ld", &x);

                if (conjuntos == 1) {
                    retorno = pertenceConjunto(x, C1);
                }
                else {
                    printf("Em qual conjunto deseja verificar o pertercimento do elemento? (1 para o C1 e 2 para o C2) ");
                    scanf("%d", &optionConj);

                    if (optionConj == 1) {
                        retorno = pertenceConjunto(x, C1);
                    }
                    else if (optionConj == 2) {
                        retorno = pertenceConjunto(x, C2);
                    }
                    else {
                        puts("[ERROR] Esse conjunto nao existe!");
                        puts("Por favor, insira o numero de um conjunto existente.");
                    }
                }

                if (retorno == true) {
                    printf("O elemento %ld pertence ao conjunto C%d!\n\n", x, optionConj);
                }
                else if (retorno == false) {
                    printf("O elemento %ld nao pertence ao conjunto C%d!\n\n", x, optionConj);
                }
                break;
            case 10:
                if (C1 != NULL && C2 != NULL) {
                    if (C1->elementos != NULL && C2->elementos != NULL) {
                        retorno = conjuntosIdenticos(C1, C2);
                        if (retorno == true) {
                            puts("Os conjuntos sao Identicos!");
                        }
                        else {
                            puts("Os conjuntos nao sao Identicos!");
                        }
                    }
                    else {
                        puts("[ERROR] Nao ha elementos em um dos conjuntos!");
                        puts("Por favor, conf   ira os elementos dos conjuntos.");
                    }
                }
                else {
                    puts("Nao existem dois conjuntos para serem comparados!");
                }
                break;

            default:
                break;
        }

        optionConj = 1;
        retorno = -1;
    }
    
    
    // destroy = destroiConjunto(C1);
    // destroy = destroiConjunto(C2);

    printf("Programa Finalizado!");

    return 0;
}