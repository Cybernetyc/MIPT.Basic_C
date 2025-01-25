#include "interface.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *optarg;

result_of_arg_t interface (int argc, char *argv[])
{
  int rez = 0;
  result_of_arg_t out = {0};

  char help = 0;
  char month = 0;
  char file = 0;
  char err = 0;

  while ((rez = getopt(argc, argv, "hHf:m:")) !=-1){
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
    
  if (err){
  out.status = ERR;
  print_error_key();
  return out;
  }
    
  if (help && (month || file)) {
    out.status = ERR;
    print_error_help_with_another_key();
    return out;
  }

  if ((month) && ((out.mounth >12) || (out.mounth < 1))){
    out.status = ERR;
    print_error_months();
    return out;
  }
  
  if (!file && !month && !help){
      print_error_key();
  }
  
 if ((!file) && (month)){
    print_error_key();
  }


  if (help){
    print_keys();
  }

  if (file){
    if (strlen(out.path) !=0 ){
       out.status = CLC;
       return out;
    }
    else {
      print_error_key_file();
    }
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
  puts("\n\t  No such key exists.\n  Use the -H or -h switches to get help\n\n");
}

void print_error_months(void)
{
  puts("\n=========================================");
  puts("=\t\t ERROR\t\t\t=");
  puts("=========================================");
  puts("\n   The month must be between 1 and 12\n");
}

void print_error_help_with_another_key(void)
{
  puts("\n=========================================");
  puts("=\t\t ERROR\t\t\t=");
  puts("=========================================");
  puts("\n   The -h switch is entered separately\n\
          from other switches.\n\
  Use the -H or -h switches to get help\n"); 
}

void print_error_key_file(void)
{
  puts("\n=========================================");
  puts("=\t\t ERROR\t\t\t=");
  puts("=========================================");
  puts("\n\t  Path to file = 0.\n  Use the -H or -h switches to get help\n\n");
}