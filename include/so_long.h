/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:09:37 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/30 00:04:26 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "./miniaudio.h"
# include <time.h>
# include <sys/time.h>

# define IMGSIZE 64
# define L_TRASH -1
# define L_GROUND 0
# define L_WALL 1
# define L_SOME 2
# define L_BLOOD1 5
# define L_DEATH 6
# define L_BLOOD2 7
# define L_BLOOD3 8
# define L_COLLECTIBLE 9
# define L_PLAYER 10
# define L_ENEMY 11
# define L_EXIT 12
# define L_DUST 13
# define L_POINT 14

typedef struct s_sound
{
	ma_result	result;
	ma_engine	engine;
	ma_sound	track1;
	ma_sound	track2;
	ma_sound	track3;
	ma_sound	track4;
	ma_sound	dog_barking2;
	ma_sound	hacking00;
	ma_sound	rip;
	ma_sound	eating;
	ma_sound	take_key;
	ma_sound	heartbeat;
	ma_sound	tresor_door_open;
	ma_sound	keyboard;
	ma_sound	server;
	ma_sound	server_access;
}	t_sound;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct directions
{
	int	mid;
	int	left;
	int	right;
	int	top;
	int	bot;
}	t_dir;

typedef struct max
{
	bool	init;
	bool	run_flag;
	uint8_t	n;
	size_t	cnt_time;
}	t_max;

typedef struct renemy
{
	size_t	cnt;
}	t_renemy;

typedef struct enemys
{
	t_max		max;
	t_renemy	renemy;
}	t_enemys;

typedef struct s_vars
{
	int			p_ctr;
	int			e_ctr;
	int			c_ctr;
	int			x_ctr;
	int			size_x;
	int			size_y;
	int			steps;
	int			randenemy_option;
	bool		player_is_running;
	bool		stop_flag;
	bool		cluster_flag;
	bool		key_server;
	bool		server_flag;
	int			win_lose_flag;
	bool		entered_room[3];
	char		**map;
	mlx_t		*mlx;
	t_sound		sound;
	t_point		start;
	t_point		exit;
	t_enemys	enemys;
	t_dir		direction;

	mlx_image_t	*player;
	mlx_image_t	*player_r1;
	mlx_image_t	*player_r2;
	mlx_image_t	*player_l1;
	mlx_image_t	*player_l2;
	mlx_image_t	*player_u1;
	mlx_image_t	*player_u2;
	mlx_image_t	*player_d1;
	mlx_image_t	*player_d2;
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*coll;
	mlx_image_t	*coll2;
	mlx_image_t	*gameexit;
	mlx_image_t	*openexit;
	mlx_image_t	*saad;
	mlx_image_t	*enemy;
	mlx_image_t	*enemy2;
	mlx_image_t	*enemy3;
	mlx_image_t	*blood0;
	mlx_image_t	*blood1;
	mlx_image_t	*blood2;
	mlx_image_t	*deadguy0;
	mlx_image_t	*deadguy1;
	mlx_image_t	*deadguy2;
	mlx_image_t	*lost;
	mlx_image_t	*won;
	mlx_image_t	*black;
	mlx_image_t	*black_server;
	mlx_image_t	*black_kitchen;
	mlx_image_t	*black_room;
	mlx_image_t	*room_point;
	mlx_image_t	*server_point;
	mlx_image_t	*green_trans;
	mlx_image_t	*red_trans;
	mlx_image_t	*purple_trans;
	mlx_image_t	*black_trans;
	mlx_image_t	*tablet;
	mlx_image_t	*alarmtext;
	mlx_image_t	*kueche00;
	mlx_image_t	*kueche01;
	mlx_image_t	*server00;
	mlx_image_t	*key00;
	mlx_image_t	*prestory;
	mlx_image_t	*tresor_door_closed;
	mlx_image_t	*tresor_door_up;
	mlx_image_t	*tresor_door_down;
	mlx_image_t	*max_l;
	mlx_image_t	*max_r;
	mlx_image_t	*max_u;
	mlx_image_t	*max_d;
	mlx_image_t	*mlx_outputstring;
	mlx_image_t	*mlx_outputstring2;
	mlx_image_t	*mlx_outputstring3;
}	t_vars;

