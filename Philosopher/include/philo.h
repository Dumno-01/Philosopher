/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:11:29 by ffreze            #+#    #+#             */
/*   Updated: 2023/10/16 08:11:29 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# define ERR_INPUT_1 "Only numbers : philo, ttd, tte, tts, (optional)nbm"
# define ERR_INPUT_2 "Invalid values"
# define THREAD_ERR "Error whit the thread's creation"
# define TIME_ERR "Time error"
# define ALLOC_ERR_1 "Error while allocating thread numbers"
# define ALLOC_ERR_3 "Error while allocating philo"
# define ALLOC_ERR_2 "Error while allocating fork"
# define JOIN_ERR "Join error"
# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	size_t			time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	long			death_time;
	long			eat_time;
	long			sleep_time;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

long		ft_atoi(const char *str);
int			error(char *str, t_data *data);
int			ft_strcmp(char *s1, char *s2);
void		messages(char *str, t_philo *philo);
void		eat(t_philo *philo);
void		ft_exit(t_data *data);
size_t		get_time(void);
int			ft_usleep(useconds_t time);
int			init(t_data *data, char **argv, int argc);
int			input_checker(char **argv);
int			thread_init(t_data *data);
void		*routine(void *philo_pointer);

#endif