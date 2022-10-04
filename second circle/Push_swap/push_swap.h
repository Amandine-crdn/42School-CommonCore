/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:11:00 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:11:08 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		ft_atoi(char *str);
void	ft_rb(int *stackb, int pb);
void	ft_rrb(int *stackb, int pb);
int		ft_pa(int *stacka, int *stackb, int pa, int total);
int		ft_pb(int *stacka, int *stackb, int pb);
void	ft_ra(int *stacka, int total);
int		ft_range_stack_b(int *stackb, int pb, int i);
void	ft_range_stack_b2(int *stackb, int pb);
void	ft_range_stack_a(int *stacka, int pa);
void	ft_rra(int *stacka, int total);
void	ft_swap_reel_a(int *a, int *b);
void	ft_swap_reel_b(int *a, int *b);
int		ft_push_min(int total, int *a);
void	ft_push_min_a(int total, int *a);
void	ft_push_min_b(int pb, int *b);
int		ft_value_chunk(int again, int div);
int		ft_modif_chunk(int x, int *chunk, int div);
int		ft_choice_nbr(int again);
int		ft_calcul_block(int *chunk, int total);
int		ft_sort_int_tab_error(int *stacka, int argc);
int		ft_sort_error(int *stacka, int argc);
int		ft_check_error(int *stacka, int argc, char **argv);
void	ft_swap(int *a, int *b);
int		ft_superior(int *stackb, int nb_chunk);
void	ft_sort_int(int *tab, int size);
void	ft_sort_for_median(int new_value, int *sort, int *stacka);
void	ft_second(int *stacka, int pb, int *stackb, int total);
int		ft_first(int *stacka, int total, int *stackb);
int		ft_start(int *stacka, int total);
int		ft_sort_check_max(int *tab, int size);
int		ft_search_startmax(int *stack, int pb, int max);
int		ft_search_endmax(int *stack, int pb, int max);
void	ft_check_max(int *stack, int pb);
void	ft_check_min(int *stack, int total, int m);
int		ft_search_end(int *stack, int total, int m);
int		ft_search_start(int *stack, int total, int m);
int		ft_check_ascii(int argc, char **argv);
void	ft_free(int *stack);
void	ft_insert_sort(int *sort, int *tab, int size);
void	ft_choice_action_max(int *stack, int next, int next2, int pb);
void	ft_choice_action_min(int *stack, int next, int next2, int total);
void	ft_initialize(int pb, int x);
int		ft_check_atoi(char **argv, int argc);

#endif
