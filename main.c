#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "registerNewEntry.h"
#include "registerNewOutput.h"
#include "createFile.h"

void main()
{
  int skip = 1, choose;
  float fuelsEntry[3], fuelsOutput[3], *newFuelsValues;
  // FuelsEntry/Output (0 - Alcool; 1 - Gasolina; 2 - Querosene)

  for (int i = 0; i < 3; i++)
  {
    fuelsEntry[i] = 0.0;
    fuelsOutput[i] = 0.0;
  }

  printf("Bem vindo ao controle de estoque!");
  while (skip == 1)
  {
    printf("\n\nO que deseja?\n1 - Entrada de caminhão\n2 - Saída de caminhão\n3 - Listar dados cadastrados\n4 - Gerar arquivo com relatório\n5 - Sair\n> ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
    {
      newFuelsValues = registerNewEntry(fuelsEntry);
      fuelsEntry[0] = newFuelsValues[0];
      fuelsEntry[1] = newFuelsValues[1];
      fuelsEntry[2] = newFuelsValues[2];

      break;
    }
    case 2:
    {
      newFuelsValues = registerNewOutput(fuelsOutput, fuelsEntry);
      fuelsOutput[0] = newFuelsValues[0];
      fuelsOutput[1] = newFuelsValues[1];
      fuelsOutput[2] = newFuelsValues[2];

      break;
    }
    case 3:
    {
      printf("\n\nRelatório dos resevatórios:");
      printf("\n\nÁlcool:\n - Total de entradas: %.2f\n - Total de saídas: %.2f\n - Disponível em resevatório: %.2f", fuelsEntry[0], fuelsOutput[0], fuelsEntry[0] - fuelsOutput[0]);
      printf("\n\nGasolina:\n - Total de entradas: %.2f\n - Total de saídas: %.2f\n - Disponível em resevatório: %.2f", fuelsEntry[1], fuelsOutput[1], fuelsEntry[1] - fuelsOutput[1]);
      printf("\n\nQuerosene:\n - Total de entradas: %.2f\n - Total de saídas: %.2f\n - Disponível em resevatório: %.2f", fuelsEntry[2], fuelsOutput[2], fuelsEntry[2] - fuelsOutput[2]);

      break;
    }
    case 4:
    {
      createFile(fuelsEntry, fuelsOutput);

      break;
    }

    case 5:
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