/*main.c*/
void		ft_so_long_init(t_vars *vars, int i);
int			terminate(t_vars *vars, int ret);
int			init_endscreen(t_vars *vars);
/*error_checks_1.c*/
int			valid_chars(t_vars *vars, int i);
int			invalid_path(t_vars *vars, int i);
int			error_check(t_vars *vars, int i);
/*error_checks_2.c*/
void		flood_fill(char **tab, t_vars *vars, t_point begin);
/*cluster_1.c*/
void		setup_cluster_mlx(void);
void		setup_cluster(t_vars *vars);
void		print_some_cool_cluster(t_vars *vars);
/*cluster_2.c*/
int			init_sounds_1(t_sound *sound);
int			init_sounds_2(t_sound *sound);
void		init_sounds_3(t_sound	*sound);
void		setup_cluster_sound(t_vars *vars);
void		terminate_cluster_sound(t_vars *vars);
/*cluster_hook_1.c*/
void		cluster_hook(t_vars *vars);
void		kill_sound(t_vars *vars, int track_nbr);
void		light_switch(t_vars *vars);
void		key_switch(t_vars *vars, mlx_image_t *img);
void		enemy_switch(t_vars *vars);
void		open_tresor_door(t_vars *vars);
void		hack_server(t_vars *vars);
/*cluster_hook_2.c*/
void		key_switch(t_vars *vars, mlx_image_t *img);
void		light_switch(t_vars *vars);
void		enemy_switch(t_vars *vars);
/*cluster_hook_3.c*/
void		hack_server(t_vars *vars);
/*print_1.c*/
int			img_handling(t_vars *vars);
int			setting_ctrs(t_vars *vars, int j, int k, char c);
int			print_ground(t_vars *vars);
int			print_c_p(t_vars *vars, int xs, int ys);
int			print_img(t_vars *vars, int xs, int ys);
/*print_2.c*/
int			print_map(t_vars *vars);
void		set_image_depth(mlx_image_t *image, int z);
void		set_depth(t_vars *vars);
void		spawn_player_imgs(t_vars *vars);
/*pics_1.c*/
mlx_image_t	*source_to_mlx_image_t(t_vars *vars, char *adress);
int			start_and_error(int argc, char **argv, t_vars *vars);
/*pics_2.c*/
int			pics_init_zero(t_vars *vars);
int			pics_init_one(t_vars *vars);
int			pics_init_two(t_vars *vars);
int			pics_init_three(t_vars *vars);
int			pics_init_four(t_vars *vars);
/*utils_1.c*/
int			check_lines(char *joined);
int			cnt_maplines(char **map);
void		win_func(t_vars *vars);
void		lose_func(t_vars *vars);
/*utils_2.c*/
char		*join_and_free(char *a, char *b);
char		*check_suffix(char *str);
char		*read_file(char *argv, int *i);
void		ft_free(char **str);
int			ft_error_sl(char *s);
/*utils_3.c*/
int			return_free_split(char **map, char *s);
int			line_check(t_vars *vars, int i);
int			same_length(t_vars *vars, int i);
char		**dup_string_arr(char **original, int length);
int			which_instance(t_vars *vars);
/*utils_4.c*/
int			init_endscreen(t_vars *vars);
int			init_prestory(t_vars *vars);
/*add_functions_1.c*/
int			remote_delay_ms(size_t delay);
size_t		delay_ms(void);
int			check_hitbox_fog(t_vars *vars, mlx_instance_t instance);
void		search_field_2_hitbox(t_vars *vars, mlx_image_t *image);
int			check_hitbox(t_vars *vars, mlx_instance_t instance, \
				int x_off, int y_off);
/*add_functions_2.c*/
int			search_through_instances(t_vars *vars, mlx_image_t *image);
int			search_through_instances2(t_vars *vars, mlx_image_t *image);
int			search_through_instances3(t_vars *vars, mlx_image_t *image, \
				int x_off, int y_off);
