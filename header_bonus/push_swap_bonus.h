/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 14:21:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_dll {
	void			*content;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_item {
	int		data;
	long	idx;
	long	cmd_cnt;
	long	ra_cmd_cnt;
	long	rb_cmd_cnt;
	long	rra_cmd_cnt;
	long	rrb_cmd_cnt;
}	t_item;

t_dll	*dll_new_node(void *item);
void	dll_add_front(t_dll **dll, t_dll *new);
void	dll_add_back(t_dll **dll, t_dll *new);
t_dll	*dll_del_front(t_dll **dll);
t_dll	*dll_del_back(t_dll **dll);

long	dll_size(t_dll *dll);
int		dll_empty(t_dll *dll);
void	dll_del_one(t_dll *del_node);
void	dll_del_all(t_dll **dll);

void	ps_partition(t_dll **sa, t_dll **sb, t_dll **cmds);
void	ps_partition2(t_dll **sa, t_dll **sb, t_dll **cmds, long *lis_check);
void	ps_optimize(t_dll **cmds);
int		ps_can_optimize(char *curr_cmd, char *next_cmd);
int		ps_is_all_in_lis(t_dll *sa, long *lis_check);

long	*ps_lis(t_dll *sa, const long size);
long	ps_bin_search(long *lis, long data, long size);
void	ps_make_check_arr(long *data, long *recode, long *lis, long size);
void	ps_arr_init(long **data, long **lis, long **recode, long size);

void	ps_fill_cmd_cnt(t_dll *sa, t_dll *sb);
long	ps_get_idx_j(t_dll *sa, t_dll *sb);
void	ps_set_cmd(t_dll *sa, t_dll *sb, long i, long j);
void	ps_set_cmd2(t_dll *sa, t_dll *sb, long i, long j);
long	ps_get_min_idx_in_sa_j(t_dll *sa);

void	ps_greedy(t_dll **sa, t_dll **sb, t_dll **cmds);
t_dll	*ps_get_min_cmd_dll(t_dll *sb);
void	ps_sb_sa_move_top(t_dll **sa, t_dll **sb, t_dll *min_sb, t_dll **cmds);
void	ps_ra_sort(t_dll **sa, t_dll **cmds);

void	ps_init(int argc, char **argv, t_dll **sa, t_dll **sb);
void	ps_init2(char **res_split, t_dll **sa);
int		ps_is_valid_data(const char *s);

long	ps_atol(const char *str);
int		ps_double_check(t_dll *sa);
void	ps_data_normalization(t_dll *sa);

void	sab(t_dll **s, char *str, t_dll **cmds);
void	ss(t_dll **sa, t_dll **sb, char *str, t_dll **cmds);
void	pab(t_dll **src_s, t_dll **dest_s, char *str, t_dll **cmds);
void	rab(t_dll **s, char *str, t_dll **cmds);
void	rr(t_dll **sa, t_dll **sb, char *str, t_dll **cmds);

void	rrab(t_dll **s, char *str, t_dll **cmds);
void	rrr(t_dll **sa, t_dll **sb, char *str, t_dll **cmds);
char	*ps_get_cmd(const char *str);
void	ps_save_cmd(const char *str, t_dll **cmds);

long	ps_max(long n, long m);
long	ps_min(long n, long m);

int		exit_manager(char *str);
void	print_dll(t_dll *sa, t_dll *sb);
void	print_arr(long *arr, long size);
void	print_cmds(t_dll *cmds);
void	print_cmds_inversion(t_dll *cmds);
void	print_cmd(t_dll *cmds);

void	ps_sort(t_dll **sa, t_dll **sb, t_dll **cmds_p, t_dll **cmds_q);

void	ps_small_data(t_dll **sa, t_dll **sb, t_dll **cmds, long size);

#endif
