#include "MainGameState.h"




void MainGameState::showLevelStartHint()
{
	isLevelStartHintShowing = true;
	sf::Clock clk;
	while (clk.getElapsedTime() < sf::seconds(LEVEL_INTRO_TIME))
	{
		//do nothing
	}
	isLevelStartHintShowing = false;
}

std::unique_ptr<Panel> MainGameState::levelStartHint()
{
	std::unique_ptr<Panel> levelStartHint(new Panel(GameParameters::instance()->getFont()));
	levelStartHint->ifBG = true;
	std::string levelStartText = "Level " + std::to_string(m_level);
	levelStartHint->AddTextToPanel(levelStartText, { 1366 / 2,280 });
	return std::move(levelStartHint);
}

void MainGameState::TogglePauseMenu()
{
	ShouldDrawPauseMenu = !ShouldDrawPauseMenu;
	if (ShouldDrawPauseMenu)
	{
		Timer::instance()->set_value(0);
		p_currentMenu = new Menu(650, 350,GameParameters::instance()->getFont());
		p_currentMenu->AddButton("Resume",&MainGameState::ResumeGame,this);
		p_currentMenu->AddButton("Exit",&MainGameState::QuitGame, this);
		p_currentMenu->SetActive(true);

	}
	else
	{
		Timer::instance()->set_value(1);
		delete p_currentMenu;
	}
}


void MainGameState::HandleWindowCollisions()
{
	sf::Vector2f* velocity = &p_ball->GetComponent<PhysicsBody>()->Velocity;
	if (p_ball->getPosition().y < 0)
	{
		velocity->y = -velocity->y;
	}
	if (p_ball->getPosition().x < boxXpos)
	{
		velocity->x = -velocity->x;
	}
	if (p_ball->getPosition().y > 768)
	{
		//Reset 
		ResetBall();
	}
	if (p_ball->getPosition().x > (boxXpos + 700))
	{
		velocity->x = -velocity->x;
	}
}

void MainGameState::ResetBall()
{
	
	p_ball->setPosition({ p_paddle->Sprite.getPosition().x, p_paddle->Sprite.getPosition().y - p_paddle->getSize().y / 2 - p_ball->getSize().y / 2 });
	p_paddle->isBallAttached = true;
	p_ball->GetComponent<PhysicsBody>()->Velocity = { 0,0 };
	--m_lives;
	
	CheckLives();
}









void MainGameState::CheckLives()
{
	if (m_lives < 1)
	{

		SpawnLevelEndMenu();

	}
}

void MainGameState::LoadLevel(int _level)
{

	gameScene.SceneObjects.clear();


	m_bricksContainer.clear();
	BrickFactory factory = BrickFactory();

	factory.createAndAssembleBricks(m_bricksContainer, _level);

	
	
	MAX_BRICKS = m_bricksContainer.size();
	p_ball = new Ball({650, 620});
	p_paddle = new Paddle({ 650, 650 },p_ball,&uniqueBulletList);
	p_ball->setPosition({ 650,650 - p_paddle->getSize().y / 2 - p_ball->getSize().y / 2 });
	std::unique_ptr<GameObject> s0(p_ball);
	std::unique_ptr<GameObject> s1(p_paddle);
	if (m_bricksContainer.size() <= 0)
	{
		SpawnEndMenu();
	}

	gameScene.SceneObjects.push_back(std::move(s0));
	gameScene.SceneObjects.push_back(std::move(s1));

	for (auto const& item : m_bricksContainer)
	{
		uniqueColliders.push_back(item.get());
	
	}

	std::cout << "Sceneobject list size : " << gameScene.SceneObjects.size() << std::endl;

	m_levelHint = levelStartHint();
	std::thread levelHintThread(&MainGameState::showLevelStartHint, this);
	levelHintThread.detach();
}

void MainGameState::Reset()
{
	m_level = 3;

}

void MainGameState::OnLevelFinished()
{
	LoadNextLevel();
}

void MainGameState::LoadNextLevel()
{
	++m_level;
	//gameScene.SceneObjects.clear();
	LoadLevel(m_level);
}

