#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

using namespace std;
using namespace sf;

class Map
{
private:
	Sprite map;
	Texture mapTexture;

	float movementSpeed;

	void initVariables();
	void initSprites();
public:
	Map();
	virtual ~Map();

	void updateInput();
	void update(RenderTarget* target);
	void render(RenderTarget* target);
};

