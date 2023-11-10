/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:53:11 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 14:09:46 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

//check
void	is_blank(char *av);
void	is_number(char *av);
void	is_only_sign_or_more(char *av);
void	check_input(char **av);
//check2
void	stack_free(t_stack *stack);
int		ft_atoi(char *str, t_stack *stack, long long num);
void	is_duplicate(int num, t_stack *stack);
void	is_one_para(t_stack *stack);
void	is_already_sorted(t_stack *stack);
//stack
int		count(char const *s, char c);
char	*allocate_word(int idx, char const *s, char c);
char	**ft_split(char const *s, char c);
char	**free_all(char **result);
void	fill_stack(int ac, char **av, t_stack *stack);
//make_node
t_stack	*make_stack(void);
t_node	*make_node(int num);
void	make_top_node(int num, t_stack *stack);
void	join_node(int num, t_stack *stack);
//make_idx
void	sort_arr(int *arr, int size);
void	change_to_idx(int *arr, int size, t_stack *stack);
void	make_index(t_stack *stack_a);
//push
void	set_dest(t_stack *dest, t_node *tmp);
void	push_elements(t_stack *src, t_stack *dest);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
//swap
void	swap_top_2_elements(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
//rotate
void	rotate(t_stack *stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
//reverse_rotate
void	reverse_rotate(t_stack *stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
//sort_tiny
int		is_sorted(t_stack *stack);
void	sort_2_elements(t_stack *stack_a);
void	sort_3_elements(t_stack *stack_a);
void	sort_2_or_3(t_stack *stack_a);
//a_to_b
int		all_bigger_than_pivot2(t_stack *stack_a, int pivot2);
void	bigger_than_p2(t_stack *stack_a, int p2);
void	between_p1_n_p2(t_stack *stack_a, t_stack *stack_b, int p1, int p2);
void	smaller_than_p1(t_stack *stack_a, t_stack *stack_b, int p1);
void	a_to_b(t_stack *stack_a, t_stack *stack_b);
//b_to_a
void	rotate_same(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
void	rotate_stack_a(int idx, t_stack *stack_a);
void	rotate_stack_b(int idx, t_stack *stack_b);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);
//min_command
int		find_min_rotate(int idx, t_stack *stack);
int		idx_to_min_command(t_stack *stack_b, int b_idx);
int		find_min_command_in_a(t_stack *stack_a, int *a_idx, int content);
void	find_min_command(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
//last_sort
int		search_idx_0(t_stack *stack_a);
void	last_sort(t_stack *stack_a);

#endif
