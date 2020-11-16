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

	bool moving;
	bool running;
	bool lying;
	bool jumping;
	bool fstLie;
	int ellieStand;
	int ellieMove;
	bool turnLeft;
	float aniTime;
	float widthCenter;
	float heightCenter;
	int aniHeadNumEye;
	int aniHead;
	int aniLegs;

	Vector2i mousePosWindow;
	Vector2f mousePosView;

	void initVariables();
	void initSprites();
	void initAnimations();
public:
	Player();
	virtual ~Player();

	void updateMousePosition(RenderWindow* window);
	void updateInput();
	void updateAnimations();
	void update(RenderTarget* target, RenderWindow* window);
	void render(RenderTarget* target, Shader* shader = NULL);
};
