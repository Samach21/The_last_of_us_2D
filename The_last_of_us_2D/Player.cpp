#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.f;
	this->moving = false;
	this->ellieStand = 1;
	this->ellieMove = 1;
	this->turnLeft = false;
	this->width = 40.f;
	this->height = 55.f;
	this->frameShipLeft = 11.f;
	this->frameShipTop = 177.f;
}

void Player::initSprites()
{
	if (!this->texture.loadFromFile("Map/PC Computer - Among Us - Cafeteria Skeld.png"))
	{
		cout << "ERROR" << "\n";
	}
	if (!this->ellieTexture.loadFromFile("Textures/preEllie.png"))
	{
		cout << "ERROR::COULD NOT LOAD ELLIE TEXTURE." << "\n";
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
	this->initSprites();
	this->initAnimations();
}

Player::~Player()
{
}

void Player::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			this->movementSpeed = 4.5f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 1.5f;
		else
			this->movementSpeed = 2.f;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->sprite.move(0.f, this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->sprite.move(0.f, -this->movementSpeed);
		}
		this->sprite.move(this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = true;
		this->aniTime = 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			this->movementSpeed = 4.5f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 1.5f;
		else
			this->movementSpeed = 2.f;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->sprite.move(0.f, this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->sprite.move(0.f, -this->movementSpeed);
		}
		this->sprite.move(-this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = false;
		this->aniTime = 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			this->movementSpeed = 4.5f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 1.5f;
		else
			this->movementSpeed = 2.f;
		this->sprite.move(0.f, this->movementSpeed);
		this->moving = true;
		this->aniTime = 0.1f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			this->movementSpeed = 4.5f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 1.5f;
		else
			this->movementSpeed = 2.f;
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
			this->frameShipTop = 177.f;
			switch (this->ellieStand)
			{
			case 1: this->frameShipLeft = 59.f;
				break;
			case 2: this->frameShipLeft = 110.f;
				break;
			case 3: this->frameShipLeft = 11.f;
				break;
			default:
				break;
			}
			this->ellieStand++;
			this->ellieMove = 1;
		}
		else
		{
			this->frameShipTop = 261.f;
			this->width = 52.f;
			switch (this->ellieMove)
			{
			case 1: this->frameShipLeft = 8.f;
				break;
			case 2: this->frameShipLeft = 65.f;
				break;
			case 3: this->frameShipLeft = 142.f;
				break;
			case 4: this->frameShipLeft = 202.f;
				break;
			default:
				break;
			}
			this->ellieMove++;
			this->ellieStand = 1;
		}
		if (this->turnLeft == false)
		{
			this->currentFrame = IntRect(this->frameShipLeft, this->frameShipTop, this->width, this->height);
		}
		else if (this->turnLeft == true)
		{
			this->currentFrame = IntRect(this->frameShipLeft + this->width, this->frameShipTop, this->width * (-1), this->height);
		}
		this->animationTimer.restart();
		this->ellie.setTextureRect(this->currentFrame);
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