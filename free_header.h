#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int 	nl_check(char *s);
int 	ft_strlen(char *s);

#endif // HEADER_H