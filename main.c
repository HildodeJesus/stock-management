#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "register.h"

void main()
{
  int skip = 1, choose;
  float currentValue, fuels[3], *newFuelsValues;

  // fuels[0] - Alcool; fuels[1] - gasolina; fuels[2] - Querosene

  printf("Bem vindo ao controle de estoque!");
  while (skip == 1)
  {
    printf("\n\nO que deseja?\n1 - Entrada de caminhão\n2 - Saída de caminhão\n3 - Histórico\n4 - Sair\n> ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
    {
      newFuelsValues = registerNewEntry(fuels);
      fuels[0] = newFuelsValues[0];
      fuels[1] = newFuelsValues[1];
      fuels[2] = newFuelsValues[2];

      printf("\n\n%.2f", fuels[1]);

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