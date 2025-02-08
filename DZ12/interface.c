#include "interface.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *optarg;

void print_keys(void);
void print_error_key(void);

result_of_arg_t interface (int argc, char *argv[])
{
    int rez = 0;
    result_of_arg_t out;

    char help = 0;
    char month = 0;
    char file = 0;
    char err = 0;

    while ((rez = getopt(argc, argv, "hHf:m:")) !=-1)
    {
        switch (rez)
        {
        case 'h':
        case 'H':
            help = 1;
            break;
        case 'f':
            file = 1;
            strcpy(out.path, optarg);
            break;
        case 'm':
            month = 1;
            out.mounth = atoi(optarg);
            break;
        case '?':
            err = 1;
            break;
        }
    }
    
    if (err)
    {
      out.status = ERR;
      print_error_key();
      return out;
    }
    
    if (help && (month || file)) {
        out.status = ERR;
        print_error_key();
        return out;
    }

    if ((month >12) || (month < 1)){
        out.status = ERR;
        return out;
    }

    return out;
}




void print_keys(void)
{
    puts("\n=========================================");
    puts("\tThis console application\n\
     displays temperature statistics\n\
   collected by the sensor for a year.");
    puts("=========================================");
    puts("\n\tBelow is a list of keys\n\
    that processes this application\n\
           and their purpose.");
    puts("");
    puts(" -f [path to file]               OUTPUT STATISTICS");
    puts(" -f [path to file] -m [mounth]   OUTPUT STATISTICS CURRENT MOUNTH");
}





void print_error_key(void)
{
    puts("\n=========================================");
    puts("=\t\t ERROR\t\t\t=");
    puts("=========================================");
    puts("\n\t  No such key exists.\n  Use the -H or -h switches to get help\n");
}