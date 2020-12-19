#include "Enemy.h"

void Enemy::initVariables()
{
	this->movementSpeed = 5.f;
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
	this->isDelete = false;
	this->killed = false;
	this->targetLock = false;
	this->isCollide = false;
	this->targetPo.x = 0.f;
	this->targetPo.y = 0.f;
	this->hearRange = 200.f;
	this->a = 0;
	this->b = 0;
	this->c = 0;
}

void Enemy::initColor()
{
	int type = rand() % 100;
	if (type >= 0 && type < 40) {
		if (!this->texture.loadFromFile("Textures/red.png"))
			cout << "ERROR" << "\n";
		this->enemyType = TYPE::RED; this->enemyHealth = 50; this->hearRange = 200.f; this->typeofenemy = 1;
	}
	else if (type >= 40 && type < 65)
	{
		if (!this->texture.loadFromFile("Textures/green.png"))
			cout << "ERROR" << "\n";
		this->enemyType = TYPE::GREEN; this->enemyHealth = 100; this->hearRange = 300.f; this->typeofenemy = 2;
	}
	else if (type >= 65 && type < 78)
	{
		if (!this->texture.loadFromFile("Textures/yellow.png"))
			cout << "ERROR" << "\n";
		this->enemyType = TYPE::YELLOW; this->enemyHealth = 150; this->hearRange = 300.f; this->typeofenemy = 3;
	}
	else if (type >= 78 && type < 90)
	{
		if (!this->texture.loadFromFile("Textures/blue.png"))
			cout << "ERROR" << "\n";
		this->enemyType = TYPE::BLUE; this->enemyHealth = 150; this->hearRange = 500.f; this->typeofenemy = 4;
	}
	else
	{
		if (!this->texture.loadFromFile("Textures/Spritesheet.png"))
			cout << "ERROR" << "\n";
		this->enemyType = TYPE::RIANBOW; this->enemyHealth = 200; this->hearRange = 500.f; this->typeofenemy = 5;
	}
}

void Enemy::initSprite(float x, float y)
{
	int type = rand() % 14;
	switch (type)
	{
	case 0: this->enemyposition.x = 3020.f; this->enemyposition.y = 2022.f;//med
		break;
	case 1: this->enemyposition.x = 5696.f; this->enemyposition.y = 1321.f;//cafe
		break;
	case 2: this->enemyposition.x = 6517.f; this->enemyposition.y = 673.f;//weapon
		break;
	case 3: this->enemyposition.x = 7814.f; this->enemyposition.y = 1844.f;//navitop
		break;
	case 4: this->enemyposition.x = 7814.f; this->enemyposition.y = 2422.f;//navibottom
		break;
	case 5: this->enemyposition.x = 6620.f; this->enemyposition.y = 2428.f;//frontnavi
		break;
	case 6: this->enemyposition.x = 5390.f; this->enemyposition.y = 3060.f;//admin
		break;
	case 7: this->enemyposition.x = 6646.f; this->enemyposition.y = 3852.f;//rightbottom
		break;
	case 8: this->enemyposition.x = 3172.f; this->enemyposition.y = 2713.f;//
		break;
	case 9: this->enemyposition.x = 2187.f; this->enemyposition.y = 3735.f;//
		break;
	case 10: this->enemyposition.x = 2675.f; this->enemyposition.y = 2520.f;//
		break;
	case 11: this->enemyposition.x = 1190.f; this->enemyposition.y = 2520.f;//
		break;
	case 12: this->enemyposition.x = 998.f; this->enemyposition.y = 1819.f;//
		break;
	case 13: this->enemyposition.x = 2180.f; this->enemyposition.y = 820.f;//
		break;
	default:
		break;
	}
	x = x + this->enemyposition.x; y = y + this->enemyposition.y;
	this->currentFrame = IntRect(this->preWidth, this->preHeight + this->height, this->width, -this->height);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.scale(1.25f, -1.25f);
	this->sprite.setPosition(x, y);

	if (!this->ventTexture.loadFromFile("Textures/PC Computer - Among Us - Electrical Skeld.png"))
		cout << "ERROR" << "\n";
	this->ventSprite.setTexture(this->ventTexture);
	this->ventSprite.setTextureRect(IntRect(83.f, 617.f, 53.f, 45.f));
	this->ventSprite.scale(2.2f, 2.2f);
	this->ventSprite.setPosition(x , y - 70.f);

	if (!this->shadowTexture.loadFromFile("Textures/shadow.png"))
		cout << "ERROR::COULD NOT LOAD ENEMY SHADOW TEXTURE." << "\n";
	this->shadowSprite.setTexture(this->shadowTexture);
	this->shadowSprite.scale(0.4f, 0.4f);
	this->shadowSprite.setPosition(x + 9.f, y - 18.f);
	this->shadowSprite.setColor(Color::Transparent);

	if (!this->bodyTexture.loadFromFile("Textures/enemyBody.png"))
		cout << "ERROR::COULD NOT LOAD ENEMY SHADOW TEXTURE." << "\n";
	this->body.setTexture(this->bodyTexture);
	this->body.scale(0.8f, 0.6f);
	this->body.setPosition(x + 10.f, y - 140.f);

	this->signSprite.setSize(Vector2f(380.f, 150.f));
	this->signSprite.setFillColor(Color::Transparent);
	this->signSprite.setOutlineColor(Color::Red);
	this->signSprite.setOutlineThickness(1.f);
	this->signSprite.setPosition(x + 89.f, y - 93.f);

	this->hearCircle.setFillColor(Color::Transparent);
	this->hearCircle.setRadius(this->hearRange);
	this->hearCircle.setOutlineColor(Color::Green);
	this->hearCircle.setOutlineThickness(1.f);
	this->hearCircle.setPosition(x - 20.f, y - 18.f);
}

