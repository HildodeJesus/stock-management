#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float *registerNewEntry(float fuels[3])
{
  int skip = 1, type, i;
  float currentWeight;

  while (skip == 1)
  {
    printf("\n\nQual o tipo de combustível deseja cadastrar?\n1 - Álcool\n2 - Gasolina\n3 - Querosene\n> ");
    scanf("%d", &type);

    printf("\n\nQuantos quilos(kg) possui a entrada?\n> ");
    scanf("%f", &currentWeight);

    switch (type)
    {
    case 1:
    {

      fuels[0] = fuels[0] + (currentWeight / 0.783); // A cada 783g(0.783kg) um litro de Alcool

      printf("\nÁlcool cadastrado com sucesso!");

      break;
    }
    case 2:
    {
      fuels[1] = fuels[1] + (currentWeight / 0.75); // A cada 750g(0.75kg) um litro de gasolina

      printf("\nGasolina cadastrada com sucesso!");

      break;
    }
    case 3:
    {
      fuels[2] = fuels[2] + (currentWeight / 0.817); // A cada 817g(0.817kg) um litro de Querosene

      printf("\nQuerosene cadastrado com sucesso!");
      break;
    }

    default:
    {
      printf("\nOpção inválida!");
      break;
    }
    }

    printf("\n\nDeseja cadastrar mais uma entrada? (1 - Sim ou 2 - Não)\n> ");
    scanf("%d", &skip);
  }

  return fuels;
}