#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef LIBFT_H
#define LIBFT_H

void    *ft_memset(void *s,int c,size_t n);
void    ft_bzero(void *s,size_t n);
void    *ft_memcpy(void *dest,const void *src,size_t n);
void    *ft_memmove(void *dst,const void *src,size_t len);

char    *ft_strchr(const char *str,int character);
char    *ft_strrchr(const char* str,int i);
int    ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_calloc(size_t count, size_t size)

#endif