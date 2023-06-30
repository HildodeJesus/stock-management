#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void createFile(float fuelsEntry[3], float fuelsOutput[3])
{
  int type, month, day;
  FILE *fp;

  printf("\n\nQual extensão de arquivo prefere?\n1 - .csv (Excel)\n2 - .txt\n> ");
  scanf("%d", &type);

  if (type == 1)
  {
    fp = fopen("temp/relatórios.csv", "a");

    fprintf(fp, ",ÁLCOOL,GASOLINA,QUEROSENE");
    fprintf(fp, "\nENTRADA,%.2f,%.2f,%.2f", fuelsEntry[0], fuelsEntry[1], fuelsEntry[2]);
    fprintf(fp, "\nSAÍDA,%.2f,%.2f,%.2f", fuelsOutput[0], fuelsOutput[1], fuelsOutput[2]);
    fprintf(fp, "\nBALANÇO,%.2f,%.2f,%.2f", fuelsEntry[0] - fuelsOutput[0], fuelsEntry[1] - fuelsOutput[1], fuelsEntry[2] - fuelsOutput[2]);

    fclose(fp);
  }
  else if (type == 2)
  {
    printf("\n\nQual o dia de hoje?\n> ");
    scanf("%d", &day);
    printf("\n\nQual o mês que estamos?\n> ");
    scanf("%d", &month);

    float totalEntry = fuelsEntry[0] + fuelsEntry[1] + fuelsEntry[2];
    float totalOutput = fuelsOutput[0] + fuelsOutput[1] + fuelsOutput[2];
    float balanco = totalEntry - totalOutput;

    fp = fopen("temp/relatórios.txt", "a");

    fprintf(fp, "\n\nRelatório - %d/%d", day, month);
    fprintf(fp, "\n\nTotal de entrada de combustível: %.2f\nTotal de saída de combustível: %.2f\nBalanço atual: %.2f", totalEntry, totalOutput, balanco);
    fprintf(fp, "\n\nTotal de entrada de combustível: %.2f\nTotal de saída de combustível: %.2f\nBalanço atual: %.2f", totalEntry, totalOutput, balanco);

    fprintf(fp, "\n\nRelatório dos resevatórios:");
    fprintf(fp, "\n\nÁlcool:\n - Entrada: %.2f\n - Saída: %.2f\n - Balanço: %.2f", fuelsEntry[0], fuelsOutput[0], fuelsEntry[0] - fuelsOutput[0]);
    fprintf(fp, "\n\nGasolina:\n - Entrada: %.2f\n - Saída: %.2f\n - Balanço: %.2f", fuelsEntry[1], fuelsOutput[1], fuelsEntry[1] - fuelsOutput[1]);
    fprintf(fp, "\n\nQuerosene:\n - Entrada: %.2f\n - Saída: %.2f\n - Balanço: %.2f", fuelsEntry[2], fuelsOutput[2], fuelsEntry[2] - fuelsOutput[2]);

    fclose(fp);
  }

  printf("\n\nCriado com sucesso!\nOBS.: O arquivo gerado se encontra na pasta 'temp'");
}