/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:57:05 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 13:33:45 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

# define BLACK     "\033[1;30m"
# define RED       "\033[1;31m"
# define GREEN     "\033[1;32m"
# define YELLOW    "\033[1;33m"
# define BLUE      "\033[1;34m"
# define PURPLE    "\033[1;35m"
# define CYAN      "\033[1;36m"
# define GREY      "\033[1;37m"
# define BUFF_SIZE 100

/*
** Lists and Strutures
*/

typedef struct		s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Functions for Lists and Strutures
*/

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, char *s2);
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *str);
char				*ft_strncat(char *s1, char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strlcat(char *dst, const char *src, size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, int c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_swap(void **a, void **b);
void				ft_join(char **str1, char *str2);
char				*ft_strndup(const char *s1, size_t n);
void				ft_deltab(char ***str);
int					get_next_line(int const fd, char **line);
int					ft_intlen(int n);

#endif
