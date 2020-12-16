#include "Enemy.h"

void Enemy::initVariables()
{
	this->movementSpeed = 10.f;
	this->preWidth = 13.f;
	this->preHeight = 72.f;
	this->width = 78.f;
	this->height = 103.f;
	this->moving = false;
	this->spawnNum = 0;
	this->moveNum = 1;
	this->turnLeft = false;
	this->moveY = 0.f;
	this->lastMoveY = 0.f;
	this->spawning = true;
	this->isDead = false;
	this->deadNum = 1;
}

void Enemy::initSprite()
{
	this->currentFrame = IntRect(this->preWidth, this->preHeight + this->height, this->width, -this->height);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.scale(1.25f, -1.25f);
	this->sprite.setPosition(300.f, 300.f);
}

void Enemy::initColor()
{
	
	int type = rand() % 5;
	switch (type)
	{
	case 0:
		if (!this->texture.loadFromFile("Textures/red.png"))
			cout << "ERROR" << "\n";
		break;
	case 1:
		if (!this->texture.loadFromFile("Textures/green.png"))
			cout << "ERROR" << "\n";
		break;
	case 2:
		if (!this->texture.loadFromFile("Textures/yellow.png"))
			cout << "ERROR" << "\n";
		break;
	case 3:
		if (!this->texture.loadFromFile("Textures/blue.png"))
			cout << "ERROR" << "\n";
		break;
	case 4:
		if (!this->texture.loadFromFile("Textures/Spritesheet.png"))
			cout << "ERROR" << "\n";
		break;
	default:
		if (!this->texture.loadFromFile("Textures/red.png"))
			cout << "ERROR" << "\n";
		break;
	}
}

void Enemy::initAnimetion()
{
	this->aniTime.restart();
}

Enemy::Enemy()
{
	this->initVariables();
	this->initColor();
	this->initSprite();
	this->initAnimetion();
}

Enemy::~Enemy()
{
}

