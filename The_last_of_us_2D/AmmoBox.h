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

class AmmoBox
{
private:
	Texture texture;
	struct LastPosition
	{
		float x;
		float y;
	};

	Clock despawnTime;
	SoundBuffer takeBuff;
	Sound take;

	long a;

	LastPosition mapPo;

	void initVariables();
	void initType();
	void initSprite(float x, float y);
	void initSounds();
public:
	AmmoBox(float x, float y, float targetx, float targety);
	virtual ~AmmoBox();

	bool isDelete;
	Sprite sprite;
	int typeOfAmmoBox;
	bool isTake;

	void updatePosition(float x, float y);
	void update(RenderTarget* target, float x, float y);
	void render(RenderTarget* target);
};