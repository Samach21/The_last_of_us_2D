#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 4.5f;
	this->moving = false;
	this->ellieStand = 1;
	this->ellieMove = 1;
	this->turnLeft = false;
	this->width = 40.f;
	this->height = 55.f;
	this->frame = 11.f;
}

void Player::initShape()
{
	if (!this->texture.loadFromFile("Map/PC Computer - Among Us - Cafeteria Skeld.png"))
	{
		cout << "ERROR" << "\n";
	}
	if (!this->ellieTexture.loadFromFile("Textures/preEllie.png"))
	{
		cout << "ERROR" << "\n";
	}
	this->currentFrame = IntRect(11.f, 177.f, 40.f, 55.f);
	this->ellie.setTexture(this->ellieTexture);
	this->ellie.setTextureRect(this->currentFrame);
	this->ellie.scale(2.5f, 2.5f);
	this->ellie.setPosition(Vector2f(885.f, 427.5f));
	this->sprite.scale(2.f, 2.f);
	this->sprite.setTexture(this->texture);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player(float x, float y)
{
	this->shape.setPosition(910.f, 490.f);
	this->sprite.setPosition(x, y);

	this->initVariables();
	this->initShape();
	this->initAnimations();
}

Player::~Player()
{
}

void Player::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->sprite.move(this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = true;
		this->aniTime = 0.1f;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
		this->sprite.move(0.f, -this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->sprite.move(-this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = false;
		this->aniTime = 0.1f;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->sprite.move(0.f, this->movementSpeed);
		this->moving = true;
		this->aniTime = 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->sprite.move(0.f, -this->movementSpeed);
		this->moving = true;
		this->aniTime = 0.1f;
	}
	else
	{
		this->moving = false;
		this->aniTime = 0.13f;
	}
}

void Player::updateAnimations()
{
	if (this->ellieStand >= 4)
	{
		this->ellieStand = 1;
	}
	if (this->ellieMove >= 5)
	{
		this->ellieMove = 1;
	}
	if (this->animationTimer.getElapsedTime().asSeconds() >= this->aniTime)
	{
		if (this->moving == false)
		{
			this->width = 40.f;
			switch (this->ellieStand)
			{
			case 1: this->frame = 59.f;
				break;
			case 2: this->frame = 110.f;
				break;
			case 3: this->frame = 11.f;
				break;
			default:
				break;
			}
			if (this->turnLeft == false)
			{
				this->currentFrame = IntRect(this->frame, 177.f, this->width, this->height);
			}
			else if (this->turnLeft == true)
			{
				this->currentFrame = IntRect(this->frame + this->width, 177.f, this->width * (-1), this->height);
			}
			this->animationTimer.restart();
			this->ellie.setTextureRect(this->currentFrame);
			this->ellieStand++;
			this->ellieMove = 1;
		}
		else
		{
			this->width = 52.f;
			switch (this->ellieMove)
			{
			case 1: this->frame = 8.f;
				break;
			case 2: this->frame = 65.f;
				break;
			case 3: this->frame = 142.f;
				break;
			case 4: this->frame = 202.f;
				break;
			default:
				break;
			}
			if (this->turnLeft == false)
			{
				this->currentFrame = IntRect(this->frame, 261.f, this->width, this->height);
			}
			else if (this->turnLeft == true)
			{
				this->currentFrame = IntRect(this->frame + this->width, 261.f, this->width * (-1), this->height);
			}
			this->animationTimer.restart();
			this->ellie.setTextureRect(this->currentFrame);
			this->ellieMove++;
			this->ellieStand = 1;
		}
	}
}

void Player::update(RenderTarget* target)
{
	this->updateInput();
	this->updateAnimations();
}

void Player::render(RenderTarget* target, Shader* shader)
{
	target->draw(this->sprite);
	if (shader)
	{
		target->draw(this->ellie, shader);
	}
	else
	{
		//target->draw(this->ellie);
	}
}