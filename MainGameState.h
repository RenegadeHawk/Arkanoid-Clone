#pragma once
#include <thread>
#include "State.h"
#include "Ball.h"
#include "Paddle.h"
#include "Scene.h"
#include "Brick.h"
#include "Menu.h"
#include "Panel.h"
#include "BrickFactory.h"
#include "Expand.h"
#include "Fireball.h"
#include "PowerUp.h"
#include "Bullet.h"
class MainGameState : public State
{

public:
	std::vector<std::unique_ptr<Bullet>> uniqueBulletList;
	void AddCollectible(PowerUp* pow);
	MainGameState();
	~MainGameState();

	Scene	gameScene;
	// Inherited via State
	virtual void Initialize() override;
	virtual void UpdateDisplay() override;

	void RestartLevel();
	void RestartGame();
	void QuitGame();
	void ResumeGame();
	virtual void UpdateEvents() override;
	virtual void HandleEvents() override;
	int ival = 1.01;

private:
	unsigned int MAX_BRICKS = 0;
	unsigned int LEVEL_INTRO_TIME = 3;

	void showLevelStartHint();
	std::unique_ptr<Panel> levelStartHint();

	bool isLevelStartHintShowing = false;
	std::unique_ptr<Panel> m_levelHint;

	sf::RectangleShape gameBox;
	float boxXpos = 0;


	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;


	


	std::vector<std::unique_ptr<Brick>> m_bricksContainer;
	

	std::vector<ICollidable*> uniqueColliders;

	std::vector<std::unique_ptr<PowerUp>> powerUpContainer;


	bool forcedQuit = false;
	unsigned int m_lives = 3;
	Paddle *	p_paddle;
	Ball * p_ball;



	Menu*	 p_currentMenu;
	
	unsigned int m_score = 0;
	unsigned int m_level = 1;
	void	 TogglePauseMenu();
	bool	 ShouldDrawPauseMenu = false;
	bool	 ShouldDrawEndMenu = false;
	bool	 ShouldDrawLevelEndMenu = false;
	void	 ResetBall();

	


	void CheckLives();

	void	LoadLevel(int level);
	void	Reset();

	bool	IsWon = false;
	void	HandleWindowCollisions();
	void	OnLevelFinished();
	void	LoadNextLevel();
	void	SpawnEndMenu();
	void	 SpawnLevelEndMenu();

	Panel*	hudPanel;


	Panel*	endGamePanel;
	Panel* endLevelPanel;
	Panel*	levelHintPanel;
	
	Expand *e;


};

