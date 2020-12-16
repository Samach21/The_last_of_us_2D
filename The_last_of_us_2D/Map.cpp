#include "Map.h"

void Map::initVariables()
{
	this->movementSpeed = 5.f;
	this->turnLeft = false;
	this->lying = false;
	this->lyingTimer.restart();
	this->lastPosition.x = -3850;
	this->lastPosition.y = -300;
	this->positionTimer.restart();
	this->Aon = true;
	this->AWon = true;
	this->ASon = true;
	this->Don = true;
	this->DWon = true;
	this->DSon = true;
	this->Son = true;
	this->Won = true;
	this->renderFrontON = false;
}

void Map::initSprites()
{
	if (!this->mapTexture.loadFromFile("Map/SkeldWall.png"))
		cout << "ERROR" << "\n";
	this->map.setTexture(this->mapTexture);
	this->map.setPosition(Vector2f(-3850.f, -300.f));
	if (!this->FloorMapTexture.loadFromFile("Map/Skeld.png"))
		cout << "ERROR" << "\n";
	this->FloorMap.setTexture(this->FloorMapTexture);
	this->FloorMap.setPosition(Vector2f(-3850.f, -300.f));
	if (!this->FrontMapTexture.loadFromFile("Map/SkeldFront.png"))
		cout << "ERROR" << "\n";
	this->FrontMap.setTexture(this->FrontMapTexture);
	this->FrontMap.setPosition(Vector2f(-3850.f, -300.f));
	if (!this->mapCheckTexture.loadFromFile("Map/SkeldFront.png"))
		cout << "ERROR" << "\n";
	this->mapCheck.setTexture(this->mapCheckTexture);
	this->mapCheck.setPosition(Vector2f(-3850.f, -300.f));

	if (!this->dotTexture.loadFromFile("Map/cicle.png"))
		cout << "ERROR" << "\n";
	this->top.setTexture(this->dotTexture);
	this->down.setTexture(this->dotTexture);
	this->left.setTexture(this->dotTexture);
	this->right.setTexture(this->dotTexture);
	this->topleft.setTexture(this->dotTexture);
	this->topright.setTexture(this->dotTexture);
	this->downleft.setTexture(this->dotTexture);
	this->downright.setTexture(this->dotTexture);
	this->lefttop.setTexture(this->dotTexture);
	this->leftdown.setTexture(this->dotTexture);
	this->righttop.setTexture(this->dotTexture);
	this->rightdown.setTexture(this->dotTexture);

	this->top.setPosition(954.f, 555.f);
	this->down.setPosition(954.f, 587.f);
	this->left.setPosition(895.f, 573.f);
	this->right.setPosition(1014.f, 573.f);
	this->topleft.setPosition(911.f, 555.f);
	this->topright.setPosition(998.f, 555.f);
	this->downleft.setPosition(911.f, 587.f);
	this->downright.setPosition(998.f, 587.f);
	this->lefttop.setPosition(895.f, 555.f);
	this->leftdown.setPosition(895.f, 587.f);
	this->righttop.setPosition(1014.f, 555.f);
	this->rightdown.setPosition(1014.f, 587.f);
}

Map::Map()
{
	this->initVariables();
	this->initSprites();
}

Map::~Map()
{
}

void Map::allmove(float x, float y)
{
	if (this->isCollide == false)
	{
		//this->lastPosition.x += x;
		//this->lastPosition.y += y;
	}
	else
	{
		//this->lastPosition.x -= x;
		//this->lastPosition.y -= y;
	}
	this->lastPosition.x += x;
	this->lastPosition.y += y;
	this->map.setPosition(this->lastPosition);
	this->mapCheck.setPosition(this->lastPosition);
	this->FloorMap.setPosition(this->lastPosition);
	this->FrontMap.setPosition(this->lastPosition);
	//std::cout << this->lastPosition.x << " " << this->lastPosition.y << std::endl;
}

void Map::updateMousePosition(RenderWindow* window)
{
	this->mousePosWindow = Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
	if (this->mousePosWindow.x > 960)
		this->turnLeft = false;
	else
		this->turnLeft = true;
}

