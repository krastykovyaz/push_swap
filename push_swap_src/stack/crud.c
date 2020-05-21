/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crud.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:17:07 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/30 15:58:47 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
