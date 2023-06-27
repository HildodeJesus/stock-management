#include <stdio.h>
#include <stdlib.h>

void main()
{
  int skip = 1, choose;

  printf("Bem vindo ao controle de estoque!");
  while (skip == 1)
  {
    printf("\n\nO que deseja?\n1 - Entrada de caminhão\n2 - Saída de caminhão\n3 - Histórico\n4 - Sair\n> ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
    {

      break;
    }
    case 2:
    {

      break;
    }
    case 3:
    {

      break;
    }
    case 4:
    {
      skip = 2;
      break;
    }

    default:
    {
      printf("\nOpção inválida");
      break;
    }
    }
  }
}