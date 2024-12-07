/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:31:33 by ayarab            #+#    #+#             */
/*   Updated: 2024/12/02 14:47:31 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_add_tab_cmd(t_exec_line *line, char **tab)
{
	t_exec	*current;
	t_exec	*new;

	new = ft_malloc(sizeof(t_exec));
	if (!new)
		return ;
	current = line->first;
	new->cmd = tab;
	new->next = NULL;
	if (!current)
		line->first = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

char	**ft_add_to_tab(t_token *current, char **tab)
{
	int	i;

	i = 0;
	while (current && current->type != PIPE)
	{
		if (current->type == WORD || current->type == SFX)
		{
			tab[i] = ft_strdup(current->content);
			if (!tab[i])
				return (NULL);
			i++;
		}
		current = current->next;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_display_exec(t_exec_line *line)
{
	t_exec	*current;
	int		i;

	current = line->first;
	while (current)
	{
		i = 0;
		while (current->cmd[i])
		{
			printf("[%s] ----------> [%d] = etage de la cmd\n", current->cmd[i],
				i);
			i++;
		}
		current = current->next;
	}
	printf("\nFIN DE LA LIST DE EXEC\n");
}

int	ft_check_word(t_shell *shell)
{
	t_token	*current;

	current = shell->command->first;
	while (current)
	{
		if (current->type == WORD)
			return (EXIT_SUCCESS);
		current = current->next;
	}
	return (EXIT_FAILURE);
}
