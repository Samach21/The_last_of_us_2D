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
	Clock animationTimer;
	Sprite ellieHead;
	Sprite ellieLeft;
	Sprite ellieRight;
	Sprite ellieBody;
	Sprite ellieLegs;
	Sprite ellieShadow;
	Texture ellieHeadTexture;
	Texture ellieLeftTexture;
	Texture ellieRightTexture;
	Texture ellieBodyTexture;
	Texture ellieLegsTexture;
	Texture ellieShadowTexture;

	float width;
	float height;
	float frameShipLeft;
	float frameShipTop;
	bool moving;
	int ellieStand;
	int ellieMove;
	bool turnLeft;
	float aniTime;

	float widthCenter;
	float heightCenter;
	int aniHeadNumEye;
	int aniHead;
	int aniLegs;

	void initVariables();
	void initSprites();
	void initAnimations();
public:
	Player();
	virtual ~Player();

	void updateInput();
	void updateAnimations();
	void update(RenderTarget* target);
	void render(RenderTarget* target, Shader* shader = NULL);
};