void Map::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && this->Aon == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == true && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		allmove(this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && this->AWon == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == true && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		this->movementSpeed = this->movementSpeed * 0.707f;
		allmove(this->movementSpeed, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S) && this->ASon == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == true && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		this->movementSpeed = this->movementSpeed * 0.707f;
		allmove(this->movementSpeed, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && this->Don == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == false && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		allmove(-this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && this->DWon == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == false && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		this->movementSpeed = this->movementSpeed * 0.707f;
		allmove(-this->movementSpeed, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S) && this->DSon == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == false && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		this->movementSpeed = this->movementSpeed * 0.707f;
		allmove(-this->movementSpeed, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && this->Won == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		allmove(0.f, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && this->Son == true)
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->lying == false)
			this->movementSpeed = 10.f;
		else if (Keyboard::isKeyPressed(Keyboard::LControl))
			this->movementSpeed = 4.f;
		else
			this->movementSpeed = 6.f;
		allmove(0.f, -this->movementSpeed);
	}
	//std::cout << this->isW << this->isA << this->isS << this->isD << std::endl;
	if (Keyboard::isKeyPressed(Keyboard::C))
	{
		if (this->lyingTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->lying = !this->lying;
			this->lyingTimer.restart();
		}
	}

	if (this->AWon == false && this->topleftBool == false && Keyboard::isKeyPressed(Keyboard::W))
	{
		this->movementSpeed = 3.f;
		allmove(0.f, this->movementSpeed);
	}
	else if (this->ASon == false && this->downleftBool == false && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->movementSpeed = 3.f;
		allmove(0.f, -this->movementSpeed);
	}
	else if (this->DWon == false && this->toprightBool == false && Keyboard::isKeyPressed(Keyboard::W))
	{
		this->movementSpeed = 3.f;
		allmove(0.f, this->movementSpeed);
	}
	else if (this->DSon == false && this->downrightBool == false && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->movementSpeed = 3.f;
		allmove(0.f, -this->movementSpeed);
	}

	if (this->AWon == false && this->leftBool == false && Keyboard::isKeyPressed(Keyboard::A))
	{
		this->movementSpeed = 3.f;
		allmove(this->movementSpeed, 0.f);
	}
	else if (this->DWon == false && this->rightBool == false && Keyboard::isKeyPressed(Keyboard::D))
	{
		this->movementSpeed = 3.f;
		allmove(-this->movementSpeed, 0.f);
	}
	else if (this->ASon == false && this->leftBool == false && Keyboard::isKeyPressed(Keyboard::A))
	{
		this->movementSpeed = 3.f;
		allmove(this->movementSpeed, 0.f);
	}
	else if (this->DSon == false && this->rightBool == false && Keyboard::isKeyPressed(Keyboard::D))
	{
		this->movementSpeed = 3.f;
		allmove(-this->movementSpeed, 0.f);
	}
}

void Map::updatePosition()
{
	if (this->topBool == true || this->topleftBool == true || this->toprightBool == true)
		this->Won = false;
	else 
		this->Won = true;
	if (this->topBool == true || (this->leftBool == true && this->topleftBool == true) || (this->leftBool == true && this->lefttopBool == true && this->leftdownBool == true))
		this->AWon = false;
	else if (this->topBool == false && this->leftBool == false)
		this->AWon = true;
	if (this->leftBool == true)
		this->Aon = false;
	else
		this->Aon = true;
	if (this->downBool == true || (this->leftBool == true && this->downleftBool == true) || (this->leftBool == true && this->lefttopBool == true && this->leftdownBool == true))
		this->ASon = false;
	else if (this->downBool == false && this->leftBool == false)
		this->ASon = true;
	if (this->downBool == true || this->downleftBool == true || this->downrightBool == true)
		this->Son = false;
	else
		this->Son = true;
	if (this->downBool == true || (this->rightBool == true && this->downrightBool == true) || (this->rightBool == true && this->righttopBool == true && this->rightdownBool == true))
		this->DSon = false;
	else if (this->downBool == false && this->rightBool == false)
		this->DSon = true;
	if (this->rightBool == true)
		this->Don = false;
	else
		this->Don = true;
	if (this->topBool == true || (this->rightBool == true && this->toprightBool == true) || (this->rightBool == true && this->righttopBool == true && this->rightdownBool == true))
		this->DWon = false;
	else if (this->topBool == false && this->rightBool == false)
		this->DWon = true;
	//std::cout << this->rightBool << std::endl;
}

void Map::updateCollide()
{
	if (Collision::PixelPerfectTest(this->map, this->top))
		this->topBool = true;
	else
		this->topBool = false;
	if (Collision::PixelPerfectTest(this->map, this->down))
		this->downBool = true;
	else
		this->downBool = false;
	if (Collision::PixelPerfectTest(this->map, this->left))
		this->leftBool = true;
	else
		this->leftBool = false;
	if (Collision::PixelPerfectTest(this->map, this->right))
		this->rightBool = true;
	else
		this->rightBool = false;
	if (Collision::PixelPerfectTest(this->map, this->topleft))
		this->topleftBool = true;
	else
		this->topleftBool = false;
	if (Collision::PixelPerfectTest(this->map, this->topright))
		this->toprightBool = true;
	else
		this->toprightBool = false;
	if (Collision::PixelPerfectTest(this->map, this->downleft))
		this->downleftBool = true;
	else
		this->downleftBool = false;
	if (Collision::PixelPerfectTest(this->map, this->downright))
		this->downrightBool = true;
	else
		this->downrightBool = false;
	if (Collision::PixelPerfectTest(this->map, this->lefttop))
		this->lefttopBool = true;
	else
		this->lefttopBool = false;
	if (Collision::PixelPerfectTest(this->map, this->leftdown))
		this->leftdownBool = true;
	else
		this->leftdownBool = false;
	if (Collision::PixelPerfectTest(this->map, this->righttop))
		this->righttopBool = true;
	else
		this->righttopBool = false;
	if (Collision::PixelPerfectTest(this->map, this->rightdown))
		this->rightdownBool = true;
	else
		this->rightdownBool = false;
}

void Map::updateRenderFront()
{
}

void Map::update(RenderTarget* target, RenderWindow* window)
{
	this->updateMousePosition(window);
	this->updateCollide();
	this->updateRenderFront();
	this->updatePosition();
	this->updateInput();
}

void Map::render(RenderTarget* target)
{
	target->draw(this->FloorMap);
	target->draw(this->map);
}

void Map::renderFront(RenderTarget* target)
{
	if (this->renderFrontON == true)
		target->draw(this->FrontMap);
	/*target->draw(this->top);
	target->draw(this->down);
	target->draw(this->left);
	target->draw(this->right);
	target->draw(this->topleft);
	target->draw(this->topright);
	target->draw(this->downleft);
	target->draw(this->downright);
	target->draw(this->lefttop);
	target->draw(this->leftdown);
	target->draw(this->righttop);
	target->draw(this->rightdown);*/
}
