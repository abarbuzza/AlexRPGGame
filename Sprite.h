
#ifndef SPRITEH
#define SPRITEH
#include <allegro5/allegro.h>

using namespace std;
class Sprite
{

	friend int collided(int x, int y);
	friend bool endValue(int x, int y);
	friend bool save(int xPos, int yPos);
	friend bool load();
public:
	Sprite();
	~Sprite();
	void InitSprites(int width, int height);
	void UpdateSprites(int width, int height, int dir); //dir 1 = right, 0 = left, 2 = Standing Still
	void UpdateSprintingSprites(int width, int height, int dir); //dir 1 = right, 0 = left, 2 = Standing Still
	void DrawSprites(int xoffset, int yoffset);
	float getX() { return x; }
	float getY() { return y; }
	int getWidth() { return frameWidth; }
	int getHeight() { return frameHeight; }
	bool getHitEnd();

private:
	float x;
	float y;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationRows;
	int animationDirection;
	bool hitEnd;



	ALLEGRO_BITMAP* image;
};
#endif