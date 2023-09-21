#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#ifndef LIBFT_H
#define LIBFT_H

//part 1
int         ft_isalpha(int c);
int         ft_isdigit(int c);
int         ft_isalnum(int c);
int         ft_isascii(int c);
int         ft_isprint(int c);
size_t      ft_strlen(const char *s);
void        *ft_memset(void *s, int c, size_t n);
void        ft_bzero(void *s, size_t n);
void        *ft_memcpy(void *dest, const void *src, size_t n);
void        *ft_memmove(void *dst, const void *src, size_t len);
size_t      ft_strlcpy(char *dst, const char *src, size_t maxlen);
size_t      ft_strlcat(char * restrict dst, const char * restrict src, size_t destsize);
int         ft_toupper(int c);
int         ft_tolower(int c);
char        *ft_strchr(const char *str, int character);
char        *ft_strrchr(const char* str, int i);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
int         ft_memcmp(const void *s1, const void *s2, size_t n);
char    *strnstr(const char *haystack, const char *needle, size_t len);
int         ft_atoi(char *str);
void        *ft_calloc(size_t count, size_t size);
char        *ft_strdup(const char *s1);
char        *ft_strjoin(char const *s1, char const *s2);
char        *ft_strtrim(char const *s1, char const *set);
//part 2
char    *ft_substr(char const *s, unsigned int start, size_t len);
#endif