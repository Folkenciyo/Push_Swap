/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:52:52 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/11 22:52:58 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Include libraries */
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*
***************** STRUCTURES *****************
*/

/**
 * @brief Structure to store the instructions
*/
typedef struct s_instruction
{
	char					*line;
	struct s_instruction	*next;
}	t_instruction;
/**
 * @brief Structure to store the pile
 *
 */
typedef struct s_pile
{
	int						content;
	int						actual_i;
	int						target_pos;
	int						cost_a;
	int						cost_b;
	int						final_cost;
	struct s_pile			*next;
}	t_numb;
/**
 * @brief Structure to store the state of the program
 *
 */
typedef struct s_state
{
	t_numb					*pile_one;
	t_numb					*pile_two;
	int						max_size;
	t_instruction			*instructions;
}	t_state;

/**
 * @brief Prints the instructions
 * 
 * @param state 
 */
void				print_instructions(t_state *state);

/*
***************** INSTRUCTIONS UTILS *****************
*/
/**
 * @brief This function adds a new instruction to the list of instructions.
 * 
 * @param str
 * @return t_instruction*
*/
t_instruction		*add_new_instruction(char *str);
/**
 * @brief This function writes the instructions in the list of instructions.
 * 
 * @param state
 * @param instruction
*/
void				write_instructions(t_state *state, char *instruction);
/**
 * @brief liberate the memory of the instructions
 * 
 * @param state 
 */
void				free_instructions(t_state *state);

/*
***************** PILE MEMORIES UTILS *****************
*/

/**
 * @brief Add a number to the pile
 *
 * @param pile
 * @param c Content
 * @return t_numb*
 */
t_numb				*add_number(t_numb *pile, char *content);
/**
 * @brief Add a number to the pile depending the arguments
 * 
 * @param actual_state 
 * @param argc 
 * @param argv 
 * @param i 
 */
void				complete_add_num(t_state *actual_state, int argc,
						char **argv, int i);
void				free_argv(char **arr);
/**
 * @brief Allocate memory for the pile
 *
 * @param state
 * @return t_state*
 */
t_state				*allocate_state_memory(t_state *state);
/**
 * @brief Allocate memory for the pile
 *
 * @param pile
 * @return t_numb*
 */
t_numb				*allocate_pile_memory(t_numb *pile);

/**
 * @brief Free the memory of the state
 * 
 * @param state 
 */
void				free_state_memory(t_state *state);
/*
***************** PILE UTILS *****************
*/
/**
 * @brief This function returns the size of the pile.
 * 
 * @param pile
 * @return int
*/
int					ft_pile_size(t_numb *pile);
/**
 * @brief This function returns the last element of the pile.
 * 
 * @param pile
 * @return t_numb*
*/
t_numb				*ft_pile_last(t_numb *pile);
/**
 * @brief This function finds and returns the smallest number and returns it.
 * 
 * @param pile
 * @return int
*/
int					ft_min(t_numb *pile);
/**
 * @brief This function finds and returns the biggest number and returns it.
 * 
 * @param pile
 * @return int
*/
int					ft_max(t_numb *pile);
/**
 * @brief This function checks the index of a number in the pile.
 * 
 * @param pile
 * @param c Content
 * @return int
*/
int					ft_find_index(t_numb *pile, int content);
/**
 * @brief This function send all the numbers from pile_one to pile_two
 *  from minor to major.
 * 
 * @param state
*/
void				ft_send_all_to_b(t_state *state);
/**
 * @brief This function give the last number in pile_one.
 * 
 * @param state 
 * @return int 
 */
int					ft_last_num_in_pile_1(t_state *state);
/**
 * @brief This function give the last number in pile_two.
 * 
 * @param state 
 * @return int 
 */
int					ft_last_num_in_pile_2(t_state *state);
/**
 * @brief 
 * 
 * @param state 
 */
void				ft_calculate_pos(t_state *state);
/**
 * @brief This function finds the cheapest number to move and reorder
 * pile_one to send the number from pile_two in it right position.
 * 
 * @param state 
 */
void				ft_reorder_pile_one(t_state *state);
/**
 * @brief reorder pile_two
 * 
 * @param state 
 * @param num_to_mov Choosen number
 */
void				ft_num_to_top_p_2(t_state *state, int num_to_mov);
/**
 * @brief reorder pile_one
 * 
 * @param state 
 * @param num_to_mov 
 */
void				ft_num_to_top_p_1(t_state *state, int num_to_mov);
/**
 * @brief This function reorders pile_one
 * 
 * @param state 
 * @param pile 
 * @param num_to_mov 
 * @param i 
 */
