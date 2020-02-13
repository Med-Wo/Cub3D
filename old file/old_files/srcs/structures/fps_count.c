/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:37:26 by mravily           #+#    #+#             */
/*   Updated: 2020/01/28 22:01:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
//
//	double		time;
//	double		old_time;
// //timing for input and FPS counter
// oldTime = time;
// time = getTicks();
// double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
// print(1.0 / frameTime); //FPS counter
// redraw();
// cls();
//
// //speed modifiers
// double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
// double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
// readKeys();
// //move forward if no wall in front of you
// if(keyDown(SDLK_UP))
// {
//   if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//   if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
// }
// //move backwards if no wall behind you
// if(keyDown(SDLK_DOWN))
// {
//   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
// }
// //rotate to the right
// if(keyDown(SDLK_RIGHT))
// {
//   //both camera direction and camera plane must be rotated
//   double oldDirX = dirX;
//   dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//   dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//   double oldPlaneX = planeX;
//   planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//   planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// }
// //rotate to the left
// if(keyDown(SDLK_LEFT))
// {
//   //both camera direction and camera plane must be rotated
//   double oldDirX = dirX;
//   dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//   dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//   double oldPlaneX = planeX;
//   planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//   planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// }
