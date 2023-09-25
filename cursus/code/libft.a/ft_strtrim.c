#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t	len;
	char	*final;
	
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != 0) //increment until characters not found
		s1++;

	len = ft_strlen(s1);

	while (len && ft_strchr(set, s1[len - 1]) != 0) //decrement len until character not found
		len--;
	
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	ft_memcpy(final, s1, len);
	
    final[len] = '\0';
	
	return (final);
}

/*int main(void)
{
    char a[] = "ba ba ba bafgse sfjgoer reg ba ba aefierfherhgie rba ba ba ba ba ba";
    char b[] = "ba ba";
    printf("Result:: %s\n",ft_strtrim(a,b));

}*/