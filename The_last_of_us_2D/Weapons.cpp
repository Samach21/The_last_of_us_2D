#include "Weapons.h"

void Weapons::initVariables()
{
	this->width = 1031.f;
	this->height = 515.f;
	this->weaponsx = 980.f;
	this->weaponsy = 510.f;
}

void Weapons::initSprites()
{
	if (!this->weaponsTexture.loadFromFile("Weapons/Beretta 92FS Inox.png"))
		cout << "ERROR" << "\n";
	this->weapons.setTexture(this->weaponsTexture);
	this->weapons.setTextureRect(IntRect(0.f, 0.f, this->width, this->height));
	this->weapons.setPosition(this->weaponsx, this->weaponsy);
	this->weapons.setScale(0.08f, 0.08f);
}

Weapons::Weapons()
{
	this->initVariables();
	this->initSprites();
}

Weapons::~Weapons()
{
}

void Weapons::update(bool turnLeft, int slot)
{
	if (this->mem != slot)
	{
		switch (slot)
		{
		case 0:
			break;
		case 3:
			this->weaponsTexture.loadFromFile("Weapons/Beretta 92FS Inox.png");
			this->weapons.setScale(0.06f, 0.06f);
			this->width = 1031.f;
			this->height = 515.f;
			break;
		case 2:
			this->weaponsTexture.loadFromFile("Weapons/AK-47.png");
			this->weapons.setScale(0.07f, 0.07f);
			this->width = 1739.f;
			this->height = 537.f;
			break;
		case 1:
			this->weaponsTexture.loadFromFile("Weapons/Remington 870.png");
			this->weapons.setScale(0.06f, 0.06f);
			this->width = 2143.f;
			this->height = 465.f;
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
		case 3:
			this->weaponsx = 985.f;
			this->weaponsy = 515.f;
			break;
		case 2:
			this->weaponsx = 925.f;
			this->weaponsy = 520.f;
			break;
		case 1:
			this->weaponsx = 925.f;
			this->weaponsy = 520.f;
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
		case 3:
			this->weaponsx = 985.f - 111.f;
			this->weaponsy = 515.f;
			break;
		case 2:
			this->weaponsx = 925.f - 50.f;
			this->weaponsy = 520.f;
			break;
		case 1:
			this->weaponsx = 925.f- 57.f;
			this->weaponsy = 520.f;
			break;
		default:
			break;
		}
		this->weapons.setTextureRect(IntRect(this->width, 0.f, -this->width, this->height));
	}
	this->weapons.setPosition(this->weaponsx, this->weaponsy);
}

void Weapons::render(RenderTarget* target)
{
	target->draw(this->weapons);
}
