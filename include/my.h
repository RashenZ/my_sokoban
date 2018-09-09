/*
** my.h for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Thu Dec  8 18:32:36 2016 Victor Zhu
** Last update Wed Dec 21 14:16:52 2016 Victor Zhu
*/

#define SYNTAX_ERROR	"syntax error\n"

#ifndef MY_H
#define MY_H

void	my_putchar(char c);
int	my_putstr();
int	my_strlen();
int	my_put_nbr();
int	*show_map();
char	*my_strcpy();
char	*my_strdup();
void	man_my_sokoban();
void	start_window();
int	sokoban_start();
int	player_flags();
int	*color_map();
int	*color_map_2();
int	*move_else();
int	*move_into_oup();
int	*move_into_odown();
int	*move_into_oleft();
int	*move_into_oright();
int	*move_else_up();
int	*move_else_down();
int	*move_else_left();
int	*move_else_right();
int	game_restart();
int	prepare_menu();
void	when_you_won();
void	check_error();
int	move_menu();
int	display_menu();
int	my_select_level();
int	redirect_level();
void	disp_select();
int	my_option();
int	option_move();
int	display_option();
void	my_help();
struct dirent	*check_alloc_dirent();

#endif
