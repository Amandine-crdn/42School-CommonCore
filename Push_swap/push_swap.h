#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# if defined(APPLE)
# elif defined(linux)
# endif

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

int       ft_atoi(char *str);
void    ft_add_value(int *stackA, int argc, char **argv);
void    ft_check(int *stackB, int total);
int        ft_superior(int *stackB, int total);
 void    ft_range_stackB(int *stackB, int M);
 void    ft_range_stackA(int *stackA, int pa);
void    ft_action(int *stackB, int i, int total);
void    ft_rb(int *stackB, int M);
void    ft_rrb(int *stackB, int total);
int    ft_pa(int *stackA, int *stackB, int pa);
void    ft_pb(int *stackA, int *stackB, int    total);
int     ft_check_error(int *stackA, int argc);
int     ft_sort_int_tab(int *stackA, int argc);
int     ft_sort(int *tab, int size);
int     ft_check_limit(int *stackA, int argc);
int     ft_calcul_median(int total, int	*stackA);
int     ft_push_min(int total, int *stackA);
void	ft_swap(int *a, int *b);
void    ft_go(int total);
int	ft_calcul_block(int total);

#endif
