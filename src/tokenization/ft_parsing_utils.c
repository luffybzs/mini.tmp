/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:58:44 by utilisateur       #+#    #+#             */
/*   Updated: 2024/12/02 14:46:48 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_next_char(char *str, char c, int *i, int *j)
{
	(*j)++;
	while (str[*i + *j] != c)
		(*j)++;
}

int	ft_skip_spaces(char *str, int *i)
{
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_len_word(char *command, int i, char c)
{
	int	len;

	len = 0;
	while (command[i + len])
	{
		while (command[i + len] == c)
		{
			++len;
			while (command[i + len] && command[i + len] != c)
				++len;
			++len;
		}
		if (ft_isspace(command[i + len]))
			break ;
		if (command[i + len])
			++len;
	}
	return (len);
}

char	*ft_supp_quote(char *command, int i, int *j, char c)
{
	char	*word;
	int		len;
	int		tmp;

	tmp = 0;
	len = ft_len_word(command, i, c);
	if (len == -1)
		return (NULL);
	*j = len + (command[i + len] != '\0');
	word = ft_malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (len)
	{
		if (command[i] == c)
			i++;
		else
			word[tmp++] = command[i++];
		len--;
	}
	word[tmp] = '\0';
	return (word);
}

char	*ft_supp_quote2(char *command, char c, int i)
{
	char	*word;
	int		len;
	int		tmp;

	tmp = 0;
	len = ft_len_word(command, i, c);
	if (len == -1)
		return (NULL);
	word = ft_malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (len)
	{
		if (command[i] == c)
			i++;
		else
			word[tmp++] = command[i++];
		len--;
	}
	word[tmp] = '\0';
	return (word);
}
