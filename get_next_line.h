/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:56:09 by aerbosna          #+#    #+#             */
/*   Updated: 2023/05/04 04:12:39 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	*ft_memcpy(char	*dst, char *src, size_t n);
char	*ft_strdup(char	*str1);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*get_buff(int fd, char *str);
char	*get_returnline(char *str);
char	*dlt_line(char *str);
#endif