#include "MainMenuState.h"

// Initialzer functions
void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);
	
	int type = rand() % 6;
	switch (type)
	{
	case 0:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/01.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	case 1:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/02.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	case 2:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/03.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	case 3:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/04.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	case 4:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/05.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	case 5:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/06.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	default:
		if (!this->backgroundTexture.loadFromFile("Textures/bg/01.png"))
			throw "ERROR::MAINMENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
		break;
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/FCSaveSpace.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(
		890.f, 750.f, 140.f, 30.f,
		&this->font, "New Game", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["LEADERBOARD"] = new Button(
		890.f, 800.f, 140.f, 30.f,
		&this->font, "Leaderboard", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["HOW_TO_PLAY"] = new Button(
		890.f, 850.f, 140.f, 30.f,
		&this->font, "How to Play", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["CREDIT"] = new Button(
		890.f, 900.f, 140.f, 30.f,
		&this->font, "Credit", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);


	this->buttons["EXIT_STATE"] = new Button(
		890.f, 950.f, 140.f, 30.f,
		&this->font, "Quit", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);
}

void MainMenuState::initLeaderBoard()
{
	this->leaderBoard = new Plane(710.f, 250.f, 500.f, 450.f, &this->font, 72, 48);
}

void MainMenuState::initInputField()
{
	this->InputPlane = new InputFieldPlane(710.f, 375.f, 500.f, 300.f, &this->font, 72, 0);
	this->buttons["START_GAME"] = new Button(
		740, 600, 200, 50,
		&this->font, "Start", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["CANCEL_GAME"] = new Button(
		980, 600, 200, 50,
		&this->font, "Cancel", 50,
		sf::Color(170, 170, 170, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);


}

void MainMenuState::initSounds()
{
	if (!this->clickBuffer.loadFromFile("Sounds/Click.wav")) {
		throw("ERROR::MAINMENUSTATE::COULD_NOT_LOAD_SOUND");
	}

	this->click.setBuffer(this->clickBuffer);
	this->click.setVolume(30.f);

	if (!this->bgSoundBuffer.loadFromFile("Sounds/MainMenu.wav")) {
		throw("ERROR::MAINMENUSTATE::COULD_NOT_LOAD_SOUND");
	}

	this->bgSound.setBuffer(this->bgSoundBuffer);
	this->bgSound.setVolume(50.f);
	this->bgSound.setLoop(true);
	this->bgSound.play();
}

void MainMenuState::initCreditPlane()
{
	this->creditPlane = new CreditPlane(
		710.f, 400.f, 500.f, 250.f, &this->font, 72, 48
	);
}

void MainMenuState::initGoalsAndContralPlane()
{
	this->goalsPlane = new GoalsPlane(
		560.f, 225.f, 800.f, 200.f, &this->font, 48, 36
	);

	this->contralPlane = new ContralPlane(
		560.f, 450.f, 800.f, 250.f, &this->font, 48, 36
	);
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, bool* shouldPollEvent)
	: State(window, supportedKeys, states)
{
	this->toggleLeaderBoard = false;
	this->toggleInputField = false;
	this->toggleCreditPlane = false;
	this->toggleGoalsAndContralPlane = false;
	this->shouldPollEvent = shouldPollEvent;
	*this->shouldPollEvent = true;

	this->initVariables();
	this->initBackground();
	this->initFonts();
	//this->initKeybinds();
	this->initButtons();
	this->initFonts();
	this->initLeaderBoard();
	this->initInputField();
	this->initCreditPlane();
	this->initGoalsAndContralPlane();
	this->initSounds();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

	delete this->leaderBoard;

	delete this->creditPlane;

	delete this->goalsPlane;

	delete this->contralPlane;
	//if (this->input)
	//	delete this->input;

}

void MainMenuState::toggleStatePaused()
{
}

void MainMenuState::updateInput(const float& dt)
{
	this->input->update(dt, this->mousePosView);

}

void MainMenuState::updateShouldPollEvent()
{
	if (this->toggleInputField) {
		*this->shouldPollEvent = false;
	}
	else {
		*this->shouldPollEvent = true;
	}
}

void MainMenuState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->click.play();
		this->input = new InputField(this->window, 810.f, 500.f, 300.f, 50.f, &this->font, 34);
		this->toggleInputField = !this->toggleInputField;

		this->toggleLeaderBoard = false;
		this->toggleCreditPlane = false;
		this->toggleGoalsAndContralPlane = false;
		if (!this->toggleInputField) {
			delete this->input;
		}
	}

	if (this->buttons["START_GAME"]->isPressed() && this->input->getName().size() > 0) {
		this->click.play();
		this->toggleInputField = false;
		//this->bgSound.stop();
		this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->input->getName(), &this->bgSound));
		delete this->input;
		*this->shouldPollEvent = true;
	}

	if (this->buttons["CANCEL_GAME"]->isPressed()) {
		this->click.play();
		this->toggleInputField = false;
		delete this->input;
	}

	if (this->buttons["LEADERBOARD"]->isPressed()) {
		this->click.play();
		if (this->toggleInputField) {
			this->toggleInputField = false;
			delete this->input;
		}
		this->toggleCreditPlane = false;
		this->toggleGoalsAndContralPlane = false;

		this->leaderBoard = new Plane(710.f, 250.f, 500.f, 450.f, &this->font, 72, 48);;
		this->toggleLeaderBoard = !this->toggleLeaderBoard;
	}

	if (this->buttons["HOW_TO_PLAY"]->isPressed()) {
		this->click.play();
		if (this->toggleInputField) {
			this->toggleInputField = false;
			delete this->input;
		}
		this->toggleLeaderBoard = false;
		this->toggleCreditPlane = false;

		this->toggleGoalsAndContralPlane = !this->toggleGoalsAndContralPlane;
	}

	if (this->buttons["CREDIT"]->isPressed()) {
		this->click.play();
		if (this->toggleInputField) {
			this->toggleInputField = false;
			delete this->input;
		}
		this->toggleLeaderBoard = false;
		this->toggleGoalsAndContralPlane = false;

		this->toggleCreditPlane = !this->toggleCreditPlane;
	}

	// Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->click.play();
		this->endState();
	}



}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateShouldPollEvent();

	if (this->toggleInputField) {
		this->updateInput(dt);
	}

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		if (it.first == "START_GAME" || it.first == "CANCEL_GAME") {
			if (this->toggleInputField) it.second->render(target);
		}
		else {
			it.second->render(target);
		}
	}
}

void MainMenuState::renderBackground(sf::RenderTarget* target)
{
	target->draw(this->background);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->renderBackground(target);

	if (this->input && this->InputPlane && this->toggleInputField) {
		this->InputPlane->render(target);
		this->input->render(target);
	}


	this->renderButtons(target);


	if (this->toggleLeaderBoard) {
		this->leaderBoard->render(target);
	}

	if (this->toggleCreditPlane) {
		this->creditPlane->render(target);
	}

	if (this->toggleGoalsAndContralPlane) {
		this->goalsPlane->render(target);
		this->contralPlane->render(target);
	}
}