void Enemy::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->moving = true;
		this->turnLeft = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->moving = true;
		this->turnLeft = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->spawning = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->isDead = true;
	}
	else
	{
		this->moving = false;
	}
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
	if (this->moveNum > 12)
	{
		this->moveNum = 1;
	}
	if (this->spawnNum > 7)
	{
		this->spawnNum = 0;
		this->spawning = false;
	}
	if (this->deadNum > 33)
	{
		this->deadNum = 1;
		this->isDead = false;
	}
	if (this->aniTime.getElapsedTime().asSeconds() >= 0.04f)
	{
		if (this->isDead == false)
		{
			if (this->moving == false && this->spawning == false)
			{
				this->preWidth = 13.f;
				this->preHeight = 72.f;
				this->width = 78.f;
				this->height = 103.f;
				this->moveNum = 1;
				this->lastMoveY = 0.f;
				this->moveY = 0.f;
			}
			else if (this->moving == true && this->spawning == false)
			{
				this->preHeight = 420.f;
				switch (this->moveNum)
				{
				case 1: this->preWidth = 13.f; this->width = 84.f; this->height = 113.f;
					break;
				case 2: this->preWidth = 110.f; this->width = 84.f; this->height = 115.f;
					break;
				case 3: this->preWidth = 207.f; this->width = 84.f; this->height = 112.f;
					break;
				case 4: this->preWidth = 304.f; this->width = 84.f; this->height = 107.f;
					break;
				case 5: this->preWidth = 401.f; this->width = 76.f; this->height = 97.f;
					break;
				case 6: this->preWidth = 490.f; this->width = 76.f; this->height = 97.f;
					break;
				case 7: this->preWidth = 579.f; this->width = 78.f; this->height = 117.f;
					break;
				case 8: this->preWidth = 670.f; this->width = 78.f; this->height = 120.f;
					break;
				case 9: this->preWidth = 761.f; this->width = 78.f; this->height = 117.f;
					break;
				case 10: this->preWidth = 852.f; this->width = 77.f; this->height = 107.f;
					break;
				case 11: this->preWidth = 942.f; this->width = 76.f; this->height = 95.f;
					break;
				case 12: this->preWidth = 1031.f; this->width = 76.f; this->height = 95.f;
					break;
				default:
					break;
				}
				this->moveNum++;
			}
			else if (this->spawning == true)
			{
				this->preHeight = 934.f;
				switch (this->spawnNum)
				{
				case 0: this->preWidth = 668.f; this->width = 81.f; this->height = 68.f;
					break;
				case 1: this->preWidth = 577.f; this->width = 81.f; this->height = 68.f;
					break;
				case 2: this->preWidth = 483.f; this->width = 81.f; this->height = 93.f;
					break;
				case 3: this->preWidth = 389.f; this->width = 81.f; this->height = 92.f;
					break;
				case 4: this->preWidth = 295.f; this->width = 81.f; this->height = 100.f;
					break;
				case 5: this->preWidth = 201.f; this->width = 81.f; this->height = 100.f;
					break;
				case 6: this->preWidth = 107.f; this->width = 81.f; this->height = 93.f;
					break;
				case 7: this->preWidth = 13.f; this->width = 81.f; this->height = 92.f;
					break;
				default:
					break;
				}
				this->spawnNum++;
			}
		}
		else
		{
			if (this->deadNum <= 14)
				this->preHeight = 1106.f;
			else if (this->deadNum > 14 && this->deadNum <= 28)
				this->preHeight = 1218.f;
			else if (this->deadNum > 28)
				this->preHeight = 1327.f;
			switch (this->deadNum)
			{
			case 1: this->preWidth = 13.f; this->width = 80.f; this->height = 81.f;
				break;
			case 2: this->preWidth = 106.f; this->width = 79.f; this->height = 81.f;
				break;
			case 3: this->preWidth = 198.f; this->width = 79.f; this->height = 81.f;
				break;
			case 4: this->preWidth = 290.f; this->width = 79.f; this->height = 81.f;
				break;
			case 5: this->preWidth = 382.f; this->width = 79.f; this->height = 81.f;
				break;
			case 6: this->preWidth = 474.f; this->width = 78.f; this->height = 81.f;
				break;
			case 7: this->preWidth = 565.f; this->width = 78.f; this->height = 81.f;
				break;
			case 8: this->preWidth = 656.f; this->width = 78.f; this->height = 81.f;
				break;
			case 9: this->preWidth = 747.f; this->width = 78.f; this->height = 81.f;
				break;
			case 10: this->preWidth = 838.f; this->width = 78.f; this->height = 81.f;
				break;
			case 11: this->preWidth = 929.f; this->width = 78.f; this->height = 81.f;
				break;
			case 12: this->preWidth = 1020.f; this->width = 79.f; this->height = 81.f;
				break;
			case 13: this->preWidth = 1112.f; this->width = 80.f; this->height = 81.f;
				break;
			case 14: this->preWidth = 1205.f; this->width = 80.f; this->height = 81.f;
				break;
			case 15: this->preWidth = 13.f; this->width = 80.f; this->height = 81.f;
				break;
			case 16: this->preWidth = 106.f; this->width = 80.f; this->height = 81.f;
				break;
			case 17: this->preWidth = 199.f; this->width = 80.f; this->height = 81.f;
				break;
			case 18: this->preWidth = 292.f; this->width = 80.f; this->height = 81.f;
				break;
			case 19: this->preWidth = 385.f; this->width = 80.f; this->height = 81.f;
				break;
			case 20: this->preWidth = 478.f; this->width = 80.f; this->height = 81.f;
				break;
			case 21: this->preWidth = 571.f; this->width = 80.f; this->height = 81.f;
				break;
			case 22: this->preWidth = 664.f; this->width = 80.f; this->height = 81.f;
				break;
			case 23: this->preWidth = 757.f; this->width = 80.f; this->height = 81.f;
				break;
			case 24: this->preWidth = 850.f; this->width = 80.f; this->height = 81.f;
				break;
			case 25: this->preWidth = 943.f; this->width = 80.f; this->height = 81.f;
				break;
			case 26: this->preWidth = 1041.f; this->width = 80.f; this->height = 81.f;
				break;
			case 27: this->preWidth = 1134.f; this->width = 79.f; this->height = 81.f;
				break;
			case 28: this->preWidth = 1226.f; this->width = 79.f; this->height = 81.f;
				break;
			case 29: this->preWidth = 13.f; this->width = 78.f; this->height = 81.f;
				break;
			case 30: this->preWidth = 104.f; this->width = 78.f; this->height = 81.f;
				break;
			case 31: this->preWidth = 195.f; this->width = 88.f; this->height = 81.f; this->sprite.move(-10.f, 0.f);
				break;
			case 32: this->preWidth = 296.f; this->width = 84.f; this->height = 64.f; this->sprite.move(10.f, 0.f);
				break;
			case 33: this->preWidth = 393.f; this->width = 77.f; this->height = 69.f;
				break;
			default:
				break;
			}
			this->deadNum++;
		}
		if (this->turnLeft == false)
		{
			if (this->isDead == false)
				this->currentFrame = IntRect(this->preWidth, this->preHeight + this->height, this->width, -this->height);
			else
				this->currentFrame = IntRect(this->preWidth + this->width, this->preHeight + this->height, -this->width, -this->height);
		}
		else if (this->turnLeft == true)
		{
			if (this->isDead == false)
				this->currentFrame = IntRect(this->preWidth + this->width, this->preHeight + this->height, -this->width, -this->height);
			else
				this->currentFrame = IntRect(this->preWidth, this->preHeight + this->height, this->width, -this->height);
		}
		this->sprite.setTextureRect(this->currentFrame);
		this->aniTime.restart();
	}
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