void Enemy::initAnimetion()
{
	this->aniTime.restart();
	this->walkTime.restart();
	this->wallTime.restart();
}

void Enemy::initSounds()
{
	if (!this->killedBuff.loadFromFile("Sounds/enemyDeath.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->kill.setBuffer(this->killedBuff);
	this->kill.setVolume(50.f);

	if (!this->ventBuff.loadFromFile("Sounds/vent.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->vent.setBuffer(this->ventBuff);
	this->vent.setVolume(0.f);

	if (!this->walkBuff.loadFromFile("Sounds/enemyWalk.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->walk.setBuffer(this->walkBuff);
	this->walk.setVolume(70.f);
	this->walk.setLoop(true);
}

Enemy::Enemy(float x, float y)
{
	this->initVariables();
	this->initColor();
	this->initSprite(x, y);
	this->initAnimetion();
	this->initSounds();
}

Enemy::~Enemy()
{
}

void Enemy::walking(float* x, float* y)
{
	if ((*x != 0.f || *y != 0.f) && (!this->isCollide))
	{
		if (*x < 0.f)
		{
			this->turnLeft = true;
			this->enemyposition.x -= this->movementSpeed;
			*x += this->movementSpeed;
			if (*x > 0.f)
				*x = 0;
		}
		else if (*x > 0.f)
		{
			this->turnLeft = false;
			this->enemyposition.x += this->movementSpeed;
			*x -= this->movementSpeed;
			if (*x < 0.f)
				*x = 0;
		}
		if (*y < 0.f)
		{
			this->enemyposition.y -= this->movementSpeed;
			*y += this->movementSpeed;
			if (*y > 0.f)
				*y = 0;
		}
		else if (*y > 0.f)
		{
			this->enemyposition.y += this->movementSpeed;
			*y -= this->movementSpeed;
			if (*y < 0.f)
				*y = 0;
		}
		this->moving = true;
	}
	else
	{
		if (this->isCollide)
		{
			if (*x < 0.f)
				this->enemyposition.x += 2 * this->movementSpeed;
			else if (*x > 0.f)
				this->enemyposition.x -= 2 * this->movementSpeed;
			if (*y < 0.f)
				this->enemyposition.y += 2 * this->movementSpeed;
			else
				this->enemyposition.y -= 2 * this->movementSpeed;
		}
		this->moving = false;
		*x = 0.f;
		*y = 0.f;
		this->wallTime.restart();
	}
}

void Enemy::updateHealth()
{
	if (this->enemyHealth <= 0)
	{
		this->isDead = true;
		this->moving = false;
	}
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
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->enemyHealth -= 50;
	}
	else
	{
		//this->moving = false;
	}
}

void Enemy::updateWalk()
{
	if (this->walkTime.getElapsedTime().asSeconds() >= 0.08f && this->wallTime.getElapsedTime().asSeconds() >= 1.f)
	{
		this->walkTime.restart();
		if (!this->moving && !this->targetLock)
		{
			this->randposi.x = static_cast<float>(rand() % 300) - 150.f;
			this->randposi.y = static_cast<float>(rand() % 300) - 150.f;
			this->movementSpeed = 6.f;
		}
		else if (this->targetLock)
		{
			this->randposi.x = this->targetPo.x;
			this->randposi.y = this->targetPo.y;
			this->movementSpeed = 12.f;
		}
		walking(&randposi.x, &randposi.y);
	}
}

void Enemy::updateSound()
{
	if (this->moving)
		this->a++;
	else if (!this->moving && this->a > 0) {
		this->a = 0;
		this->walk.stop();
	}
	if (this->isDead)
		this->b++;
	else if (!this->isDead && this->b > 0)
		this->b = 0;
	if (this->spawning)
		this->c++;
	else if (!this->spawning && this->c > 0)
		this->c = 0;

	if (this->a == 1)
		this->walk.play();
	if (this->b == 1)
		this->kill.play();
	if (this->c == 1)
		this->vent.play();

	if (this->shadowSprite.getPosition().x > 0.f &&
		this->shadowSprite.getPosition().x < 1920.f &&
		this->shadowSprite.getPosition().y > 0.f &&
		this->shadowSprite.getPosition().y < 1080.f) {
		this->walk.setVolume(50.f);
		this->vent.setVolume(50.f);
	}
	else {
		this->walk.setVolume(0.f);
		this->vent.setVolume(0.f);
	}
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
		this->killed = true;
		this->killedTime.restart();
	}
	if (this->aniTime.getElapsedTime().asSeconds() >= 0.04f && !this->killed)
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
			this->signSprite.setTextureRect(IntRect(0.f, 0.f, 450.f, 150.f));
		}
		else if (this->turnLeft == true)
		{
			if (this->isDead == false)
				this->currentFrame = IntRect(this->preWidth + this->width, this->preHeight + this->height, -this->width, -this->height);
			else
				this->currentFrame = IntRect(this->preWidth, this->preHeight + this->height, this->width, -this->height);
			this->signSprite.setTextureRect(IntRect(450.f, 0.f, -450.f, 150.f));
		}
		this->sprite.setTextureRect(this->currentFrame);
		this->aniTime.restart();
	}
	else if (this->killed && this->killedTime.getElapsedTime().asSeconds() >= 10.f)
	{
		this->isDelete = true;
	}
}

void Enemy::updatePosition(float x, float y)
{
	this->sprite.setPosition(x + this->enemyposition.x, y + this->enemyposition.y);
	this->body.setPosition(x + this->enemyposition.x + 10.f, y + this->enemyposition.y - 130.f);
	this->ventSprite.setPosition(x + this->enemyposition.x, y + this->enemyposition.y - 70.f);
	this->shadowSprite.setPosition(x + this->enemyposition.x + 9.f, y + this->enemyposition.y - 18.f);
	this->hearCircle.setPosition(x + this->enemyposition.x + 48.f - this->hearRange, y + this->enemyposition.y - 15.f - this->hearRange);
	if (!this->turnLeft)
		this->signSprite.setPosition(x + this->enemyposition.x + 89.f, y + this->enemyposition.y - 93.f);
	else
		this->signSprite.setPosition(x + this->enemyposition.x + 9.f - 380.f, y + this->enemyposition.y - 93.f);
}

void Enemy::update(RenderTarget* target, float x, float y)
{
	this->updateHealth();
	this->updateInput();
	if (!this->isDead)
		this->updateWalk();
	this->updateSound();
	this->updatePosition(x, y);
	this->updateAnimation();
}

void Enemy::render(RenderTarget* target)
{
	if (this->spawning)
		target->draw(this->ventSprite);
	target->draw(this->sprite);
	//target->draw(this->signSprite);
	//target->draw(this->hearCircle);
	//target->draw(this->body);
	//target->draw(this->shadowSprite);
}