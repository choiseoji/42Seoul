/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:38:02 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 15:48:54 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}t_stack;

//check_bonus
void	is_blank(char *av);
void	is_number(char *av);
void	is_only_sign_or_more(char *av);
void	check_input(char **av);
int		is_empty(t_stack *stack_b);
//check2_bonus
void	stack_free(t_stack *stack);
int		ft_atoi(char *str, t_stack *stack, long long num);
void	is_duplicate(int num, t_stack *stack);
//make_node_bonus
t_stack	*make_stack(void);
t_node	*make_node(int num);
void	make_top_node(int num, t_stack *stack);
void	join_node(int num, t_stack *stack);
//stack_bonus
int		count(char const *s, char c);
char	*allocate_word(int idx, char const *s, char c);
char	**free_all(char **result);
char	**ft_split(char const *s, char c);
void	fill_stack(int ac, char **av, t_stack *stack);
//push_bonus
void	set_dest(t_stack *dest, t_node *tmp);
void	push_elements(t_stack *src, t_stack *dest);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
//swap_bonus
void	swap_top_2_elements(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
//rotate_bonus
void	rotate(t_stack *stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
//reverse_rotate_bonus
void	reverse_rotate(t_stack *stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
