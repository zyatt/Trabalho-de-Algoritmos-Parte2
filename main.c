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

    void InicializarMatriz(char vet[TAM][TAM]){ // Inicializa a matriz com todas as posições como '*'.
        for(int i=0; i<TAM; i++){
            for(int j = 0; j<TAM; j++){
                vet[i][j] = '*';
            }
        }
    }
    void EsconderMatriz(char vet2[TAM][TAM]){ // Esconde a matriz.
        for(int i=0; i<TAM; i++){
            for(int j=0; j<TAM; j++){
                vet2[i][j] = '*';
            }
        }
    }
    void PrintarMatriz(char vet[TAM][TAM]){ // Printa a matriz
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
        int contador = (BOMAX * 1) + (AVMAX * 4) + (SUMAX * 4) + (E1MAX * 6) + (E2MAX * 6) + (PAMAX * 10); // Contador dos elementos
        char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
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

        while(aviao<AVMAX){ // Sortear aviões aleatoriamente
            linha = rand()%20;// Sortear linha
            coluna = rand()%20; // Sortear coluna
            virar = (rand()%4) + 1; // Sortear a opção virar

            switch(virar){ // switch case para rotação do elemento.
                case 1: // Opção virado para a direita.
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

                case 2: // Opção virado para a esquerda.
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

                case 3: // Opção virado para cima
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

                case 4: // Opção virado para baixo
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

        while(submarino<SUMAX){ // Sortear submarinos aleatoriamente
            linha = rand()%20; // Sortear linha
            coluna = rand()%20; // Sortear coluna
            virar = (rand()%2) + 1; // Sortear a opção virar

            switch(virar){
                case 1: // Opcão horizontal
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

                case 2: // Opcão vertical
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
            }
        }

        while(espiao_1<E1MAX){ // Sortear espião 1 aleatoriamente
            linha = rand()%20;// Sortear linha
            coluna = rand()%20; // Sortear coluna
            virar = (rand()%4) + 1; // Sortear a opção virar

            switch(virar){ // switch case da opção virar que rotaciona o elemento.
                case 1: // Opção virado para direita
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

                case 2: // Opção virado para a esquerda.
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

                case 3: // Opção virado para baixo.
                    if(coluna<1|| linha>16 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
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
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 4: // Opção virado para cima
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

        while(espiao_2<E2MAX){ // Sortear espião 1 aleatoriamente
            linha = rand()%20;// Sortear linha
            coluna = rand()%20; // Sortear coluna
            virar = (rand()%4) + 1; // Sortear a opção virar

            switch(virar){ // switch case da opção virar que rotaciona o elemento.
                case 1: // Opção virado para direita
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

                case 2: // Opção virado para a esquerda.
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

                case 3: // Opção virado para baixo.
                    if(coluna<1|| linha>16 || coluna>18){ // Condição que lê se o elemento pode ser impresso inteiramente na matriz.
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
                            printf("%d %c B %c\n",linha,letra[coluna],vet[linha][coluna]);
                        }
                    }
                break;

                case 4: // Opção virado para cima
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

        while(porta_avioes<PAMAX){ // Sortear porta-aviões aleatoriamente
            linha = rand()%20; // Sortear linha
            coluna = rand()%20; // Sortear coluna
            virar = (rand()%2) + 1; // Sortear a opção virar

            switch(virar){
                case 1: // Opcão horizontal.
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

                case 2: // Opcão vertical.
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
            }
        }
    }
    void Jogar(char vet[TAM][TAM]){ // Resolvedor.
        int linha,coluna;
        int contador = (BOMAX * 1) + (AVMAX * 4) + (SUMAX * 4) + (E1MAX * 6) + (E2MAX * 6) + (PAMAX * 10); // Contador dos elementos
        srand(time(NULL));

        while(contador>0){
            linha = rand()%20; // Sortear linha
            coluna = rand()%20; // Sortear coluna

            if(vet[linha][coluna]=='0'){
                vet[linha][coluna] = '0';
                contador--;
            }
            else if(vet[linha][coluna]=='1'){
                vet[linha][coluna] = '1';
                contador--;
            }
            else if(vet[linha][coluna]=='2'){
                vet[linha][coluna] = '2';
                contador--;
            }
            else if(vet[linha][coluna]=='3'){
                vet[linha][coluna] = '3';
                contador--;
            }
            else if(vet[linha][coluna]=='4'){
                vet[linha][coluna] = '4';
                contador--;
            }
            else if(vet[linha][coluna]=='5'){
                vet[linha][coluna] = '5';
                contador--;
            }
            else if(vet[linha][coluna]=='*'){ // Caso o usuário não acerte nenhuma embarcação, imprime um X na posição.
                vet[linha][coluna] = '#';
            }
            else{
            }
        }
    }

    int main(){

        char vet[TAM][TAM];
        char vet2[TAM][TAM];

        int jogar,sortear,esconder;

        InicializarMatriz(vet);
        PrintarMatriz(vet);

        printf("\n");
        printf("[1] Sortear\n");
        scanf("%d",&sortear);

        if(sortear==1){
            system("cls");
            SortearMatriz(vet);
            PrintarMatriz(vet);
        }

        printf("\n");
        printf("[1] Esconder o tabuleiro\n");
        scanf("%d",&esconder);

        if(esconder==1){
            system("cls");
            EsconderMatriz(vet2);
            PrintarMatriz(vet2);

        }

        printf("\n");
        printf("[1] Jogar\n");
        scanf("%d",&jogar);

        if(jogar==1){
            system("cls");
            Jogar(vet);
            PrintarMatriz(vet);
        }

        return 0;
    }
