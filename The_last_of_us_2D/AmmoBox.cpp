#include "AmmoBox.h"

void AmmoBox::initVariables()
{
	this->a = 0;
	this->isDelete = false;
	this->isTake = false;
}

void AmmoBox::initType()
{
	int type = rand() % 100;
	if (type >= 0 && type < 25) {
		if (!this->texture.loadFromFile("Weapons/box2.png"))
			cout << "ERROR" << "\n";
		this->typeOfAmmoBox = 1;
	}
	else if (type >= 25 && type < 50)
	{
		if (!this->texture.loadFromFile("Weapons/box4.png"))
			cout << "ERROR" << "\n";
		this->typeOfAmmoBox = 2;
	}
	else if (type >= 50 && type < 75)
	{
		if (!this->texture.loadFromFile("Weapons/box3.png"))
			cout << "ERROR" << "\n";
		this->typeOfAmmoBox = 3;
	}
	else
	{
		if (!this->texture.loadFromFile("Weapons/box1.png"))
			cout << "ERROR" << "\n";
		this->typeOfAmmoBox = 4;
	}
}

void AmmoBox::initSprite(float x, float y)
{
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.8f, 0.8f);
	//this->sprite.setScale(80.f, 60.f);
	this->sprite.setPosition(x + 20.f, y - 60.f);
}

void AmmoBox::initSounds()
{
}

AmmoBox::AmmoBox(float x, float y, float mapx, float mapy)
{
	this->initVariables();
	this->initType();
	this->initSprite(x, y);
	this->initSounds();

	this->mapPo.x = mapx;
	this->mapPo.y = mapy;

	this->despawnTime.restart();
}

AmmoBox::~AmmoBox()
{
}

void AmmoBox::updatePosition(float x, float y)
{
	float dx, dy;
	if (this->mapPo.x != x) {
		dx = x - this->mapPo.x;
		this->mapPo.x = x;
	}
	else
		dx = 0;
	if (this->mapPo.y != y) {
		dy = y - this->mapPo.y;
		this->mapPo.y = y;
	}
	else
		dy = 0;
	this->sprite.move(dx, dy);
}

void AmmoBox::update(RenderTarget* target, float x, float y)
{
	this->updatePosition(x, y);
	if (this->despawnTime.getElapsedTime().asSeconds() >= 10.f)
	{
		this->isDelete = true;
		this->isTake = true;
	}
}

void AmmoBox::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
