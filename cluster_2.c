/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 19:18:09 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
int	init_sounds_1(t_sound *sound)
{
	sound->result = ma_engine_init(NULL, &sound->engine);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/deeptrain.wav", 0, NULL, NULL, &sound->track1);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/deeprun.wav", 0, NULL, NULL, &sound->track2);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/dogsteps.wav", 0, NULL, NULL, &sound->track3);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/deep.wav", 0, NULL, NULL, &sound->track4);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/dog_barking2.wav", 0, NULL, NULL, \
		&sound->dog_barking2);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/hacking00.wav", 0, NULL, NULL, &sound->hacking00);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/rip00.mp3", 0, NULL, NULL, &sound->rip);
	init_sounds_2(sound);
	return (0);
}

int	init_sounds_2(t_sound *sound)
{
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/eating.mp3", 0, NULL, NULL, &sound->eating);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/take_key.wav", 0, NULL, NULL, &sound->take_key);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/heartbeat.wav", 0, NULL, NULL, &sound->heartbeat);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/tresor_door_open.wav", 0, NULL, NULL, \
		&sound->tresor_door_open);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/keyboard.wav", 0, NULL, NULL, &sound->keyboard);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/server.mp3", 0, NULL, NULL, &sound->server);
	sound->result = ma_sound_init_from_file(&sound->engine, \
		"./sound/server_access.wav", 0, NULL, NULL, &sound->server_access);
	init_sounds_3(sound);
	return (0);
}

void	init_sounds_3(t_sound	*sound)
{
	ma_sound_set_volume(&sound->track1, 0.8);
	ma_sound_set_volume(&sound->track2, 0.8);
	ma_sound_set_volume(&sound->dog_barking2, 0.4);
	ma_sound_set_volume(&sound->hacking00, 0.2);
	ma_sound_set_volume(&sound->tresor_door_open, 0.8);
	ma_sound_set_volume(&sound->server, 10);
	ma_sound_set_volume(&sound->server_access, 10);
	ma_sound_set_volume(&sound->heartbeat, 10);
	ma_sound_set_volume(&sound->take_key, 10);
	ma_sound_set_looping(&sound->keyboard, 1);
	ma_sound_set_looping(&sound->heartbeat, 1);
}

void	setup_cluster_sound(t_vars *vars)
{
	init_sounds_1(&vars->sound);
	ma_sound_set_looping(&vars->sound.track1, 1);
	ma_sound_start(&vars->sound.track1);
}

void	terminate_cluster_sound(t_vars *vars)
{
	ma_sound_stop(&vars->sound.track1);
	ma_engine_uninit(&vars->sound.engine);
}
