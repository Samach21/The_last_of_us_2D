#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

#include"Weapons.h"
#include"HitboxComponent.h"

#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;
using namespace sf;

class Player
{
private:
	struct Ammo
	{
		int bow;
		int minigun;
		int ak;
		int shotgun;
	};
	Clock animationTimer;
	Sprite ellieHead;
	Sprite ellieLeft;
	Sprite ellieRight;
	Sprite ellieBody;
	Sprite ellieLegs;
	
	Texture ellieHeadTexture;
	Texture ellieLeftTexture;
	Texture ellieRightTexture;
	Texture ellieBodyTexture;
	Texture ellieLegsTexture;
	Texture ellieShadowTexture;
	Clock weaponsTimer;
	Clock lyingTimer;
	Clock jumpCooldown;
	Weapons weapons;
	Clock staminaTime;
	Clock cooldownStamina;

	Texture loadingTexture;
	Sprite loading;

	Texture sweatTexture;
	Sprite sweat;

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
	float jumpHigh;

	SoundBuffer walkBuff;

	Sound walk;

	bool firstWalk;
	unsigned long ad;

	void initVariables();
	void initSprites();
	void initAnimations();
	void initSounds();
public:
	Player();
	virtual ~Player();

	int slot;
	Sprite ellieShadow;
	HitboxComponent* hitbox;
	HitboxComponent* getHitboxComponent() const;
	CircleShape circle;
	int playerHealth;
	bool makeNoise;
	int stamina;
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	Ammo ammo;

	void updateSound();
	void updateMousePosition(RenderWindow* window);
	void updateInput();
	void updateStamina();
	void updateAnimations();
	void mouseScroll(int a);
	void update(RenderTarget* target, RenderWindow* window);
	void renderLoading(RenderTarget* target);
	void render(RenderTarget* target);
};
