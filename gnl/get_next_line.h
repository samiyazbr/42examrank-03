#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif