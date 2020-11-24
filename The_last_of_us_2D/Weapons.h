#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

using namespace std;
using namespace sf;

class Weapons
{
private:
	Sprite weapons;
	Sprite arrow;
	Texture weaponsTexture;
	Texture arrowTexture;
	Clock arrowTime;

	int arrowN;
	bool lastLying;
	float lieWidth;
	float lieHeight;
	bool checkArrow;
	int mem;
	float width;
	float height;
	float weaponsx;
	float weaponsy;

	void initVariables();
	void initSprites();
public:
	Weapons();
	virtual ~Weapons();

	void move(Vector2f x);
	void updateAnimations(bool lying, bool jumping, bool turnLeft,  int slot);
	void update(bool lying, bool jumping, bool turnLeft, int slot);
	void render(RenderTarget* target, int slot);
};

