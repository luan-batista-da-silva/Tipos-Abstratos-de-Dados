#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MENOR -1
#define IGUAL 0
#define MAIOR 1


// =============================================================
// ================== ARQUIVO "datas.h" ========================
// =============================================================
typedef struct data Data;
Data* criaData (unsigned int dia, unsigned int mes, unsigned int ano);
Data* copiaData (Data d);
void liberaData (Data * d);
Data* somaDiasData (Data d, unsigned int dias);
Data* subtrairDiasData (Data d, unsigned int dias);
void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);
unsigned int obtemDiaData (Data d);
unsigned int obtemMesData (Data d);
unsigned int obtemAnoData (Data d);
unsigned int bissextoData (Data d);
int comparaData (Data d1, Data d2);
unsigned int numeroDiasDatas (Data d1, Data d2);
unsigned int numeroMesesDatas (Data d1, Data d2);
unsigned int numeroAnosDatas (Data d1, Data d2);
unsigned int obtemDiaSemanaData (Data d);
char* imprimeData (Data d, char * formato);

// =============================================================
// ================== ARQUIVO "datas.c" ========================
// =============================================================
struct data {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

// +---------------------------------------------+
// | Cria uma Nova Data                          |
// +---------------------------------------------+
Data* criaData (unsigned int dia, unsigned int mes, unsigned int ano) {
    Data* newDate = (Data*)malloc(sizeof(Data));
    newDate->dia = dia;
    newDate->mes = mes;
    newDate->ano = ano;
    return newDate;
}

// +---------------------------------------------+
// | Copia uma Data ja Existente                 |
// +---------------------------------------------+
Data* copiaData (Data d) {
    Data* dateCopy = (Data*)malloc(sizeof(Data));
    dateCopy->dia = d.dia;
    dateCopy->mes = d.mes;
    dateCopy->ano = d.ano;

    return dateCopy;

}

// +---------------------------------------------+
// | Destroi uma Data                            |
// +---------------------------------------------+
void liberaData (Data * d) {
    if (d != NULL) {
        free(d);
        puts("Data destruida com Sucesso!");
    }
    else {
        puts("A data nao foi destruida!");
    }
}

// +---------------------------------------------+
// | Soma dias a Data desejada                   |
// +---------------------------------------------+
Data* somaDiasData (Data d, unsigned int dias) {
    Data* newDate = (Data*)malloc(sizeof(Data));
    unsigned int qntDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int indexMes;

    newDate->dia = d.dia;
    newDate->mes = d.mes;
    newDate->ano = d.ano;

    if (bissextoData(*newDate) == true) {
        qntDias[1] = 29;
    }

    for (unsigned int i = 1; i <= dias; i++) {
        indexMes = newDate->mes - 1;
        newDate->dia++;
        if(newDate->dia > qntDias[indexMes]) {
            newDate->dia = 1;
            if (indexMes == 11) {
                newDate->mes = 1;
                newDate->ano++;
                if (bissextoData(*newDate) == true) {
                    qntDias[1] = 29;
                }
            }
            else {
                newDate->mes++;
            }
        }
    }

    return newDate;
}

// +---------------------------------------------+
// | Subtrair dias a Data desejada               |
// +---------------------------------------------+
Data* subtrairDiasData (Data d, unsigned int dias) {
    Data* newDate = (Data*)malloc(sizeof(Data));
    unsigned int qntDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int indexMes;

    newDate->dia = d.dia;
    newDate->mes = d.mes;
    newDate->ano = d.ano;

    if (bissextoData(*newDate) == true) {
        qntDias[1] = 29;
    }

    for (unsigned int i = 1; i <= dias; i++) {
        indexMes = newDate->mes - 1;
        if(newDate->dia > 1) {
            newDate->dia--;
        }
        else if (newDate->dia == 1) {
            if (indexMes == 0) {
                newDate->dia = qntDias[11];
                newDate->mes = 12;
                newDate->ano--;
                if (bissextoData(*newDate) == true) {
                    qntDias[1] = 29;
                }
            }
            else {
                newDate->dia = qntDias[indexMes - 1];
                newDate->mes--;
            }
        }
    }

    return newDate;
}

// +---------------------------------------------+
// | Atribuir Data nova a uma Existente          |
// +---------------------------------------------+
void atribuirData(Data * d, unsigned int dia, unsigned int mes, unsigned int ano) {
    if (d != NULL) {
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
    }
    else {
        d = (Data*)NULL;
    }
}

// +---------------------------------------------+
// | Obtem o dia da data                         |
// +---------------------------------------------+
unsigned int obtemDiaData (Data d) {
    return d.dia;
}

// +---------------------------------------------+
// | Obtem o mes da data                         |
// +---------------------------------------------+
unsigned int obtemMesData (Data d) {
    return d.mes;
}

// +---------------------------------------------+
// | Obtem o ano da data                         |
// +---------------------------------------------+
unsigned int obtemAnoData (Data d) {
    return d.ano;
}

// +---------------------------------------------+
// | Verifica se o Ano é Bissexto                |
// +---------------------------------------------+
unsigned int bissextoData (Data d) {
    unsigned int ano = d.ano;

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

// +---------------------------------------------+
// | Compara Datas                               |
// +---------------------------------------------+
int comparaData (Data d1, Data d2) {
    if (d1.ano < d2.ano) {
        return MENOR;
    }
    else if (d1.ano > d2.ano) {
        return MAIOR;
    }
    else {
        if (d1.mes < d2.mes) {
            return MENOR;
        }
        else if (d1.mes > d2.mes) {
            return MAIOR;
        }
        else {
            if (d1.dia < d2.dia) {
                return MENOR;
            }
            else if (d1.dia > d2.dia) {
                return MAIOR;
            }
            else {
                return IGUAL;
            }
        }
    }
}

// +---------------------------------------------+
// | Conta quantos dias tem entre D1 e D2        |
// +---------------------------------------------+
unsigned int numeroDiasDatas (Data d1, Data d2) {
    Data* newDate = (Data*)NULL;
    unsigned int qntDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned int countDias = 0;
    int retorno = -1;

    retorno = comparaData(d1, d2);
    newDate = &d1;

    if (bissextoData(d1) == true) {
        qntDias[1] = 29;
    }

    if (retorno == MAIOR) {
        while(true) {
            newDate = subtrairDiasData(*newDate, 1);
            countDias++;
            if (comparaData(*newDate, d2) == IGUAL) {
                return countDias;
            }
        }
    }
    else if (retorno == MENOR) {
        while(true) {
            newDate = somaDiasData(*newDate, 1);
            countDias++;
            if (comparaData(*newDate, d2) == IGUAL) {
                return countDias;
            }
        }
    }
    else {
        return countDias;
    }
}


// +---------------------------------------------+
// | Conta quantos meses ha entre D1 e D2        |
// +---------------------------------------------+
unsigned int numeroMesesDatas (Data d1, Data d2) {
    unsigned int countMeses = 0;
    int compara;

    if (d1.ano == d2.ano) {
        if (d1.mes == d2.mes) {
            return countMeses;
        }
        else {
            compara = comparaData(d1, d2);
            if (compara == MAIOR) {
                countMeses = d1.mes - d2.mes;
                return countMeses;
            }
            else if (compara == MENOR) {
                countMeses = d2.mes - d1.mes;
                return countMeses;
            }
        }
    }
    else {
        compara = comparaData(d1, d2);
        if (compara == MAIOR) {
            while (true) {
                d1.mes--;
                countMeses++;
                if (d1.ano == d2.ano) {
                    if (d1.mes == d2.mes) {
                        return countMeses;
                    }
                }
                else if (d1.mes == 0) {
                    d1.ano--;
                    d1.mes = 12;
                }
            }
        }
        else if (compara == MENOR) {
            while (true) {
                d1.mes++;
                countMeses++;
                if (d1.ano == d2.ano) {
                    if (d1.mes == d2.mes) {
                        return countMeses;
                    }
                }
                else if (d1.mes == 13) {
                    d1.ano++;
                    d1.mes = 1;
                }
            }
        }
    }
}

// +---------------------------------------------+
// | Conta quantos anos tem entre D1 e D2        |
// +---------------------------------------------+
unsigned int numeroAnosDatas (Data d1, Data d2) {
    unsigned int countAnos = 0;

    if (d1.ano > d2.ano) {
        while (true) {
            d1.ano--;
            countAnos++;
            if (d1.ano == d2.ano) {
                return countAnos;
            }
        }
    }
    else if (d1.ano < d2.ano) {
        while (true) {
            d1.ano++;
            countAnos++;
            if (d1.ano == d2.ano) {
                return countAnos;
            }
        }
    }
    else {
        return countAnos;
    }
}

//  formula = dia + 2*mes + (3*(mes+1)/5) + ano + ano/4 - ano/100 + ano/400 + 2;  // Formula para calcular o dia da semana.

// +---------------------------------------------+
// | Obtem o dia da Semana                       |
// +---------------------------------------------+
unsigned int obtemDiaSemanaData(Data d) {
    unsigned int dia = d.dia;
    unsigned int mes = d.mes;
    unsigned int ano = d.ano;

    if (mes < 3) {
        mes += 12;
        ano--;
    }

    unsigned int restoAno100 = ano % 100;
    unsigned int divAno100 = ano / 100;

    unsigned int res = (dia + ((13 * (mes + 1)) / 5) + restoAno100 + (restoAno100 / 4) + (divAno100 / 4) - (2 * divAno100)) % 7;

    unsigned int diaSemana = (res + 5) % 7 + 1;

    return diaSemana;
}

// +---------------------------------------------+
// | Imprime a Data Desejada                     |
// +---------------------------------------------+
char* imprimeData (Data d, char * formato) {
    char* printData[15];
    char dia[3];
    char mes[3];
    char ano[5];

    if (formato == 'ddmmaaaa') {
        sprintf(printData, "%02u/%02u/%04u", d.dia, d.mes, d.ano);
        printf("%s", printData);
    }

}

// =============================================================
// ================== ARQUIVO "datasMain.h" ====================
// =============================================================

int main () {
    Data* d1 = (Data*)NULL;
    Data* d2 = (Data*)NULL;
    Data* dateCopy = (Data*)NULL;
    Data* newDate = (Data*)NULL;
    int operacao = 1;
    int countDatas = 0;
    unsigned int dia, mes, ano;
    int dias = 0;
    int optionDate = 1;
    int retorno;
    unsigned int countDias, countMeses, countAnos, diaSemana;
    char weekDays[][20] = {"Segunda-Feira", "Terca-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sabado", "Domingo"};
    char formato[10];

    while (operacao != 0)
    {

        puts("+-----------------------------------------------------+");
        puts("| Escolha a operacao a ser feita:                     |");
        puts("|                                                     |");
        puts("| 0 - Finalizar o programa                            |");
        puts("| 1 - Criar Data                                      |");
        puts("| 2 - Copia Data                                      |");
        puts("| 3 - Destruir Data                                   |");
        puts("| 4 - Somar dias da data                              |");
        puts("| 5 - Subtrair dias da data                           |");
        puts("| 6 - Atribuir data                                   |");
        puts("| 7 - Obtem Dia da Data                               |");
        puts("| 8 - Obtem Mes da Data                               |");
        puts("| 9 - Obtem Ano da Data                               |");
        puts("| 10 - Verificar se o Ano e Bissexto                  |");
        puts("| 11 - Compara Datas                                  |");
        puts("| 12 - Numero de dias entre duas Datas                |");
        puts("| 13 - Numero de meses entre duas Datas               |");
        puts("| 14 - Numero de Anos entre duas Datas                |");
        puts("| 15 - Saber o dia da semana                          |");
        puts("| 16 - Imprimir Data                                  |");
        puts("+-----------------------------------------------------+");

        scanf("%d", &operacao);

        switch (operacao)
        {
            case 1:
                printf("Digite o Dia: ");
                scanf("%u", &dia);
                printf("Digite o Mes: ");
                scanf("%u", &mes);
                printf("Digite o Ano: ");
                scanf("%u", &ano);
                
                if (countDatas == 0) {
                    d1 = criaData(dia, mes, ano);

                    if (d1 == NULL) {
                        puts("[ERROR] A data nao foi criada!");
                    }
                    else {
                        countDatas++;
                        puts("A data foi criada com sucesso!");
                        puts("=== IMPRIMINDO DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", d1->dia, d1->mes, d1->ano);
                    }    
                }
                else if (countDatas == 1) {
                    d2 = criaData(dia, mes, ano);

                    if (d2 == NULL) {
                        puts("[ERROR] A data nao foi criada!");
                    }
                    else {
                        countDatas++;
                        puts("A data foi criada com sucesso!");
                        puts("=== IMPRIMINDO DATA D2 ===");
                        printf("%02u/%02u/%u\n\n", d2->dia, d2->mes, d2->ano);
                    }    
                }
                else {
                    puts("[ERROR] Nao foi possivel criar uma terceira data!");
                }
                break;

            case 2:
                if (countDatas == 0) {
                    puts("[ERROR] Nao a datas existentes!");
                    puts("Por favor, crie uma data para poder copiar!");
                }
                else if (countDatas == 1) {
                    dateCopy = copiaData(*d1);

                    puts("=== PRINTANDO D1 COPIADA ===");
                    printf("%02u/%02u/%u\n\n", dateCopy->dia, dateCopy->mes, dateCopy->ano);
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja criar uma copia? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate);

                    if (optionDate == 1) {
                        dateCopy = copiaData(*d1);

                        puts("=== PRINTANDO D1 COPIADA ===");
                        printf("%02u/%02u/%u\n\n", dateCopy->dia, dateCopy->mes, dateCopy->ano);
                    }
                    else if (optionDate == 2) {
                        dateCopy = copiaData(*d2);

                        puts("=== PRINTANDO D2 COPIADA ===");
                        printf("%02u/%02u/%u\n\n", dateCopy->dia, dateCopy->mes, dateCopy->ano);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;
            
            case 3:
                if (countDatas == 0) {
                    puts("[ERROR] Nao se tem nenhuma data para destruir!");
                }
                else if (countDatas == 1) {
                    liberaData(d1);
                    countDatas--;
                    puts("A data d1 foi destruida!");
                }
                else if (countDatas == 2) {
                    liberaData(d2);
                    countDatas--;
                    puts("A data d2 foi destruida!");
                }
                break;

            case 4:
                if (countDatas == 0) {
                    puts("[ERROR] Nao ha datas para adicionar dias!");
                }
                else if (countDatas == 1) {
                    printf("Quantos dias deseja somar? ");
                    scanf("%d", &dias);
                    newDate = somaDiasData(*d1, dias);
                    puts("=== IMPRIMINDO NOVA DATA D1 ===");
                    printf("%02u/%02u/%u\n\n", newDate->dia, newDate->mes, newDate->ano);
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja somar dias? (Digite 1 para d1 ou 2 para d2)");
                    scanf("%d", &optionDate);
                    if (optionDate == 1) {
                        printf("Quantos dias deseja somar a data d1?");
                        scanf("%d", &dias);
                        newDate = somaDiasData(*d1, dias);
                        puts("=== IMPRIMINDO NOVA DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", newDate->dia, newDate->mes, newDate->ano);
                    }
                    else if (optionDate == 2) {
                        printf("Quantos dias deseja somar a data d2?");
                        scanf("%d", &dias);
                        newDate = somaDiasData(*d2, dias);
                        puts("=== IMPRIMINDO DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", newDate->dia, newDate->mes, newDate->ano);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;

            case 5:
                if (countDatas == 0) {
                    puts("[ERROR] Nao ha datas para adicionar dias!");
                }
                else if (countDatas == 1) {
                    printf("Quantos dias deseja subtrair? ");
                    scanf("%d", &dias);
                    newDate = subtrairDiasData(*d1, dias);
                    puts("=== IMPRIMINDO NOVA DATA D1 ===");
                    printf("%02u/%02u/%u\n\n", newDate->dia, newDate->mes, newDate->ano);
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja subtrair dias? (Digite 1 para d1 ou 2 para d2)");
                    scanf("%d", &optionDate);
                    if (optionDate == 1) {
                        printf("Quantos dias deseja subtrair a data d1?");
                        scanf("%d", &dias);
                        newDate = subtrairDiasData(*d1, dias);
                        puts("=== IMPRIMINDO NOVA DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", newDate->dia, newDate->mes, newDate->ano);
                    }
                    else if (optionDate == 2) {
                        printf("Quantos dias deseja subtrair a data d2?");
                        scanf("%d", &dias);
                        newDate = subtrairDiasData(*d2, dias);
                        puts("=== IMPRIMINDO DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", newDate->dia, newDate->mes, newDate->ano);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;

            case 6:
                if (countDatas == 0) {
                    puts("[ERROR] Nao a datas existentes!");
                    puts("Por favor, crie uma data para poder atribuir outra data!");
                }
                else if (countDatas == 1) {
                    printf("Digite o novo dia: ");
                    scanf("%u", &dia);
                    printf("Digite o novo mes: ");
                    scanf("%u", &mes);
                    printf("Digite o novo ano: ");
                    scanf("%u", &ano);

                    atribuirData(d1, dia, mes, ano);

                    puts("=== PRINTANDO NOVA DATA D1 ===");
                    printf("%02u/%02u/%u\n\n", d1->dia, d1->mes, d1->ano);
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja substituir? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate);

                    if (optionDate == 1) {
                        printf("Digite o novo dia: ");
                        scanf("%u", &dia);
                        printf("Digite o novo mes: ");
                        scanf("%u", &mes);
                        printf("Digite o novo ano: ");
                        scanf("%u", &ano);

                        atribuirData(d1, dia, mes, ano);

                        puts("=== PRINTANDO NOVA DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", d1->dia, d1->mes, d1->ano);
                    }
                    else if (optionDate == 2) {
                        printf("Digite o novo dia: ");
                        scanf("%u", &dia);
                        printf("Digite o novo mes: ");
                        scanf("%u", &mes);
                        printf("Digite o novo ano: ");
                        scanf("%u", &ano);

                        atribuirData(d2, dia, mes, ano);

                        puts("=== PRINTANDO NOVA DATA D1 ===");
                        printf("%02u/%02u/%u\n\n", d2->dia, d2->mes, d2->ano);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;

            case 7:
                if (countDatas == 0) {
                    puts("[ERROR] Nao a datas existentes!");
                    puts("Por favor, crie uma data para poder obter o dia!");
                }
                else if (countDatas == 1) {
                    printf("Dia da Data D1 = %u\n\n", obtemDiaData(*d1));
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja verificar o dia? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate);

                    if (optionDate == 1) {
                        printf("Dia da Data D1 = %u\n\n", obtemDiaData(*d1));
                    }
                    else if (optionDate == 2) {
                        printf("Dia da Data D2 = %u\n\n", obtemDiaData(*d2));
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;

            case 8:
                if (countDatas == 0) {
                    puts("[ERROR] Nao a datas existentes!");
                    puts("Por favor, crie uma data para poder obter o Mes!");
                }
                else if (countDatas == 1) {
                    printf("Mes da Data D1 = %u\n\n", obtemMesData(*d1));
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja verificar o mes? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate);

                    if (optionDate == 1) {
                        printf("Mes da Data D1 = %u\n\n", obtemMesData(*d1));
                    }
                    else if (optionDate == 2) {
                        printf("Mes da Data D2 = %u\n\n", obtemMesData(*d2));
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;

            case 9:
                if (countDatas == 0) {
                    puts("[ERROR] Nao a datas existentes!");
                    puts("Por favor, crie uma data para poder obter o Ano!");
                }
                else if (countDatas == 1) {
                    printf("Ano da Data D1 = %u\n\n", obtemAnoData(*d1));
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja verificar o ano? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate);

                    if (optionDate == 1) {
                        printf("Ano da Data D1 = %u\n\n", obtemAnoData(*d1));
                    }
                    else if (optionDate == 2) {
                        printf("Ano da Data D2 = %u\n\n", obtemAnoData(*d2));
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, insira o numero de uma data que exista!");
                    }
                }
                break;
        
            case 10:
                if (countDatas == 0) {
                    puts("[ERROR] Nao foi criada nenhuma data!");
                    puts("Por favor, crie uma data antes de verificar se o ano é bissexto!");
                }
                else if (countDatas == 1) {
                    retorno = bissextoData(*d1);
                }
                else if (countDatas == 2) {
                    printf("Qual data deseja verificar se o ano e bissexto? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate); 

                    if (optionDate == 1) {
                        retorno = bissextoData(*d1);
                    }
                    else if (optionDate == 2) {
                        retorno = bissextoData(*d2);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, digite o numero de uma data que exista!");
                    }
                }
                
                if (retorno == true) {
                    puts("O ano e bissexto!");
                }
                else {
                    puts("O ano nao e bissexto!");
                }
                break;

            case 11:
                if (countDatas < 2) {
                    puts("[ERROR] Nao existem duas datas para serem comparadas!"); 
                    puts("Por favor, crie duas datas antes de comparar!");
                }
                else {
                    retorno = comparaData(*d1, *d2);

                    if (retorno == MENOR) {
                        puts("D1 e menor que D2!");
                    }
                    else if (retorno == MAIOR) {
                        puts("D1 e maior que d2!");
                    }
                    else {
                        puts("D1 e D2 sao iguais!");
                    }
                }
                break;

            case 12:
                if (countDatas < 2) {
                    puts("[ERROR] Nao existem duas datas para serem comparadas!"); 
                    puts("Por favor, crie duas datas contar os dias!");
                }
                else {
                    countDias = numeroDiasDatas(*d1, *d2);
                    
                    if (countDias == 0) {
                        puts("D1 e D2 sao iguais!");
                    }
                    else {
                        printf("As duas datas estao a %u dias de diferenca!\n\n", countDias);
                    }
                }   
                break;

            case 13:
                if (countDatas < 2) {
                    puts("[ERROR] Nao existem duas datas para serem comparadas!"); 
                    puts("Por favor, crie duas datas contar os meses!");
                }
                else {
                    countMeses = numeroMesesDatas(*d1, *d2);
                    
                    if (countMeses == 0) {
                        puts("D1 e D2 estao no mesmo mes!");
                    }
                    else {
                        printf("As duas datas estao a %u meses de diferenca!\n\n", countMeses);
                    }
                }   
                break;

            case 14:
                if (countDatas < 2) {
                    puts("[ERROR] Nao existem duas datas para serem comparadas!"); 
                    puts("Por favor, crie duas datas contar os anos!");
                }
                else {
                    countAnos = numeroAnosDatas(*d1, *d2);
                    
                    if (countAnos == 0) {
                        puts("D1 e D2 estao no mesmo ano!");
                    }
                    else {
                        printf("As duas datas estao a %u anos de diferenca!\n\n", countAnos);
                    }
                }
                break;

            case 15:
                if (countDatas == 0) {
                    puts("[ERROR] Nao ha data para obter o dia da semana!");
                    puts("Por favor, crie datas antes de obter o dia da semana!");
                }
                else if (countDatas == 1) {
                    diaSemana = obtemDiaSemanaData(*d1) - 1;
                    printf("Dia da Semana = %s\n\n", weekDays[diaSemana]);
                }
                else {
                    printf("Qual data deseja saber o dia da semana? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate); 

                    if (optionDate == 1) {
                        diaSemana = obtemDiaSemanaData(*d1) - 1;
                        printf("Dia da Semana = %s\n\n", weekDays[diaSemana]);
                    }
                    else if (optionDate == 2) {
                        diaSemana = obtemDiaSemanaData(*d2) - 1;
                        printf("Dia da Semana = %s\n\n", weekDays[diaSemana]);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, digite o numero de uma data que exista!");
                    }
                }
                break;

            case 16:
                if (countDatas == 0) {
                    puts("[ERROR] Nao ha data para ser impressa!");
                    puts("Por favor, crie datas antes de obter !");
                }
                else if (countDatas == 1) {
                    diaSemana = obtemDiaSemanaData(*d1) - 1;
                    printf("Dia da Semana = %s\n\n", weekDays[diaSemana]);
                }
                else {
                    printf("Qual data deseja saber o dia da semana? (Digite 1 para d1 ou 2 para d2) ");
                    scanf("%d", &optionDate); 

                    if (optionDate == 1) {
                        diaSemana = obtemDiaSemanaData(*d1) - 1;
                        printf("Dia da Semana = %s\n\n", weekDays[diaSemana]);
                    }
                    else if (optionDate == 2) {
                        diaSemana = obtemDiaSemanaData(*d2) - 1;
                        printf("Dia da Semana = %s\n\n", weekDays[diaSemana]);
                    }
                    else {
                        puts("[ERROR] Essa data nao existe!");
                        puts("Por favor, digite o numero de uma data que exista!");
                    }
                }
                break;

            default:
                break;
        }
        optionDate = 1;
        retorno = -1;
    }
    
    if (countDatas == 1) {
        liberaData(d1);
        puts("A data d1 foi destruida com sucesso!");
    }
    else if (countDatas == 2) {
        liberaData(d1);
        liberaData(d2);
        puts("As datas d1 e d2 foram destruidas com sucesso!");
    }

    if (newDate != NULL) {
        liberaData(newDate);
        puts("NewDate foi destruida com sucesso!");
    }

    if (dateCopy != NULL) {
        liberaData(dateCopy);
        puts("DateCopy foi destruida com sucesso!");
    }

    puts("\nPROGRAMA FINALIZADO!");

    return 0;
}