#include <stdio.h>
//Biblioteca para acessar funções de tempo 
#include <time.h>

//estrutura para armazenar o horario (hora, minuto e segundo)
struct Horario
{
    int hora;
    int minuto;
    int segundo;
};

//função para mostrar o horario no formato HH:MM:SS
void mostrarHorario(struct Horario agora)
{
    printf("Horario: %02d:%02d:%02d\n", agora.hora, agora.minuto, agora.segundo);
}


//função para adicionar 1 segundo ao horario, ajustando o minuto e a hora conforme necessário
void adicionarSegundo(struct Horario *horario)
{
    horario->segundo=horario->segundo+1;

    if (horario->segundo==60)
    {
        horario->segundo=horario->segundo%60;
        horario->minuto=horario->minuto+1;
    }

    if (horario->minuto==60)
    {
        horario->minuto=horario->minuto%60;
        horario->hora=horario->hora+1;
    }

    if (horario->hora==24)
    {
        horario->hora=horario->hora%24;
    }
}

//função para verificar se o horario é valido (hora<24, minuto<60, segundo<60 e todos>=0)
int horarioValido(struct Horario agora)
{
    if (agora.hora<24 && agora.minuto<60 && agora.segundo<60 && agora.hora>=0 && agora.minuto>=0 &&agora.segundo>=0)
    {
        return 1;
    }
    return 0;
}

//aqui ta a razão para usar a biblioteca time.h, para fazer o programa esperar um segundo antes de atualizar o horario, a função time(NULL) retorna o tempo de agora em segundos, então podemos usar isso para criar um loop que espera até que um segundo tenha passado
void esperarUmSegundo()
{
    time_t inicio=time(NULL);
    while(time(NULL)-inicio<1);
}

int main()
{
    int X, Y, Z;

    printf("Qual o horario exato agora? (HH:MM:SS): ");
    scanf("%d:%d:%d", &X, &Y, &Z);

    struct Horario agora={X, Y, Z};

    if (horarioValido(agora))
    {
        printf("Horario valido!\n");

        while (1)
        {
            mostrarHorario(agora);
            esperarUmSegundo();
            adicionarSegundo(&agora);
        }
    }
    else
    {
        printf("Horario invalido!\n");
    }

    return 0;
}
