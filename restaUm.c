#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define BRED "\033[1;31m"
#define BGRN "\033[0;32m"
#define BBLU "\033[1;34m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BCYN "\033[1;36m"
#define BYEL "\033[1;33m"

#define MAXLETRAS 10
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void imprimeMatriz(char matriz[7][7]){
    int i, j;
    printf("\n");
    printf(BYEL"           (0)   (1)   (2)   (3)   (4)   (5)   (6)\n"RESET);
    printf("                      _________________\n");
    printf("                     |     |     |     |\n");
    printf(BCYN"     (0) "RESET);
    printf("            |  %c  |  %c  |  %c  |\n", matriz[0][2], matriz[0][3], matriz[0][4]);
    printf("                     |_____|_____|_____|\n");
    printf("                     |     |     |     |\n");
    printf(BCYN"     (1) "RESET);
    printf("            |  %c  |  %c  |  %c  |\n", matriz[1][2], matriz[1][3], matriz[1][4]);
    printf("          ___________|_____|_____|_____|___________\n");
    printf("         |     |     |     |     |     |     |     |\n");
    printf(BCYN"     (2) "RESET);
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3], matriz[2][4], matriz[2][5], matriz[2][6]);
    printf("         |_____|_____|_____|_____|_____|_____|_____|\n");
    printf("         |     |     |     |     |     |     |     |\n");
    printf(BCYN"     (3) "RESET);
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3], matriz[3][4], matriz[3][5], matriz[3][6]);
    printf("         |_____|_____|_____|_____|_____|_____|_____|\n");
    printf("         |     |     |     |     |     |     |     |\n");
    printf(BCYN"     (4) "RESET);
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", matriz[4][0], matriz[4][1], matriz[4][2], matriz[4][3], matriz[4][4], matriz[4][5], matriz[4][6]);
    printf("         |_____|_____|_____|_____|_____|_____|_____|\n");
    printf("                     |     |     |     |\n");
    printf(BCYN"     (5) "RESET);
    printf("            |  %c  |  %c  |  %c  |\n", matriz[5][2], matriz[5][3], matriz[5][4]);
    printf("                     |_____|_____|_____|\n");
    printf("                     |     |     |     |\n");
    printf(BCYN"     (6) "RESET);
    printf("            |  %c  |  %c  |  %c  |\n", matriz[6][2], matriz[6][3], matriz[6][4]);
    printf("                     |_____|_____|_____|\n");
    
}

void exibeTimer(int qtdSegundos){
    int h, m, s, resto;
    h = qtdSegundos / 3600;
    resto = qtdSegundos % 3600;
    m = resto / 60;
    s = resto % 60;
    printf("Tempo de jogo: %d:%d:%d\n", h, m, s);
}

void movimentaPecas(char matriz[7][7], int lin, int col, char dir){
    if(dir == 'w'){
        matriz[lin - 2][col] = '0';
        matriz[lin - 1][col] = ' ';
        matriz[lin][col] = ' ';
    }
    else{
        if(dir == 's'){
            matriz[lin + 2][col] = '0';
            matriz[lin + 1][col] = ' ';
            matriz[lin][col] = ' ';
        }
        else{
            if(dir == 'a'){
                matriz[lin][col - 2] = '0';
                matriz[lin][col - 1] = ' ';
                matriz[lin][col] = ' ';
            }
            else{
                if(dir == 'd'){
                    matriz[lin][col + 2] = '0';
                    matriz[lin][col + 1] = ' ';
                    matriz[lin][col] = ' ';
                }
            }
        }
    }    
}

void exibeResultado(char matriz[7][7]){
    int qtdPeca = 0, i, j;
    for(i = 0; i < 7; i++){
                for(j = 0; j < 7; j++){
                    if(matriz[i][j] == '0') qtdPeca++;
                }
    }
    if(qtdPeca == 1){
        printf(BGRN "\n      Parabens! Voce ganhou!\n\n" RESET);
    }
    else{
        printf(BRED "\n      Nao foi dessa vez! Restaram %d pecas. Tente mais uma vez!\n\n" RESET, qtdPeca);
    }
}

