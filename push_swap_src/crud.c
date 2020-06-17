/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crud.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:01:57 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:01:59 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int		delete_head(t_stack **head)
{
	int		n;
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	n = tmp->element;
	free(tmp);
	return (n);
}

int		delete_element(t_stack **stack, int number)
{
	int		i;
	int		n;
	t_stack	*p;
	t_stack	*prev;

	if (number == 0)
		return (delete_head(&(*stack)));
	i = 0;
	p = *stack;
	prev = NULL;
	while (p->next && i < number)
	{
		prev = p;
		p = p->next;
		i++;
	}
	prev->next = p->next;
	n = p->element;
	free(p);
	return (n);
}

int		delete_last(t_stack *stack)
{
	int		n;
	t_stack	*prev;
	t_stack	*p;

	p = stack;
	prev = NULL;
	while (p->next)
	{
		prev = p;
		p = p->next;
	}
	prev->next = NULL;
	n = p->element;
	free(p);
	return (n);
}

void	append_head(t_stack **stack, int element)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		raise_memory_error();
	tmp->element = element;
	tmp->next = *stack;
	*stack = tmp;
}
