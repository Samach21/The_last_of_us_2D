#include "Map.h"

void Map::initVariables()
{
	this->movementSpeed = 5.f;
	this->turnLeft = false;
	this->lying = false;
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

void Map::updateMousePosition(RenderWindow* window)
{
	this->mousePosWindow = Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
	if (this->mousePosWindow.x > 960)
	{
		this->turnLeft = false;
	}
	else
	{
		this->turnLeft = true;
	}
}

void Map::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == true && this->lying == false) {
			this->movementSpeed = 10.f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 4.f;
		}
		else {
			this->movementSpeed = 6.f;
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
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == false && this->lying == false) {
			this->movementSpeed = 10.f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 4.f;
		}
		else {
			this->movementSpeed = 6.f;
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
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->lying == false) {
			this->movementSpeed = 10.f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 4.f;
		}
		else {
			this->movementSpeed = 6.f;
		}
		this->map.move(0.f, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->lying == false) {
			this->movementSpeed = 10.f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->movementSpeed = 4.f;
		}
		else {
			this->movementSpeed = 6.f;
		}
		this->map.move(0.f, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::C))
	{
		if (this->lying == true)
		{
			this->lying = false;
		}
		else if (this->lying == false)
		{
			this->lying = true;
		}
	}
}

void Map::update(RenderTarget* target, RenderWindow* window)
{
	this->updateMousePosition(window);
	this->updateInput();
}

void Map::render(RenderTarget* target)
{
	target->draw(this->map);
}
