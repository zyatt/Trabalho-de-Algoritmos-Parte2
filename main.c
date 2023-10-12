#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20 // Valor definido para o total de linhas e colunas.
#define BOMAX 10
#define AVMAX 5
#define SUMAX 5   // Valores para teste (Aumentar para 10,5,5,4,4,2 respectivamente).
#define E1MAX 4
#define E2MAX 4
#define PAMAX 2

int main()
{
    /// Trabalho (parte 2) da disciplina de algoritmos.
    /// Tentei comentar o m�ximo que deu, se n�o estiver comentado foi porque esqueci ou n�o achei necess�rio.
    /// Adicionei coisas a mais no c�digo, mas os requerimentos foram cumpridos.
    /// A inicializa��o dos elementos de forma manual pode parecer um pouco complicada a princ�pio (Recomendado ver as instru��es). Tentei explicar como fazer, recomendo printar no centro da matriz para testar.

    int menu,voltar_sair,finalizar,opcao,virar,voltar_sair2 = 0,jogar_novamente = 0, contador = 0;
    char matriz_menu[TAM][TAM]; // Matriz usada nas instru��es.
    char vet[TAM][TAM];
    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'}; // Usado para indicar a coluna.
    int i,j,k,l,m;
    int linha;   // Adicionei as vari�veis 'linha' e 'coluna' pra n�o ter conflito com a 'i' e 'j'.
    char coluna;
    int boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0; // Variav�l de cada elemento.
    srand(time(NULL));
    contador = (BOMAX * 1) + (AVMAX * 4) + (SUMAX * 4) + (E1MAX * 6) + (E2MAX * 6) + (PAMAX * 10); // Contador feito para a parte 2 do trabalho (

    do{
        do{
            printf("Bem vindo!\n\n");
            printf("Trabalho de Algoritmos.\nBatalha Naval.\n\n");  // Menu.
            printf("------------------\n");
            printf("[1] Jogar\n");
            printf("[2] Instrucoes (Recomendado)\n"); // Menu de instru��es. Feito apenas por divers�o :)
            printf("[3] Sair\n------------------\n");
            printf("Feito por Matheus Vinicius.\n\n");
            scanf("%d",&menu);
            system("cls"); // Limpa o console
        }while(menu<1 || menu>3);

        switch(menu){

            case 1:
                for(i=0; i<TAM; i++){
                    for(j = 0; j<TAM; j++){  // Inicializa a matriz com todas as posi��es como '*'.
                        vet[i][j] = '*';
                    }
                }
                do{ // Loop principal
                    voltar_sair2=0;
                    voltar_sair=0;

                    l = 0;
                    k = 65;
                    printf("   ");

                    while(k<=84){
                        printf("%c ",k); // Imprime a primeira linha com letras de A-T (com uso da tabela ASCII) para identifica��o de cada posi��o y. (Poderia ter usado o vetor 'letra' mas decidi manter assim).
                        k++;
                    }
                    printf("\n");

                    for(i=0; i<TAM; i++){
                        if(l<10){
                            printf(" ");
                        }
                        printf("%d",l);
                        l++; // Imprime a primeira coluna com n�meros de 0-19 para identifica��o de cada posi��o x.

                        for(j=0; j<TAM; j++){
                            printf(" ");            // Imprime a matriz.
                            printf("%c",vet[i][j]);
                            }
                    printf("\n");
                    }
                    if(boia == BOMAX && aviao == AVMAX && submarino == SUMAX && espiao_1 == E1MAX && espiao_2 == E2MAX && porta_avioes == PAMAX){ // Condi��o de parada do loop.
                        printf("\n");
                        printf("A Frota maritima foi posicinada com sucesso!\n\n");
                        printf("Escolha uma das opcoes:\n");
                        printf("[1] Jogar\n");
                        printf("[2] Reiniciar o jogo\n");
                        printf("[3] Sair\n");
                        do{
                            scanf("%d",&jogar_novamente);
                            if(jogar_novamente<1 || jogar_novamente>3){
                                printf("\n");
                                printf("Opcao invalida. Tente novamente.\n");
                            }
                        }while(jogar_novamente<1 || jogar_novamente>3);
                        system("cls");
                        do{
                            if(jogar_novamente==1){ // Opc�o Jogar ap�s o usu�rio aleatorizar as embarca��es.
                                l=0;
                                k = 65;
                                printf("   ");
                                while(k<=84){
                                    printf("%c ",k); // Imprime a primeira linha com letras de A-T (com uso da tabela ASCII) para identifica��o de cada posi��o y. (Poderia ter usado o vetor 'letra' mas decidi manter assim).
                                    k++;
                                }
                                printf("\n");
                                for(i=0; i<TAM; i++){
                                    if(l<10){
                                        printf(" ");
                                    }
                                    printf("%d",l);
                                    l++; // Imprime a primeira coluna com n�meros de 0-19 para identifica��o de cada posi��o x.
                                    for(j=0; j<TAM; j++){
                                        printf(" ");            // Imprime a matriz.
                                        printf("%c",vet[i][j]);
                                    }
                                    printf("\n");
                                }
                                if(contador==0){ // Quando o usu�rio acertar todas as posi��es que possuem elementos o jogo termina.
                                    printf("\n");
                                    printf("Voce acertou todas as embarcacoes!\n\n");
                                    break;
                                }
                                printf("\n");
                                printf("Escolha uma linha e coluna:\n");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){  // Convers�o dos valores do vetor letra para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                    printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                }
                                else if(vet[linha][coluna]=='0'){
                                   printf("Voce acertou uma Boia!\n\n"); // Se tiver uma boia na posi��o, troca por 'O' e diminui o contador.
                                    vet[linha][coluna] = 'O';
                                    contador--;
                                }
                                else if(vet[linha][coluna]=='1'){
                                   printf("Voce acertou um Aviao!\n\n"); // Se tiver um avi�o na posi��o, troca por 'O' e diminui o contador.
                                    vet[linha][coluna] = 'O';
                                    contador--;
                                }
                                else if(vet[linha][coluna]=='2'){
                                   printf("Voce acertou um Submarino!\n\n"); // Se tiver um submarino na posi��o, troca por 'O' e diminui o contador.
                                    vet[linha][coluna] = 'O';
                                    contador--;
                                }
                                else if(vet[linha][coluna]=='3'){
                                   printf("Voce acertou um Espiao 1!\n\n"); // Se tiver um espi�o 1 na posi��o, troca por 'O' e diminui o contador.
                                    vet[linha][coluna] = 'O';
                                    contador--;
                                }
                                else if(vet[linha][coluna]=='4'){
                                   printf("Voce acertou um Espiao 2!\n\n"); // Se tiver um espi�o 2 na posi��o, troca por 'O' e diminui o contador.
                                    vet[linha][coluna] = 'O';
                                    contador--;
                                }
                                else if(vet[linha][coluna]=='5'){
                                   printf("Voce acertou um Porta-aviao!\n\n"); // Se tiver um porta-avi�o na posi��o, troca por 'O' e diminui o contador.
                                    vet[linha][coluna] = 'O';
                                    contador--;
                                }
                                else if(vet[linha][coluna]=='*'){ // Caso o usu�rio n�o acerte nenhuma embarca��o, imprime um X na posi��o.
                                    printf("Errou!\n\n");
                                    vet[linha][coluna] = 'X';
                                }
                                else{
                                    printf("Posicao ja escolhida.\n\n"); // Para impedir que o usu�rio escolha uma posi��o 'O' ou 'X'.
                                }
                            }
                        }while(jogar_novamente==1);

                            if(jogar_novamente==2){
                                voltar_sair=1;       // Aqui todas as vari�veis resetam para que o jogo recomece.
                                voltar_sair2=1;
                                boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0;
                                break;
                            }
                            else{
                                printf("Obrigado por jogar!\n");
                                return 0;
                            }
                        }
                    do{
                        do{
                            printf("\n");
                            printf("Escolha uma opcao:\n");
                            printf("[1] Boia\n");
                            printf("[2] Aviao\n");
                            printf("[3] Submarino\n");     // Op��es (com condi��es e loops).
                            printf("[4] Espiao 1\n");
                            printf("[5] Espiao 2\n");
                            printf("[6] Porta-Avioes\n");
                            printf("[7] Voltar\n"); // Volta para o menu principal (reseta o jogo).
                            printf("[8] Aleatorizar\n");
                            printf("[9] Finalizar o jogo\n");
                            scanf("%d",&opcao);
                            if(opcao==7){
                                voltar_sair=1;       // Aqui todas as vari�veis resetam para que o jogo recomece.
                                voltar_sair2=1;
                                boia = 0, aviao = 0, submarino = 0, espiao_1 = 0, espiao_2 = 0, porta_avioes = 0;
                            }
                            if(opcao<1 || opcao>9){
                                printf("\n");
                                printf("Opcao invalida. Tente novamente.\n");
                            }
                        }while(opcao<1||opcao>9);
                        virar = 0; // resetar a vari�vel 'virar'
                    }while(virar==5 || virar==3);

                    printf("\n");

                    switch(opcao){ // switch-case da op��o escolhida pelo usu�rio.
                        case 1:  // Boia.
                            do{ // La�o de repeti��o.
                                printf("Digite a linha e coluna para adicionar a Boia: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){  // Convers�o dos valores do vetor letra para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                    printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                }
                                if(boia==BOMAX){
                                    printf("Quantidade maxima de Boias atingida.\n"); // Limitar a quantidade.
                                }
                                else if(linha>=0 && linha<TAM && coluna>=0 && coluna<TAM){
                                    if(vet[linha][coluna] != '*'){ // Condi��o para impedir sobreposi��o.
                                        printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                }
                                    else{
                                        vet[linha][coluna] = '0';   // Imprime a posi��o da boia na posi��o (x,y) escolhida pelo usu�rio.
                                        boia++;
                                    }
                                }
                            }while(linha>19 || coluna>19 || linha<0 || coluna<0);
                        break;

                        case 2: // Avi�o.
                            do{ // La�o de repeti��o.
                                printf("Escolha como sera o posicionamento do Aviao:\n");
                                printf("[1] Padrao\n");
                                printf("[2] Rotacionar 90 graus para a direita\n");     // Op��es para virar o elemento.
                                printf("[3] Rotacionar 90 graus para a esquerda\n");
                                printf("[4] Rotacionar 180 graus\n");
                                printf("[5] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar>5){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar>5);
                            if(virar==5){
                                system("cls");
                                break;
                            }

                            do{ // La�o de repeti��o.
                                printf("Digite a linha e coluna para adicionar o Aviao: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){ // Convers�o dos valores do vetor 'letra' para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(aviao==AVMAX){
                                    printf("Quantidade maxima de Avioes atingida.\n"); // Limitar a quantidade.
                                }
                                else{
                                    switch(virar){ // switch case para rota��o do elemento.
                                        case 1: // Opc�o padr�o:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha-1][coluna+1] != '*'){ // Verifica se h� algum elemento na posi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha+1][coluna+1] = '1';    // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha-1][coluna+1] = '1';
                                                    aviao++;
                                                    }
                                            }
                                        break;

                                        case 2: // Op��o virar 90� para a direita:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>19 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha][coluna+2] != '*'){ // Verifica se h� algum elemento na posi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha-1][coluna+1] = '1';    // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 3: // Op��o virar 90� para a esquerda:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>18 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*'){ // Verifica se h� algum elemento na posi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';   // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '1';
                                                    vet[linha+1][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 4: // Opcao virar 180�
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18   || coluna>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*'){  // Verifica se h� algum elemento na posi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha+1][coluna] = '1';
                                                    vet[linha-1][coluna] = '1';   // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna>19 || linha<0 || coluna<0);
                        break;

                        case 3: // Submarino.
                            do{ // La�o de repeti��o.
                                printf("Escolha como sera o posicionamento do Submarino:\n");
                                printf("[1] Padrao\n");
                                printf("[2] Rotacionar 90 graus\n");     // Op��es para virar o elemento.
                                printf("[3] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar>3){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar>3);
                            if(virar==3){
                                system("cls");
                                break;
                            }
                            do{ // La�o de repeti��o.
                                printf("Digite a linha e coluna para adicionar o Submarino: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){  // Convers�o dos valores do vetor letra para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(submarino==SUMAX){
                                    printf("Quantidade maxima de Submarinos atingida.\n"); // Limitar a quantidade.
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opc�o padr�o:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(coluna>16){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha][coluna+1] = '2';
                                                    vet[linha][coluna+2] = '2';    // Imprime as posi��es do submarino a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+3] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;

                                        case 2: // Opc�o rotacionar 90 graus.
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>16){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha+1][coluna] = '2';
                                                    vet[linha+2][coluna] = '2';    // Imprime as posi��es do submarino a partir da posi��o (x,y) inicializada.
                                                    vet[linha+3][coluna] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna > 19 || linha<0 || coluna<0);
                        break;

                        case 4: // Espi�o 1.
                            do{ // La�o de repeti��o.
                                printf("Escolha como sera o posicionamento do Espiao 1:\n");
                                printf("[1] Padrao\n");
                                printf("[2] Rotacionar 90 graus para a direita\n");     // Op��es para virar o elemento.
                                printf("[3] Rotacionar 90 graus para a esquerda\n");
                                printf("[4] Rotacionar 180 graus\n");
                                printf("[5] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar > 5){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar > 5);
                            if(virar==5){
                                system("cls");
                                break;
                            }
                            do{ // La�o de repeti��o.
                                printf("Digite a linha e coluna para adicionar o Espiao 1: ");
                                scanf("%d %c",&linha,&coluna);

                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){  // Convers�o dos valores do vetor letra para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(espiao_1==E1MAX){
                                    printf("Quantidade maxima de Espioes 1 atingida.\n"); // Limitar a quantidade.
                                }

                                else{
                                    switch(virar){ // switch case da op��o virar que rotaciona o elemento.
                                        case 1:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha+1][coluna] = '3';
                                                    vet[linha-1][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>16 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha+1][coluna+1] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha+2][coluna+1] = '3';
                                                    vet[linha+3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<3 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha-1][coluna+1] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-2][coluna+1] = '3';
                                                    vet[linha-3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-1][coluna+3] = '3';
                                                    vet[linha+1][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna>19 || linha<0 || coluna<0);
                        break;

                        case 5: // Espi�o 2.
                            do{ // La�o de repeti��o.
                                printf("Escolha como sera o posicionamento do Espiao 2:\n");
                                printf("[1] Padrao\n");
                                printf("[2] Rotacionar 90 graus para a direita\n");     // Op��es para virar o elemento.
                                printf("[3] Rotacionar 90 graus para a esquerda\n");
                                printf("[4] Rotacionar 180 graus\n");
                                printf("[5] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar > 5){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar > 5);
                            if(virar==5){
                                system("cls");
                                break;
                            }
                            do{ // La�o de repeti��o.
                                printf("Digite a linha e coluna para adicionar o Espiao 2: ");
                                scanf("%d %c",&linha,&coluna);

                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){  // Convers�o dos valores do vetor letra para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(espiao_2==E2MAX){
                                    printf("Quantidade maxima de Espioes 2 atingida.\n"); // Limitar a quantidade.
                                }

                                else{
                                    switch(virar){ // switch case da op��o virar que rotaciona o elemento.
                                        case 1:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha+1][coluna] = '4';
                                                    vet[linha-1][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>16 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha+1][coluna+1] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha+2][coluna+1] = '4';
                                                    vet[linha+3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<3 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha-1][coluna+1] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-2][coluna+1] = '4';
                                                    vet[linha-3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-1][coluna+3] = '4';
                                                    vet[linha+1][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna > 19 || linha<0 || coluna<0);
                        break;

                        case 6: // Porta-avi�es.
                            do{ // La�o de repeti��o.
                                printf("Escolha como sera o posicionamento do Porta-avioes:\n");
                                printf("[1] Padrao\n");
                                printf("[2] Rotacionar 90 graus\n");     // Op��es para virar o elemento.
                                printf("[3] Voltar\n");
                                scanf("%d",&virar);
                                if(virar<1 || virar>3){
                                    printf("\n");
                                    printf("Opcao invalida. Tente novamente.\n\n");
                                }
                            }while(virar<1 || virar > 3);
                            if(virar==3){
                                system("cls");
                                break;
                            }
                            do{ // La�o de repeti��o.
                                printf("Digite a linha e coluna para adicionar o Porta-avioes: ");
                                scanf("%d %c",&linha,&coluna);
                                for(m=0; m<TAM; m++){
                                    if(coluna==letra[m]){  // Convers�o dos valores do vetor letra para valores inteiros (facilita a indica��o da coluna).
                                        coluna = m;
                                    }
                                }
                                if(submarino==PAMAX){
                                    printf("Quantidade maxima de Porta-avioes atingida.\n"); // Limitar a quantidade.
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opc�o padr�o:
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(coluna>15 || linha>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha][coluna+4] != '*' || vet[linha+1][coluna] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+1][coluna+2] != '*' || vet[linha+1][coluna+3] != '*' || vet[linha+1][coluna+4] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';
                                                    vet[linha][coluna+2] = '5';
                                                    vet[linha][coluna+3] = '5';
                                                    vet[linha][coluna+4] = '5';
                                                    vet[linha+1][coluna] = '5';     // Imprime as posi��es do porta-avi�es a partir da posi��o (x,y) inicializada.
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+1][coluna+2] = '5';
                                                    vet[linha+1][coluna+3] = '5';
                                                    vet[linha+1][coluna+4] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;

                                        case 2: // Opc�o rotacionar 90 graus.
                                            if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                                printf("\n");
                                                printf("Linha e/ou Coluna invalida. Tente novamente.\n");
                                            }
                                            else if(linha>15 || coluna>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                                printf("Elemento ultrapassa a matriz. Tente novamente.\n");
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*' || vet[linha+4][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*' || vet[linha+4][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                    printf("Posicao Invalida. Posicao ja possui um elemento.\n");
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha+1][coluna] = '5';
                                                    vet[linha+2][coluna] = '5';
                                                    vet[linha+3][coluna] = '5';
                                                    vet[linha+4][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';     // Imprime as posi��es do porta-avi�es a partir da posi��o (x,y) inicializada.
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+2][coluna+1] = '5';
                                                    vet[linha+3][coluna+1] = '5';
                                                    vet[linha+4][coluna+1] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(linha>19 || coluna > 19 || linha<0 || coluna<0);
                        break;

                        case 9:
                            printf("Obrigado por jogar!\n");
                            return 0;
                            break;
                        case 8: // Case da op��o aleatorizar.
                            do{ // Sortear boias aleatoriamente
                                linha = rand()%20; // Sortear linha
                                coluna = rand()%20; // Sortear coluna

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                    }
                                    if(boia==BOMAX){
                                    }
                                    else if(linha>=0 && linha<TAM && coluna>=0 && coluna<TAM){
                                        if(vet[linha][coluna] != '*'){ // Condi��o para impedir sobreposi��o.
                                    }
                                        else{
                                            vet[linha][coluna] = '0';   // Imprime a posi��o da boia na posi��o (x,y) escolhida pelo usu�rio.
                                            boia++;
                                        }
                                    }
                            }while(boia<BOMAX);

                            do{ // Sortear avi�es aleatoriamente
                                linha = rand()%20;// Sortear linha
                                coluna = rand()%20; // Sortear coluna
                                virar = (rand()%4) + 1; // Sortear a op��o virar

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                }
                                if(aviao==AVMAX){
                                }
                                else{
                                    switch(virar){ // switch case para rota��o do elemento.
                                        case 1: // Opc�o padr�o:
                                            if(linha<1 || linha>18 || coluna>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha-1][coluna+1] != '*'){ // Verifica se h� algum elemento na posi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha+1][coluna+1] = '1';    // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha-1][coluna+1] = '1';
                                                    aviao++;
                                                    }
                                            }
                                        break;

                                        case 2: // Op��o virar 90� para a direita:
                                            if(linha<1 || linha>19 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha][coluna+2] != '*'){ // Verifica se h� algum elemento na posi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';
                                                    vet[linha-1][coluna+1] = '1';    // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 3: // Op��o virar 90� para a esquerda:
                                            if(linha>18 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*'){ // Verifica se h� algum elemento na posi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha][coluna+1] = '1';   // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '1';
                                                    vet[linha+1][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;

                                        case 4: // Opcao virar 180�
                                            if(linha<1 || linha>18   || coluna>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*'){  // Verifica se h� algum elemento na posi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '1';
                                                    vet[linha+1][coluna] = '1';
                                                    vet[linha-1][coluna] = '1';   // Imprime as posi��es do avi�o a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+1] = '1';
                                                    aviao++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(aviao<AVMAX);

                            do{ // Sortear submarinos aleatoriamente
                                linha = rand()%20; // Sortear linha
                                coluna = rand()%20; // Sortear coluna
                                virar = (rand()%2) + 1; // Sortear a op��o virar

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                }
                                if(submarino==SUMAX){
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opc�o padr�o:
                                            if(coluna>16){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha][coluna+1] = '2';
                                                    vet[linha][coluna+2] = '2';    // Imprime as posi��es do submarino a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+3] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;

                                        case 2: // Opc�o rotacionar 90 graus.
                                            if(linha>16){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '2';
                                                    vet[linha+1][coluna] = '2';
                                                    vet[linha+2][coluna] = '2';    // Imprime as posi��es do submarino a partir da posi��o (x,y) inicializada.
                                                    vet[linha+3][coluna] = '2';
                                                    submarino++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(submarino<SUMAX);

                            do{ // Sortear espi�o 1 aleatoriamente
                                linha = rand()%20;// Sortear linha
                                coluna = rand()%20; // Sortear coluna
                                virar = (rand()%4) + 1; // Sortear a op��o virar

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapaassar a matriz.
                                }
                                if(espiao_1==E1MAX){
                                }

                                else{
                                    switch(virar){ // switch case da op��o virar que rotaciona o elemento.
                                        case 1:
                                            if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha+1][coluna] = '3';
                                                    vet[linha-1][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>16 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha+1][coluna+1] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha+2][coluna+1] = '3';
                                                    vet[linha+3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha<3 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha-1][coluna+1] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-2][coluna+1] = '3';
                                                    vet[linha-3][coluna+1] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '3';
                                                    vet[linha][coluna+1] = '3';
                                                    vet[linha][coluna+2] = '3';
                                                    vet[linha][coluna+3] = '3';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-1][coluna+3] = '3';
                                                    vet[linha+1][coluna+3] = '3';
                                                    espiao_1++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(espiao_1<E1MAX);

                            do{ // Sortear espi�o 2 aleatoriamente
                                linha = rand()%20;// Sortear linha
                                coluna = rand()%20; // Sortear coluna
                                virar = (rand()%4) + 1; // Sortear a op��o virar

                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapaassar a matriz.
                                }
                                if(espiao_2==E2MAX){
                                }

                                else{
                                    switch(virar){ // switch case da op��o virar que rotaciona o elemento.
                                        case 1:
                                            if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha-1][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha+1][coluna] = '4';
                                                    vet[linha-1][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 2:
                                            if(linha>16 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha+1][coluna+1] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha+2][coluna+1] = '4';
                                                    vet[linha+3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 3:
                                            if(linha<3 || coluna>17){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha-1][coluna+1] != '*' || vet[linha-2][coluna+1] != '*' || vet[linha-3][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha-1][coluna+1] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-2][coluna+1] = '4';
                                                    vet[linha-3][coluna+1] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;

                                        case 4:
                                            if(linha<1 || linha>18 || coluna>16){  // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha-1][coluna+3] != '*' || vet[linha+1][coluna+3] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '4';
                                                    vet[linha][coluna+1] = '4';
                                                    vet[linha][coluna+2] = '4';
                                                    vet[linha][coluna+3] = '4';     // Imprime as posi��es do espi�o 1 a partir da posi��o (x,y) inicializada.
                                                    vet[linha-1][coluna+3] = '4';
                                                    vet[linha+1][coluna+3] = '4';
                                                    espiao_2++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(espiao_2<E2MAX);

                            do{ // Sortear porta-avi�es aleatoriamente
                                linha = rand()%20; // Sortear linha
                                coluna = rand()%20; // Sortear coluna
                                virar = (rand()%2) + 1; // Sortear a op��o virar
                                if(linha>19 || coluna>19 || linha<0 || coluna<0){ // Condi��o para n�o ultrapassar a matriz.
                                }
                                if(submarino==PAMAX){
                                }
                                else{
                                    switch(virar){
                                        case 1: // Opc�o padr�o:
                                            if(coluna>15 || linha>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha][coluna+2] != '*' || vet[linha][coluna+3] != '*' || vet[linha][coluna+4] != '*' || vet[linha+1][coluna] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+1][coluna+2] != '*' || vet[linha+1][coluna+3] != '*' || vet[linha+1][coluna+4] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';
                                                    vet[linha][coluna+2] = '5';
                                                    vet[linha][coluna+3] = '5';
                                                    vet[linha][coluna+4] = '5';
                                                    vet[linha+1][coluna] = '5';     // Imprime as posi��es do porta-avi�es a partir da posi��o (x,y) inicializada.
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+1][coluna+2] = '5';
                                                    vet[linha+1][coluna+3] = '5';
                                                    vet[linha+1][coluna+4] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;

                                        case 2: // Opc�o rotacionar 90 graus.
                                            if(linha>15 || coluna>18){ // Condi��o que l� se o elemento pode ser impresso inteiramente na matriz.
                                            }
                                            else{
                                                if(vet[linha][coluna] != '*' || vet[linha+1][coluna] != '*' || vet[linha+2][coluna] != '*' || vet[linha+3][coluna] != '*' || vet[linha+4][coluna] != '*' || vet[linha][coluna+1] != '*' || vet[linha+1][coluna+1] != '*' || vet[linha+2][coluna+1] != '*' || vet[linha+3][coluna+1] != '*' || vet[linha+4][coluna+1] != '*'){ // Condi��o para impedir sobreposi��o.
                                                }
                                                else{
                                                    vet[linha][coluna] = '5';
                                                    vet[linha+1][coluna] = '5';
                                                    vet[linha+2][coluna] = '5';
                                                    vet[linha+3][coluna] = '5';
                                                    vet[linha+4][coluna] = '5';
                                                    vet[linha][coluna+1] = '5';     // Imprime as posi��es do porta-avi�es a partir da posi��o (x,y) inicializada.
                                                    vet[linha+1][coluna+1] = '5';
                                                    vet[linha+2][coluna+1] = '5';
                                                    vet[linha+3][coluna+1] = '5';
                                                    vet[linha+4][coluna+1] = '5';
                                                    porta_avioes++;
                                                }
                                            }
                                        break;
                                    }
                                }
                            }while(porta_avioes<PAMAX);
                        break;
                    }
                }while(voltar_sair2==0);

                break;

            case 2: // Aqui est� a op��o 2 (Instru��es) do menu principal. N�o acho que precisa de explica��es maiores. Feito apenas por est�tica. (N�o sei usar fun��o, poderia minimizar a quantidade de linhas).
                printf("Instrucoes de posicionamento das pecas.\n");
                printf("\---------------------------------------\n");
                printf(">>O ponto de incializacao do elemento vai do ponto mais a esquerda para direita, e de cima para baixo.<<\n");
                printf("\n");

                printf("Boia esta representada com '0'.\n");
                printf("\n");
                for(int i=0; i<5; i++){
                    for(int j=0; j<5 ; j++){
                        matriz_menu[i][j] = '*';
                        if(i==2 && j==2){
                            matriz_menu[i][j] = '0';
                        }
                        printf("%c ",matriz_menu[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                printf("Aviao esta representado com '1'. Possui 4 possiveis rotacoes. Sendo respectivamente:\n");
                printf("Padrao, 90 graus para direita, 90 graus para a esquerda, 180 graus.\n");
                printf("\n");

                for(int i=0; i<5; i++){
                    for(int j=0; j<23; j++){
                        matriz_menu[i][j] = '*';
                        matriz_menu[0][5] = ' '; matriz_menu[0][11] = ' '; matriz_menu[0][17] = ' ';
                        matriz_menu[1][5] = ' '; matriz_menu[1][11] = ' '; matriz_menu[1][17] = ' ';
                        matriz_menu[2][5] = ' '; matriz_menu[2][11] = ' '; matriz_menu[2][17] = ' ';
                        matriz_menu[3][5] = ' '; matriz_menu[3][11] = ' '; matriz_menu[3][17] = ' ';
                        matriz_menu[4][5] = ' '; matriz_menu[4][11] = ' '; matriz_menu[4][17] = ' ';
                        matriz_menu[5][5] = ' '; matriz_menu[5][11] = ' '; matriz_menu[5][17] = ' ';
                        if(i==2 && j==2 || i==1 && j==2 || i==3 && j==2 || i==2 && j==1){
                            matriz_menu[2][2] = '1';
                            matriz_menu[1][2] = '1';
                            matriz_menu[3][2] = '1';
                            matriz_menu[2][1] = '1';
                        }
                        if(i==2 && j==8 || i==1 && j==8 || i==2 && j==9 || i==2 && j==7){
                            matriz_menu[2][8] = '1';
                            matriz_menu[1][8] = '1';
                            matriz_menu[2][9] = '1';
                            matriz_menu[2][7] = '1';
                        }
                        if(i==2 && j==15 || i==2 && j==14 || i==3 && j==14 || i==2 && j==13){
                            matriz_menu[2][15] = '1';
                            matriz_menu[2][14] = '1';
                            matriz_menu[3][14] = '1';
                            matriz_menu[2][13] = '1';
                        }
                        if(i==2 && j==20 || i==1 && j==20 || i==3 && j==20 || i==2 && j==21){
                            matriz_menu[2][20] = '1';
                            matriz_menu[1][20] = '1';
                            matriz_menu[3][20] = '1';
                            matriz_menu[2][21] = '1';
                        }
                        printf("%c ", matriz_menu[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                printf("Submarino esta representado com '2'. Possui 2 possiveis rotacoes. Sendo respectivamente:\n");
                printf("Padrao, 90 graus (direita ou esquerda).\n");
                printf("\n");

                for(int i=0; i<5; i++){
                    for(int j=0; j<11; j++){
                        matriz_menu[i][j] = '*';
                        matriz_menu[0][5] = ' ';
                        matriz_menu[1][5] = ' ';
                        matriz_menu[2][5] = ' ';
                        matriz_menu[3][5] = ' ';
                        matriz_menu[4][5] = ' ';
                        matriz_menu[5][5] = ' ';
                        if(i==2 && j==0 || i==2 && j==1 || i==2 && j == 2 || i==2 && j==3){
                            matriz_menu[2][0] = '2';
                            matriz_menu[2][1] = '2';
                            matriz_menu[2][2] = '2';
                            matriz_menu[2][3] = '2';
                        }
                        if(i==1 && j==8 || i==2 && j==8 || i==3 && j ==8 || i==4 && j==8){
                            matriz_menu[1][8] = '2';
                            matriz_menu[2][8] = '2';
                            matriz_menu[3][8] = '2';
                            matriz_menu[4][8] = '2';
                        }
                        printf("%c ", matriz_menu[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                printf("Espiao 1 esta representado com '3'. Possui 4 possiveis rotacoes. Sendo respectivamente:\n");
                printf("Padrao, 90 graus para direita, 90 graus para a esquerda, 180 graus.\n");
                printf("\n");

                for(int i=0; i<5; i++){
                    for(int j=0; j<23; j++){
                        matriz_menu[i][j] = '*';
                        matriz_menu[0][5] = ' '; matriz_menu[0][11] = ' '; matriz_menu[0][17] = ' ';
                        matriz_menu[1][5] = ' '; matriz_menu[1][11] = ' '; matriz_menu[1][17] = ' ';
                        matriz_menu[2][5] = ' '; matriz_menu[2][11] = ' '; matriz_menu[2][17] = ' ';
                        matriz_menu[3][5] = ' '; matriz_menu[3][11] = ' '; matriz_menu[3][17] = ' ';
                        matriz_menu[4][5] = ' '; matriz_menu[4][11] = ' '; matriz_menu[4][17] = ' ';
                        matriz_menu[5][5] = ' '; matriz_menu[5][11] = ' '; matriz_menu[5][17] = ' ';
                        if(i==2 && j==0 || i==2 && j==1 || i==2 && j==2 || i==2 && j==3 || i==1 && j==0 || i==3 && j==0){
                            matriz_menu[2][0] = '3';
                            matriz_menu[2][1] = '3';
                            matriz_menu[2][2] = '3';
                            matriz_menu[2][3] = '3';
                            matriz_menu[1][0] = '3';
                            matriz_menu[3][0] = '3';
                        }
                        if(i==1 && j==7 || i==1 && j==8 || i==1 && j==9 || i==2 && j==8 || i==3 && j==8 || i==4 && j==8){
                            matriz_menu[1][7] = '3';
                            matriz_menu[1][8] = '3';
                            matriz_menu[1][9] = '3';
                            matriz_menu[2][8] = '3';
                            matriz_menu[3][8] = '3';
                            matriz_menu[4][8] = '3';
                        }
                        if(i==4 && j==13 || i==4 && j==14 || i==4 && j==15 || i==3 && j==14 || i==2 && j==14 || i==1 && j==14){
                            matriz_menu[4][13] = '3';
                            matriz_menu[4][14] = '3';
                            matriz_menu[4][15] = '3';
                            matriz_menu[3][14] = '3';
                            matriz_menu[2][14] = '3';
                            matriz_menu[1][14] = '3';
                        }
                        if(i==2 && j==19 || i==2 && j==20 || i==2 && j==21 || i==3 && j==22 || i==2 && j==22 || i==1 && j==22){
                            matriz_menu[2][19] = '3';
                            matriz_menu[2][20] = '3';
                            matriz_menu[2][21] = '3';
                            matriz_menu[3][22] = '3';
                            matriz_menu[2][22] = '3';
                            matriz_menu[1][22] = '3';
                        }
                        printf("%c ", matriz_menu[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                printf("Espiao 2 esta representado com '4'. Possui 4 possiveis rotacoes. Sendo respectivamente:\n");
                printf("Padrao, 90 graus para direita, 90 graus para a esquerda, 180 graus.\n");
                printf("\n");

                for(int i=0; i<5; i++){
                    for(int j=0; j<23; j++){
                        matriz_menu[i][j] = '*';
                        matriz_menu[0][5] = ' '; matriz_menu[0][11] = ' '; matriz_menu[0][17] = ' ';
                        matriz_menu[1][5] = ' '; matriz_menu[1][11] = ' '; matriz_menu[1][17] = ' ';
                        matriz_menu[2][5] = ' '; matriz_menu[2][11] = ' '; matriz_menu[2][17] = ' ';
                        matriz_menu[3][5] = ' '; matriz_menu[3][11] = ' '; matriz_menu[3][17] = ' ';
                        matriz_menu[4][5] = ' '; matriz_menu[4][11] = ' '; matriz_menu[4][17] = ' ';
                        matriz_menu[5][5] = ' '; matriz_menu[5][11] = ' '; matriz_menu[5][17] = ' ';
                        if(i==2 && j==0 || i==2 && j==1 || i==2 && j==2 || i==2 && j==3 || i==1 && j==0 || i==3 && j==0){
                            matriz_menu[2][0] = '4';
                            matriz_menu[2][1] = '4';
                            matriz_menu[2][2] = '4';
                            matriz_menu[2][3] = '4';
                            matriz_menu[1][0] = '4';
                            matriz_menu[3][0] = '4';
                        }
                        if(i==1 && j==7 || i==1 && j==8 || i==1 && j==9 || i==2 && j==8 || i==3 && j==8 || i==4 && j==8){
                            matriz_menu[1][7] = '4';
                            matriz_menu[1][8] = '4';
                            matriz_menu[1][9] = '4';
                            matriz_menu[2][8] = '4';
                            matriz_menu[3][8] = '4';
                            matriz_menu[4][8] = '4';
                        }
                        if(i==4 && j==13 || i==4 && j==14 || i==4 && j==15 || i==3 && j==14 || i==2 && j==14 || i==1 && j==14){
                            matriz_menu[4][13] = '4';
                            matriz_menu[4][14] = '4';
                            matriz_menu[4][15] = '4';
                            matriz_menu[3][14] = '4';
                            matriz_menu[2][14] = '4';
                            matriz_menu[1][14] = '4';
                        }
                        if(i==2 && j==19 || i==2 && j==20 || i==2 && j==21 || i==3 && j==22 || i==2 && j==22 || i==1 && j==22){
                            matriz_menu[2][19] = '4';
                            matriz_menu[2][20] = '4';
                            matriz_menu[2][21] = '4';
                            matriz_menu[3][22] = '4';
                            matriz_menu[2][22] = '4';
                            matriz_menu[1][22] = '4';
                        }
                        printf("%c ", matriz_menu[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                printf("Porta-avioes esta representado com '5'. Possui 2 possiveis rotacoes. Sendo respectivamente:\n");
                printf("Padrao, 90 graus (direita ou esquerda).\n");
                printf("\n");

                for(int i=0; i<5; i++){
                    for(int j=0; j<11; j++){
                        matriz_menu[i][j] = '*';
                        matriz_menu[0][5] = ' ';
                        matriz_menu[1][5] = ' ';
                        matriz_menu[2][5] = ' ';
                        matriz_menu[3][5] = ' ';
                        matriz_menu[4][5] = ' ';
                        matriz_menu[5][5] = ' ';
                        if(i==1 && j==0 || i==1 && j==1 || i==1 && j==2 || i==1 && j==3 || i==1 && j==4 || i==2 && j==0 || i==2 && j==1 || i==2 && j==2 || i==2 && j==3 || i==2 && j==4){
                            matriz_menu[1][0] = '5';
                            matriz_menu[1][1] = '5';
                            matriz_menu[1][2] = '5';
                            matriz_menu[1][3] = '5';
                            matriz_menu[1][4] = '5';
                            matriz_menu[2][0] = '5';
                            matriz_menu[2][1] = '5';
                            matriz_menu[2][2] = '5';
                            matriz_menu[2][3] = '5';
                            matriz_menu[2][4] = '5';
                        }
                        if(i==0 && j==8 || i==1 && j==8 || i==2 && j==8 || i==3 && j==8 || i==4 && j==8 || i==0 && j==9 || i==1 && j==9 || i==2 && j==9 || i==3 && j==9 || i==4 && j==9){
                            matriz_menu[0][8] = '5';
                            matriz_menu[1][8] = '5';
                            matriz_menu[2][8] = '5';
                            matriz_menu[3][8] = '5';
                            matriz_menu[4][8] = '5';
                            matriz_menu[0][9] = '5';
                            matriz_menu[1][9] = '5';
                            matriz_menu[2][9] = '5';
                            matriz_menu[3][9] = '5';
                            matriz_menu[4][9] = '5';
                        }
                        printf("%c ", matriz_menu[i][j]);
                    }
                    printf("\n");
                }

                do{
                    printf("\n");
                    printf("[1] Voltar\n");  // Menu que aparece nas instru��es.
                    printf("[2] Sair\n");
                    scanf("%d",&voltar_sair);
                    if(voltar_sair>2 || voltar_sair<1){
                        printf("\n");
                        printf("Opcao invalida.\n");
                    }
                    if(voltar_sair==2){ // Op��o sair. (Fecha o jogo nas instru��es...)
                        system("cls");
                        printf("Obrigado por jogar!\n");
                        return 0;
                    }
                }while(voltar_sair<1 || voltar_sair>2);

                break;

            case 3: // Op��o sair.
                printf("Obrigado por jogar!\n");
                return 0;
                break;
            default:
                printf("\n");
                printf("Opcao invalida.\n");
        }
        system("cls");
    }while(voltar_sair==1);

    return 0;
}
