#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float *registerNewOutput(float fuelsOutput[3], float fuelsEntry[3])
{
  int skip = 1, type, currentValue;
  float outputVol;

  while (skip == 1)
  {
    printf("\n\nQual combustível será retirado?\n1 - Álcool\n2 - Gasolina\n3 - Querosene\n> ");
    scanf("%d", &type);

    switch (type)
    {
    case 1:
    {
      printf("\n\nVolume no Resevatório de Alcool: %.2f", fuelsEntry[0]);
      printf("\n\nQuantos litros deseja retirar?\n> ");
      scanf("%f", &outputVol);

      if (outputVol <= fuelsEntry[0])
      {
        fuelsOutput[0] = fuelsOutput[0] + outputVol;
        fuelsEntry[0] = fuelsEntry[0] - outputVol;
        printf("\nRetirada de combustível realizada com sucesso!");
      }
      else
      {
        printf("\nRetirada não permitida. Ultrapassou o total em resevatório");
      }

      break;
    }
    case 2:
    {
      printf("\n\nVolume no Resevatório de Gasolina: %.2f", fuelsEntry[1]);
      printf("\n\nQuantos litros deseja retirar?\n> ");
      scanf("%f", &outputVol);

      if (outputVol <= fuelsEntry[1])
      {
        fuelsOutput[1] = fuelsOutput[1] + outputVol;
        fuelsEntry[1] = fuelsEntry[1] - outputVol;

        printf("\nRetirada de combustível realizada com sucesso!");
      }
      else
      {
        printf("\nRetirada não permitida. Ultrapassou o total em resevatório");
      }

      break;
    }
    case 3:
    {
      printf("\n\nVolume no Resevatório de Querosene: %.2f", fuelsEntry[2]);
      printf("\n\nQuantos litros deseja retirar?\n> ");
      scanf("%f", &outputVol);

      if (outputVol <= fuelsEntry[2])
      {
        fuelsOutput[2] = fuelsOutput[2] + outputVol;
        fuelsEntry[2] = fuelsEntry[2] - outputVol;

        printf("\nRetirada de combustível realizada com sucesso!");
      }
      else
      {
        printf("\nRetirada não permitida. Ultrapassou o total em resevatório");
      }

      break;
    }

    default:
    {
      printf("Opção inválida!");
      break;
    }
    }

    printf("\n\nDeseja continuar retirando combustível? (1 - Sim ou 2 - Não)");
    scanf("%d", &skip);
  }

  return fuelsOutput;
}