#include "Brick.h"



void Brick::Destroy()
{
	
	//isDestroyed = true;
	IfDestroyed = true;
	// TODO 
	//sceneResiding->RemoveObjectFromScene(static_cast<GameObject*>(this));
	//sceneResiding->RemoveObjectFromScene(std::shared_ptr<GameObject>(this));
}

bool Brick::IsDestroyed()
{
	return isDestroyed;
}


sf::Vector2f Brick::getPosition()
{
	return m_position;
}

int Brick::getScore()
{
	return m_score;
}

void Brick::recieveDamage(float damage)
{
	m_HP -= damage;
	makeSpriteLighter();
	GameParameters::instance()->getSoundPlayer().playEffect(SFX::BALL_HIT_BRICK);
	if (m_HP <= 0)
	{
		Destroy();
	}
}

Brick::Brick()
{

}




Brick::~Brick()
{
	std::cout << "Brick instance deleted" << std::endl;
}

Brick::Brick(float t_xPosition, float t_yPosition, sf::Color t_color, int t_hp, std::string t_name) :
	m_position(t_xPosition,t_yPosition),m_color(t_color),m_name(t_name),m_HP(t_hp),m_size(50,15)
{
	
		Name = m_name;
		m_sprite.setFillColor(m_color);
		m_sprite.setSize(m_size);
		m_sprite.setPosition(m_position);
		m_sprite.setOrigin(m_size.x / 2, m_size.y / 2);
		box = AABB(m_position, m_size);
		m_score = m_HP * 100;
		
}

void Brick::Draw(sf::RenderWindow & window) const
{
	window.draw(m_sprite);
}

void Brick::Update()
{
	//add
}

bool Brick::CollisionCheck(ICollidable & other)
{
	if (ifColliding(box, other.box))
	{
		OnCollisionEnter(other);
		return true;
	}
	return false;
}

void Brick::OnCollisionEnter(ICollidable & other)
{
	other.OnCollisionEnter(*static_cast<ICollidable*>(this));
}

void Brick::makeSpriteLighter()
{
	sf::Color col = m_sprite.getFillColor();
	int r = col.r;
	int g = col.g;
	int b = col.b;

	r = r + (255 - r) * 0.5;
	g = g + (255 - g) * 0.5;
	b = b + (255 - b) * 0.5;
	col = sf::Color(r, g, b, 255);
	m_sprite.setFillColor(col);
}

