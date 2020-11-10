#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
	this->ellieStand = 1;
	this->ellieMove = 1;
	this->turnLeft = false;
	this->width = 40.f;
	this->height = 55.f;
	this->frameShipLeft = 11.f;
	this->frameShipTop = 177.f;
	this->widthCenter = 881.25f;
	this->heightCenter = 424.f;
	this->aniHeadNumEye = 1;
	this->aniHead = 1;
	this->aniLegs = 1;
}

void Player::initSprites()
{
	/*-------------------------------------------------------------------------*/
	if (!this->ellieHeadTexture.loadFromFile("Textures/head01.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE HEAD TEXTURE." << "\n";
	if (!this->ellieLeftTexture.loadFromFile("Textures/lefthand.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE LEFT TEXTURE." << "\n";
	if (!this->ellieRightTexture.loadFromFile("Textures/righthand.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE RIGHT TEXTURE." << "\n";
	if (!this->ellieBodyTexture.loadFromFile("Textures/body.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE BODY TEXTURE." << "\n";
	if (!this->ellieLegsTexture.loadFromFile("Textures/legs.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE LEGS TEXTURE." << "\n";
	if (!this->ellieShadowTexture.loadFromFile("Textures/shadow.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE LEGS TEXTURE." << "\n";
	/*-------------------------------------------------------------------------*/
	this->ellieHead.setTexture(this->ellieHeadTexture);
	this->ellieLeft.setTexture(this->ellieLeftTexture);
	this->ellieRight.setTexture(this->ellieRightTexture);
	this->ellieBody.setTexture(this->ellieBodyTexture);
	this->ellieLegs.setTexture(this->ellieLegsTexture);
	this->ellieShadow.setTexture(this->ellieShadowTexture);
	this->ellieHead.setPosition(this->widthCenter, this->heightCenter);
	this->ellieBody.setPosition(this->widthCenter + 50.f, this->heightCenter + 105.f);
	this->ellieLeft.setPosition(this->widthCenter + 40.f, this->heightCenter + 110.f);
	this->ellieRight.setPosition(this->widthCenter + 100.f, this->heightCenter + 110.f);
	this->ellieLegs.setPosition(this->widthCenter + 55.f, this->heightCenter + 160.f);
	this->ellieShadow.setPosition(this->widthCenter + 27.f, this->heightCenter + 178.f);
	this->ellieHead.scale(0.5f, 0.5f);
	this->ellieBody.scale(0.5f, 0.5f);
	this->ellieLeft.scale(0.5f, 0.5f);
	this->ellieRight.scale(0.5f, 0.5f);
	this->ellieLegs.scale(0.5f, 0.5f);
	this->ellieShadow.scale(0.5f, 0.5f);
	/*-------------------------------------------------------------------------*/
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
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
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.05f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
		}
		this->moving = true;
		this->turnLeft = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.05f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
		}
		this->moving = true;
		this->turnLeft = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.05f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
		}
		this->moving = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.05f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
		}
		this->moving = true;
		
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
		this->ellieStand = 1;
	if (this->ellieMove >= 5)
		this->ellieMove = 1;
	if (this->aniHeadNumEye > 40)
		this->aniHeadNumEye = 1;
	if (this->aniHead > 2)
		this->aniHead = 1;
	if (this->aniLegs > 8)
		this->aniLegs = 1;
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
			this->ellieLegsTexture.loadFromFile("Textures/legs.png");
			this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 104.f, 57.f));
			this->ellieLegs.setPosition(this->widthCenter + 55.f, this->heightCenter + 160.f);
			this->ellieStand++;
			this->ellieMove = 1;
			this->aniLegs = 1;
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
			switch (this->aniLegs)
			{
			case 1:
				this->ellieLegsTexture.loadFromFile("Textures/legs01.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 112.f, 60.f));
				this->ellieLegs.setPosition(this->widthCenter + 52.f, this->heightCenter + 158.f);
				break;
			case 2:
				this->ellieLegsTexture.loadFromFile("Textures/legs02.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 126.f, 72.f));
				this->ellieLegs.setPosition(this->widthCenter + 51.f, this->heightCenter + 150.f);
				break;
			case 3:
				this->ellieLegsTexture.loadFromFile("Textures/legs03.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 112.f, 60.f));
				this->ellieLegs.setPosition(this->widthCenter + 52.f, this->heightCenter + 158.f);
				break;
			case 4:
				this->ellieLegsTexture.loadFromFile("Textures/legs04.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 108.f, 60.f));
				this->ellieLegs.setPosition(this->widthCenter + 52.f, this->heightCenter + 158.f);
				break;
			case 5:
				this->ellieLegsTexture.loadFromFile("Textures/legs05.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 113.f, 69.f));
				this->ellieLegs.setPosition(this->widthCenter + 51.f, this->heightCenter + 153.f);
				break;
			case 6:
				this->ellieLegsTexture.loadFromFile("Textures/legs06.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 112.f, 81.f));
				this->ellieLegs.setPosition(this->widthCenter + 54.f, this->heightCenter + 145.f);
				break;
			case 7:
				this->ellieLegsTexture.loadFromFile("Textures/legs07.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 108.f, 66.f));
				this->ellieLegs.setPosition(this->widthCenter + 55.f, this->heightCenter + 155.f);
				break;
			case 8:
				this->ellieLegsTexture.loadFromFile("Textures/legs.png");
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 104.f, 57.f));
				this->ellieLegs.setPosition(this->widthCenter + 55.f, this->heightCenter + 160.f);
				break;
			default:
				break;
			}
			this->ellieMove++;
			this->aniLegs++;
			this->ellieStand = 1;
		}
		if (this->turnLeft == false)
		{
			
		}
		else if (this->turnLeft == true)
		{
			
		}
		switch (this->aniHeadNumEye)
		{
		case 1: this->ellieHeadTexture.loadFromFile("Textures/head02.png");
			break;
		case 3: this->ellieHeadTexture.loadFromFile("Textures/head01.png");
			break;
		case 20: this->ellieHeadTexture.loadFromFile("Textures/head02.png");
			break;
		case 22: this->ellieHeadTexture.loadFromFile("Textures/head01.png");
			break;
		default:
			break;
		}
		if (this->aniHead == 1)
		{
			this->ellieHead.setPosition(this->widthCenter, this->heightCenter + 2.f);
			this->ellieBody.setPosition(this->widthCenter + 50.f, this->heightCenter + 106.f);
		}
		else
		{
			this->ellieHead.setPosition(this->widthCenter, this->heightCenter);
			this->ellieBody.setPosition(this->widthCenter + 50.f, this->heightCenter + 105.f);
		}
		this->aniHeadNumEye++;
		this->aniHead++;
		this->ellieLegs.setTexture(this->ellieLegsTexture);
		this->ellieHead.setTexture(this->ellieHeadTexture);
		this->animationTimer.restart();
	}
}

void Player::update(RenderTarget* target)
{
	this->updateInput();
	this->updateAnimations();
}

void Player::render(RenderTarget* target, Shader* shader)
{
	if (shader)
	{
		//target->draw(this->ellie, shader);
	}
	else
	{
		//target->draw(this->ellie);
	}
	target->draw(this->ellieShadow);
	target->draw(this->ellieLegs);
	target->draw(this->ellieRight);
	target->draw(this->ellieBody);
	target->draw(this->ellieLeft);
	target->draw(this->ellieHead);
	
}