void MainGameState::SpawnLevelEndMenu()
{
	/*paddle->isInputLocked = true;
	endLevelPanel = new Panel(GameParameters::instance()->getFont());
	endLevelPanel->ifBG = true;
	endLevelPanel->AddTextToPanel("Game Over !", { 1366/2,280 });
	currentMenu = new Menu(1366/2, 768/2, GameParameters::instance()->getFont());
	currentMenu->AddButton<MainGameState>("Restart",&MainGameState::RestartLevel,this);
	currentMenu->AddButton<MainGameState>("Exit",&MainGameState::QuitGame, this);
	currentMenu->SetActive(true);
	ShouldDrawLevelEndMenu = true;*/
}

void MainGameState::SpawnEndMenu()
{
	//paddle->isInputLocked = true;
	//endGamePanel= new Panel(GameParameters::instance()->getFont());
	//endGamePanel->AddTextToPanel("Well Played !", { 650,300 });
	//currentMenu = new Menu(650, 350, GameParameters::instance()->getFont());
	//currentMenu->AddButton("Restart", &MainGameState::RestartGame, this);
	//currentMenu->AddButton("Exit", &MainGameState::QuitGame, this);
	//currentMenu->SetActive(true);
	//ShouldDrawEndMenu = true;
}

void MainGameState::AddCollectible(PowerUp * pow)
{
	std::unique_ptr<PowerUp> ex(pow);
	powerUpContainer.push_back(std::move(ex));
}

MainGameState::MainGameState()
{
	Initialize();
}


MainGameState::~MainGameState()
{
}

