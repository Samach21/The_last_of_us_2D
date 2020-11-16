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

	bool turnLeft;
	bool lying;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	float movementSpeed;

	void initVariables();
	void initSprites();
public:
	Map();
	virtual ~Map();

	void updateMousePosition(RenderWindow* window);
	void updateInput();
	void update(RenderTarget* target, RenderWindow* window);
	void render(RenderTarget* target);
};

