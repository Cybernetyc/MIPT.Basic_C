#ifndef INTERFACE_H
#define INTERFACE_H

void print_keys(void);
void print_error_key(void);
void print_error_months (void);
void print_error_help_with_another_key (void);
void print_error_key_file(void);

typedef enum 
{
  ERR,
  CLC,          // Calculate
  HELP,
} status_t;

typedef struct 
{
  status_t status;
  char mounth;
  char path[60];
} result_of_arg_t;

result_of_arg_t interface (int argc, char *argv[]);

#endif