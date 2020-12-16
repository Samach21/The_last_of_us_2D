#include "Game.h"
//private
void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;
}

void Game::innitWindow()
{
	this->videomode.height = 1080;
	this->videomode.width = 1920;
	this->window = new RenderWindow(this->videomode, "Test game", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}

//public
Game::Game()
{
	this->initVariables();
	this->innitWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		case Event::MouseWheelMoved:
			this->player.mouseScroll(this->ev.mouseWheel.delta);
			break;
		default:
			break;
		}
	}
}

void Game::updateCollide()
{
	
}

void Game::update()
{
	this->pollEvent();
	if (this->endGame == false)
	{
		this->map.update(this->window, this->window);
		this->player.update(this->window, this->window);
		this->enemy.update(this->window);
		if (Collision::PixelPerfectTest(this->player.ellieShadow, this->map.map))
			this->map.isCollide = true;
		else
			this->map.isCollide = false;
		if (Collision::PixelPerfectTest(this->player.ellieShadow, this->map.mapCheck))
			this->map.renderFrontON = true;
		else
			this->map.renderFrontON = false;
	}
}

void Game::render()
{
	this->window->clear();

	this->map.render(this->window);
	this->player.render(this->window);
	this->map.renderFront(this->window);
	this->enemy.render(this->window);

	this->window->display();
}