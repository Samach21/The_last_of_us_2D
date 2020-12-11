#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

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

	bool moving;
	int standNum;
	int moveNum;
	bool turnLeft;

	void initVariables();
	void initSprite();
	void initAnimetion();
public:
	Enemy();
	virtual ~Enemy();

	void updateInput();
	void updateAnimation();
	void update(RenderTarget* target);
	void render(RenderTarget* target);
};