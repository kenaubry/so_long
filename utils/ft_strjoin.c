/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:33:10 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:33:12 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*

The realloc() function changes the size of the memory block pointed 
to by ptr to size bytes. The contents will be unchanged in the range 
from the start of the region up to the minimum of the old and new sizes. 
If the new size is larger than the old size, the added memory will not 
be initialized.  If ptr is NULL, then the call is equivalent to 
malloc(size), for all values of size; if size is equal to zero, and 
ptr is not NULL, then the call is equivalent to free(ptr). Unless ptr 
is NULL, it must have been returned by an earlier call to malloc(), 
calloc() or realloc(). If the area pointed to was moved, a free(ptr) 
is done.

The realloc() function returns a pointer to the newly allocated memory, 
which is suitably aligned for any kind of variable and may be different 
from ptr, or NULL if the request fails. If size was equal to 0, either 
NULL or a pointer suitable to be passed to free() is returned. If 
realloc() fails the original block is left untouched; it is not freed 
or moved.

*/

static void    *ft_realloc_str(char *ptr, size_t size)
{
    char    *new;
    int      i;

    i = 0;
    if (ptr == NULL)
    {
        new = malloc(size);
        if (!new)
            exit(1);
        return (new);
    }
    else if (size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }
    while (ptr[i])
    {
        new[i] = ptr[i];
        i++;
    }
    free(ptr);
    return (new);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
    //printf("len 1 = %ld, len 2 = %ld\n", ft_strlen(s1), ft_strlen(s2));
    //printf("str p = %p\n", &str);
    //str = NULL;
    //str = ft_realloc_str(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (str == 0)
		return (NULL);
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	if (s2)
		while (*s2)
			str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
