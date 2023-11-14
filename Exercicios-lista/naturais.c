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



// =============================================================
// ================ ARQUIVO "naturaisMain.c" ===================
// =============================================================

int main () {
    Conjunto *C1 = (Conjunto*)malloc(sizeof(Conjunto));
    int operacao = 1;
    int retorno;
    long int x;

    while (operacao != 0) {
        puts("+-------------------------------------------+");
        puts("| Escolha a operacao a ser feita:           |");
        puts("|                                           |");
        puts("| 0 - Finalizar o programa                  |");
        puts("| 1 - Criar conjunto vazio                  |");
        puts("| 2 - Destruir o conjunto                   |");
        puts("| 3 - Verificar se Conjunto e Vazio         |");
        puts("| 4 - Adicionar um Elemento ao Conjunto     |");
        puts("| 5 - Exclui um Elemento do Conjunto        |");
        puts("| 6 - Cardinalidade do Conjunto             |");
        puts("| 7 - Quantos sao maiores que:              |");
        puts("| 8 - Quantos sao menores que:              |");
        puts("| 9 - Pertence ao Conjunto?                 |");
        puts("+-------------------------------------------+");

        scanf("%d", &operacao);

        switch (operacao)
        {
            case 1:
                retorno = criaConjunto(C1);
                if (retorno == SUCESSO) {
                    puts("Conjunto C criado com Sucesso!");
                }
                else {
                    puts("[ERROR] Nao foi possível criar o conjunto!");
                }
                break;
            
            case 2:
                retorno = destroiConjunto(C1);
                if (retorno == SUCESSO) {
                    puts("O conjunto foi Destruido!");
                }
                else if (retorno == FALHA) {
                    puts("O conjunto nao foi Destruido!");
                }
                break;

            case 3:
                retorno = conjuntoVazio(C1);
                if (retorno == true) {
                    puts("O Conjunto eh Vazio!");
                }
                else {
                    puts("O Conjunto nao eh Vazio!");
                }
                break;

            case 4:
                printf("Digite o Elemento: ");
                scanf("%ld", &x);
                retorno = insereElementoConjunto(x, C1);

                if (retorno == SUCESSO) {
                    puts("O elemento foi adicionado!");
                }
                else if (retorno == FALHA) {
                    puts("O elemento não foi adicionado!");
                }
                break;

            case 5:
                printf("Digite o Elemento a ser Excluido: ");
                scanf("%ld", &x);
                retorno = excluirElementoConjunto(x, C1);

                if (retorno == SUCESSO) {
                    puts("O elemento foi excluido!");
                }
                else if (retorno == FALHA) {
                    puts("O elemento nao foi excluido!");
                }
                break;
            
            case 6:
                retorno = tamanhoConjunto(C1);
                printf("%d\n", retorno);
                break;
            
            case 7:
                printf("Digite o numero a ser comparado: ");
                scanf("%ld", &x);
                retorno = maior(x, C1);
                printf("%d\n", retorno);
                break;
            
            case 8:
                printf("Digite o numero a ser comparado: ");
                scanf("%ld", &x);
                retorno = menor(x, C1);
                printf("%d\n", retorno);
                break;

            case 9:
                printf("Digite o numero a ser analisado: ");
                scanf("%ld", &x);
                retorno = pertenceConjunto(x, C1);

                if (retorno == true) {
                    puts("O numero pertence ao conjunto!");
                }
                else if (retorno == false) {
                    puts("O numero nao pertence ao conjunto!");
                }

            default:
                break;
        }

        // if (operacao == 1) {
            // retorno = criaConjunto(C1);
            // if (retorno == SUCESSO) {
            //     puts("Conjunto C criado com Sucesso!");
            // }
            // else {
            //     puts("[ERROR] Nao foi possível criar o conjunto!");
            // }
        // }
        // else if (operacao == 2) {
            // retorno = destroiConjunto(C1);
            // if (retorno == SUCESSO) {
            //     puts("O conjunto foi Destruido!");
            // }
            // else if (retorno == FALHA) {
            //     puts("O conjunto nao foi Destruido!");
            // }
        // }
        // else if (operacao == 3) {
            // retorno = conjuntoVazio(C1);
            // if (retorno == true) {
            //     puts("O Conjunto eh Vazio!");
            // }
            // else {
            //     puts("O Conjunto nao eh Vazio!");
            // }
        // }
        // else if (operacao == 4) {
            // printf("Digite o Elemento: ");
            // scanf("%ld", &x);
            // retorno = insereElementoConjunto(x, C1);

            // if (retorno == SUCESSO) {
            //     puts("O elemento foi adicionado!");
            // }
            // else if (retorno == FALHA) {
            //     puts("O elemento não foi adicionado!");
            // }
        // }
        // else if (operacao == 5) {
            // printf("Digite o Elemento a ser Excluido: ");
            // scanf("%ld", &x);
            // retorno = excluirElementoConjunto(x, C1);

            // if (retorno == SUCESSO) {
            //     puts("O elemento foi excluido!");
            // }
            // else if (retorno == FALHA) {
            //     puts("O elemento nao foi excluido!");
            // }
        // }
    }

    printf("Programa Finalizado!");

    return 0;
}

