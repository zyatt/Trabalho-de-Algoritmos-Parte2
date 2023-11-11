#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20 // Valor definido para o total de linhas e colunas.
#define BOMAX 10 // Valores definidos para o total de cada elemento impresso na matriz.
#define AVMAX 5
#define SUMAX 5
#define E1MAX 4
#define E2MAX 4
#define PAMAX 2

    void InicializarMatriz(char vet[TAM][TAM],char vet2[TAM][TAM]){ // Inicializa a matriz com todas as posições como '*'.
        for(int i=0; i<TAM; i++){
            for(int j = 0; j<TAM; j++){
                vet[i][j] = '*';
                vet2[i][j] = '*';
            }
        }
    }
    void PrintarMatriz(char vet[TAM][TAM]){ // Printa a matriz.
        int k=0,l=0;
        char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'}; // Vetor usado para printar as letras acima da matriz.
        printf("   ");
        while(k<TAM){ // Printa as letras de A-T usando o vetor letra.
            printf("%c ",letra[k]);
            k++;
        }
        printf("\n");
        for(int i=0; i<TAM; i++){
            if(l<10){
                printf(" ");
            }
            printf("%d",l);
            l++;
            for(int j=0; j<TAM; j++){
                printf(" ");
                printf("%c",vet[i][j]);
            }
            printf("\n");
        }
    }
    void SortearMatriz(char vet[TAM][TAM]){ // Sorteia as embarcações na matriz.
        int i,j,linha,coluna,virar;
        int boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0; // Variavél de cada elemento.
        char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'}; // Vetor usado para printar as letras acima da matriz.
        srand(time(NULL));

        while(boia<BOMAX){

            linha = rand()%20;
            coluna = rand()%20;

            if(vet[linha][coluna] != '*'){
            }
            else{
                vet[linha][coluna] = '0';
                boia++;
                printf("%d %c - %c\n",linha,letra[coluna],vet[linha][coluna]);
            }
        }
        while(aviao<AVMAX){ // Sortear aviões aleatoriamente.

            linha = rand()%20;// Sortear linha.
            coluna = rand()%20; // Sortear coluna.
            virar = rand()%4; // Sortear a opção virar.

            switch(virar){ // switch case para rotação do elemento.
                case 0: // Opção virado para a direita.
                    if(linha<1 || linha>18 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha][coluna+1] != '*'){ // Verifica se há algum elemento na posição.
                        }
                        else{
                            vet[linha][coluna] = '1';
                            vet[linha-1][coluna] = '1';
                            vet[linha+1][coluna] = '1';    // Imprime as posições do avião a partir da posição (x,y) inicializada.
                            vet[linha][coluna+1] = '1';
                            aviao++;
                            printf("%d %c D %c\n",linha,letra[coluna],vet[linha][coluna]);
                            }
                    }
                break;

                case 1: // Opção virado para a esquerda.
                    if(coluna<1 || linha>18 || linha<1){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha][coluna-1] != '*'){ // Verifica se há algum elemento na posição.
                        }
                        else{
                            vet[linha][coluna] = '1';
                            vet[linha-1][coluna] = '1';
                            vet[linha+1][coluna] = '1';    // Imprime as posições do avião a partir da posição (x,y) inicializada.
                            vet[linha][coluna-1] = '1';
                            aviao++;
                            printf("%d %c E %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 2: // Opção virado para cima.
                    if(coluna<1|| coluna>18 || linha<1){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna-1] != '*' || vet[linha-1][coluna] != '*'){ // Verifica se há algum elemento na posição.
                        }
                        else{
                            vet[linha][coluna] = '1';
                            vet[linha][coluna+1] = '1';   // Imprime as posições do avião a partir da posição (x,y) inicializada.
                            vet[linha][coluna-1] = '1';
                            vet[linha-1][coluna] = '1';
                            aviao++;
                            printf("%d %c C %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 3: // Opção virado para baixo.
                    if(linha>18 || coluna <1 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna-1] != '*' || vet[linha+1][coluna] != '*'){  // Verifica se há algum elemento na posição.
                        }
                        else{
                            vet[linha][coluna] = '1';
                            vet[linha][coluna+1] = '1';
                            vet[linha][coluna-1] = '1';   // Imprime as posições do avião a partir da posição (x,y) inicializada.
                            vet[linha+1][coluna] = '1';
                            aviao++;
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;
            }
        }
        while(submarino<SUMAX){ // Sortear submarinos aleatoriamente.

            linha = rand()%20; // Sortear linha.
            coluna = rand()%20; // Sortear coluna.
            virar = rand()%4; // Sortear a opção virar.

            switch(virar){
                case 0: // Opcão virado para direita.
                    if(coluna>16){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '2';
                            vet[linha][coluna+1] = '2';
                            vet[linha][coluna+2] = '2';    // Imprime as posições do submarino a partir da posição (x,y) inicializada.
                            vet[linha][coluna+3] = '2';
                            submarino++;
                            printf("%d %c D %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 1: // Opcão virado para baixo.
                    if(linha>16){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '2';
                            vet[linha+1][coluna] = '2';
                            vet[linha+2][coluna] = '2';    // Imprime as posições do submarino a partir da posição (x,y) inicializada.
                            vet[linha+3][coluna] = '2';
                            submarino++;
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 2: // Opcão virado para esquerda.
                    if(coluna<3){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna-1] != '*' || vet[linha][coluna-2] != '*' || vet[linha][coluna-3] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '2';
                            vet[linha][coluna-1] = '2';
                            vet[linha][coluna-2] = '2';    // Imprime as posições do submarino a partir da posição (x,y) inicializada.
                            vet[linha][coluna-3] = '2';
                            submarino++;
                            printf("%d %c E %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 3: // Opcão virado para cima.
                    if(linha<3){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha-2][coluna] != '*' || vet[linha-3][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '2';
                            vet[linha-1][coluna] = '2';
                            vet[linha-2][coluna] = '2';    // Imprime as posições do submarino a partir da posição (x,y) inicializada.
                            vet[linha-3][coluna] = '2';
                            submarino++;
                            printf("%d %c C %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;
            }
        }
        while(espiao_1<E1MAX){ // Sortear espião 1 aleatoriamente.

            linha = rand()%20;// Sortear linha.
            coluna = rand()%20; // Sortear coluna.
            virar = rand()%4; // Sortear a opção virar.

            switch(virar){ // switch case da opção virar que rotaciona o elemento.
                case 0: // Opção virado para direita
                    if(linha<1 || linha>18 || coluna>16){  // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '3';
                            vet[linha+1][coluna] = '3';
                            vet[linha-1][coluna] = '3';
                            vet[linha][coluna+1] = '3';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha][coluna+2] = '3';
                            vet[linha][coluna+3] = '3';
                            espiao_1++;
                            printf("%d %c D %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 1: // Opção virado para a esquerda.
                    if(linha<1 || linha>18 || coluna<3){  // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna-1] != '*' || vet[linha][coluna-2] != '*' || vet[linha][coluna-3] != '*' || vet[linha-1][coluna] != '*' || vet[linha+1][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '3';
                            vet[linha][coluna-1] = '3';
                            vet[linha][coluna-2] = '3';
                            vet[linha][coluna-3] = '3';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha-1][coluna] = '3';
                            vet[linha+1][coluna] = '3';
                            espiao_1++;
                            printf("%d %c E %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 2: // Opção virado para baixo.
                    if(coluna<1|| linha>16 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna-1] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '3';
                            vet[linha][coluna+1] = '3';
                            vet[linha][coluna-1] = '3';
                            vet[linha+1][coluna] = '3';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha+2][coluna] = '3';
                            vet[linha+3][coluna] = '3';
                            espiao_1++;
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 3: // Opção virado para cima.
                    if(coluna<1 || linha<3 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna-1] != '*' || vet[linha-1][coluna] != '*' || vet[linha-2][coluna] != '*' || vet[linha-3][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '3';
                            vet[linha][coluna+1] = '3';
                            vet[linha][coluna-1] = '3';
                            vet[linha-1][coluna] = '3';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha-2][coluna] = '3';
                            vet[linha-3][coluna] = '3';
                            espiao_1++;
                            printf("%d %c C %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;
            }
        }
        while(espiao_2<E2MAX){ // Sortear espião 1 aleatoriamente.

            linha = rand()%20;// Sortear linha.
            coluna = rand()%20; // Sortear coluna.
            virar = rand()%4; // Sortear a opção virar.

            switch(virar){ // switch case da opção virar que rotaciona o elemento.
                case 0: // Opção virado para direita
                    if(linha<1 || linha>18 || coluna>16){  // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '4';
                            vet[linha+1][coluna] = '4';
                            vet[linha-1][coluna] = '4';
                            vet[linha][coluna+1] = '4';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha][coluna+2] = '4';
                            vet[linha][coluna+3] = '4';
                            espiao_2++;
                            printf("%d %c D %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 1: // Opção virado para a esquerda.
                    if(linha<1 || linha>18 || coluna<3){  // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna-1] != '*' || vet[linha][coluna-2] != '*' || vet[linha][coluna-3] != '*' || vet[linha-1][coluna] != '*' || vet[linha+1][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '4';
                            vet[linha][coluna-1] = '4';
                            vet[linha][coluna-2] = '4';
                            vet[linha][coluna-3] = '4';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha-1][coluna] = '4';
                            vet[linha+1][coluna] = '4';
                            espiao_2++;
                            printf("%d %c E %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 2: // Opção virado para baixo.
                    if(coluna<1|| linha>16 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna-1] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '4';
                            vet[linha][coluna+1] = '4';
                            vet[linha][coluna-1] = '4';
                            vet[linha+1][coluna] = '4';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha+2][coluna] = '4';
                            vet[linha+3][coluna] = '4';
                            espiao_2++;
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 3: // Opção virado para cima.
                    if(coluna<1 || linha<3 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna-1] != '*' || vet[linha-1][coluna] != '*' || vet[linha-2][coluna] != '*' || vet[linha-3][coluna] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '4';
                            vet[linha][coluna+1] = '4';
                            vet[linha][coluna-1] = '4';
                            vet[linha-1][coluna] = '4';     // Imprime as posições do espião 1 a partir da posição (x,y) inicializada.
                            vet[linha-2][coluna] = '4';
                            vet[linha-3][coluna] = '4';
                            espiao_2++;
                            printf("%d %c C %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;
            }
        }
        while(porta_avioes<PAMAX){ // Sortear porta-aviões aleatoriamente.

            linha = rand()%20; // Sortear linha.
            coluna = rand()%20; // Sortear coluna.
            virar = rand()%4; // Sortear a opção virar.

            switch(virar){
                case 0: // Opcão virado para direita.
                    if(coluna>15 || linha>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha][coluna+4] != '*' || vet[linha+1][coluna] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+1][coluna+2] != '*' || vet[linha+1][coluna+3] != '*' || vet[linha+1][coluna+4] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '5';
                            vet[linha][coluna+1] = '5';
                            vet[linha][coluna+2] = '5';
                            vet[linha][coluna+3] = '5';
                            vet[linha][coluna+4] = '5';
                            vet[linha+1][coluna] = '5';     // Imprime as posições do porta-aviões a partir da posição (x,y) inicializada.
                            vet[linha+1][coluna+1] = '5';
                            vet[linha+1][coluna+2] = '5';
                            vet[linha+1][coluna+3] = '5';
                            vet[linha+1][coluna+4] = '5';
                            porta_avioes++;
                            printf("%d %c D %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 1: // Opcão virado para baixo.
                    if(linha>15 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*' || vet[linha+4][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*' || vet[linha+4][coluna+1] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '5';
                            vet[linha+1][coluna] = '5';
                            vet[linha+2][coluna] = '5';
                            vet[linha+3][coluna] = '5';
                            vet[linha+4][coluna] = '5';
                            vet[linha][coluna+1] = '5';     // Imprime as posições do porta-aviões a partir da posição (x,y) inicializada.
                            vet[linha+1][coluna+1] = '5';
                            vet[linha+2][coluna+1] = '5';
                            vet[linha+3][coluna+1] = '5';
                            vet[linha+4][coluna+1] = '5';
                            porta_avioes++;
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 2: // Opcão virado para esquerda.
                    if(linha>18 || coluna<4){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha][coluna-1] != '*' || vet[linha][coluna-2] != '*' || vet[linha][coluna-3] != '*' || vet[linha][coluna-4] != '*' || vet[linha+1][coluna] != '*' || vet[linha+1][coluna-1] != '*' || vet[linha+1][coluna-2] != '*' || vet[linha+1][coluna-3] != '*' || vet[linha+1][coluna-4] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '5';
                            vet[linha][coluna-1] = '5';
                            vet[linha][coluna-2] = '5';
                            vet[linha][coluna-3] = '5';
                            vet[linha][coluna-4] = '5';
                            vet[linha+1][coluna] = '5';     // Imprime as posições do porta-aviões a partir da posição (x,y) inicializada.
                            vet[linha+1][coluna-1] = '5';
                            vet[linha+1][coluna-2] = '5';
                            vet[linha+1][coluna-3] = '5';
                            vet[linha+1][coluna-4] = '5';
                            porta_avioes++;
                            printf("%d %c E %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 3: // Opcão virado para cima.
                    if(linha<4 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
                    }
                    else{
                        if(vet[linha][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha-2][coluna] != '*' || vet[linha-3][coluna] != '*' || vet[linha-4][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*' || vet[linha-4][coluna+1] != '*'){ // Condição para impedir sobreposição.
                        }
                        else{
                            vet[linha][coluna] = '5';
                            vet[linha-1][coluna] = '5';
                            vet[linha-2][coluna] = '5';
                            vet[linha-3][coluna] = '5';
                            vet[linha-4][coluna] = '5';
                            vet[linha][coluna+1] = '5';     // Imprime as posições do porta-aviões a partir da posição (x,y) inicializada.
                            vet[linha-1][coluna+1] = '5';
                            vet[linha-2][coluna+1] = '5';
                            vet[linha-3][coluna+1] = '5';
                            vet[linha-4][coluna+1] = '5';
                            porta_avioes++;
                            printf("%d %c C %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;
            }
        }
    }
    void Jogar(char vet[TAM][TAM],char vet2[TAM][TAM]){ // Resolvedor.
        int linha,coluna,acerto = 0,erro = 0, jogadas = 0;
        int contador = (BOMAX * 1) + (AVMAX * 4) + (SUMAX * 4) + (E1MAX * 6) + (E2MAX * 6) + (PAMAX * 10); // Contador da quantidade e tamanho dos elementos.
        int guardar[TAM][TAM]; // Matriz de Cache
        char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'}; // Vetor usado para printar as letras acima da matriz.
        srand(time(NULL));

        for(int i=0; i<TAM; i++){
            for(int j=0; j<TAM; j++){
                guardar[i][j] = 0; // Inicializa a matriz de cache.
            }
        }
        do{
            do{
                linha = rand()%20;
                coluna = rand()%20;
             }while(guardar[linha][coluna]==1);  // Impedir o rand de sortear valores repetidos.
            guardar[linha][coluna] = 1; // Guarda os valores sorteador no cache, está aqui apenas por garantia.
            if(vet[linha][coluna]=='*'){ // Mar.
                jogadas++;
                //printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                vet[linha][coluna] = '#';
                guardar[linha][coluna] = 1;
                erro++;
                vet2[linha][coluna] = vet[linha][coluna];
                //PrintarMatriz(vet2);
                //printf("\n");
            }
            if(vet[linha][coluna]=='0'){ // Boia.
                jogadas++;
                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                guardar[linha][coluna] = 1;
                vet2[linha][coluna] = vet[linha][coluna];
                contador--;
                acerto++;
                PrintarMatriz(vet2);
                printf("\n");
            }
            if(vet[linha][coluna]=='1'){ // Avião.
                int AcertosPossiveis = 0; // Variável de controle.
                int ErrosPossiveis = 0; // Variável de controle.
                int TamanhoAviao = 0; // Variável de controle caso encontre 4 posições.
                jogadas++;
                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                guardar[linha][coluna] = 1; // Guarda o valor no cache.
                vet2[linha][coluna] = vet[linha][coluna];
                contador--;
                acerto++;
                TamanhoAviao++;
                PrintarMatriz(vet2);
                printf("\n");
                AcertosPossiveis++;
                for(int i=linha-2;i<=linha+2&&TamanhoAviao<4&&contador>0;i++){ // A partir daqui começa os testes de possíveis posições do avião. Começando verticalmente.
                    if(i<0 || i>=TAM){
                        ErrosPossiveis++;
                    }
                    if(i>=0 && i<TAM){
                        if(vet[i][coluna]=='1'){ // Posição encontrada.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                TamanhoAviao++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++; // Acerto somado, para quando acertar as 4 posições.
                            }
                        }
                        else if(vet[i][coluna]=='*'){ // Mar encontrado
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet[i][coluna] = '#';
                                vet2[i][coluna] = vet[i][coluna];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                            }
                        }
                        else if(vet[i][coluna]=='1'&&guardar[i][coluna]==1){
                            AcertosPossiveis++;
                        }
                        else if(vet[i][coluna]!='1'&&guardar[i][coluna]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do avião e mar.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Erro pois não está relacionado ao avião.
                            }
                        }
                    }
                    if(AcertosPossiveis==3||ErrosPossiveis==3){ // Condiçõe de parada, também evitando testes desnecessários.
                        break;
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==0){ // Testes de possíveis posições.
                    for(int i=linha-1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==1){ // Testes de possíveis posições.
                    for(int i=linha;i<=linha&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==2){ // Testes de possíveis posições.
                    for(int i=linha+1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==2&&ErrosPossiveis==3){ // Testes de possíveis posições.
                    for(int i=linha-1;i<=linha-1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else if(vet[i][j]!='1'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==4){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else if(vet[i][j]!='1'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==5){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                AcertosPossiveis = 1; // Reseta a variável acertos para os testes na horizontal.
                ErrosPossiveis = 0; // Reseta a variável erros para os testes na horizontal.
                for(int j=coluna-2;j<=coluna+2&&TamanhoAviao<4&&contador>0;j++){ // Agora buscando horizontalmente.
                    if(j<0 || j>=TAM){
                        ErrosPossiveis++;
                    }
                    if(j>=0 && j<TAM){
                        if(vet[linha][j]=='1'){
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                TamanhoAviao++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++;
                            }
                        }
                        else if(vet[linha][j]=='*'){
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet[linha][j] = '#';
                                vet2[linha][j] = vet[linha][j];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++;
                            }
                        }
                        else if(vet[linha][j]=='1'&&guardar[linha][j]==1){
                            AcertosPossiveis++;
                        }
                        else if(vet[linha][j]!='1'&&guardar[linha][j]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do avião e mar.
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++;
                            }
                        }
                    }
                    if(AcertosPossiveis==3){
                        break;
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==0){ // Testes de possíveis posições.
                    for(int i=linha-1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna-1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==1){ // Testes de possíveis posições.
                    for(int i=linha-1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna;j<=coluna&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==2){ // Testes de possíveis posições.
                    for(int i=linha-1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                        for(int j=coluna+1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==2&&ErrosPossiveis==3){ // Testes de possíveis posições.
                    for(int j=coluna-1;j<=coluna-1&&TamanhoAviao<4&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]=='1'&&guardar[i][j]==1){
                                    AcertosPossiveis++;
                                }
                                else if(vet[i][j]!='1'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do avião e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==4){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoAviao<4&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoAviao<4&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='1'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoAviao++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(vet[linha][coluna]=='2'){ // Submarino.
                int TamanhoSub = 0; // Variável de controle caso encontre 4 posições.
                int ErrosPossiveis = 0;
                jogadas++;
                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                guardar[linha][coluna] = 1;
                vet2[linha][coluna] = vet[linha][coluna];
                contador--;
                acerto++;
                TamanhoSub++;
                PrintarMatriz(vet2);
                printf("\n");
                for(int i=linha-3;i<=linha+3&&TamanhoSub<4&&contador>0;i++){
                    if(i<0 || i>=TAM){
                        ErrosPossiveis++;
                    }
                    if(i>=0 && i<TAM){
                        if(vet[i][coluna]=='2'){
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                TamanhoSub++;
                                PrintarMatriz(vet2);
                                printf("\n");
                            }
                        }
                        else if(vet[i][coluna]=='*'){
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet[i][coluna] = '#';
                                vet2[i][coluna] = vet[i][coluna];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++;

                            }
                        }
                        else if(vet[i][coluna]!='2'&&guardar[i][coluna]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do avião e mar.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++;
                            }
                        }
                    }
                    if(ErrosPossiveis==4){
                        break;
                    }
                }
                for(int j=coluna-3;j<=coluna+3&&TamanhoSub<4&&contador>0;j++){
                    if(j<0 || j>=TAM){
                        ErrosPossiveis++;
                    }
                    if(j>=0 && j<TAM){
                        if(vet[linha][j]=='2'){
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                TamanhoSub++;
                                PrintarMatriz(vet2);
                                printf("\n");
                            }
                        }
                        else if(vet[linha][j]=='*'){
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet[linha][j] = '#';
                                vet2[linha][j] = vet[linha][j];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                            }
                        }
                        else{
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                            }
                        }
                    }
                }
            }
            if(vet[linha][coluna]=='3'){ // Espião 1.
                int TamanhoEspiao1 = 0;
                int AcertosPossiveis = 0;
                int ErrosPossiveis = 0;
                jogadas++;
                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                guardar[linha][coluna] = 1;
                vet2[linha][coluna] = vet[linha][coluna];
                contador--;
                acerto++;
                TamanhoEspiao1++;
                PrintarMatriz(vet2);
                printf("\n");
                AcertosPossiveis++;
                for(int i=linha-3;i<=linha+3&&TamanhoEspiao1<6&&contador>0;i++){ // Vertical.
                    if(i<0 || i>=TAM){
                        ErrosPossiveis++;
                    }
                    if(i>=0 && i<TAM){
                        if(vet[i][coluna]=='3'){
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                TamanhoEspiao1++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++;
                            }
                        }
                        else if(vet[i][coluna]=='*'){ // Mar encontrado
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet[i][coluna] = '#';
                                vet2[i][coluna] = vet[i][coluna];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                            }
                        }
                        else if(vet[i][coluna]!='3'&&guardar[i][coluna]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do espião 1 e mar.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Erro pois não está relacionado ao espião 1.
                            }
                        }
                    }
                    if(AcertosPossiveis==4){
                        break;
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==0){
                    for(int i=linha-3;i<=linha-3&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(vet[linha-3][coluna+1]!='3'&&guardar[linha-3][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==1){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==1){
                    for(int i=linha-2;i<=linha-2&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(vet[linha-2][coluna+1]!='3'&&guardar[linha-2][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==2){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==2){
                    for(int i=linha-1;i<=linha-1&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(vet[linha-1][coluna+1]!='3'&&guardar[linha-1][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==3){
                                break;
                            }
                        }
                    }
                    for(int i=linha+2;i<=linha+2&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==3){
                    for(int i=linha;i<=linha&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(vet[linha][coluna+1]!='3'&&guardar[linha][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==4){
                                break;
                            }
                        }
                    }
                    for(int i=linha+3;i<=linha+3&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==4){
                    for(int i=linha-1;i<=linha-1&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-3;j<=coluna&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==5){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-3;j<=coluna&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==6){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna-3;j<=coluna&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==7){
                                break;
                            }
                        }
                    }
                    for(int i=linha-1;i<=linha-1&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna+1;j<=coluna+3&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==8){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna+1;j<=coluna+3&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==9){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                        for(int j=coluna+1;j<=coluna+3&&TamanhoEspiao1<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                AcertosPossiveis=1; // Reseta a variável acertos para os testes na horizontal.
                ErrosPossiveis=0; // Reseta a variável erros para os testes na horizontal.
                for(int j=coluna-3;j<=coluna+3&&TamanhoEspiao1<6&&contador>0;j++){ // Horizontal.
                    if(j<0 || j>=TAM){
                        ErrosPossiveis++;
                    }
                    if(j>=0 && j<TAM){
                        if(vet[linha][j]=='3'){
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                TamanhoEspiao1++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++;
                            }
                        }
                        else if(vet[linha][j]=='*'){ // Mar encontrado
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet[linha][j] = '#';
                                vet2[linha][j] = vet[linha][j];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                            }
                        }
                        else if(vet[linha][j]!='3'&&guardar[linha][j]==1){
                                    ErrosPossiveis++;
                                }
                        else{ // Qualquer outro elemento diferente do espião 1 e mar.
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Erro pois não está relacionado ao espião 1.
                            }
                        }
                    }
                    if(AcertosPossiveis==4){
                        break;
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==0){
                    for(int j=coluna-3;j<=coluna-3&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==1){
                    for(int j=coluna-2;j<=coluna-2&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==2){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==2){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==3){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+2;j<=coluna+2&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==3){
                    for(int j=coluna+3;j<=coluna+3&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==4){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-3;i<=linha&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i<0 || i>=TAM || j<0 || j>=TAM){
                                ErrosPossiveis++;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==5){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha-3;i<=linha&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==6){
                                break;
                            }
                        }
                    }
                    for(int j=coluna-1;j<=coluna-1&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha;i<=linha+3&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='3'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==7){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoEspiao1<6&&contador>0;j++){
                        for(int i=linha;i<=linha+3&&TamanhoEspiao1<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao1++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else{ // Qualquer outro elemento diferente do espião 1 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(vet[linha][coluna]=='4'){ // Espião 2.
                int TamanhoEspiao2 = 0;
                int AcertosPossiveis = 0;
                int ErrosPossiveis = 0;
                jogadas++;
                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                guardar[linha][coluna] = 1;
                vet2[linha][coluna] = vet[linha][coluna];
                contador--;
                acerto++;
                TamanhoEspiao2++;
                PrintarMatriz(vet2);
                printf("\n");
                AcertosPossiveis++;
                for(int i=linha-3;i<=linha+3&&TamanhoEspiao2<6&&contador>0;i++){ // Vertical.
                    if(i<0 || i>=TAM){
                        ErrosPossiveis++;
                    }
                    if(i>=0 && i<TAM){
                        if(vet[i][coluna]=='4'){
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                TamanhoEspiao2++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++;
                            }
                        }
                        else if(vet[i][coluna]=='*'){ // Mar encontrado
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet[i][coluna] = '#';
                                vet2[i][coluna] = vet[i][coluna];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                            }
                        }
                        else if(vet[i][coluna]!='4'&&guardar[i][coluna]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do espião 2 e mar.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Erro pois não está relacionado ao espião 2.
                            }
                        }
                    }
                    if(AcertosPossiveis==4){
                        break;
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==0){
                    for(int i=linha-3;i<=linha-3&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(vet[linha-3][coluna+1]!='4'&&guardar[linha-3][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==1){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(vet[linha-2][coluna+1]!='4'&&guardar[linha-2][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='3'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==1){
                    for(int i=linha-2;i<=linha-2&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(vet[linha-1][coluna+1]!='4'&&guardar[linha-1][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==2){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==2){
                    for(int i=linha-1;i<=linha-1&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(vet[linha-1][coluna+1]!='3'&&guardar[linha-1][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==3){
                                break;
                            }
                        }
                    }
                    for(int i=linha+2;i<=linha+2&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==3){
                    for(int i=linha;i<=linha&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(vet[linha][coluna+1]!='4'&&guardar[linha][coluna+1]==1){
                                break;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==4){
                                break;
                            }
                        }
                    }
                    for(int i=linha+3;i<=linha+3&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==4){
                    for(int i=linha-1;i<=linha-1&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-3;j<=coluna&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==5){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-3;j<=coluna&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==6){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna-3;j<=coluna&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==7){
                                break;
                            }
                        }
                    }
                    for(int i=linha-1;i<=linha-1&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna;j<=coluna+3&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==8){
                                break;
                            }
                        }
                    }
                    for(int i=linha;i<=linha&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna;j<=coluna+3&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==9){
                                break;
                            }
                        }
                    }
                    for(int i=linha+1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                        for(int j=coluna;j<=coluna+3&&TamanhoEspiao2<6&&contador>0;j++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                AcertosPossiveis=1; // Reseta a variável acertos para os testes na horizontal.
                ErrosPossiveis=0; // Reseta a variável erros para os testes na horizontal.
                for(int j=coluna-3;j<=coluna+3&&TamanhoEspiao2<6&&contador>0;j++){ // Horizontal.
                    if(j<0 || j>=TAM){
                        ErrosPossiveis++;
                    }
                    if(j>=0 && j<TAM){
                        if(vet[linha][j]=='4'){
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                TamanhoEspiao2++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++;
                            }
                        }
                        else if(vet[linha][j]=='*'){ // Mar encontrado
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet[linha][j] = '#';
                                vet2[linha][j] = vet[linha][j];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                            }
                        }
                        else if(vet[linha][j]!='4'&&guardar[linha][j]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do espião 2 e mar.
                            if(guardar[linha][j]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                guardar[linha][j] = 1;
                                vet2[linha][j] = vet[linha][j];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Erro pois não está relacionado ao espião 2.
                            }
                        }
                    }
                    if(AcertosPossiveis==4){
                        break;
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==0){
                    for(int j=coluna-3;j<=coluna-3&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==1){
                    for(int j=coluna-2;j<=coluna-2&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==2){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==2){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==3){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+2;j<=coluna+2&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==4&&ErrosPossiveis==3){
                    for(int j=coluna+3;j<=coluna+3&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-1;i<=linha+1&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==3&&ErrosPossiveis==4){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-3;i<=linha&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i<0 || i>=TAM || j<0 || j>=TAM){
                                ErrosPossiveis++;
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==5){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha-3;i<=linha&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==6){
                                break;
                            }
                        }
                    }
                    for(int j=coluna-1;j<=coluna-1&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha;i<=linha+3&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='4'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==7){
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoEspiao2<6&&contador>0;j++){
                        for(int i=linha;i<=linha+3&&TamanhoEspiao2<6&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='4'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoEspiao2++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else{ // Qualquer outro elemento diferente do espião 2 e mar.
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(vet[linha][coluna]=='5'){ // Porta-Aviões.
                int TamanhoPortaAvioes = 0;
                int AcertosPossiveis = 0;
                int ErrosPossiveis = 0;
                jogadas++;
                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[coluna],vet[linha][coluna]);
                guardar[linha][coluna] = 1;
                vet2[linha][coluna] = vet[linha][coluna];
                contador--;
                acerto++;
                TamanhoPortaAvioes++;
                PrintarMatriz(vet2);
                printf("\n");
                AcertosPossiveis++;
                for(int i=linha-4;i<=linha+4&&TamanhoPortaAvioes<10&&contador>0;i++){ // A partir daqui começa os testes de possíveis posições do avião. Começando verticalmente.
                    if(i<0 || i>=TAM){
                        ErrosPossiveis++;
                    }
                    if(i>=0 && i<TAM){
                        if(vet[i][coluna]=='5'){ // Posição encontrada.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                TamanhoPortaAvioes++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                AcertosPossiveis++;
                            }
                        }
                        else if(vet[i][coluna]=='*'){ // Mar encontrado
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet[i][coluna] = '#';
                                vet2[i][coluna] = vet[i][coluna];
                                erro++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                            }
                        }
                        else if(vet[i][coluna]!='5'&&guardar[i][coluna]==1){
                            ErrosPossiveis++;
                        }
                        else{ // Qualquer outro elemento diferente do porta-aviões e mar.
                            if(guardar[i][coluna]==0){
                                jogadas++;
                                printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[coluna],vet[i][coluna]);
                                guardar[i][coluna] = 1;
                                vet2[i][coluna] = vet[i][coluna];
                                contador--;
                                acerto++;
                                PrintarMatriz(vet2);
                                printf("\n");
                                ErrosPossiveis++; // Erro pois não está relacionado ao porta-aviões.
                            }
                        }
                    }
                    if(AcertosPossiveis==5||ErrosPossiveis==5){
                        break;
                    }
                }
                if(AcertosPossiveis==5&&ErrosPossiveis==0){ // Caso ele encontre verticalmente.
                    for(int j=coluna-1;j<=coluna-1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Começa testando na coluna da esquerda.
                        for(int i=linha-4;i<=linha&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(guardar[linha][coluna-1]==1&&vet[linha][coluna-1]!='5'||guardar[linha-1][coluna-1]==1&&vet[linha-1][coluna-1]!='5'||
                               guardar[linha-2][coluna-1]==1&&vet[linha-2][coluna-1]!='5'||guardar[linha-3][coluna-1]==1&&vet[linha-3][coluna-1]!='5'||
                               guardar[linha-4][coluna-1]==1&&vet[linha-4][coluna-1]!='5'){
                                break; // Aqui ele testa se em alguma posição adjacente à esquerda possui um valor já encontrado diferente de 5.
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==1){ // Evitar testes desnecessários.
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                        for(int i=linha-4;i<=linha&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==5&&ErrosPossiveis==1){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Começa testando na coluna da esquerda.
                        for(int i=linha-3;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(guardar[linha][coluna-1]==1&&vet[linha][coluna-1]!='5'||guardar[linha+1][coluna-1]==1&&vet[linha+1][coluna-1]!='5'||
                               guardar[linha-3][coluna-1]==1&&vet[linha-3][coluna-1]!='5'||guardar[linha-2][coluna-1]==1&&vet[linha-2][coluna-1]!='5'||
                               guardar[linha-1][coluna-1]==1&&vet[linha-1][coluna-1]!='5'){
                                break; // Aqui ele testa se em alguma posição adjacente à esquerda possui um valor já encontrado diferente de 5.
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==2){ // Evitar testes desnecessários.
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                        for(int i=linha-3;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==5&&ErrosPossiveis==2){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Começa testando na coluna da esquerda.
                        for(int i=linha-2;i<=linha+2&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(guardar[linha][coluna-1]==1&&vet[linha][coluna-1]!='5'||guardar[linha+1][coluna-1]==1&&vet[linha+1][coluna-1]!='5'||
                               guardar[linha+2][coluna-1]==1&&vet[linha+2][coluna-1]!='5'||guardar[linha-1][coluna-1]==1&&vet[linha-1][coluna-1]!='5'||
                               guardar[linha-2][coluna-1]==1&&vet[linha-2][coluna-1]!='5'){
                                break; // Aqui ele testa se em alguma posição adjacente à esquerda possui um valor já encontrado diferente de 5.
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==3){ // Evitar testes desnecessários.
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                        for(int i=linha-2;i<=linha+2&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==5&&ErrosPossiveis==3){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Começa testando na coluna da esquerda.
                        for(int i=linha-1;i<=linha+3&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(guardar[linha][coluna-1]==1&&vet[linha][coluna-1]!='5'||guardar[linha-1][coluna-1]==1&&vet[linha-1][coluna-1]!='5'||
                               guardar[linha+1][coluna-1]==1&&vet[linha+1][coluna-1]!='5'||guardar[linha+2][coluna-1]==1&&vet[linha+2][coluna-1]!='5'||
                               guardar[linha+3][coluna-1]==1&&vet[linha+3 ][coluna-1]!='5'){
                                break; // Aqui ele testa se em alguma posição adjacente à esquerda possui um valor já encontrado diferente de 5.
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==4){ // Evitar testes desnecessários.
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                        for(int i=linha-1;i<=linha+3&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==5&&ErrosPossiveis==4){
                    for(int j=coluna-1;j<=coluna-1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Começa testando na coluna da esquerda.
                        for(int i=linha;i<=linha+4&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(guardar[linha][coluna-1]==1&&vet[linha][coluna-1]!='5'||guardar[linha+1][coluna-1]==1&&vet[linha+1][coluna-1]!='5'||
                               guardar[linha+2][coluna-1]==1&&vet[linha+2][coluna-1]!='5'||guardar[linha+3][coluna-1]==1&&vet[linha+3][coluna-1]!='5'||
                               guardar[linha+4][coluna-1]==1&&vet[linha+4][coluna-1]!='5'){
                                break; // Aqui ele testa se em alguma posição adjacente à esquerda possui um valor já encontrado diferente de 5.
                            }
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                                else if(vet[i][j]=='*'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet[i][j] = '#';
                                        vet2[i][j] = vet[i][j];
                                        erro++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                                else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                    ErrosPossiveis++;
                                }
                                else{
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                        ErrosPossiveis++;
                                    }
                                }
                            }
                            if(ErrosPossiveis==5){ // Evitar testes desnecessários.
                                break;
                            }
                        }
                    }
                    for(int j=coluna+1;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                        for(int i=linha;i<=linha+4&&TamanhoPortaAvioes<10&&contador>0;i++){
                            if(i>=0 && i<TAM && j>=0 && j<TAM){
                                if(vet[i][j]=='5'){
                                    if(guardar[i][j]==0){
                                        jogadas++;
                                        printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                        guardar[i][j] = 1;
                                        vet2[i][j] = vet[i][j];
                                        contador--;
                                        acerto++;
                                        TamanhoPortaAvioes++;
                                        PrintarMatriz(vet2);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
                if(AcertosPossiveis==2&&ErrosPossiveis==5){ // Testes para posição na horizontal.
                    AcertosPossiveis=1; // Reseta a variável acertos para os testes na horizontal.
                    ErrosPossiveis=0; // Reseta a variável erros para os testes na horizontal.
                    for(int j=coluna-4;j<=coluna+4&&TamanhoPortaAvioes<10&&contador>0;j++){
                        if(j<0 || j>=TAM){
                            ErrosPossiveis++;
                        }
                        if(j>=0 && j<TAM){
                            if(vet[linha][j]=='5'){ // Posição encontrada.
                                if(guardar[linha][j]==0){
                                    jogadas++;
                                    printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                    guardar[linha][j] = 1;
                                    vet2[linha][j] = vet[linha][j];
                                    contador--;
                                    acerto++;
                                    TamanhoPortaAvioes++;
                                    PrintarMatriz(vet2);
                                    printf("\n");
                                    AcertosPossiveis++;
                                }
                            }
                            else if(vet[linha][j]=='*'){ // Mar encontrado
                                if(guardar[linha][j]==0){
                                    jogadas++;
                                    printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                    guardar[linha][j] = 1;
                                    vet[linha][j] = '#';
                                    vet2[linha][j] = vet[linha][j];
                                    erro++;
                                    PrintarMatriz(vet2);
                                    printf("\n");
                                    ErrosPossiveis++; // Variável de controle para evitar testes desnecessários.
                                }
                            }
                            else if(vet[linha][j]!='5'&&guardar[linha][j]==1){
                                ErrosPossiveis++;
                            }
                            else{ // Qualquer outro elemento diferente do porta-aviões e mar.
                                if(guardar[linha][j]==0){
                                    jogadas++;
                                    printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,linha,letra[j],vet[linha][j]);
                                    guardar[linha][j] = 1;
                                    vet2[linha][j] = vet[linha][j];
                                    contador--;
                                    acerto++;
                                    PrintarMatriz(vet2);
                                    printf("\n");
                                    ErrosPossiveis++; // Erro pois não está relacionado ao porta-aviões.
                                }
                            }
                        }
                        if(AcertosPossiveis==5){
                            break;
                        }
                    }
                    if(AcertosPossiveis==5&&ErrosPossiveis==0){  // Mesma lógica usada para os testes anteriores na vertical.
                        for(int i=linha-1;i<=linha-1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna;j>=coluna-4&&TamanhoPortaAvioes<10&&contador>0;j--){
                                if(vet[linha-1][coluna]!='5'){
                                    break;;
                                }
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                    else if(vet[i][j]=='*'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet[i][j] = '#';
                                            vet2[i][j] = vet[i][j];
                                            erro++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                    else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                        ErrosPossiveis++;
                                    }
                                    else{
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                }
                                if(ErrosPossiveis==1){ // Evitar testes desnecessários.
                                    break;
                                }
                            }
                        }
                        for(int i=linha+1;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna;j>=coluna-4&&TamanhoPortaAvioes<10&&contador>0;j--){ // Testa na coluna da direita caso não encontre na outra.
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(AcertosPossiveis==5&&ErrosPossiveis==1){ // Mesma lógica usada para os testes anteriores na vertical.
                        for(int i=linha-1;i<=linha-1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna-3;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){
                                if(vet[linha-1][coluna]!='5'){
                                    break;;
                                }
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                    else if(vet[i][j]=='*'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet[i][j] = '#';
                                            vet2[i][j] = vet[i][j];
                                            erro++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                    else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                        ErrosPossiveis++;
                                    }
                                    else{
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                }
                                if(ErrosPossiveis==2){ // Evitar testes desnecessários.
                                    break;
                                }
                            }
                        }
                        for(int i=linha+1;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna-3;j<=coluna+1&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(AcertosPossiveis==5&&ErrosPossiveis==2){ // Mesma lógica usada para os testes anteriores na vertical.
                        for(int i=linha-1;i<=linha-1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna-2;j<=coluna+2&&TamanhoPortaAvioes<10&&contador>0;j++){
                                if(vet[linha-1][coluna]!='5'){
                                    break;;
                                }
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                    else if(vet[i][j]=='*'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet[i][j] = '#';
                                            vet2[i][j] = vet[i][j];
                                            erro++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                    else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                        ErrosPossiveis++;
                                    }
                                    else{
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                }
                                if(ErrosPossiveis==3){ // Evitar testes desnecessários.
                                    break;
                                }
                            }
                        }
                        for(int i=linha+1;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna-2;j<=coluna+2&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(AcertosPossiveis==5&&ErrosPossiveis==3){ // Mesma lógica usada para os testes anteriores na vertical.
                        for(int i=linha-1;i<=linha-1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna-1;j<=coluna+3&&TamanhoPortaAvioes<10&&contador>0;j++){
                                if(vet[linha-1][coluna]!='5'){
                                    break;;
                                }
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                    else if(vet[i][j]=='*'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet[i][j] = '#';
                                            vet2[i][j] = vet[i][j];
                                            erro++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                    else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                        ErrosPossiveis++;
                                    }
                                    else{
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                }
                                if(ErrosPossiveis==4){ // Evitar testes desnecessários.
                                    break;
                                }
                            }
                        }
                        for(int i=linha+1;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna-1;j<=coluna+3&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(AcertosPossiveis==5&&ErrosPossiveis==4){ // Mesma lógica usada para os testes anteriores na vertical.
                        for(int i=linha-1;i<=linha-1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna;j<=coluna+4&&TamanhoPortaAvioes<10&&contador>0;j++){
                                if(vet[linha-1][coluna]!='5'){
                                    break;;
                                }
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                    else if(vet[i][j]=='*'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet[i][j] = '#';
                                            vet2[i][j] = vet[i][j];
                                            erro++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                    else if(vet[i][j]!='5'&&guardar[i][j]==1){
                                        ErrosPossiveis++;
                                    }
                                    else{
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                            ErrosPossiveis++;
                                        }
                                    }
                                }
                                if(ErrosPossiveis==5){ // Evitar testes desnecessários.
                                    break;
                                }
                            }
                        }
                        for(int i=linha+1;i<=linha+1&&TamanhoPortaAvioes<10&&contador>0;i++){
                            for(int j=coluna;j<=coluna+4&&TamanhoPortaAvioes<10&&contador>0;j++){ // Testa na coluna da direita caso não encontre na outra.
                                if(i>=0 && i<TAM && j>=0 && j<TAM){
                                    if(vet[i][j]=='5'){
                                        if(guardar[i][j]==0){
                                            jogadas++;
                                            printf("Jogada [%d] - Linha [%d] Coluna [%c] Alvo [%c]\n",jogadas,i,letra[j],vet[i][j]);
                                            guardar[i][j] = 1;
                                            vet2[i][j] = vet[i][j];
                                            contador--;
                                            acerto++;
                                            TamanhoPortaAvioes++;
                                            PrintarMatriz(vet2);
                                            printf("\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }while(contador>0);
        printf("Acertos: %d\n",acerto);
        printf("Erros: %d\n",erro);
        printf("Jogadas: %d\n",jogadas);
    }
    int main(){

        char vet[TAM][TAM];
        char vet2[TAM][TAM];
        int jogar_novamente;

        do{
            InicializarMatriz(vet,vet2);
            SortearMatriz(vet);
            printf("\n");
            PrintarMatriz(vet);
            printf("\n");
            printf("           [Tabuleiro Ocultado]\n");
            PrintarMatriz(vet2);
            printf("\n");
            Jogar(vet,vet2);
            printf("\n");
            PrintarMatriz(vet2);
            printf("\n");
            printf("[1] Jogar novamente.\n");
            scanf("%d",&jogar_novamente);
        }while(jogar_novamente==1);

        return 0;
    }
