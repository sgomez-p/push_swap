/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/23 13:13:11 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* lo primero q haremos es pasarle los numeros y las columnas para verlo gráficamente.
Me tiene que crear un box con ellos. Los n los recibimos como un str*/
void	create_box(situation *situ, int argc, char **argv)
{
	int		i;
	box		*current;
	situ->movements = NULL;
	situ->box_b = NULL;
	current = (box*)malloc(sizeof(box));
	error_manage((int)(current))
	situ->box_a = current;
	i = 0;
	error_manage(!(i >= argc -1)); /*no entiendo bien esta gestion*/
	while(++i < argc)
	{
		current->n = ft_atoi(argv[i]);
		current->next = NULL;
		if(i + 1 < argc)
		{
			current->next = (box*)malloc(sizeof(box));
			/*error*/
			current = current->next;
		}
		situ->final_a = current; /*hacer la funcion para q nos pille el ultimo nodo*/
		free(current);
	}
}

int	write_box_a(box *box)
{
	box current;

	current = box;
	while(current != NULL)
	{
		ft_putnbr(current->n);
		while(current->next)
			current = current->next;
	}
	ft_putstr("\n");
}

int	write_box_b(box *box)
{
	box *current;

	current = box;
	while(current != NULL)
	{
		ft_putstr("         ");
		ft_putnbr(current->next);
		while(current->next)
			current = current->next;
	}
}

/*gestionar los errores que me pueda pasar*/
void error_no_nbr(int argc, char **argv)
{	
	int	i;
	
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (check_is_nbr(argv[i]) == 0)
				quit();
			i++;
		}
	}
}

int	check_is_nbr(char **argc)
{
	int i;
	
	i = 1;
	if(argc[i] < '0' || argc[i] > '9')
		return (0);
	i++;
	return (1);
}
















/*
t_list	pre_lst(char **argv)
{
	t_list	*box_a;
	int		i;
	int		j;

	box_a = NULL;
	while (argv[i])
	{
		j = 0; //no se pq hace esto supongo q luego se usa puede q en el lst2
		push_to_lst(argv, i, &j, &box_a);
		i++;
	}
}

void	push_to_lst(char **argv, int i, int *j, t_list **box_a)
{
	long int	nbr;

	nbr = 0;
	while (argv[i][(*j)])
	{
		nbr = ft_atoi((argv[i] + (*j)));
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit ;
		save_nbr(box_a, nbr);
		while (argv[i][(*j)] == '-' || argv[i][(*j)] == '+') //omite caracteres q no sean signos o espacios etc
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
		while (ft_isdigit(argv[i][(*j)]))
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
	}
}

static void	save_nbr(t_list **box, int n)
{
	t_list	*tmp;

	if (*box == NULL) //si acaba el null simplemente le añades un nodo mas
		*box = ft_lstnew(n);
	else
	{
		tmp = ft_lstnew(n);
		ft_lstadd_back(box, tmp); //añade nodo new al final de la lista
	}
}

int	check_is_nbr(char *nbr)
{
	int i;
	
	i = 0;
	/**
	 ** estamos controlando signos y caracterres raros
	 */
	while(str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && \
			(str[i] < '0' || str[i] > '9') && \
			str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	/**
	 
	 *? aqui hay mas condiciones q no entiendo muy bien pq me parecen repetitivas
	 */
	while(str[i])
	{
		if (i == 0 && str[i] != '-' && str[i] != '+')
			(str[i * 1] < '0' || str[i + 1] > '9') && \ 
			return (0);
		i++;
	}
	return (1);
} 
