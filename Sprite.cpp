#include "Sprite.h"
#include "mappy_A5.h"

#ifndef SPRITECPP
#define SPRITECPP


Sprite::Sprite()
{
	image = NULL;
}
Sprite::~Sprite()
{
	al_destroy_bitmap(image);
}
void Sprite::InitSprites(int width, int height)
{
	x = 20;
	y = 10;


	maxFrame = 14;
	curFrame = 0;
	frameCount = 14;
	frameDelay = 4;
	frameWidth = 42.5;
	frameHeight = 55;
	animationColumns = 14;
	animationDirection = 1;

	image = al_load_bitmap("greenguy1.png");
	al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));
}

void Sprite::UpdateSprites(int width, int height, int dir)
{
	int oldx = x;
	int oldy = y;

	if (x <= width && y <= height) {
		hitEnd = true;
	}

	if (dir == 1) { //right key
		animationDirection = 1;
		x += 4;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else if (dir == 0) { //left key
		animationDirection = 0;
		x -= 4;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else if (dir == 2) { //up key
		animationDirection = 2;
		y -= 4;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else if (dir == 3) { //down key
		animationDirection = 3;
		y += 4;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else //represent that they hit the space bar and that mean direction = 0
		animationDirection = dir;

	//check for collided with foreground tiles
	if (animationDirection == 0)
	{
		if (x <= 0) { //collision detection to the left
			x = oldx;
			y = oldy;
		}
	}
	else if (animationDirection == 1)
	{
		if (x >= width) { //collision detection to the right
			x = oldx;
			y = oldy;
		}
	}
	else if (animationDirection == 2)
	{
		if (y <= 0) { //collision detection up
			x = oldx;
			y = oldy;
		}
	}
	else if (animationDirection == 3)
	{
		if (y >= height) { //collision detection down
			x = oldx;
			y = oldy;
		}
	}
}

void Sprite::UpdateSprintingSprites(int width, int height, int dir)
{
	int oldx = x;
	int oldy = y;

	if (x <= width && y <= height) {
		hitEnd = true;
	}

	if (dir == 1) { //right key
		animationDirection = 1;
		x += 8;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 1;
		}
	}
	else if (dir == 0) { //left key
		animationDirection = 0;
		x -= 8;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else if (dir == 2) { //up key
		animationDirection = 2;
		y -= 8;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else if (dir == 3) { //down key
		animationDirection = 3;
		y += 8;
		if (++frameCount >= frameDelay)
		{
			frameCount = 0;
			if (++curFrame >= maxFrame)
				curFrame = 0;
		}
	}
	else //represent that they hit the space bar and that mean direction = 0
		animationDirection = dir;

	//check for collided with foreground tiles
	if (animationDirection == 0)
	{
		if (x <= 0) { //collision detection to the left
			x = oldx;
			y = oldy;
		}
	}
	if (animationDirection == 1)
	{
		if (x >= width) { //collision detection to the right
			x = oldx;
			y = oldy;
		}
	}
	if (animationDirection == 2)
	{
		if (y <= 0) { //collision detection up
			x = oldx;
			y = oldy;
		}
	}
	if (animationDirection == 3)
	{
		if (y >= height) { //collision detection down
			x = oldx;
			y = oldy;
		}
	}
}

void Sprite::DrawSprites(int xoffset, int yoffset)
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = (curFrame / animationColumns) * frameHeight;

	if (animationDirection == 1) {
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
	}
	else if (animationDirection == 0) {
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, ALLEGRO_FLIP_HORIZONTAL);
	}
	else if (animationDirection == 2) { //up
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
	}
	else if (animationDirection == 3) { //down
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, ALLEGRO_FLIP_HORIZONTAL);
	}
}
bool Sprite::getHitEnd() {
	return hitEnd;
}
#endif