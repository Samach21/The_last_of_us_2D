#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include "Collision.h"

using namespace std;
using namespace sf;

class Map
{
private:
	
	Texture mapTexture;
	Texture mapCheckTexture;
	Clock lyingTimer;
	Clock positionTimer;
	Texture FloorMapTexture;
	Texture FrontMapTexture;
	Sprite FloorMap;
	Sprite FrontMap;

	bool turnLeft;
	bool lying;
	bool Aon;
	bool AWon;
	bool ASon;
	bool Don;
	bool DWon;
	bool DSon;
	bool Son;
	bool Won;

	Sprite top;
	Sprite down;
	Sprite left;
	Sprite right;
	Sprite topleft;
	Sprite topright;
	Sprite downleft;
	Sprite downright;
	Sprite righttop;
	Sprite rightdown;
	Sprite lefttop;
	Sprite leftdown;
	bool topBool;
	bool downBool;
	bool leftBool;
	bool rightBool;
	bool topleftBool;
	bool toprightBool;
	bool downleftBool;
	bool downrightBool;
	bool lefttopBool;
	bool leftdownBool;
	bool righttopBool;
	bool rightdownBool;

	Vector2f lastPosition;
	Vector2f position;

	Vector2i mousePosWindow;
	Vector2f mousePosView;

	Texture dotTexture;

	float movementSpeed;

	void initVariables();
	void initSprites();
public:
	Map();
	virtual ~Map();

	Sprite map;
	Sprite mapCheck;
	bool renderFrontON;
	bool isCollide;

	void allmove(float x, float y);

	void updateMousePosition(RenderWindow* window);
	void updateInput();
	void updatePosition();
	void updateCollide();
	void updateRenderFront();
	void update(RenderTarget* target, RenderWindow* window);
	void render(RenderTarget* target);
	void renderFront(RenderTarget* target);
};

