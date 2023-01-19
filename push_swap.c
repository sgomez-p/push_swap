/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/19 18:23:53 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

size_t ft_strlen(const char *s)
{
    size_t len;
    len = 0;
    while (s[len])
        len++;
    return (len);
}


int ft_isint(char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    if (len == 0)
        return (0);
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void	create_stack(t_stacks *situ, int argc, char **argv)
{
    t_stack *current;
    int i;

    current = (t_stack *)malloc(sizeof(t_stack));
    if (!current)
    {
        ft_putstr("Error al reservar memoria\n");
        exit(1);
    }
    situ->stack_a = current;
    current->next = NULL;
    i = 1;
    while (i < argc)
    {
        if (ft_isint(argv[i]) && (check_dup(ft_atoi(argv[i]), (situ->stack_a))))
        {   
            current->n = ft_atoi(argv[i]);
            if (i + 1 < argc)
            {
                current->next = (t_stack *)malloc(sizeof(t_stack));
                if (!(current->next))
                {
                    ft_putstr("Error al reservar memoria\n");
                    exit(1);
                }
                current = current->next;
                current->next = NULL;
            }
            i++;    
        }
        else
            ft_error();
    }
}

void	write_stack_a(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		ft_putnbr(current->n);
		ft_putchar('\n');
		current = current->next;
	}
	//free(current);
}

void	write_stack_b(t_stack *stack_b)
{
	t_stack	*current;

	if (stack_b == NULL)
	{
		ft_putstr("    ");
		return;
	}
	current = stack_b;
	while (current != NULL)
	{
		ft_putstr("       ");
		ft_putnbr(current->n);
		current = current->next;
		ft_putstr("\n");
	}
	//free(current);
}

int	main(int argc, char **argv)
{
	int		stack_len;
	//t_stack	*aux;
	t_stacks *current;

	//aux = NULL;
	current = (t_stacks *) malloc(sizeof(t_stacks) * 1);
	create_stack(current, argc, argv);
	stack_len = get_lenstack(current->stack_a);
	if (argc < 2)
	{
		ft_putstr("Introduce números a ordenar\n");
		return 0;
	}
	if(ft_validation(argc,argv))
	{
		//if (stack_len == 3)
		//	order3(current->stack_a);
		write_stack_a(current->stack_a);
		ft_putstr("\n1-------\n");
		ft_putstr("a");
		ft_putstr("    ");
		ft_putstr("b");
	//	write_stack_b(current->stack_b);
		if (stack_len == 5)
		{
			ft_putstr("\n\n\n");
			order5(&current->stack_a, &current->stack_b);
			write_stack_a(current->stack_a);
			write_stack_b(current->stack_b);
			ft_putstr("\n2-------\n");
			ft_putstr("a");
			ft_putstr("    ");
			ft_putstr("b      ");
		}
	}
	free(current);
	return 0;
}

void free_stack(t_stack *stack)
{
    t_stack *current = stack;
    t_stack *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}


/*
int	main(int argc, char **argv)
{
    int stack_len;
    t_stack *aux;
    t_stacks *current;

    aux = NULL;
    current = (t_stacks *) malloc(sizeof(t_stacks) * 1);
    create_stack(current, argc, argv);
    stack_len = get_lenstack(current->stack_a);

    if (argc < 2)
    {
        ft_putstr("Introduce números a ordenar\n");
        return 0;
    }

    if(ft_validation(argc,argv))
    {
        // Mostrar números iniciales
        ft_putstr("Números iniciales: \n");
        write_stack_a(current->stack_a);

        if (stack_len == 5)
        {
            ft_putstr("\n\n\n");
            order5(&current->stack_a, &aux);

            // Mostrar números después de order5
            ft_putstr("Números después de order5: \n");
            write_stack_a(current->stack_a);
        }
    }
    free(current);
    return 0;
}



*/