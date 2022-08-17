#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void
desenhaforca (int vidas)
{

    if (vidas == 5)

    {

        printf ("+---+\n");

        printf ("|\n");

        printf ("|\n");

        printf ("|\n");

        printf ("|\n");

        printf ("=========\n");

    }

    if (vidas == 4)

    {

        printf ("+---+\n");

        printf ("|   O\n");

        printf ("|\n");

        printf ("|\n");

        printf ("|\n");

        printf ("=========\n");

    }

    if (vidas == 3)

    {

        printf ("+---+\n");

        printf ("|   O\n");

        printf ("|   I\n");

        printf ("|\n");

        printf ("|\n");

        printf ("=========\n");

    }

    if (vidas == 2)

    {

        printf ("+---+\n");

        printf ("|   O\n");

        printf ("|   I\n");

        printf ("|  /I\\ \n");

        printf ("|\n");

        printf ("=========\n");

    }

    if (vidas == 1)

    {

        printf ("+---+\n");

        printf ("|   O\n");

        printf ("|   I\n");

        printf ("|  /I\\ \n");

        printf ("|   I \n");

        printf ("=========\n");

    }

    if (vidas == 0)

    {

        printf ("+---+\n");

        printf ("|   O\n");

        printf ("|   I\n");

        printf ("|  /I\\ \n");

        printf ("|   I \n");

        printf ("   / \\");

        printf ("\n");

        printf ("=========\n");

    }

}


int
main ()
{


    char palavras[][20] =
    { "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito","nove", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete","dezoito", "dezenove", "vinte" };

    char d1[][20] =
    {
        "d1p1", "d1p2", "d1p3", "d1p4", "d1p5", "d1p6", "d1p7", "d1p8", "d1p9",
        "d1p10", "d1p11", "d1p12", "d1p13", "d1p14", "d1p15", "d1p16", "d1p17", "d1p18", "d1p19",
        "d1p20"
    };

    char d2[][20] =
    {
        "d2p1", "d2p2", "d2p3", "d2p4", "d2p5", "d2p6", "d2p7", "d2p8", "d2p9",
        "d2p10", "d2p11", "d2p12", "d2p13", "d2p14", "d2p15", "d2p16", "d2p17", "d2p18",
        "d2p19", "d2p20"
    };

    char d3[][20] =
    {
        "d3p1", "d3p2", "d3p3", "d3p4", "d3p5", "d3p6", "d3p7", "d3p8", "d3p9",
        "d3p10", "d3p11", "d3p12", "d3p13", "d3p14", "d3p15", "d3p16", "d3p17", "d3p18",
        "d3p19", "d3p20"
    };

    char d4[][20] =
    {
        "d4p1", "d4p2", "d4p3", "d4p4", "d4p5", "d4p6", "d4p7", "d4p8", "d4p9",
        "d4p10", "d4p11", "d4p12", "d4p13", "d4p14", "d4p15", "d4p16", "d4p17", "d4p18",
        "d4p19", "d4p20"
    };

    srand (time (NULL));

    int i;

    int n = rand () % 20;

    int vidas = 5;

    int acertos = 0;

    char letra;

    char resp[20];

    int verificaerro = 0;

    int palavrasadivinhadas[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


    printf
    ("Atencao, voce pode sair do jogo a qualquer momento! Basta digitar a palavra 'sair' e finalizaremos a partida!! Pressione qualquer tecla para comecar!\n\n");

    getchar ();

    system ("cls");


    while (acertos < strlen (palavras[n]))

    {

        verificaerro = 0;

        desenhaforca(vidas);

        for (int y = 0; y < strlen (palavras[n]); y++)

        {

            if (palavrasadivinhadas[y] == 1)

            {

                printf ("%c ", palavras[n][y]);

            }

            else

            {

                printf ("- ");

            }

        }

        printf ("\nLetras acertadas ate agora: %d\n", acertos);

        printf ("Vidas ate agora: %d\n", vidas);

        printf("Voce pode tentar arriscar a palavra a qualquer momento!! Basta digitar 'tentar'\n");

        switch (vidas)

        {

        case 5:

            printf ("Ainda nao ha dicas disponiveis!!\n");

            break;

        case 4:

            printf ("Primeira dica: %s\n", d1[n]);

            break;

        case 3:

            printf ("Segunda dica: %s\n", d2[n]);

            break;

        case 2:

            printf ("Terceira dica: %s\n", d3[n]);
            break;

        case 1:

            printf ("Ultima dica: %s\n", d4[n]);
            break;

        }

        printf ("Digite uma letra: ");

        gets (resp);

        if (strcasecmp (resp, "sair") == 0)

        {

            printf ("Voce abandonou a partida!");

            exit (0);

        }

        if (strcasecmp (resp, "tentar") == 0)

        {

            printf ("Digite a palavra:");

            gets(resp);

            if (strcasecmp(resp,palavras[n])==0)
            {
                printf("\n\nParabens!! Voce ganhou!!\n\n");
                exit(0);
            }
            else
            {
                printf("Voce se fudeu!!");
                vidas=0;
                desenhaforca(vidas);

                exit(0);
            }

        }

        letra = resp[0];

        system ("cls");

        for (i = 0; i < strlen (palavras[n]); i++)

        {

            if (palavrasadivinhadas[i] == 1)

            {

                continue;

            }

            if (letra == palavras[n][i])

            {

                acertos++;

                verificaerro++;

                palavrasadivinhadas[i] = 1;

            }

        }

        if (verificaerro == 0)

        {

            vidas--;

        }


        if (vidas == 0)

        {

            printf ("Voce se fudeu!\n\n");
            desenhaforca(vidas);

            exit (0);

        }

    }

    printf ("Parabens voce venceu!!");

    return 0;

}
