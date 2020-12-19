#include "GameState.h"

void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void GameState::initFont()
{
	if (!this->font.loadFromFile("Fonts/FCSaveSpace.ttf")) {
		throw("ERROR::GAMESTATE::COULD NOT LOAD FONT");
	}
	this->timeText.setFont(this->font);
	this->timeText.setCharacterSize(40.f);
	this->timeText.setPosition(10.f, 10.f);
	this->timeText.setFillColor(Color::White);

	this->ammoText.setFont(this->font);
	this->ammoText.setCharacterSize(100.f);
	this->ammoText.setPosition(1800.f, 900.f);
	this->ammoText.setFillColor(Color::White);
}

// Initializer
void GameState::initPlayer()
{
	
}

void GameState::initPausedButtons()
{
	this->pausedButtons["RESUME"] = new Button(
		860.f, 480.f, 200.f, 60.f,
		&this->font, "Resume", 72,
		sf::Color(250, 250, 250, 250), sf::Color(250, 250, 250, 100), sf::Color(70, 70, 70, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->pausedButtons["BACK_TO_MENU"] = new Button(
		860.f, 550.f, 200.f, 60.f,
		&this->font, "Back To Menu", 72,
		sf::Color(250, 250, 250, 250), sf::Color(250, 250, 250, 100), sf::Color(70, 70, 70, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);
}

void GameState::initPausedMenu()
{
	this->pausedPlane.setFillColor(sf::Color(70, 70, 70, 150));
	this->pausedPlane.setPosition(0.f, 0.f);
	this->pausedPlane.setSize(sf::Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));
}

void GameState::initEndButtons()
{
	this->endButtons["BACK_TO_MENU"] = new Button(
		this->window->getSize().x / 2, 570.f, 240.f, 70.f,
		&this->font, "Back To Menu", 72,
		sf::Color(250, 250, 250, 250), sf::Color(250, 250, 250, 100), sf::Color(70, 70, 70, 200),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->endButtons["BACK_TO_MENU"]->setButtonPosition(this->window->getSize().x / 2 - this->endButtons["BACK_TO_MENU"]->getTextGlobalBounds().width / 2, 570.f);    void setButtonPosition();
	this->endButtons["BACK_TO_MENU"]->setShapePosition(this->window->getSize().x / 2 - this->endButtons["BACK_TO_MENU"]->getTextGlobalBounds().width / 2, 570.f);    void setButtonPosition();
}

void GameState::initEndMenu()
{
	this->endPlane.setFillColor(sf::Color(70, 70, 70, 150));
	this->endPlane.setPosition(0.f, 0.f);
	this->endPlane.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));

	this->endText.setString("Game Over");
	this->endText.setFont(this->font);
	this->endText.setCharacterSize(72);
	this->endText.setFillColor(sf::Color::White);
	this->endText.setPosition(this->window->getSize().x / 2 - this->endText.getGlobalBounds().width / 2, 350.f);
	//this->endText.setOutlineColor(sf::Color::Black);
	//this->endText.setOutlineThickness(1.f);

	this->scoreEndText.setFont(this->font);
	this->scoreEndText.setCharacterSize(72);
	this->scoreEndText.setFillColor(sf::Color::White);
	this->scoreEndText.setPosition(this->window->getSize().x / 2 - this->scoreEndText.getGlobalBounds().width / 2, 450.f);
	//this->scoreEndText.setOutlineColor(sf::Color::Black);
	//this->scoreEndText.setOutlineThickness(1.f);
}

void GameState::initSounds()
{
	if (!this->clickBuffer.loadFromFile("Sounds/Click.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->click.setBuffer(this->clickBuffer);
	this->click.setVolume(50.f);

	if (!this->bgMapSoundBuff.loadFromFile("Sounds/bgMapSound.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->bgMapSound.setBuffer(this->bgMapSoundBuff);
	this->bgMapSound.setVolume(70.f);
	this->bgMapSound.setLoop(true);

	if (!this->deathScenceBuff.loadFromFile("Sounds/deathScence.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->deathScence.setBuffer(this->deathScenceBuff);
	this->deathScence.setVolume(50.f);

	if (!this->akBuff.loadFromFile("Sounds/ak.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->ak.setBuffer(this->akBuff);
	this->ak.setVolume(50.f);

	if (!this->shotgunBuff.loadFromFile("Sounds/shotgun.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->shotgun.setBuffer(this->shotgunBuff);
	this->shotgun.setVolume(50.f);

	if (!this->minigunBuff.loadFromFile("Sounds/minigun.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->minigun.setBuffer(this->minigunBuff);
	this->minigun.setVolume(50.f);

	if (!this->bowBuff.loadFromFile("Sounds/bow.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->bow.setBuffer(this->bowBuff);
	this->bow.setVolume(50.f);

	if (!this->killedBuff.loadFromFile("Sounds/enemyDeath.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->kill.setBuffer(this->killedBuff);
	this->kill.setVolume(50.f);

	if (!this->walkBuff.loadFromFile("Sounds/playerWalk.wav"))
		throw("ERROR::GAMESTATE::COULD_NOT_LOAD_SOUND");
	this->walk.setBuffer(this->walkBuff);
	this->walk.setVolume(70.f);
	this->walk.setLoop(true);
}

void GameState::spawnEnemies()
{
	if (this->firstSpawn)
	{
		for (int i = 0; i < 10; i++)
		{
			this->enemies.push_back(new Enemy(this->map.map.getPosition().x, this->map.map.getPosition().y));
		}
		this->firstSpawn = false;
		this->Time.restart();
	}
	else
	{
		if (this->spawnCooldown.getElapsedTime().asSeconds() >= 30.f)
		{
			this->spawnCooldown.restart();
			this->enemies.push_back(new Enemy(this->map.map.getPosition().x, this->map.map.getPosition().y));
		}
	}
}

void GameState::updateEnemiesKilled()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		if (this->enemies[i]->isDelete == true) {
			this->lastx = this->enemies[i]->sprite.getPosition().x;
			this->lasty = this->enemies[i]->sprite.getPosition().y;
			this->enemies.erase(this->enemies.begin() + i);
			int type = rand() % 3;
			if (type != 2)
				this->ammoBoxs.push_back(new AmmoBox(this->lastx, this->lasty, this->map.map.getPosition().x, this->map.map.getPosition().y));
		}
	}
}

void GameState::updateAmmoBoxs()
{
	//cout << this->ammoBoxs.size() << endl;
	for (int i = 0; i < this->ammoBoxs.size(); i++)
	{
		this->ammoBoxs[i]->update(this->window, this->map.map.getPosition().x, this->map.map.getPosition().y);
		
		if (Collision::PixelPerfectTest(this->ammoBoxs[i]->sprite, this->player.ellieShadow))
			this->ammoBoxs[i]->isDelete = true;

		if (this->ammoBoxs[i]->isDelete == true) {
			if (this->ammoBoxs[i]->isTake == false) {
				switch (this->ammoBoxs[i]->typeOfAmmoBox)
				{
				case 1: this->player.ammo.minigun += 3;
					break;
				case 2: this->player.ammo.bow += 3;
					break;
				case 3: this->player.ammo.shotgun += 3;
					break;
				case 4: this->player.ammo.ak += 10;
					break;
				default:
					break;
				}
			}
			this->ammoBoxs.erase(this->ammoBoxs.begin() + i);
		}
	}
}

// Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, std::string player_name, sf::Sound* bgsound)
	: State(window, supportedKeys, states)
{

	std::srand((unsigned)std::time(NULL));

	this->playerName = player_name;
	this->backgroundSound = bgsound;
	this->initKeybinds();
	this->initFont();
	this->initPlayer();
	this->initPausedButtons();
	this->initPausedMenu();
	this->initEndButtons();
	this->initEndMenu();
	this->initSounds();

	this->isGamePause = false;
	this->status = GameState::Status::PLAY;
	this->sec = 0; this->min = 0; this->hour = 0; this->allTime = 0;
	this->Time.restart();
	this->firstSpawn = true;
	this->firstbgsound = false;
	this->spawnCooldown.restart();
	this->bulletClock.restart();
	this->showEnemy = false;
	this->resetDeathClock = false;
	this->playerNum = 0;

	if (!this->shaderTexture.loadFromFile("Textures/shader.png"))
		std::cout << "ERROR::COULD NOT LOAD TEXTURE." << "\n";
	this->shader.setTexture(this->shaderTexture);
	this->shader.setPosition(0.f, 0.f);

	if (!this->deathTexture.loadFromFile("Textures/deathScene.png"))
		std::cout << "ERROR::COULD NOT LOAD TEXTURE." << "\n";
	this->death.setTexture(this->deathTexture);
	this->death.setPosition(0.f, 0.f);
}

GameState::~GameState()
{

}

void GameState::checkEndGame()
{
	if (this->player.playerHealth <= 0) {
		this->resetDeathClock = true;
		this->deathClock.restart();
		this->deathScence.play();
	}
}

void GameState::waitForEnd()
{
	if (this->deathClock.getElapsedTime().asSeconds() >= 2.f)
	{
		this->endGame();
	}
}

void GameState::endGame()
{
	this->isGamePause = true;
	this->status = GameState::Status::END;
	this->toggleStatePaused();
	//this->updateAndSaveScore();
}

void GameState::toggleStatePaused()
{
	if (this->pauseDebounce.getElapsedTime() > sf::seconds(0.2f)) {
		this->pauseDebounce.restart();

		this->isGamePause = !this->isGamePause;

		if (this->isGamePause) {
			if (this->player.playerHealth > 0) {
				this->status = GameState::Status::PAUSE;
			}
			else {
				this->status = GameState::Status::END;
			}
		}
		else if (!this->isGamePause) {
			this->status = GameState::Status::PLAY;
		}
	}
}

void GameState::updateTime()
{
	if (this->Time.getElapsedTime().asSeconds() >= 1.f)
	{
		this->Time.restart();
		this->sec++;
		this->allTime++;
		if (this->sec == 60)
		{
			this->min++;
			this->sec = 0;
		}
		if (this->min == 60)
		{
			this->hour++;
			this->min = 0;
		}
	}
	String H, M, S;
	if (this->hour < 10)
		H = "0" + to_string(this->hour);
	else
		H = to_string(this->hour);
	if (this->min < 10)
		M = "0" + to_string(this->min);
	else
		M = to_string(this->min);
	if (this->sec < 10)
		S = "0" + to_string(this->sec);
	else
		S = to_string(this->sec);
	this->TimeString = H + "." + M + "." + S;
	this->timeText.setString(this->TimeString);
}

void GameState::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::LControl))
		this->showEnemy = true;
	else
		this->showEnemy = false;
}

void GameState::updateEnemiesCollide()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		if (Collision::PixelPerfectTest(this->enemies[i]->shadowSprite, this->map.map))
			this->enemies[i]->isCollide = true;
		else
			this->enemies[i]->isCollide = false;
		if (Collision::PixelPerfectTest(this->enemies[i]->shadowSprite, this->player.ellieShadow) && !this->enemies[i]->isDead) {
			this->player.playerHealth -= 100;
			this->lastEnemy = &enemies[i]->sprite;
		}
		if (Collision::Intersects(this->player.circle, this->enemies[i]->signSprite) &&
			this->enemies[i]->typeofenemy != 3 &&
			this->enemies[i]->typeofenemy != 4) {
			this->enemies[i]->targetLock = true;
			this->enemies[i]->targetPo.x = this->player.ellieShadow.getPosition().x - this->enemies[i]->shadowSprite.getPosition().x;
			this->enemies[i]->targetPo.y = this->player.ellieShadow.getPosition().y - this->enemies[i]->shadowSprite.getPosition().y;
		}
		else if (Collision::IntersectsCircle(this->player.circle, this->enemies[i]->hearCircle) && this->player.makeNoise) {
			this->enemies[i]->targetLock = true;
			this->enemies[i]->targetPo.x = this->player.ellieShadow.getPosition().x - this->enemies[i]->shadowSprite.getPosition().x;
			this->enemies[i]->targetPo.y = this->player.ellieShadow.getPosition().y - this->enemies[i]->shadowSprite.getPosition().y;
		}
		else
			this->enemies[i]->targetLock = false;
	}
}

void GameState::updateEnemies()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i]->update(this->window, this->map.map.getPosition().x, this->map.map.getPosition().y);
	}
}

void GameState::updateBullets()
{
	switch (this->player.slot)
	{
	case 0: this->ammoText.setString("");
		break;
	case 1: this->bulletTime = 2.f; this->ammoText.setString(to_string(this->player.ammo.bow));
		break;
	case 2: this->bulletTime = 1.f; this->ammoText.setString(to_string(this->player.ammo.shotgun));
		break;
	case 3: this->bulletTime = 0.1f; this->ammoText.setString(to_string(this->player.ammo.ak));
		break;
	case 4: this->bulletTime = 1.f; this->ammoText.setString(to_string(this->player.ammo.minigun));
		break;
	default: 
		break;
	}
	if (this->player.slot != 0 && this->bulletClock.getElapsedTime().asSeconds() >= this->bulletTime)
	{
		if (Mouse::isButtonPressed(Mouse::Left)) {
			bool shoot = false;
			this->bulletClock.restart();
			if (this->player.slot != 1)
				this->player.makeNoise = true;
			switch (this->player.slot)
			{
			case 1:
				if (this->player.ammo.bow > 0) {
					shoot = true; this->player.ammo.bow--; this->bow.play();
				}
				break;
			case 2:
				if (this->player.ammo.shotgun > 0) {
					shoot = true; this->player.ammo.shotgun--; this->shotgun.play();
				}
				break;
			case 3:
				if (this->player.ammo.ak > 0) {
					shoot = true; this->player.ammo.ak--; this->ak.play();
				}
				break;
			case 4:
				if (this->player.ammo.minigun > 0) {
					shoot = true; this->player.ammo.minigun--; this->minigun.play();
				}
				break;
			default:
				break;
			}
			//cout << "OK" << endl;
			if (this->player.slot != 2 && shoot) {
				this->bullets.push_back(new Bullet((this->player.circle.getPosition().x + this->player.circle.getRadius()),
					(this->player.circle.getPosition().y + this->player.circle.getRadius()),
					this->player.mousePosView.x,
					this->player.mousePosView.y,
					&this->player.slot,
					this->map.map.getPosition().x,
					this->map.map.getPosition().y));
			}
			else if (this->player.slot == 2 && shoot)
			{
				for (int i = 0; i < 5; i++)
				{
					float y = static_cast<float>(rand() % 100) - 50.f;
					this->bullets.push_back(new Bullet((this->player.circle.getPosition().x + this->player.circle.getRadius()),
						(this->player.circle.getPosition().y + this->player.circle.getRadius()),
						this->player.mousePosView.x,
						this->player.mousePosView.y + y,
						&this->player.slot,
						this->map.map.getPosition().x,
						this->map.map.getPosition().y));
				}
			}
		}
	}
	for (int i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i]->update(this->window, this->map.map.getPosition().x, this->map.map.getPosition().y);
	}
}

void GameState::updateBulletsCollide()
{
	for (int i = 0; i < this->bullets.size(); i++)
	{
		if (Collision::PixelPerfectTest(this->bullets[i]->sprite, this->map.map))
			this->bullets[i]->isDelete = true;
		else
			this->bullets[i]->isDelete = false;
		for (int j = 0; j < enemies.size(); j++)
		{
			if (Collision::PixelPerfectTest(this->bullets[i]->sprite, this->enemies[j]->body) && !this->enemies[j]->isDead) {
				this->bullets[i]->isDelete = true;
				this->enemies[j]->enemyHealth -= 70.f;
			}
		}
	}
}

void GameState::updateDeleteBullet()
{
	for (int i = 0; i < this->bullets.size(); i++)
	{
		if (this->bullets[i]->isDelete == true) {
			this->bullets.erase(this->bullets.begin() + i);
		}
	}
}

void GameState::updateSound()
{
	
}

void GameState::updatePausedMenu()
{
	for (auto button : this->pausedButtons) {
		button.second->update(this->mousePosView);
	}

	// if pressed
	if (this->pausedButtons["RESUME"]->isPressed()) {
		this->click.play();
		this->toggleStatePaused();
	}

	if (this->pausedButtons["BACK_TO_MENU"]->isPressed()) {
		this->click.play();
		this->backgroundSound->play();
		this->bgMapSound.stop();
		for (int i = 0; i < enemies.size(); i++)
		{
			this->enemies[i]->walk.stop();
		}
		this->endState();
	}
}

void GameState::updateEndMenu()
{
	for (auto button : this->endButtons) {
		button.second->update(this->mousePosView);
	}

	this->scoreEndText.setString(this->TimeString);
	this->scoreEndText.setPosition(this->window->getSize().x / 2 - this->scoreEndText.getGlobalBounds().width / 2, 450.f);

	if (this->endButtons["BACK_TO_MENU"]->isPressed()) {
		this->click.play();
		this->backgroundSound->play();
		this->bgMapSound.stop();
		for (int i = 0; i < enemies.size(); i++)
		{
			this->enemies[i]->walk.stop();
		}
		this->endState();
		this->updateAndSaveScore();
	}
}

void GameState::updateAndSaveScore()
{
	typedef struct NameWithScore {
		std::string name;
		std::string time;
		unsigned long score;
	} NameWithScore;

	auto compareScores = [](NameWithScore p_1, NameWithScore p_2) {
		return p_1.score < p_2.score;
	};

	std::vector<NameWithScore> namesWithScore;

	NameWithScore currentPlayer;
	currentPlayer.name = this->playerName;
	currentPlayer.time = this->TimeString;
	currentPlayer.score = this->allTime;

	namesWithScore.push_back(currentPlayer);

	std::ifstream ifs("Scores/scores.txt");

	if (ifs.is_open())
	{
		std::string playerName = "";
		std::string playerTime = "";
		std::string playerScore = "";

		while (ifs >> playerName >> playerTime >> playerScore)
		{
			NameWithScore temp;
			temp.name = playerName;
			temp.time = playerTime;
			temp.score = std::stoi(playerScore);
			namesWithScore.push_back(temp);
		}
	}

	ifs.close();

	std::sort(namesWithScore.begin(), namesWithScore.end(), compareScores);

	while (namesWithScore.size() > 5) {
		namesWithScore.pop_back();
	}

	std::fstream ofs;

	ofs.open("Scores/scores.txt", std::ios::out | std::ios::trunc);

	for (auto nameWithScore : namesWithScore) {
		ofs << nameWithScore.name + "\t"+ nameWithScore.time +"\t" + std::to_string(nameWithScore.score) + "\n";
	}

	ofs.close();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();

	if (!this->isGamePause && this->status == GameState::Status::PLAY) {
		this->spawnEnemies();
		this->updateTime();
		this->updateInput();
		if (!this->resetDeathClock)
			this->updateEnemies();
		this->updateBullets();
		this->updateEnemiesCollide();
		this->updateBulletsCollide();
		this->updateDeleteBullet();
		this->updateEnemiesKilled();
		this->updateAmmoBoxs();
		if (!this->resetDeathClock)
			this->player.update(this->window, this->window);
		this->map.update(this->window, this->window, this->player.stamina);
		if (Collision::PixelPerfectTest(this->player.ellieShadow, this->map.mapCheck))
			this->map.renderFrontON = true;
		else
			this->map.renderFrontON = false;

		if (this->resetDeathClock == false)
			this->checkEndGame();
		else
			this->waitForEnd();
	}

	else if (this->isGamePause && this->status == GameState::Status::PAUSE) {
		this->updatePausedMenu();
	}

	else if (this->isGamePause && this->status == GameState::Status::END &&
		this->status != GameState::Status::PAUSE) {
		this->updateEndMenu();
	}
}

void GameState::renderTime(sf::RenderTarget* target)
{
	target->draw(this->timeText);
	target->draw(this->ammoText);
}

void GameState::renderEnemies(sf::RenderTarget* target)
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i]->render(this->window);
	}
}

void GameState::renderAmmoBoxs(sf::RenderTarget* target)
{
	for (int i = 0; i < this->ammoBoxs.size(); i++)
	{
		this->ammoBoxs[i]->render(this->window);
	}
}

void GameState::renderBullets(sf::RenderTarget* target)
{
	for (int i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i]->render(this->window);
	}
}

void GameState::renderPausedMenu(sf::RenderTarget* target)
{
	target->draw(this->pausedPlane);

	for (auto button : this->pausedButtons) {
		button.second->render(target);
	}
}

void GameState::renderEndMenu(sf::RenderTarget* target)
{
	target->draw(this->endPlane);

	target->draw(this->endText);
	target->draw(this->scoreEndText);

	for (auto button : this->endButtons) {
		button.second->render(target);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	//draw
	this->map.render(this->window);
	if (!this->resetDeathClock) {
		this->renderEnemies(target);
		this->renderAmmoBoxs(target);
		this->player.render(this->window);
	}
	this->renderBullets(target);
	this->map.renderFront(this->window);

	target->draw(this->shader);
	if (this->resetDeathClock) {
		target->draw(this->death);
		this->player.render(this->window);
		target->draw(*this->lastEnemy);
	}
	this->renderTime(target);
	for (int i = 0; i < enemies.size() && this->showEnemy; i++)
	{
		target->draw(this->enemies[i]->body);
	}

	if (this->firstSpawn) {
		this->player.renderLoading(target);
		this->firstbgsound = true;
	}
	else if (this->firstbgsound && !this->firstSpawn) {
		this->backgroundSound->stop();
		this->bgMapSound.play();
		this->firstbgsound = false;
	}
	if (this->status == GameState::Status::PAUSE) {
		this->renderPausedMenu(target);
	}
	else if (this->status == GameState::Status::END &&
		this->status != GameState::Status::PAUSE) {
		this->renderEndMenu(target);
	}

}
