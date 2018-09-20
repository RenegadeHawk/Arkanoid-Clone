#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include "Brick.h"
#include "SpecialBrick.h"
class BrickFactory
{
public:

	BrickFactory();

	~BrickFactory();

	void createAndAssembleBricks(std::vector<std::unique_ptr<Brick>> & t_bricksContainer, int t_level);

	void assembleBricks(std::vector<std::unique_ptr<Brick>> & t_bricksContainer, std::string t_line);

	void setInitialPosition(sf::Vector2f t_initialPosition);

private:
	int m_row;
	int	m_col;
	sf::Vector2f m_initialPosition = { 370,40 };
	sf::Vector2f m_brickSize = { 50,15 };

	//dark green
	sf::Color color0 = sf::Color(65, 128, 36, 255);    
	//dark
	sf::Color color1 = sf::Color(47, 36, 128, 255);
	//dark 
	sf::Color color2 = sf::Color(128, 36, 58, 255);
	//dark 
	sf::Color color3 = sf::Color(128, 60, 36, 255);
	//dark 
	sf::Color color4 = sf::Color(14, 225, 243, 255);
};