void MainGameState::Initialize()
{

	std::cout << " up";
	backgroundTexture.loadFromFile("background0.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale({ 1.8f,1 });
	sf::Vector2f textureSize =(sf::Vector2f)backgroundTexture.getSize();
	textureSize *= 0.5f;
	backgroundSprite.setOrigin(textureSize);
	backgroundSprite.setPosition({ 1366 / 2,768 / 2 });


	float totalX = 1366 - 700;
	totalX /= 2;
	boxXpos = totalX;
	gameBox.setPosition({ totalX,0 });
	gameBox.setSize({ 700,768 });

	gameBox.setFillColor(sf::Color(0, 0, 0, 255));

	LoadLevel(m_level);

	hudPanel = new Panel(GameParameters::instance()->getFont());
	hudPanel->AddHUDElement("Score", { 50,700 },m_score);
	hudPanel->AddHUDElement("Level", { 1250,700 },m_level);
	hudPanel->AddHUDElement("Lives", { 650, 700 }, m_lives);
	

}

bool IfAlive(GameObject* item)
{
	return item->IfDestroyed;
}

void MainGameState::UpdateDisplay()
{


	if (isLevelStartHintShowing)
	{
		m_levelHint.get()->Draw(GameParameters::instance()->getWindow());
	}
	else
	{
		GameParameters::instance()->getWindow().draw(gameBox);
		std::vector<std::unique_ptr<Brick>>::iterator it;
		for (it = m_bricksContainer.begin(); it != m_bricksContainer.end(); ++it)
		{

			it->get()->Draw(GameParameters::instance()->getWindow());
			it->get()->Update();
			it->get()->CollisionCheck(*p_ball->GetComponent<ICollidable>());

			if (it->get()->IfDestroyed)
			{

				if (it->get()->Name == "SP")
				{
					switch (dynamic_cast<SpecialBrick*>(it->get())->powerType)
					{
					case Powers::EXPANDPOWER:
					{
						Expand * pwr = new Expand({ it->get()->getPosition() });
						AddCollectible(pwr);
					}
					break;
					case Powers::FIREPOWER:
					{
						FirePower* pwr = new FirePower({ it->get()->getPosition() });
						AddCollectible(pwr);
					}
					case Powers::FIREBALL:
					{
						Fireball* pwr = new Fireball({ it->get()->getPosition() });
						AddCollectible(pwr);
					}
					break;
					default:
						break;
					}

				}
				m_score += it->get()->getScore();
				std::cout << m_score << std::endl;
				m_bricksContainer.erase(it);
				--it;

			}
			if (m_bricksContainer.size() <= MAX_BRICKS - 6)
			{
				LoadNextLevel();
				break;
			}
		}

		std::vector<std::unique_ptr<PowerUp>>::iterator it0;

		for (it0 = powerUpContainer.begin(); it0 != powerUpContainer.end(); ++it0)
		{
			it0->get()->Draw(GameParameters::instance()->getWindow());
			it0->get()->Update();
			if (p_paddle->CollisionCheck(*it0->get()))
			{
				switch (dynamic_cast<PowerUp*>(it0->get())->type)
				{
				case PowerupType::PADDLE_POWER:
				{
					it0->get()->Power(p_paddle);
				}
				case PowerupType::BALL_POWER:
				{
					it0->get()->Power(p_ball);
				}
				}
				powerUpContainer.erase(it0);
				--it0;
			}
		}

		std::vector<std::unique_ptr<Bullet>>::iterator it2;

		for (it2 = uniqueBulletList.begin(); it2 != uniqueBulletList.end(); ++it2)
		{
			it2->get()->Draw(GameParameters::instance()->getWindow());
			it2->get()->Update();
			for (auto const& item : m_bricksContainer)
			{
				if (item->GetComponent<ICollidable>()->CollisionCheck(*it2->get()))
				{
					std::cout << "Bullet brick collision";
				}
			}
			if (it2->get()->IfDestroyed)
			{
				++m_score;
				uniqueBulletList.erase(it2);
				--it2;
			}


		}







		HandleWindowCollisions();
		hudPanel->Draw(GameParameters::instance()->getWindow());

		hudPanel->Update();

		if (ShouldDrawPauseMenu)
		{
			p_currentMenu->Draw(GameParameters::instance()->getWindow());
		}
		if (ShouldDrawEndMenu)
		{
			endGamePanel->Draw(GameParameters::instance()->getWindow());
			p_currentMenu->Draw(GameParameters::instance()->getWindow());
		}
		if (ShouldDrawLevelEndMenu)
		{
			endLevelPanel->Draw(GameParameters::instance()->getWindow());
			p_currentMenu->Draw(GameParameters::instance()->getWindow());
		}
		//update and draw paddle and ball

		for (auto const& item : gameScene.SceneObjects)
		{

			item->Draw(GameParameters::instance()->getWindow());
			item->Update();
		}
		p_paddle->CollisionCheck(*p_ball->GetComponent<ICollidable>());



	}
	
	
	
}

void MainGameState::RestartLevel()
{
	std::cout << "Level Failed";
	m_level = m_level;
	LoadLevel(m_level);
	m_lives = 3;
	m_score = 0;
	ShouldDrawLevelEndMenu = false;
	delete p_currentMenu;
	delete endLevelPanel;
}

void MainGameState::RestartGame()
{
	m_level = 1;
	LoadLevel(m_level);
	Reset();
	ShouldDrawEndMenu = false;
	delete p_currentMenu;
	delete endGamePanel;
}

void MainGameState::QuitGame()
{
	GameParameters::instance()->getWindow().close();
}

void MainGameState::ResumeGame()
{
	Timer::instance()->set_value(1);
	ShouldDrawPauseMenu = !ShouldDrawPauseMenu;
	delete p_currentMenu;
}

void MainGameState::UpdateEvents()
{

	if (p_currentMenu != nullptr && p_currentMenu->IsActive())
	{
		p_currentMenu->EventListener(GameParameters::instance()->getEvent());
	}

	if (GameParameters::instance()->getEvent().type == sf::Event::KeyReleased &&
		GameParameters::instance()->getEvent().key.code == sf::Keyboard::Escape)
	{
		TogglePauseMenu();
		
	}
	if (GameParameters::instance()->getEvent().type == sf::Event::KeyReleased &&
		GameParameters::instance()->getEvent().key.code == sf::Keyboard::H)
	{
		forcedQuit = true;

	}

	
}

void MainGameState::HandleEvents()
{
	//Handle input events 
	// TODO : Naive implementation of input handling
}
