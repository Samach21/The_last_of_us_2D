#include "Map.h"

void Map::initVariables()
{
	this->movementSpeed = 2.f;
}

void Map::initSprites()
{
	if (!this->mapTexture.loadFromFile("Map/PC Computer - Among Us - Cafeteria Skeld.png"))
		cout << "ERROR" << "\n";
	this->map.setTexture(this->mapTexture);
	this->map.scale(2.f, 2.f);
}

Map::Map()
{
	this->initVariables();
	this->initSprites();
}

Map::~Map()
{
}

void Map::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->movementSpeed = 4.5f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 1.5f;
		}
		else {
			this->movementSpeed = 2.f;
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->map.move(0.f, this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->map.move(0.f, -this->movementSpeed);
		}
		this->map.move(this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->movementSpeed = 4.5f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 1.5f;
		}
		else {
			this->movementSpeed = 2.f;
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->map.move(0.f, this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->movementSpeed = this->movementSpeed * 0.707f;
			this->map.move(0.f, -this->movementSpeed);
		}
		this->map.move(-this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->movementSpeed = 4.5f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 1.5f;
		}
		else {
			this->movementSpeed = 2.f;
		}
		this->map.move(0.f, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->movementSpeed = 4.5f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 1.5f;
		}
		else {
			this->movementSpeed = 2.f;
		}
		this->map.move(0.f, -this->movementSpeed);
	}
}

void Map::update(RenderTarget* target)
{
	this->updateInput();
}

void Map::render(RenderTarget* target)
{
	target->draw(this->map);
}
