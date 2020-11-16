#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
	this->running = false;
	this->lying = false;
	this->fstLie = false;
	this->ellieStand = 1;
	this->ellieMove = 1;
	this->turnLeft = false;
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
	this->ellieBody.setPosition(this->widthCenter + 42.f, this->heightCenter + 80.f);
	this->ellieLeft.setPosition(this->widthCenter + 37.f, this->heightCenter + 88.f);
	this->ellieRight.setPosition(this->widthCenter + 84.f, this->heightCenter + 88.f);
	this->ellieLegs.setPosition(this->widthCenter + 52.f, this->heightCenter + 127.f);
	this->ellieShadow.setPosition(this->widthCenter + 15.f, this->heightCenter + 143.f);
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

void Player::updateMousePosition(RenderWindow* window)
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

void Player::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == true) {
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
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Keyboard::isKeyPressed(Keyboard::LShift) && this->turnLeft == false) {
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
	else if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		this->jumping = true;
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
		if (this->lying == false)
		{
			if (this->fstLie == false)
			{
				this->ellieLeftTexture.loadFromFile("Textures/handb.png");
				this->ellieRightTexture.loadFromFile("Textures/handb.png");
				this->ellieLeft.setTexture(this->ellieLeftTexture);
				this->ellieRight.setTexture(this->ellieRightTexture);
				this->ellieLeft.setTextureRect(IntRect(0.f, 0.f, 84.f, 87.f));
				this->ellieRight.setTextureRect(IntRect(0.f, 0.f, 84.f, 87.f));
				this->ellieLeft.setPosition(this->widthCenter + 37.f, this->heightCenter + 88.f);
				this->ellieRight.setPosition(this->widthCenter + 84.f, this->heightCenter + 88.f);
				this->ellieHead.setRotation(0.f);
				this->ellieBody.setRotation(0.f);
				this->ellieLegs.setRotation(0.f);
				this->fstLie = true;
			}
			if (this->moving == false)
			{
				this->ellieLegsTexture.loadFromFile("Textures/legb.png");
				if (this->turnLeft == false) {
					this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 91.f, 55.f));
				}
				else if (this->turnLeft == true) {
					this->ellieLegs.setTextureRect(IntRect(91.f, 0.f, -91.f, 55.f));
				}
				this->ellieLegs.setPosition(this->widthCenter + 46.f, this->heightCenter + 127.f);
				this->ellieStand++;
				this->ellieMove = 1;
				this->aniLegs = 1;
			}
			else
			{
				if (this->running == false)
				{
					switch (this->aniLegs)
					{
					case 2:
						this->ellieLegsTexture.loadFromFile("Textures/legbwalk.png");
						if (this->turnLeft == false) {
							this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 98.f, 57.f));
						}
						else if (this->turnLeft == true) {
							this->ellieLegs.setTextureRect(IntRect(98.f, 0.f, -98.f, 57.f));
						}
						this->ellieLegs.setPosition(this->widthCenter + 45.f, this->heightCenter + 127.f);
						break;
					case 4:
						this->ellieLegsTexture.loadFromFile("Textures/legb01.png");
						if (this->turnLeft == false) {
							this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 67.f, 55.f));
						}
						else if (this->turnLeft == true) {
							this->ellieLegs.setTextureRect(IntRect(67.f, 0.f, -67.f, 55.f));
						}
						this->ellieLegs.setPosition(this->widthCenter + 54.f, this->heightCenter + 127.f);
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
						if (this->turnLeft == false) {
							this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 115.f, 56.f));
						}
						else if (this->turnLeft == true) {
							this->ellieLegs.setTextureRect(IntRect(115.f, 0.f, -115.f, 56.f));
						}
						this->ellieLegs.setPosition(this->widthCenter + 41.f, this->heightCenter + 127.f);
						break;
					case 4:
						this->ellieLegsTexture.loadFromFile("Textures/legb01.png");
						if (this->turnLeft == false) {
							this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 67.f, 55.f));
						}
						else if (this->turnLeft == true) {
							this->ellieLegs.setTextureRect(IntRect(67.f, 0.f, -67.f, 55.f));
						}
						this->ellieLegs.setPosition(this->widthCenter + 54.f, this->heightCenter + 127.f);
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
				this->ellieHead.setTextureRect(IntRect(0.f, 0.f, 279.f, 181.f));
				this->ellieBody.setTextureRect(IntRect(0.f, 0.f, 111.f, 108.f));
				this->ellieLeft.setPosition(this->widthCenter + 37.f, this->heightCenter + 88.f);
				this->ellieRight.setPosition(this->widthCenter + 84.f, this->heightCenter + 88.f);
				this->ellieLeft.setTextureRect(IntRect(0.f, 0.f, 84.f, 87.f));
				this->ellieRight.setTextureRect(IntRect(0.f, 0.f, 84.f, 87.f));
			}
			else if (this->turnLeft == true)
			{
				this->ellieHead.setTextureRect(IntRect(279.f, 0.f, -279.f, 181.f));
				this->ellieBody.setTextureRect(IntRect(111.f, 0.f, -111.f, 108.f));
				this->ellieLeft.setPosition(this->widthCenter + 62.f, this->heightCenter + 88.f);
				this->ellieRight.setPosition(this->widthCenter + 14.f, this->heightCenter + 88.f);
				this->ellieLeft.setTextureRect(IntRect(84.f, 0.f, -84.f, 87.f));
				this->ellieRight.setTextureRect(IntRect(84.f, 0.f, -84.f, 87.f));
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
				this->ellieBody.setPosition(this->widthCenter + 42.f, this->heightCenter + 81.f);
			}
			else
			{
				this->ellieHead.setPosition(this->widthCenter, this->heightCenter);
				this->ellieBody.setPosition(this->widthCenter + 42.f, this->heightCenter + 80.f);
			}
			this->aniHeadNumEye++;
			this->aniHead++;
			this->ellieLegs.setTexture(this->ellieLegsTexture);
			this->ellieHead.setTexture(this->ellieHeadTexture);
			this->animationTimer.restart();
		}
		else if (this->lying == true)
		{
			if (this->fstLie == true) //stand to lie
			{
				this->ellieLeftTexture.loadFromFile("Textures/handc.png");
				this->ellieRightTexture.loadFromFile("Textures/handc.png");
				this->ellieLeft.setTexture(this->ellieLeftTexture);
				this->ellieRight.setTexture(this->ellieRightTexture);
				this->fstLie = false;
			}
			if (this->turnLeft == false)
			{
				this->ellieHead.setTextureRect(IntRect(0.f, 0.f, 279.f, 181.f));
				this->ellieLeft.setTextureRect(IntRect(0.f, 0.f, 95.f, 85.f));
				this->ellieRight.setTextureRect(IntRect(0.f, 0.f, 95.f, 85.f));
				this->ellieBody.setTextureRect(IntRect(0.f, 0.f, 111.f, 108.f));
				this->ellieLegs.setTextureRect(IntRect(0.f, 0.f, 91.f, 55.f));
				this->ellieLeft.setPosition(this->widthCenter + 38.f, this->heightCenter + 100.f);
				this->ellieRight.setPosition(this->widthCenter + 63.f, this->heightCenter + 105.f);
				this->ellieHead.setPosition(this->widthCenter + 10.f, this->heightCenter + 15.f);
				this->ellieBody.setPosition(this->widthCenter + 78.f, this->heightCenter + 90.f);
				this->ellieLegs.setPosition(this->widthCenter + 32.f, this->heightCenter + 103.f);
				this->ellieHead.setRotation(12.f);
				this->ellieBody.setRotation(82.f);
				this->ellieLegs.setRotation(85.f);
			}
			else if (this->turnLeft == true)
			{
				this->ellieHead.setTextureRect(IntRect(279.f, 0.f, -279.f, 181.f));
				this->ellieLeft.setTextureRect(IntRect(95.f, 0.f, -95.f, 85.f));
				this->ellieRight.setTextureRect(IntRect(95.f, 0.f, -95.f, 85.f));
				this->ellieBody.setTextureRect(IntRect(111.f, 0.f, -111.f, 108.f));
				this->ellieLegs.setTextureRect(IntRect(91.f, 0.f, -91.f, 55.f));
				this->ellieLeft.setPosition(this->widthCenter + 51.f, this->heightCenter + 100.f);
				this->ellieRight.setPosition(this->widthCenter + 25.f, this->heightCenter + 105.f);
				this->ellieHead.setPosition(this->widthCenter + -9.f, this->heightCenter + 42.f);
				this->ellieBody.setPosition(this->widthCenter + 50.f, this->heightCenter + 146.f);
				this->ellieLegs.setPosition(this->widthCenter + 100.f, this->heightCenter + 150.f);
				this->ellieHead.setRotation(-12.f);
				this->ellieBody.setRotation(-82.f);
				this->ellieLegs.setRotation(-85.f);
			}
			if (this->moving == false)
			{
				if (this->turnLeft == false)
					this->ellieLegs.setPosition(this->widthCenter + 32.f, this->heightCenter + 103.f);
				else if (this->turnLeft == true)
					this->ellieLegs.setPosition(this->widthCenter + 100.f, this->heightCenter + 150.f);
			}
			else if (this->moving == true)
			{
				switch (this->aniLegs)
				{
				case 2:
					if (this->turnLeft == false)
						this->ellieLegs.setPosition(this->widthCenter + 37.f, this->heightCenter + 103.f);
					else if (this->turnLeft == true)
						this->ellieLegs.setPosition(this->widthCenter + 95.f, this->heightCenter + 150.f);
					break;
				case 4:
					if (this->turnLeft == false)
						this->ellieLegs.setPosition(this->widthCenter + 32.f, this->heightCenter + 103.f);
					else if (this->turnLeft == true)
						this->ellieLegs.setPosition(this->widthCenter + 100.f, this->heightCenter + 150.f);
					break;
				default:
					break;
				}
				this->aniLegs++;
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
				if (this->turnLeft == false)
				{
					this->ellieHead.setPosition(this->widthCenter + 9.f, this->heightCenter + 17.f);
					this->ellieBody.setPosition(this->widthCenter + 78.f, this->heightCenter + 91.f);
				}
				else if (this->turnLeft == true)
				{
					this->ellieHead.setPosition(this->widthCenter + -8.f, this->heightCenter + 40.f);
					this->ellieBody.setPosition(this->widthCenter + 50.f, this->heightCenter + 147.f);
				}
			}
			else
			{
				if (this->turnLeft == false)
				{
					this->ellieHead.setPosition(this->widthCenter + 10.f, this->heightCenter + 15.f);
					this->ellieBody.setPosition(this->widthCenter + 78.f, this->heightCenter + 90.f);
				}
				else if (this->turnLeft == true)
				{
					this->ellieHead.setPosition(this->widthCenter + -9.f, this->heightCenter + 42.f);
					this->ellieBody.setPosition(this->widthCenter + 50.f, this->heightCenter + 146.f);
				}
			}
			this->aniHeadNumEye++;
			this->aniHead++;
			this->ellieHead.setTexture(this->ellieHeadTexture);
			this->animationTimer.restart();
		}
	}
}

void Player::update(RenderTarget* target, RenderWindow* window)
{
	this->updateMousePosition(window);
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