void		search_darkview(t_vars *vars, mlx_image_t *image, int direction);
/*add_functions_3.c*/
void		print_colls(t_vars *vars);
void		print_steps(t_vars *vars);
void		print_time(t_vars *vars);
void		print_some_cool(t_vars *vars);
/*add_functions_4.c*/
void		death_animation(t_vars	*vars);
/*add_functions_5.c*/
void		light_scene2(t_vars *vars, int frequence);
int			print_square(t_vars *vars, mlx_image_t *img, \
				unsigned int size_xy[2], unsigned int offset_xy[2]);
/*key_handling_1.c*/
void		key_handling(t_vars *vars);
/*key_handling_2.c*/
void		key_handling_helper_3(t_vars *vars, int step, \
				size_t *tmp_steps, int *last_dir);
void		key_handling_helper_2(t_vars *vars, int step, \
				size_t *tmp_steps, int *last_dir);
void		key_handling_helper_1(t_vars *vars, int step, \
				size_t *tmp_steps, int *last_dir);
void		key_handling_helper_0(t_vars *vars, int step, \
				size_t *tmp_steps, int *last_dir);
/*mlx_func_1.c*/
void		my_key_func2(mlx_key_data_t keydata, void *bla);
void		ft_hook(void *params);
void		ft_hook2(void *vars);
void		ft_hook3(void *param);
/*mlx_func_2.c*/
int			check_for_walls(t_vars *vars, int x_off, int y_off);
void		change_collectibles(t_vars *vars, mlx_instance_t *a);
void		check_for_collectible(t_vars *vars);
int			check_for_exit(t_vars *vars);
int			check_hitbox_2(t_vars *vars, mlx_instance_t instance, \
				int x_off, int y_off);
/*mlx_func_3.c*/
void		search_darkview_helper(t_vars *vars, \
				mlx_image_t *image, int direction, int i);
int			checker_wall(t_vars *vars, mlx_image_t *pic, int i, int direction);
/*mlx_func_4.c*/
void		run_process(t_vars *vars, mlx_image_t *a, mlx_image_t *b);
void		run_img_falser(t_vars *vars, int direction);
void		run_animation(t_vars *vars, int direction);
/*enemys_1.c*/
int			check_hitbox_enemy(mlx_image_t *img1, mlx_image_t *img2, \
				int x_off, int y_off);
int			check_hitbox_enemy2(mlx_instance_t *inst1, mlx_image_t *img2, \
				int x_off, int y_off);
int			check_hitbox_enemytoenemy(mlx_image_t *img, \
				size_t n, int x_off, int y_off);
int			check_hitbox_instances(mlx_image_t *img, \
				mlx_instance_t *instance, int x_off, int y_off);
void		switchimg(t_vars *vars);
/*enemys_2.c*/
void		spawnimgs(t_vars *vars);
void		setimgs(t_vars *vars, mlx_image_t *img);
void		movevertical(t_vars *vars, \
				mlx_instance_t *enemy_instance, size_t n);
void		movehorizontical(t_vars *vars, \
				mlx_instance_t *enemy_instance, size_t n);
void		randenemy3(t_vars *vars, int option);
/*enemys_3.c*/
void		movevertical2(t_vars *vars, \
				mlx_instance_t *enemy_instance, size_t n);
void		movehorizontical2(t_vars *vars, \
				mlx_instance_t *enemy_instance, size_t n);
void		randenemy4(t_vars *vars, int option);
void		randenemy_presetup(t_vars *vars);
/*enemys_max.c*/
void		max_patrol(t_vars *vars, int x, int y);
void		little_rip_helper(t_vars *vars, int win_lose_flag, \
				int stop_flag, int death_sound);
/*enemy_max_1.c*/
void		max_init(t_vars *vars, int x, int y);
void		max_set_trash(t_vars *vars);
/*enemy_max_2.c*/
int			max_attack2(t_vars *vars);
void		max_patrol_helper(t_vars *vars, int x, int y, int delay);
void		max_patrol(t_vars *vars, int x, int y);
void		little_rip_helper(t_vars *vars, int win_lose_flag, \
				int stop_flag, int d_sound);

#endif
