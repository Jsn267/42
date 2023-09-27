#include "libft.h"

int Actual_len(char const *s, char c)
{
    int len;
    char *ss;

    ss = (char *)s;
    while(*ss)
    {
        while (*ss == c)//chg to next ptr 
            ss++;
        if (*ss)
            len++;
        while (*ss && *ss != c)//for loop
            ss++;
    }
     return (len);
}

char **ft_split(char const *s, char c)
{
    int len;
    char **rtn;
    char *tmp;

    tmp = (char *)s;
    len = Actual_len(s,c);
    rtn = (char **)malloc((len + 1) * (sizeof(char *)));

    while (*tmp)
	{
		while (*s == c)//chg ptr
			s++;
		tmp = (char *)s;
		while (*tmp && *tmp != c)//gtring each element of arr
			tmp++;
		if (*tmp == c || tmp > s)// chg to next ptr
		{
			*rtn = ft_substr(s, 0, tmp - s);
			s = tmp;
			rtn++;
		}
	}
	*rtn = NULL;

    return (rtn);
}
int main(void)
{
    char a[]="a,b,v,c,d,e,f,eef,ee,d,e,e,";
    char c = ',';
    int i = 0;
    int j = 0;
    char ** b;
    b = ft_split(a,c);
    printf("Reuslt::: %p\n", b);

    while(b[i][j] != '\0')
    {
        while(b[i][j] != '\0')
        {
            printf("%c",b[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}