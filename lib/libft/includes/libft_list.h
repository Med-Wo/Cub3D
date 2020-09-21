/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:27:40 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:39:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

/*
** typedef void (*destroy_funct)(void *to_destroy);
*/

typedef struct	s_list
{
	void		***content;
	size_t		size;
	size_t		max_size;
	size_t		nb_line;
	size_t		push_size;
}				t_list;

t_list			create_list(size_t p_push_size);
t_list			*malloc_list(size_t p_push_size);
void			destroy_list(t_list to_destroy
	, void (*destroy_funct)(void *to_destroy));
void			free_list(t_list *to_free
	, void (*destroy_funct)(void *to_destroy));
t_vector2		list_calc_index_coord(t_list *list, size_t index);
void			list_push_back(t_list *list, void *to_add);
void			*list_at(t_list *list, size_t index);
void			**list_get(t_list *list, size_t index);

#endif