int verificaSituacao(char matriz[7][7]){
    int i, j;
    for(i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            if(matriz[i][j] == '0'){
                if(i == 0 || i == 1){
                    if((matriz[i + 2][j] == ' ' && matriz[i + 1][j] == '0') || (matriz[i][j + 2] == ' ' && matriz[i][j + 1] == '0') || (matriz[i][j - 2] == ' ' && matriz[i][j - 1] == '0')){
                        return 0;
                    }
                }
                else{
                    if(i == 5 || i == 6){
                        if((matriz[i - 2][j] == ' ' && matriz[i - 1][j] == '0') || (matriz[i][j + 2] == ' ' && matriz[i][j + 1] == '0') || (matriz[i][j - 2] == ' ' && matriz[i][j - 1] == '0')){
                            return 0;
                        }
                    }
                    else{
                        if(j == 0 || j == 1){
                            if((matriz[i + 2][j] == ' ' && matriz[i + 1][j] == '0') || (matriz[i - 2][j] == ' ' && matriz[i - 1][j] == '0') || (matriz[i][j + 2] == ' ' && matriz[i][j + 1] == '0')){
                                return 0;
                            }
                        }
                        else{
                            if(j == 5 || j == 6){
                                if((matriz[i + 2][j] == ' ' && matriz[i + 1][j] == '0') || (matriz[i - 2][j] == ' ' && matriz[i - 1][j] == '0') || (matriz[i][j - 2] == ' ' && matriz[i][j - 1] == '0')){
                                    return 0;
                                }
                            }
                            else{
                                if((matriz[i + 2][j] == ' ' && matriz[i + 1][j] == '0') || (matriz[i - 2][j] == ' ' && matriz[i - 1][j] == '0') || (matriz[i][j + 2] == ' ' && matriz[i][j + 1] == '0') || (matriz[i][j - 2] == ' ' && matriz[i][j - 1] == '0')){
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

void iniciaJogo(char matriz[7][7]){
    int lin, col, linFut, colFut, res, ret, ret1;
    time_t segundosInicio, segundosAtual;
    time_t difTempo;
    char nome[20];
    char resp, carac, dir;
    time(&segundosInicio);
    printf(BBLU "    ⢀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣄⡀\n");
    printf("    ⢰⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣷\n");
    printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠶⣶⣶⣦⣄⠀⠶⣶⣶⣶⡆⣤⣶⢶⣶⣶⣶⣶⣶⣶⡆⠀⠀⣰⣆⠀⠀⠀⠀⠀⣤⣶⡆⠀⠀⠀⠀⠀⠀⠀⢸⣿\n");
    printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⡇⣹⣿⠀⠀⣿⣇⣠⡅⣿⣷⣄⠛⠃⠀⣿⡇⠀⠋⠀⢠⣿⣿⣆⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⣿\n");
    printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⡟⢿⣷⡀⠀⣿⡇⠘⣃⣄⠙⢿⣷⠀⠀⣿⡇⠀⠀⢠⣿⠶⢿⣿⡄⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⣿\n");
    printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠶⠿⠷⠆⠻⠿⠶⠿⠿⠶⠟⠿⠾⠿⠃⠀⠶⠿⠷⠆⠰⠿⠿⠀⠶⠿⠷⠆⠀⠰⠶⠿⠷⠆⠀⠀⠀⠀⠀⠀⢸⣿\n");
    printf("    ⠸⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿\n");
    printf("    ⠀⠙⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠟⠃\n" RESET);

    printf("\n\n");

    printf("      Nick do jogador: ");
    scanf("%s", nome);
    while(1){
        imprimeMatriz(matriz);
        while(1){
            if(verificaSituacao(matriz)){
                exibeResultado(matriz);
                while(getchar()!='\n');
                printf("      Pressione S para voltar: ");
                scanf("%c", &carac);  
                if(carac == 'S' || carac == 's') break;
            }
            printf("\n      Digite a " BCYN "linha " RESET "e a " BYEL "coluna " RESET "da peca que deseja mover (ex: 5 3): ");
            ret = scanf("%d %d", &lin, &col);
            if(ret != 2 || lin > 6 || lin < 0 || col > 6 || col < 0){
                printf(BRED "\n      Voce deve digitar dois numeros inteiros entre 0 e 6 separados por um espaco.\n" RESET);
                continue;
            }else{
                if(matriz[lin][col] != '0'){
                    printf(BRED "\n      Nao ha peca nessa posicao.\n" RESET);
                    continue;
                }
                else{
                    if(lin == 0 || lin == 1){
                        if(!((matriz[lin + 2][col] == ' ' && matriz[lin + 1][col] == '0') || (matriz[lin][col + 2] == ' ' && matriz[lin][col + 1] == '0') || (matriz[lin][col - 2] == ' ' && matriz[lin][col - 1] == '0'))){
                            printf(BRED "\n      Nao tem jogada para essa posicao.\n" RESET);
                            continue;
                        }
                    }
                    else{
                        if(lin == 5 || lin == 6){
                            if(!((matriz[lin - 2][col] == ' ' && matriz[lin - 1][col] == '0') || (matriz[lin][col + 2] == ' ' && matriz[lin][col + 1] == '0') || (matriz[lin][col - 2] == ' ' && matriz[lin][col - 1] == '0'))){
                                printf(BRED "\n      Nao tem jogada para essa posicao.\n" RESET);
                                continue;
                            }
                        }
                        else{
                            if(col == 0 || col == 1){
                                if(!((matriz[lin + 2][col] == ' ' && matriz[lin + 1][col] == '0') || (matriz[lin - 2][col] == ' ' && matriz[lin - 1][col] == '0') || (matriz[lin][col + 2] == ' ' && matriz[lin][col + 1] == '0'))){
                                    printf(BRED "\n      Nao tem jogada para essa posicao.\n" RESET);
                                    continue;
                                }
                            }
                            else{
                                if(col == 5 || col == 6){
                                    if(!((matriz[lin + 2][col] == ' ' && matriz[lin + 1][col] == '0') || (matriz[lin - 2][col] == ' ' && matriz[lin - 1][col] == '0') || (matriz[lin][col - 2] == ' ' && matriz[lin][col - 1] == '0'))){
                                        printf(BRED "\n      Nao tem jogada para essa posicao.\n" RESET);
                                        continue;
                                    }
                                }
                                else{
                                    if(!((matriz[lin + 2][col] == ' ' && matriz[lin + 1][col] == '0') || (matriz[lin - 2][col] == ' ' && matriz[lin - 1][col] == '0') || (matriz[lin][col + 2] == ' ' && matriz[lin][col + 1] == '0') || (matriz[lin][col - 2] == ' ' && matriz[lin][col - 1] == '0'))){
                                        printf(BRED "\n      Nao tem jogada para essa posicao.\n" RESET);
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            while(getchar()!='\n');
            break;
        }
        if(carac == 'S' || carac == 's') break;
        while(1){
            printf("\n      Pressione a direcao (w, a, d, s): ");
            scanf("%c", &dir);
            if(dir == 'w'){
                if(matriz[lin - 2][col] == ' ' && matriz[lin - 1][col] == '0') break;
            }
            else{
                if(dir == 's'){
                    if(matriz[lin + 2][col] == ' ' && matriz[lin + 1][col] == '0') break;
                }
                else{
                    if(dir == 'a'){
                        if(matriz[lin][col - 2] == ' ' && matriz[lin][col - 1] == '0') break;
                    }
                    else{
                        if(dir == 'd'){
                            if(matriz[lin][col + 2] == ' ' && matriz[lin][col + 1] == '0') break;
                        }
                    }
                }
            }
            while(getchar()!='\n');
        }
        system(CLEAR);
        time(&segundosAtual);
        difTempo = segundosAtual - segundosInicio;
        printf(BBLU "    ⢀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣄⡀\n");
        printf("    ⢰⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣷\n");
        printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠶⣶⣶⣦⣄⠀⠶⣶⣶⣶⡆⣤⣶⢶⣶⣶⣶⣶⣶⣶⡆⠀⠀⣰⣆⠀⠀⠀⠀⠀⣤⣶⡆⠀⠀⠀⠀⠀⠀⠀⢸⣿\n");
        printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⡇⣹⣿⠀⠀⣿⣇⣠⡅⣿⣷⣄⠛⠃⠀⣿⡇⠀⠋⠀⢠⣿⣿⣆⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⣿\n");
        printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⡟⢿⣷⡀⠀⣿⡇⠘⣃⣄⠙⢿⣷⠀⠀⣿⡇⠀⠀⢠⣿⠶⢿⣿⡄⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⣿\n");
        printf("    ⢸⣿⠀⠀⠀⠀⠀⠀⠶⠿⠷⠆⠻⠿⠶⠿⠿⠶⠟⠿⠾⠿⠃⠀⠶⠿⠷⠆⠰⠿⠿⠀⠶⠿⠷⠆⠀⠰⠶⠿⠷⠆⠀⠀⠀⠀⠀⠀⢸⣿\n");
        printf("    ⠸⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿\n");
        printf("    ⠀⠙⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠟⠃\n" RESET);
        printf("\n\n");
        printf("      Jogador: %s             ", nome);
        exibeTimer(difTempo);
        movimentaPecas(matriz, lin, col, dir);        
    }
}

void inicializaMatriz(char matriz[7][7]){
    int i, j;
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            matriz[i][j] = '0';
    matriz[3][3] = ' ';
    matriz[0][0] = '#';
    matriz[0][1] = '#';
    matriz[0][5] = '#';
    matriz[0][6] = '#';
    matriz[1][0] = '#';
    matriz[1][1] = '#';
    matriz[1][5] = '#';
    matriz[1][6] = '#';
    matriz[5][0] = '#';
    matriz[5][1] = '#';
    matriz[5][5] = '#';
    matriz[5][6] = '#';
    matriz[6][0] = '#';
    matriz[6][1] = '#';
    matriz[6][5] = '#';
    matriz[6][6] = '#';
}

void exibeSobreJogo(){
    char mat[7][7];
    char carac;
    inicializaMatriz(mat);
    do{
        getchar();
        system(CLEAR);
        printf(BBLU "     ⣠⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣄⠀\n" RESET);
        printf(BBLU "    ⢰⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⢠⣤⣤⣤⡄⠀⣠⣤⣤⣤⣄⠀⢤⣤⣤⣤⣤⣤⠀⣤⣤⣤⣤⣄⡀⠀⣤⣤⣤⣤⣤⣤⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⣧⡀⠛⢳⣾⡟⠀⠀⠀⢿⣷⡀⠀⣿⡇⢸⣿⡇⠀⣿⣿⠀⣻⣿⠀⠀⢸⣿⡇⢀⡙⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣦⣼⣿⡇⠀⠀⠀⢸⣿⡇⠀⣿⡗⠻⣿⣤⠀⣿⣿⣴⣿⡟⠀⠀⢸⣿⡗⢺⡇⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⢰⡆⠀⢸⣿⡟⢿⣧⡀⠀⢀⣾⡿⠁⢀⣿⡇⠀⣽⣿⠀⣿⣿⠈⢻⣿⡆⠀⢸⣿⡇⠀⣠⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠘⠛⠛⠛⠉⠀⠀⠈⠛⠛⠛⠁⠀⠘⠛⠛⠛⠛⠛⠁⠛⠛⠛⠛⠀⠙⠛⠛⠛⠛⠛⠛⠛⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "    ⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇\n" RESET);
        printf(BBLU "     ⠛⠷⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠾⠛⠀\n" RESET);
        printf("\n\n");
        printf(BBLU "Qual a origem do jogo?\n\n" RESET);
        printf("O jogo " BBLU "Resta Um" RESET " e conhecido em todo o mundo. Ha diversas historias sobre sua origem. \nConsta no Dicionario de jogos (1973) que Ovidio, poeta da Antiguidade, ja mencionava\num jogo de paciência semelhante a ele; em seus registros, descreve o tabuleiro como\numa mesa com varias cavidades onde se colocavam bolas, sendo necessario tirar uma\ndelas para move-las.\n");
        printf("\nDesde a Idade Media existiam na Franca pequenos tabuleiros redondos com buracos em\nque se colocavam as pecas, dai nasceu o Resta Um (Solitario) no seculo XVII, ou talvez\nnos finais do seculo XVI; porem, nao se sabe ao certo por quem ou quando foi inventado.\n\nUma das historias nao confirmadas, mas muito difundida, apresentada pela revista\nSuperinteressante (1990), diz que foi inventado por um prisioneiro encarcerado numa\nsolitaria da Bastilha.");
        printf("\n\nEm outro registro existente, uma carta de 1716, o filosofo e matemático Leibniz exaltava\nas virtudes desse passatempo, recomendando-o como uma boa forma de exercitar o raciocinio.\n");
        printf("De acordo ainda com diferentes fontes, este jogo parece ter origem do jogo Damas chinesas\n(Chinese Checkers) ou Raposas e Gansos.\n\n");
        printf(BBLU "Quantos podem jogar?\n\n" RESET);
        printf("O jogo quebra-cabeca e para um unico jogador.\n\n");
        printf(BBLU "Qual o formato do tabuleiro? Como ele inicia?\n\n" RESET);
        printf("O jogo e composto por um tabuleiro quadrado, com 33 orificios em formato de +. Ele comeca\ncom 32 pecas e apenas um espaco vazio na posicao central, como o tabuleiro abaixo. \n\n\n");
        imprimeMatriz(mat);
        printf("\n\n");
        printf("Voltar (S ou N)? ");
        scanf("%c", &carac);
    }while(carac != 'S' && carac != 's');
}

void exibeRegras(){
    char carac;
    do{
        getchar();
        system(CLEAR);
        printf(BBLU "    ⣠⡴⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⢦⣄⠀\n" RESET);
        printf(BBLU "    ⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠠⣤⣤⣤⣤⣀⠀⠀⢤⣤⣤⣤⣤⡄⠀⢀⣠⣤⣤⣤⡄⢠⣤⣤⣤⣤⡀⠀⠀⠀⠀⠀⣠⡄⠀⠀⠀⢀⣤⣤⣤⠀⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠀⠀⣿⡇⠘⣿⡆⠀⠀⣿⣿⠀⢀⠃⣰⡿⠃⠀⠀⠈⠃⠀⢸⣿⡇⢸⣿⠀⠀⠀⠀⢠⣿⣿⡀⠀⠀⣿⣇⠀⠘⠃⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠀⠀⣿⡧⣼⣟⠁⠀⠀⣿⣿⠖⢾⠀⣿⡇⠀⠀⣀⣀⣀⡀⢸⣿⣧⣼⣟⠀⠀⠀⢀⣿⠀⢿⣷⠀⠀⠘⠿⣷⣦⡀⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠀⢀⣿⡇⠙⣿⣦⠀⠀⣿⣿⠀⠈⡄⠻⣿⣆⠀⠉⣻⣿⠁⢸⣿⡇⠹⣿⣆⠀⠀⣾⠋⠉⠉⣿⣧⠀⣆⠀⠈⣿⡇⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠐⠚⠛⠓⠂⠈⠛⠛⠒⠛⠛⠛⠛⠃⠀⠈⠙⠛⠛⠋⠁⠐⠚⠛⠓⠂⠈⠛⠓⠚⠛⠒⠀⠒⠛⠛⠓⠛⠛⠛⠋⠀⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n" RESET);
        printf(BBLU "    ⠙⠷⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠾⠋⠀\n" RESET);
        printf("\n\n");
        printf(BBLU "Como jogar?\n\n" RESET);
        printf("Você deve movimentar as pecas. Um movimento consiste em pegar uma peca e faze-la saltar\nsobre outra peca, sempre na horizontal ou na vertical, terminando em um espaco vazio. \nLogo apos o salto, remove-se do tabuleiro o pino que o movimento saltou por cima.\nIsto continua ate que nao ha maissaltos que ossam ser feitos.\n\n");
        printf(BBLU "Qual o objetivo?\n\n" RESET);
        printf("O objetivo e deixar apenas um unico pino no tabuleiro.\n\n");
        printf(BBLU "Regras:\n\n" RESET);
        printf(BBLU "1. " RESET);
        printf("Voce deve mudar de posicao a cada jogada.\n");
        printf(BBLU "2. " RESET);
        printf("Os movimentos devem ser feitos nos limites do tabuleiro.\n");
        printf(BBLU "3. " RESET);
        printf("E impedida a ida para posicoes onde ja existam pecas.\n");
        printf(BBLU "4. " RESET);
        printf("E impedido o movimento diferente de duas posicoes.\n");
        printf(BBLU "5. " RESET);
        printf("So sao permitidos movimentos na horizontal ou na vertical.\n");
        printf(BBLU "6. " RESET);
        printf("So sao permitidos movimentos sobre casas que tenham pecas.\n");
        printf(BBLU "7. " RESET);
        printf("Na origem do movimento deve existir uma peca.\n");
        printf("\n\nVoltar (S ou N)? ");
        scanf("%c", &carac);
    }while(carac != 'S' && carac != 's');
}

int main(void){ 
    char matriz[7][7];
    int op;
    while(1){
        system(CLEAR);
        printf(BBLU "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠛⠛⠛⠛⠛⠛⠛⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠛⠛⠛⠛⠛⢻⣷⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⡾⠛⠁⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⣀⣠⣤⣶⠶⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⢸⡏⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣤⣸⣷⣶⣶⣶⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠈⢻⣿⣍⣉⣉⣉⣉⣻⡇⠀⠀⠀⢀⣀⣀⣀⣀⡀⢸⣿⡟⠛⠛⠛⣿⣦⣀⣀⣀⣀⣀⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⢰⡆⠀⠀⠀⣿⣿⠟⠋⠉⠉⠉⠛⢷⣄⣶⠟⠉⠉⠉⠉⠛⢿⡟⠃⠀⠀⠀⠛⣿⡿⠛⠉⠉⠉⠙⠻⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⢸⡇⠀⠀⠀⣿⡏⠀⠀⠀⣦⠀⠀⠀⢻⡇⠀⠀⢠⣦⠀⠀⠸⣧⡄⠀⠀⠀⣴⡟⠀⠀⠀⣦⠀⠀⠀⢸⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠠⣼⣿⡇⠀⠀⠀⠛⠀⠀⠀⢸⡇⠀⠀⠈⠻⣶⣶⣶⣿⡇⠀⠀⠀⣿⣇⣀⣀⣀⡿⠀⠀⠀⢸⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⢰⡆⠀⠀⠈⣿⡇⠀⠀⠀⣀⣀⣀⣀⣸⣿⣤⡀⠀⠀⠀⠉⠻⣿⡇⠀⠀⠀⣿⣿⠟⠋⠁⢀⠀⠀⠀⢸⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⢸⡇⠀⠀⠀⣿⡇⠀⠀⠀⣿⠀⠀⠀⢸⡟⠛⠛⢳⣤⠀⠀⠀⢿⡇⠀⠀⠀⣿⡇⠀⠀⠀⣿⠀⠀⠀⢸⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⡇⠀⠀⠀⢸⡇⠀⠀⠀⣿⡇⠀⠀⠀⠿⠀⠀⠀⣸⡇⠀⠀⠘⠿⠀⠀⠀⣾⡇⠀⠀⠀⢿⡇⠀⠀⠀⠿⠀⠀⠀⢸⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣇⣀⣀⣀⣸⣇⣀⣀⣀⣿⣿⣦⣀⣀⣀⣀⣠⣴⡿⠻⣦⣀⣀⡀⣀⣀⣴⣿⣷⣄⣀⣀⣈⣿⣄⣀⣀⣠⣀⣀⣀⣸⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠉⠀⠀⠈⠙⠛⠛⠛⠛⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣍⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣦⣤⣤⣤⣤⣤⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n" RESET);
        printf("\n\n");
        printf("[1] Iniciar jogo            [2] Sobre o jogo\n[3] Regras                  [4] Sair\n");
        scanf("%d", &op);
        if(op == 4) break;
        system(CLEAR);
        switch(op){
            case 1: 
                inicializaMatriz(matriz);
                iniciaJogo(matriz);
                break;
            case 2: 
                exibeSobreJogo();
                break;
            case 3:
                exibeRegras();
                break;
        }
        
    }    
    return 0;
}