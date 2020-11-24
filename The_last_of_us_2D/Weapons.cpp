#include "Weapons.h"

void Weapons::initVariables()
{
	this->width = 1031.f;
	this->height = 515.f;
	this->weaponsx = 980.f;
	this->weaponsy = 510.f;
	this->arrowTime.restart();
	this->arrowN = 0;
	this->checkArrow = false;
	this->lastLying = false;
	this->lieWidth = 0;
	this->lieHeight = 0;
}

void Weapons::initSprites()
{
	if (!this->weaponsTexture.loadFromFile("Weapons/Beretta 92FS Inox.png"))
		cout << "ERROR" << "\n";
	this->weaponsTexture.setSmooth(true);
	this->weapons.setTexture(this->weaponsTexture);
	this->weapons.setTextureRect(IntRect(0.f, 0.f, this->width, this->height));
	this->weapons.setPosition(this->weaponsx, this->weaponsy);
	this->weapons.setScale(0.08f, 0.08f);

	if (!this->arrowTexture.loadFromFile("Weapons/arrow.png"))
		cout << "ERROR" << "\n";
	this->arrowTexture.setSmooth(true);
	this->arrow.setTexture(this->arrowTexture);
	this->arrow.setTextureRect(IntRect(0.f, 0.f, 98.f, 12.f));
	this->arrow.setPosition(987.f, 532.f);
	this->arrow.setScale(0.5f, 0.5f);
}

Weapons::Weapons()
{
	this->initVariables();
	this->initSprites();
}

Weapons::~Weapons()
{
}

void Weapons::move(Vector2f x)
{
	this->weapons.move(x.x, x.y);
	this->arrow.move(x.x, x.y);
}

void Weapons::updateAnimations(bool lying, bool jumping, bool turnLeft, int slot)
{
	if (this->lastLying != lying)
	{
		if (this->lieHeight == 0.f)
		{
			this->lieWidth = -5.f;
			this->lieHeight = 25.f;
		}
		else
		{
			this->lieWidth = 0.f;
			this->lieHeight = 0.f;
		}
		this->lastLying = lying;
	}
	if (Mouse::isButtonPressed(Mouse::Left) && jumping == false)
	{
		if (!this->checkArrow && turnLeft)
		{
			this->arrowN = 0;
			this->arrow.setPosition(987.f - 101.f + this->lieWidth, 532.f + this->lieHeight);
			this->checkArrow = true;
		}
		else if (this->checkArrow && !turnLeft)
		{
			this->arrowN = 0;
			this->arrow.setPosition(987.f + this->lieWidth, 532.f + this->lieHeight);
			this->checkArrow = false;
		}
		if (this->arrowTime.getElapsedTime().asSeconds() >= 0.2f && this->arrowN < 3)
		{
			if (!turnLeft)
			{
				this->arrow.move(-5.f, 0.f);
				this->checkArrow = false;
			}
			else if (turnLeft)
			{
				this->arrow.move(5.f, 0.f);
				this->checkArrow = true;
			}
			this->arrowN++;
			this->arrowTime.restart();
		}
	}
	else if (!Mouse::isButtonPressed(Mouse::Left) && jumping == false)
	{
		this->arrowN = 0;
		if (!turnLeft)
		{
			this->arrow.setPosition(987.f + this->lieWidth, 532.f + this->lieHeight);
		}
		else
		{
			this->arrow.setPosition(987.f - 101.f + this->lieWidth, 532.f + this->lieHeight);
		}
	}
}

void Weapons::update(bool lying, bool jumping, bool turnLeft, int slot)
{
	if (this->mem != slot)
	{
		switch (slot)
		{
		case 0:
			break;
		case 4:
			this->weaponsTexture.loadFromFile("Weapons/Beretta 92FS Inox.png");
			this->weapons.setScale(0.06f, 0.06f);
			this->width = 1031.f;
			this->height = 515.f;
			break;
		case 3:
			this->weaponsTexture.loadFromFile("Weapons/AK-47.png");
			this->weapons.setScale(0.07f, 0.07f);
			this->width = 1739.f;
			this->height = 537.f;
			break;
		case 2:
			this->weaponsTexture.loadFromFile("Weapons/Remington 870.png");
			this->weapons.setScale(0.06f, 0.06f);
			this->width = 2143.f;
			this->height = 465.f;
			break;
		case 1:
			this->weaponsTexture.loadFromFile("Weapons/bow01.png");
			this->weapons.setScale(0.5f, 0.5f);
			this->width = 48.f;
			this->height = 119.f;
			if (!turnLeft)
			{
				this->arrow.setPosition(987.f + this->lieWidth, 532.f + this->lieHeight);
			}
			else
			{
				this->arrow.setPosition(987.f - 101.f + this->lieWidth, 532.f + this->lieHeight);
			}
			break;
		default:
			break;
		}
		this->weapons.setTexture(this->weaponsTexture);
		this->mem = slot;
	}
	if (turnLeft == false)
	{
		switch (slot)
		{
		case 0:
			break;
		case 4:
			this->weaponsx = 975.f;
			this->weaponsy = 515.f;
			break;
		case 3:
			this->weaponsx = 925.f;
			this->weaponsy = 520.f;
			break;
		case 2:
			this->weaponsx = 925.f;
			this->weaponsy = 520.f;
			break;
		case 1:
			this->weaponsx = 985.f;
			this->weaponsy = 505.f;
			this->arrow.setTextureRect(IntRect(0.f, 0.f, 98.f, 12.f));
			break;
		default:
			break;
		}
		this->weapons.setTextureRect(IntRect(0.f, 0.f, this->width, this->height));
	}
	else if (turnLeft == true)
	{
		switch (slot)
		{
		case 0:
			break;
		case 4:
			this->weaponsx = 975.f - 95.f;
			this->weaponsy = 515.f;
			break;
		case 3:
			this->weaponsx = 925.f - 50.f;
			this->weaponsy = 520.f;
			break;
		case 2:
			this->weaponsx = 925.f- 57.f;
			this->weaponsy = 520.f;
			break;
		case 1:
			this->weaponsx = 985.f - 74.f;
			this->weaponsy = 505.f;
			this->arrow.setTextureRect(IntRect(98.f, 0.f, -98.f, 12.f));
			break;
		default:
			break;
		}
		this->weapons.setTextureRect(IntRect(this->width, 0.f, -this->width, this->height));
	}
	this->weapons.setPosition(this->weaponsx + this->lieWidth, this->weaponsy + this->lieHeight);
	this->updateAnimations(lying, jumping, turnLeft, slot);
}

void Weapons::render(RenderTarget* target, int slot)
{
	if (slot == 1)
	{
		target->draw(this->arrow);
	}
	target->draw(this->weapons);
}