void				ft_num_to_top_1(t_state *state,	int num_to_mov, int i);
/**
 * @brief This function reorders pile_two
 * 
 * @param state 
 * @param pile 
 * @param num_to_mov 
 * @param i 
 */
void				ft_num_to_top_2(t_state *state,	int num_to_mov, int i);
/**
 * @brief This function finds closer number to the choosen number from pile_two
 * 
 * @param state 
 * @param num_to_mov 
 * @return int 
 */
int					ft_find_closer(t_state *state, int num_to_mov);
/**
 * @brief This function take any number and transform it to positive.
 * 
 * @param a 
 */
int					ft_abs(int a);
/*
***************** PILES SORT *****************
*/

/**
 * @brief This function sort pile of size 3.
 * 
 * @param state 
 * @return t_state* 
 */
t_state				*ft_sort_three(t_state *state);

/**
 * @brief This function sort pile of size > 3.
 * 
 * @param state 
 */
void				ft_sort_big(t_state *state);
/**
 * @brief Check num of steps in pile_one to move the number
 * 
 * @param state 
 * @param num 
 * @return int 
 */
int					ft_step_index_moves(t_state *state, int num);
/*
***************** PILES MOVES *****************
*/

/*
	=== Swap Moves ===
 */
/**
 * @brief Change the first two elements of the pile a
 * 
 * @param state
 * @return void
 */
void				ft_swap_a(t_state *state, int flag);
/**
 * @brief Change the first two elements of the pile b
 *
 * @param state
 * @return t_numb*
 */
void				ft_swap_b(t_state *state, int flag);
/**
 * @brief Change the first two elements of the both piles
 *
 * @param state
 * @return t_state*
 */
void				ft_swap_ss(t_state *state);

/*
	=== Push Moves ===
 */
/**
 * @brief Push the first element of the pile a to the pile b
 *
 * @param state
 * @return t_state*
 */
void				ft_push_a(t_state *state);
/**
 * @brief Push the first element of the pile b to the pile a
 *
 * @param state
 * @return t_state*
 */
void				ft_push_b(t_state *state);
/*
	=== Rotate Moves ===
*/
/**
 * @brief Move the first element of the pile a to the end of the pile
 * 
 * @param state
 * @return t_state*
*/
void				ft_rotate_a(t_state *state, int flag);
/**
 * @brief Move the first element of the pile b to the end of the pile
 * 
 * @param state
 * @return t_state*
*/
void				ft_rotate_b(t_state *state, int flag);
/**
 * @brief Move the first element of the pile a and b to the end of the pile
 *
 * @param state
 * @return t_state*
 */
void				ft_rotate_s(t_state *state);

/*
	=== Reverse Rotate Moves ===
*/

/**
 * @brief Move the last element of the pile a to the beginning of the pile
 *
 * @param state
 * @return t_state*
 */
void				ft_reverse_rotate_a(t_state *state, int flag);
/**
 * @brief Move the last element of the pile b to the beginning of the pile
 *
 * @param state
 * @return t_state*
 */
void				ft_reverse_rotate_b(t_state *state, int flag);
/**
 * @brief Move the last element of the pile
 *  a and b to the beginning of the pile
 *
 * @param state
 * @return t_state*
 */
void				ft_reverse_rotate_s(t_state *state);

/*
***************** MAIN FUNCTIONS *****************
*/

/**
 * @brief  This function sorts the pile of size 2.
 * It takes final sort in pile_one after all values pushed to pile_two,
 * sorted and pushed back to pile_one. Because, even if the pile is sorted,
 * the min value can be in the top of the pile_one. Them bring all the smallest
 * to the top.
 * 
 * @param state
 */
void				ft_sort(t_state *state);

/**
 * @brief Writes an error message and exits the program.
 */
void				ft_error(void);

/*
***************** CONDITIONS FUNCTIONS *****************
*/

/**
 * @brief This function checks if the pile is sorted.
 *
 * @param state
 * @return int
 */
int					ft_is_sorted(t_numb *pile);

/**
 * @brief This function checks if the pile has duplicated numbers.
 * 
 * @param pile
 * @return int
 */
int					ft_num_is_duplicated(t_numb *pile);
/**
 * @brief This function checks if the pile has only numbers.
 * 
 * @param pile 
 * @return int 
 */
void				ft_is_not_digit(int argc, char **argv);
void				ft_all_spaces(int argc, char **argv);

#endif