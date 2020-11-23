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
	Texture weaponsTexture;

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

	void update(bool turnLeft, int slot);
	void render(RenderTarget* target);
};

