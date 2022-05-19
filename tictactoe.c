/* 
   titulo: Jogo da Velha em C
   autor: Gustavo Villar Marinatto
   github: gustavo-villar-dev
   data: 19/05/2022
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

/*posicoes do jogo da velha. os nove quadrados possiveis*/
char quadrado[10] = {'o','1','2','3','4','5','6','7','8','9'}; /*"o" esta incluido para que os indices combinem com o numero*/
int verificarVitoria();
void desenharTabuleiro();

int main(void){
    int progresso; /*-1 se o jogo nao acabou, 0 se empatou, 1 se venceu*/
    int escolha; 
    int jogador = 1; /*mantem controle sobre qual jogador esta jogando*/
    char marca; /* X or O */

    do {
        fflush(stdin);
        desenharTabuleiro();
        jogador = (jogador % 2) ? 1 : 2;
        printf(">> Jogador %d, sua escolha: ", jogador);
        scanf("%d",&escolha);

        marca = (jogador==1) ? 'X' : 'O'; /*se for o jogador 1 entao marca X, senao marca O*/

        switch(escolha){
            case 1:
                if(quadrado[1] == '1')
                    quadrado[1] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 2:
                if(quadrado[2] == '2')
                    quadrado[2] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 3:
                if(quadrado[3] == '3')
                    quadrado[3] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 4: 
                if(quadrado[4] == '4')
                    quadrado[4] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 5: 
                if(quadrado[5] == '5')
                    quadrado[5] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 6:
                if(quadrado[6] == '6')
                    quadrado[6] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 7:
                if(quadrado[7] == '7')
                    quadrado[7] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 8:
                if(quadrado[8] == '8')
                    quadrado[8] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            case 9:
                if(quadrado[9] == '9')
                    quadrado[9] = marca;
                else{
                    printf("\n\t>> Opcao invalida! Pressione ENTER!");
                    jogador--; /*repetira a jogada do jogador atual*/
                    getch();
                }
                break;

            default:
                printf("\n\t>> Opcao invalida! Pressione ENTER!");
                jogador--; /*repetira a jogada do jogador atual*/
                getch();
            }

            progresso = verificarVitoria();
            jogador++; /*passa o turno pro proximo jogador*/

    } while(progresso == -1);

    /*pos termino do jogo*/
    desenharTabuleiro();                                     

    if(progresso == 1)/*mostra quem ganhou*/
    {
        printf(">> O jogador %d venceu!",--jogador); /*--jogador pq o loop incrementa*/
    }

    else /*empate*/
    {               
        printf(">> O jogo empatou.");
    }

    getch();
    return 0;
}

int verificarVitoria(){
    /*vitorias*/
    if (quadrado[1] == quadrado[2] && quadrado[2] == quadrado [3])
        return 1;

    else if(quadrado[4] == quadrado[5] && quadrado[5] == quadrado[6])
        return 1;

    else if(quadrado[7] == quadrado[8] && quadrado[8] == quadrado[9])
        return 1;

    else if(quadrado[1] == quadrado[4] && quadrado[4] == quadrado[7])
        return 1;

    else if(quadrado[2] == quadrado[5] && quadrado[5] == quadrado[8])
        return 1;

    else if(quadrado[3] == quadrado[6] && quadrado[6] == quadrado[9])
        return 1;

    else if(quadrado[1] == quadrado[5] && quadrado[5] == quadrado[9])
        return 1;

    else if(quadrado[3] == quadrado[5] && quadrado[5] == quadrado[7])
        return 1;
    
    /*empate*/
    else if(quadrado[1] != '1' && quadrado[2] != '2' && quadrado[3] != '3' && quadrado[4] != '4' && quadrado[5] != '5' && quadrado[6] != '6' && quadrado[7] != '7' && quadrado[8] != '8' && quadrado[9] != '9') 
        return 0;

    /*jogo rolando*/
    else
        return -1;
}

void desenharTabuleiro()
{

    system("cls");
    printf("\n\n\t Jogo da Velha \n\n");
    printf("Jogador 1 (X) - Jogador 2 (O) \n\n\n");

    printf("\t    |    |    \n");
    printf("\t %c  | %c  | %c  \n", quadrado[1],quadrado[2],quadrado[3]);
    printf("\t____|____|____    \n");
    printf("\t    |    |    \n");
    printf("\t %c  | %c  | %c  \n", quadrado[4],quadrado[5],quadrado[6]);
    printf("\t____|____|____    \n");
    printf("\t    |    |    \n");
    printf("\t %c  | %c  | %c  \n", quadrado[7],quadrado[8],quadrado[9]);
    printf("\t    |    |    \n\n");
    printf("\n");

}