#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validar(char num[])
{
for (int i = 0; i < strlen(num); i++)
{
if (!(isdigit(num[i])))
{
printf("Recuerde que solo lleva numeros\n");
getchar();
return 0;
}
}
return 1;
}
int validarlet(char let[])
{
for (int i = 0; i < strlen(let); i++)
{
if (!(isalpha(let[i])))
{
printf("Recuerde que solo lleva letras\n");
getchar();
return 0;
}
}
return 1;
}
int validarpunto(char num[])
{
for (int i = 0; i < strlen(num); i++)
{
if (isdigit(num[i]) || num[i] == '.')
{
return 1;
}
}
printf("Recuerde que solo lleva numeros\n");
getchar();
return 0;
}