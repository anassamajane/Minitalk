/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:12:53 by anaamaja          #+#    #+#             */
/*   Updated: 2025/04/05 09:49:21 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	printnum(int nb);
void	signal_handler(int signum);

void	display_error_and_exit(char *msg);
int		validate_and_convert_pid(char *str);
void	send_signal(int pid, int signal);
void	send_bit(int pid, char c);

#endif
