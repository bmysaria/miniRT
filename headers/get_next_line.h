#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int			get_next_line(int fd, char **line);
char		*ft_strchr(char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_strlenn(char *s);
char		*ft_strjoin_f(char *s1, char *s2);
char		*ft_strdup(char *s1);

#endif
