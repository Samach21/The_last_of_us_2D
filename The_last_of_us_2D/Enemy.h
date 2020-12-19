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

class Enemy
{
private:
	enum class TYPE{
		RED,
		GREEN,
		BLUE,
		YELLOW,
		RIANBOW
	};
	TYPE enemyType;
	Texture texture;
	Sprite ventSprite;
	Texture ventTexture;
	IntRect currentFrame;
	Clock aniTime;
	Texture shadowTexture;
	Texture bodyTexture;

	Clock walkTime;
	Clock wallTime;

	struct EnemyPosition
	{
		float x;
		float y;
	};
	EnemyPosition enemyposition;
	EnemyPosition randposi;

	float movementSpeed;
	float width;
	float height;
	float preWidth;
	float preHeight;
	float moveY;
	float lastMoveY;
	bool turnLeft;
	float hearRange;

	bool moving;
	bool spawning;
	int spawnNum;
	int moveNum;
	int deadNum;

	Clock killedTime;
	bool killed;

	SoundBuffer killedBuff;
	Sound kill;
	SoundBuffer walkBuff;

	SoundBuffer ventBuff;
	Sound vent;

	long a, b, c;

	void initVariables();
	void initColor();
	void initSprite(float x, float y);
	void initAnimetion();
	void initSounds();
public:
	Enemy(float x, float y);
	virtual ~Enemy();

	Sound walk;
	bool isDelete;
	bool targetLock;
	bool isCollide;
	bool isDead;
	Sprite shadowSprite;
	RectangleShape signSprite;
	EnemyPosition targetPo;
	CircleShape hearCircle;
	int enemyHealth;
	Sprite sprite;
	Sprite body;
	int typeofenemy;

	void walking(float* x, float* y);
	void updateHealth();
	void updateInput();
	void updateWalk();
	void updateSound();
	void updateAnimation();
	void updatePosition(float x, float y);
	void update(RenderTarget* target, float x, float y);
	void render(RenderTarget* target);
};