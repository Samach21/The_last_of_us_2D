#include "Enemy.h"

void Enemy::initVariables()
{
	this->movementSpeed = 10.f;
	this->preWidth = 13.f;
	this->preHeight = 72.f;
	this->width = 78.f;
	this->height = 103.f;
	this->moving = false;
	this->standNum = 1;
	this->moveNum = 1;
	this->turnLeft = false;
}

void Enemy::initSprite()
{
	if (!this->texture.loadFromFile("Textures/red.png"))
	{
		cout << "ERROR" << "\n";
	}
	this->currentFrame = IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.scale(1.25f, 1.25f);
	this->sprite.setPosition(300.f, 300.f);
}

void Enemy::initAnimetion()
{
	this->aniTime.restart();
}

Enemy::Enemy()
{
	this->initVariables();
	this->initSprite();
	this->initAnimetion();
}

Enemy::~Enemy()
{
}

void Enemy::updateInput()
{
	/*if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->sprite.move(-this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = true;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->sprite.move(this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = false;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->sprite.move(0.f, -this->movementSpeed);
		this->moving = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->sprite.move(0.f, this->movementSpeed);
		this->moving = true;
	}
	else
	{
		this->moving = false;
	}*/
}

void Enemy::updateAnimation()
{
	/*if (this->standNum >= 4)
	{
		this->standNum = 1;
	}
	if (this->moveNum >= 5)
	{
		this->moveNum = 1;
	}
	if (this->aniTime.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (this->moving == false)
		{
			this->moveNum = 1;
			this->preHeight = 177.f;
			this->width = 39.f;
			switch (this->standNum)
			{
			case 1: this->preWidth = 59.f;
				break;
			case 2: this->preWidth = 110.f;
				break;
			case 3: this->preWidth = 11.f;
				break;
			default:
				break;
			}
			this->standNum++;
		}
		else if (this->moving == true)
		{
			this->standNum = 3;
			this->preHeight = 257.f;
			this->width = 52.f;
			switch (this->moveNum)
			{
			case 1: this->preWidth = 8.f;
				break;
			case 2: this->preWidth = 65.f;
				break;
			case 3: this->preWidth = 143.f;
				break;
			case 4: this->preWidth = 202.f;
				break;
			default:
				break;
			}
			this->moveNum++;
		}
		if (this->turnLeft == false)
		{
			this->currentFrame = IntRect(this->preWidth, this->preHeight, this->width, this->height);
		}
		else if (this->turnLeft == true)
		{
			this->currentFrame = IntRect(this->preWidth + this->width, this->preHeight, -this->width, this->height);
		}
		this->sprite.setTextureRect(this->currentFrame);
		this->aniTime.restart();
	}*/
}

void Enemy::update(RenderTarget* target)
{
	this->updateInput();
	this->updateAnimation();
}

void Enemy::render(RenderTarget* target)
{
	target->draw(this->sprite);
}