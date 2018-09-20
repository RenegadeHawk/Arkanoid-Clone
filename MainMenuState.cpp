#include "MainMenuState.h"

void MainMenuState::ConstructMainMenu()
{
	delete currentMenu;
	mainMenu = new Menu(1100, 600, GameParameters::instance()->getFont());

	mainMenu->AddButton<MainMenuState>("Play",&MainMenuState::StartGame,this);

	mainMenu->AddButton<MainMenuState>("Options",&MainMenuState::DummyExec, this);
	mainMenu->AddButton<MainMenuState>("Exit",&MainMenuState::ConstructExitMenu, this);
	mainMenu->SetActive(true);
	currentMenu = mainMenu;
}

void MainMenuState::ConstructExitMenu()
{
	delete currentMenu;
	exitMenu = new Menu(1100, 600, GameParameters::instance()->getFont());
	exitMenu->AddButton<MainMenuState>("Yes", &MainMenuState::QuitGame, this);
	exitMenu->AddButton<MainMenuState>("No", &MainMenuState::ConstructMainMenu, this);
	exitMenu->SetActive(true);
	currentMenu = exitMenu;
	
}

MainMenuState::MainMenuState()
{
	Initialize();
}


MainMenuState::~MainMenuState()
{

}

void MainMenuState::Initialize()
{

	
	ConstructMainMenu();
	ball = Ball({ 50, 50 });
	ball.setVelocity({ 240,240 });

	m_titelTexture.loadFromFile("title.png");
	m_titleSprite.setTexture(m_titelTexture);
	m_titleSprite.setOrigin(m_titelTexture.getSize().x / 2, m_titelTexture.getSize().y / 2);
	m_titleSprite.setPosition(1366 / 2, 768 / 2);
	// Open it from an audio file
	if (!music.openFromFile("Dash Runner.wav"))
	{
		// error...
	}
	// Change some parameters
	music.setPosition(0, 1, 10); // change its 3D position
	music.setPitch(2);           // increase the pitch
	music.setVolume(50);         // reduce the volume
	music.setLoop(true);         // make it loop
								 // Play it
	//music.play();


}

void MainMenuState::HandleWindowCollisions()
{
	
}

void MainMenuState::UpdateDisplay()
{
	HandleWindowCollisions();
	ball.Update();
	//GameParameters::instance()->getWindow().draw(m_titleSprite);
	ball.Draw(GameParameters::instance()->getWindow());
	currentMenu->Draw(GameParameters::instance()->getWindow());
	

}

void MainMenuState::UpdateEvents()
{
	currentMenu->EventListener(GameParameters::instance()->getEvent());
}

void MainMenuState::QuitGame()
{
	GameParameters::instance()->getWindow().close();
}

void MainMenuState::StartGame()
{
	m_isStateFinished = true;
	std::cout << "Plaaaaay";
	delete currentMenu;
}

void MainMenuState::HandleEvents()
{

}


