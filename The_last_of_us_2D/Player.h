#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

using namespace std;
using namespace sf;

class Player
{
private:
	RectangleShape shape;
	Sprite sprite;
	Texture texture;
	Sprite ellie;
	Texture ellieTexture;
	IntRect currentFrame;
	Clock animationTimer;

	float movementSpeed;
	float width;
	float height;
	float frame;
	bool moving;
	int ellieStand;
	int ellieMove;
	bool turnLeft;
	float aniTime;

	void initVariables();
	void initShape();
	void initAnimations();
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput();
	void updateAnimations();
	void update(RenderTarget* target);
	void render(RenderTarget* target, Shader* shader = NULL);
};
