#include "Game.h"



void Game::Start()
{
	m_stateManager = new StateManager();
	//m_renderManager = new RenderManager();
	m_stateManager->addState(States::MAINMENU);
}

void Game::LoadFont()
{

	if (!font.loadFromFile("PressStart2P-Regular.ttf"))
	{
		std::cout << "failed to load font";
	}

}




Game::Game(sf::RenderWindow & _window) :window(_window)
{
	GameParameters::instance()->setWindow(window);
	LoadFont();
	GameParameters::instance()->setFont(font);
	
	Start();
}

void Game::Update()
{
	//renderManager.render();
	//collisionManager.update();
	//gameObjectManager.update();

	m_stateManager->HandleState();

	m_stateManager->GetCurrentState().UpdateDisplay();

	m_stateManager->checkState();

}


void Game::HandleEvents(sf::Event & event)
{
	GameParameters::instance()->setEvent(event);
	m_stateManager->HandleState();

	m_stateManager->GetCurrentState().UpdateEvents();
	
}

Game::~Game()
{
}

RenderManager * Game::getRenderManager()
{
	return m_renderManager;
}
