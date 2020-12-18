#include "Bullet.h"

void Bullet::initVariables()
{
	this->isDelete = false;
	this->allS = 0.f;
	this->lastSx = 0.f;
	this->lastSy = 0.f;
}

void Bullet::initSprites()
{
	if (!this->texture.loadFromFile("Textures/bullet.png"))
		std::cout << "ERROR::COULD NOT LOAD TEXTURE." << "\n";
	this->sprite.setTexture(this->texture);
	//this->sprite.scale(10.f, 10.f);
	this->sprite.setPosition(this->startPoint.x, this->startPoint.y);
}

Bullet::Bullet(float x, float y, float targetx, float targety, int* slot, float mapx, float mapy)
{
	this->slot = *slot;
	this->startPoint.x = x;
	this->startPoint.y = y;
	this->targetPoint.x = targetx;
	this->targetPoint.x = targety;
	this->lastMap.x = mapx;
	this->lastMap.y = mapy;

	switch (*slot)
	{
	case 1: this->v = 30.f; //bow
		break;
	case 2: this->v = 40.f; //shotgun
		break;
	case 3: this->v = 60.f; //ak
		break;
	case 4: this->v = 40.f; //minigun
		break;
	default:
		break;
	}
	this->sx = targetx - x;
	this->sy = targety - y;
	this->s = sqrtf((sx * sx) + (sy * sy));
	this->t = this->s / this->v;
	this->vx = this->sx / this->t;
	this->vy = this->sy / this->t;

	this->initVariables();
	this->initSprites();

	this->clock.restart();
	this->allT.restart();
}

Bullet::~Bullet()
{
}

void Bullet::updatePosition(float x, float y)
{
	float dx, dy;
	if (this->lastMap.x != x) {
		dx = x - this->lastMap.x;
		this->lastMap.x = x;
	}
	else
		dx = 0;
	if (this->lastMap.y != y) {
		dy = y - this->lastMap.y;
		this->lastMap.y = y;
	}
	else
		dy = 0;
	this->sprite.move(dx, dy);
}

void Bullet::update(sf::RenderTarget* target, float x, float y)
{
	if (this->clock.getElapsedTime().asSeconds() >= 0.001f)
	{
		this->clock.restart();
		this->sprite.move(this->vx, this->vy);
		this->allS++;
	}
	this->updatePosition(x, y);
	if (this->allS >= 2000.f)
	{
		this->isDelete = true;
	}
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}