#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
	this->running = false;
	this->ellieStand = 1;
	this->ellieMove = 1;
	this->turnLeft = false;
	this->width = 40.f;
	this->height = 55.f;
	this->frameShipLeft = 11.f;
	this->frameShipTop = 177.f;
	this->widthCenter = 890;
	this->heightCenter = 424.f;
	this->aniHeadNumEye = 1;
	this->aniHead = 1;
	this->aniLegs = 1;
}

void Player::initSprites()
{
	/*-------------------------------------------------------------------------*/
	if (!this->ellieHeadTexture.loadFromFile("Textures/head01b.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE HEAD TEXTURE." << "\n";
	if (!this->ellieLeftTexture.loadFromFile("Textures/handb.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE LEFT TEXTURE." << "\n";
	if (!this->ellieRightTexture.loadFromFile("Textures/handb.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE RIGHT TEXTURE." << "\n";
	if (!this->ellieBodyTexture.loadFromFile("Textures/bodyb.png"))
		cout << "ERROR::COULD NOT LOAD ELLIE BODY TEXTURE." << "\n";
	if (!this->ellieLegsTexture.loadFromFile("Textures/legb.png"))
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
	this->ellieBody.setPosition(this->widthCenter + 46.f, this->heightCenter + 80.f);
	this->ellieLeft.setPosition(this->widthCenter + 40.f, this->heightCenter + 88.f);
	this->ellieRight.setPosition(this->widthCenter + 85.f, this->heightCenter + 88.f);
	this->ellieLegs.setPosition(this->widthCenter + 52.f, this->heightCenter + 127.f);
	this->ellieShadow.setPosition(this->widthCenter + 21.f, this->heightCenter + 143.f);
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
			this->aniTime = 0.08f;
			this->running = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
			this->running = false;
		}
		this->moving = true;
		this->turnLeft = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.08f;
			this->running = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
			this->running = false;
		}
		this->moving = true;
		this->turnLeft = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.08f;
			this->running = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
			this->running = false;
		}
		this->moving = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			this->aniTime = 0.08f;
			this->running = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			this->aniTime = 0.1f;
		}
		else {
			this->aniTime = 0.1f;
			this->running = false;
		}
		this->moving = true;
	}
	else
	{
		this->moving = false;
		this->running = false;
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
	if (this->aniLegs > 4)
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
			this->ellieLegsTexture.loadFromFile("Textures/legb.png");
			this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 91.f, 55.f));
			this->ellieLegs.setPosition(this->widthCenter + 52.f, this->heightCenter + 127.f);
			this->ellieStand++;
			this->ellieMove = 1;
			this->aniLegs = 1;
		}
		else
		{
			this->frameShipTop = 261.f;
			this->width = 52.f;
			if (this->running == false)
			{
				switch (this->aniLegs)
				{
				case 2:
					this->ellieLegsTexture.loadFromFile("Textures/legbwalk.png");
					this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 98.f, 57.f));
					this->ellieLegs.setPosition(this->widthCenter + 49.f, this->heightCenter + 127.f);
					break;
				case 4:
					this->ellieLegsTexture.loadFromFile("Textures/legb01.png");
					this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 67.f, 55.f));
					this->ellieLegs.setPosition(this->widthCenter + 58.f, this->heightCenter + 127.f);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (this->aniLegs)
				{
				case 2:
					this->ellieLegsTexture.loadFromFile("Textures/legbrun.png");
					this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 115.f, 56.f));
					this->ellieLegs.setPosition(this->widthCenter + 45.f, this->heightCenter + 127.f);
					break;
				case 4:
					this->ellieLegsTexture.loadFromFile("Textures/legb01.png");
					this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 67.f, 55.f));
					this->ellieLegs.setPosition(this->widthCenter + 58.f, this->heightCenter + 127.f);
					break;
				default:
					break;
				}
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
		case 1: this->ellieHeadTexture.loadFromFile("Textures/head02b.png");
			break;
		case 3: this->ellieHeadTexture.loadFromFile("Textures/head01b.png");
			break;
		case 20: this->ellieHeadTexture.loadFromFile("Textures/head02b.png");
			break;
		case 22: this->ellieHeadTexture.loadFromFile("Textures/head01b.png");
			break;
		default:
			break;
		}
		if (this->aniHead == 1)
		{
			this->ellieHead.setPosition(this->widthCenter, this->heightCenter + 2.f);
			this->ellieBody.setPosition(this->widthCenter + 46.f, this->heightCenter + 81.f);
		}
		else
		{
			this->ellieHead.setPosition(this->widthCenter, this->heightCenter);
			this->ellieBody.setPosition(this->widthCenter + 46.f, this->heightCenter + 80.f);
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