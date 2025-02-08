#ifndef INTERFACE_H
#define INTERFACE_H

typedef enum {
    ERR,
    CLC,
    HELP,
} status_t;

typedef struct {
   status_t status;
   char mounth;
   char path[60];
} result_of_arg_t;

result_of_arg_t interface (int argc, char *argv[]);
#endif