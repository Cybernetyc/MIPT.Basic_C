#include "module_for_FILE_read.h"
#include "struct.h"
#include <stdio.h>

void FILE_Read(char path[])
{
    char string[60] = {0};
    sensor_t temp_rec;
    FILE *f;
    f = fopen(path,"r"); // открытие файла in.txt на запись
  
    while (fscanf (f, "%s\n", string) == 1)
    {
      if (sscanf (string, "%hd;%hhd;%hhd;%hhd;%hhd;%hhd", &temp_rec.year, &temp_rec.month,  &temp_rec.day,
                                                          &temp_rec.hour, &temp_rec.minute, &temp_rec.temperature) != 6)
      {
        perror("ERROR!");
        continue;
      }

      printf ("%hd %hd %hd %hd %hd %hd\n", temp_rec.year, temp_rec.month, temp_rec.day,
                                           temp_rec.hour, temp_rec.minute, temp_rec.temperature);
    }
    ftell(f);
    
    fclose(f);  //Закрытие файла. После окончания работы с файлом необходимо убедиться, что все записанные данные попали на диск, и освободить все ресурсы, связанные с ним.
}
