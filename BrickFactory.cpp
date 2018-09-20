#include "BrickFactory.h"



void BrickFactory::createAndAssembleBricks(std::vector<std::unique_ptr<Brick>> & t_bricksContainer, int t_level)
{
	m_row = m_col = 0;
	std::string level = std::to_string(t_level);
	std::string fileName = "Levels/level" + level;
	fileName = fileName.append(".txt");
	std::ifstream infile(fileName);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream is(line);
		assembleBricks(t_bricksContainer, line);
	}
}

void BrickFactory::assembleBricks(std::vector<std::unique_ptr<Brick>> & t_bricksContainer, std::string t_line)
{
	m_col = 0;
	for (char c : t_line)
	{
		if (c == '-')
		{
			float xPosition = m_initialPosition.x + (m_brickSize.x + 20)*m_col;
			float yPosition = m_initialPosition.y + (2 * m_brickSize.y)*m_row;
			std::unique_ptr<Brick> brick(new Brick(xPosition, yPosition, color1, 1,"Brick"));
			t_bricksContainer.push_back(std::move(brick));
		}
		if (c == '7')
		{
			float xPosition = m_initialPosition.x + (m_brickSize.x + 20)*m_col;
			float yPosition = m_initialPosition.y + (2 * m_brickSize.y)*m_row;
			std::unique_ptr<Brick> brick(new SpecialBrick(xPosition, yPosition, color4, 1,Powers::FIREBALL));
			t_bricksContainer.push_back(std::move(brick));
		}
		if (c == 'S' || c == 's')
		{
			float xPosition = m_initialPosition.x + (m_brickSize.x + 20)*m_col;
			float yPosition = m_initialPosition.y + (2 * m_brickSize.y)*m_row;
			std::unique_ptr<Brick> brick(new Brick(xPosition,yPosition, color1, 2, "Brick"));
			t_bricksContainer.push_back(std::move(brick));
		}
		if (c == 'D' || c == 'd')
		{
			float xPosition = m_initialPosition.x + (m_brickSize.x + 20)*m_col;
			float yPosition = m_initialPosition.y + (2 * m_brickSize.y)*m_row;
			std::unique_ptr<Brick> brick(new Brick(xPosition,yPosition, color3, 3,"Brick"));
			t_bricksContainer.push_back(std::move(brick));
		}
		if (c == 'O')
		{
			++m_col;
			continue;
		}

		++m_col;
	}
	++m_row;
}

void BrickFactory::setInitialPosition(sf::Vector2f t_initialPosition)
{
	m_initialPosition = t_initialPosition;
}





BrickFactory::BrickFactory()
{
	
}


BrickFactory::~BrickFactory()
{
}
