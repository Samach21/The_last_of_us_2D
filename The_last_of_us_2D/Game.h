#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include "Player.h"
#include "Map.h"
#include "Collision.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow* window;
	VideoMode videomode;
	Event ev;

	Shader coreShader;
	//logic
	bool endGame;

	Player player;
	Map map;
	Enemy enemy;

	void initVariables();
	void initShaders();
	void innitWindow();
public:
	Game();
	virtual ~Game();
	const bool running() const;
	const bool getEndGame() const;

	void pollEvent();

	void updateCollide();
	void update();

	void render();
};
