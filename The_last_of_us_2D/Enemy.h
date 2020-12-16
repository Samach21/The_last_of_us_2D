#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<vector>

#include<iostream>

using namespace std;
using namespace sf;

class Enemy
{
private:
	Sprite sprite;
	Texture texture;
	IntRect currentFrame;
	Clock aniTime;

	float movementSpeed;
	float width;
	float height;
	float preWidth;
	float preHeight;
	float moveY;
	float lastMoveY;
	bool turnLeft;

	bool moving;
	bool spawning;
	bool isDead;
	int spawnNum;
	int moveNum;
	int deadNum;

	void initVariables();
	void initSprite();
	void initColor();
	void initAnimetion();
public:
	Enemy();
	virtual ~Enemy();

	void updateInput();
	void updateAnimation();
	void update(RenderTarget* target);
	void render(RenderTarget* target);
};