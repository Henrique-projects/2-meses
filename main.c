#include <cs50.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool check(string key);

int main(int argc, string argv[])
{
    setlocale(LC_ALL, "portuguese");

    if(argc != 2)
    {
        printf("Use: ./main.c chave de substituição");

        return 1;
    }
    else if(!check(argv[1]))
    {
        printf("São necessários 26 caracteres...");
    
        return 1;
    }

    char texto[] = {argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4], argv[1][5], argv[1][6], argv[1][7], argv[1][8], argv[1][9], argv[1][10], argv[1][11], argv[1][12], argv[1][13], argv[1][14], argv[1][15], argv[1][16], argv[1][17], argv[1][18], argv[1][19], argv[1][20], argv[1][21], argv[1][22], argv[1][23], argv[1][24], argv[1][25]};

    string frase_simples = get_string("\nInsira a senha codificada para que o programa a decodifique: ");

    printf("\nA sua senha decodificada é: ");

    for(int j = 0; j < strlen(frase_simples); j++)
    {
        for(int i = 0; i < 26; i++)
        {
            if(isalpha(frase_simples[j]) && isupper(frase_simples[j]) && frase_simples[j] == toupper(texto[i]))
            {
                printf("%c", 65 + i);
            }
            else if(isalpha(frase_simples[j]) && islower(frase_simples[j]) && frase_simples[j] == texto[i])
            {
                printf("%c", 97 + i);
            }
            else if(!isalpha(frase_simples[j]) && frase_simples[j] > 0)
            {
                printf("%c", frase_simples[j]);

                break;
            }
            else if((int) frase_simples[j] < 0)
            {
                if(frase_simples[j] == -126)
                {
                    printf("é");
                    break;
                } 
                else if(frase_simples[j] == -23)
                {
                    printf("Ú");
                    break;
                }
                else if(frase_simples[j] == -121)
                {
                    printf("ç");
                    break;
                }
                else if (frase_simples[j] == - 96)
                {
                    printf("á");
                    break;
                }
                else if(frase_simples[j] == -120)
                {
                    printf("ê");
                    break;
                }
                else if(frase_simples[i] == -58)
                {
                    printf("ã");
                    break;
                }
                else if(frase_simples[j] == -94)
                {
                    printf("ó");
                    break;
                }
                else if(frase_simples[j] == -75)
                {
                    printf("Á");
                    break;
                }
                else if(frase_simples[j] == -128)
                {
                    printf("Ç");
                    break;
                }
                else if(frase_simples[j] == -112)
                {
                    printf("É");
                    break;
                }
                else if(frase_simples[j] == -32)
                {
                    printf("Ó");
                    break;
                }
                else if(frase_simples[j] == -57)
                {
                    printf("Ã");
                    break;
                }
                else if(frase_simples[j] == -93)
                {
                    printf("ú");
                    break;
                }
                else if(frase_simples[j] == -95)
                {
                    printf("í");
                    break;
                }
                else if(frase_simples[j] == -42)
                {
                    printf("Í");
                    break;
                }
                else if(frase_simples[j] == -109)
                {
                    printf("ô");
                    break;
                }
                else
                {
                    printf("%i", frase_simples[j]);
                    break;
                }
            }
        } 
    
    }

    string resposta = get_string("\n\nAgora insira a senha decodificada para revelar sua mensagem: ");

    if(strcmp(resposta, "EuTeAmoKelly!! Feliz dois meses!!!!") == 0)
    {
        printf("\n\n-------------------------------------------------------------------------------------------\n  E hoje fazemos nossos incríveis 2 meses juntinhos!!!!! Eu não sou bom em fazer presentes, até porque eu tenho 0 criatividade. Então talvez não seja muito bem o que você \nespere, me desculpa :(.\n  Como sempre eu não sei como começar um textinho KKKKKK. mas como sempre, eu vou começar dizendo que eu te amo muito muito muito muito muito muito muitos muitoes, cada \nmomento que eu passo com você se torna o melhor da minha vida, cada risada juntos, cada abraço reconfortante, cada zoação, cada BEEEEEAH, cada momento em que você dá \nalimento pra sua criança KKKKKKK, eu te amo demais meu amor, continue me alimentando :). Todos esses momentos fazem minha vida infinitamente melhor a cada dia que passa.\n  Antes de você cada dia só piorava, me sentia uma pessoa quebrada e sinceramente vivia só no automático, agora já não tenho mais dias ruins, é até estranho KKKKKK, você é meu conforto, como se fosse meu pote de sorvete que sempre consola a gente :).\n  Esses dois meses são só um pouco de uma vida muito, muito, muito, MUITO mais longa, ainda vamos viver vários meses juntinhos ouvindo nossas músicas, jogando vôlei, \ntirando print dos nossos rostos em momentos horríveis, mandando vários, vários e VÁRIOS vídeos um pro outro todos os dias.\n  Eu te amo e sempre vou te amar minha querida, você é meu bem mais precioso, meu sorvetinho de chocolate KKKKKK, meu bolinho de milho, meu tudo, sei que meu presente não \nfoi muito bem feito e elaborado ou até mesmo no tema, me desculpe, mas eu tentei fazer algo que você gostasse. <3\n\n--------------------------------------------------------------------------------");

        return 0;
    }
    else
    {
        printf("\n\nSenha incorreta >:(\n\n");

        return 1;
    }
}

bool check(string key)
{
    int tamanho;

    tamanho = strlen(key);

    if(tamanho < 26)
    {
        return false;
    }
    for(int i = 0; i < tamanho; i++)
    {
        if(!isalpha(key[i]))
        {
            return false;
        }
        for(int j = i + 1; j < tamanho; j++)
        {
            if(toupper(key[i]) == toupper(key[j]))
            {
                return false;
            }
        }
    }
    
    return true;
}