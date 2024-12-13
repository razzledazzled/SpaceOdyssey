#include "Game.h"
#include <iostream>

//Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Space Odyssey", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["Bullet"] = new sf::Texture();
	this->textures["Bullet"]->loadFromFile("Textures/bullet.png");
}

void Game::initGUI()
{
	// Load font
	if (!this->font.loadFromFile("Fonts/wence.otf"))
	{
		std::cout << "ERROR::GAME::INITGUI::Could not load font." << std::endl;
	}

	// Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);

	// Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.0f, 25.0f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(0.0f, 50.0f));

	this->playerHpBarBackground = this->playerHpBar;
	this->playerHpBarBackground.setFillColor(sf::Color(25, 25, 25, 200));

	// Init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(this->window->getSize().x / 2.0f - this->gameOverText.getGlobalBounds().width / 2.0f,
		this->window->getSize().y / 2.0f - this->gameOverText.getGlobalBounds().height / 2.0f);
}

void Game::initBackground()
{
	if (!this->backgroundTexture.loadFromFile("Textures/background.png"))
	{
		std::cout << "ERROR::GAME::INITBACKGROUND::Could not load background texture." << std::endl;
	}
	this->background.setTexture(this->backgroundTexture);
}

void Game::initPoints()
{
	this->points = 0;
}

void Game::initPlayer()
{
	this->player = new Player();
}

//void Game::initAsteroids()
//{
//	this->spawnTimerMax = 35.0f;
//	this->spawnTimer = this->spawnTimerMax;
//}

// Constructor
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initBackground();
	this->initPoints();
	this->initPlayer();
	this->initAsteroids();
}

// Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;

	//// Delete all textures
	//for (auto& i : this->textures)
	//{
	//	delete i.second;
	//}

	//// Delete all bullets
	//for (auto* i : this->bullets)
	//{
	//	delete i;
	//}

	//// Delete all asteroids
	//for (auto* i : this->asteroids)
	//{
	//	delete i;
	//}
}

// Public functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();

		if (this->player->getHp() > 0)
			this->update();

		this->render();
	}
}
