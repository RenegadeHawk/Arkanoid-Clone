#include "Ball.h"





Ball::Ball(sf::Vector2f t_position) :
	m_position(t_position)
{
	m_texture.loadFromFile("Ball.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setColor(sf::Color(255, 255, 255, 200));
	m_sprite.setPosition(m_position);
	sf::Vector2f scale = { 0.1f,0.1f };
	m_sprite.setScale(scale);

	m_size = {(float) m_sprite.getTexture()->getSize().x*scale.x,(float)m_sprite.getTexture()->getSize().y*scale.y};

	m_sprite.setOrigin(m_size.x / (2 * scale.x), m_size.y / (2 * scale.y));
	box = AABB(m_position, m_size);
}

void Ball::move(float t_deltaX)
{
	m_sprite.move({ t_deltaX,0 });
}

Ball::Ball()
{
	//Constructed with default value
}

Ball::~Ball()
{
	//Default destructor
}


void Ball::changeTexture(const std::string t_path)
{
	m_texture.loadFromFile(t_path);
	m_sprite.setTexture(m_texture);
}

sf::Vector2f Ball::getPosition() const
{
	return m_sprite.getPosition();
}

sf::Vector2f Ball::getSize() const
{
	return m_size;
}

void Ball::setPosition(const sf::Vector2f & t_position)
{
	m_sprite.setPosition(t_position);
}

void Ball::setVelocity(const sf::Vector2f _velocity)
{
	//w1Velocity = _velocity;
}

void Ball::setDamage(const float t_damage)
{
	m_damage = t_damage;
}

void Ball::launchBall()
{
	m_sprite.move({ m_ballVelocity,-m_ballVelocity });
	Velocity = { m_ballVelocity/2, -m_ballVelocity };
}


void Ball::Update()
{
	m_tickRate = m_timer.restart();
	m_sprite.move(Velocity*Timer::instance()->get_value()); //*((float)tickRate.asMilliseconds() / 1000)
	m_sprite.setTexture(m_texture);
	box.updatePosition(m_sprite.getPosition());
}

void Ball::Draw(sf::RenderWindow & window) const
{
	window.draw(m_sprite);
}

bool Ball::CollisionCheck(ICollidable & other)
{
	return false;
}

void Ball::OnCollisionEnter(ICollidable & other)
{
	if (other.Name == "Brick" || other.Name == "SP")
	{
		(dynamic_cast<Brick*>(&other))->recieveDamage(m_damage);
		if (dynamic_cast<Brick*>(&other)->IfDestroyed)
		{
			Velocity = Velocity;
			return;
		}
	}
		sf::Vector2f paddleCenter = { (other.box.getUpperRight().x + other.box.getLowerLeft().x) / 2 ,(other.box.getUpperRight().y + other.box.getLowerLeft().y) / 2 };
		sf::Vector2f ballCenter = { m_sprite.getPosition() };
		float relativePositionHit = (ballCenter.x - other.box.getLowerLeft().x);
		

		float percent = relativePositionHit / 48;
		std::cout << percent << std::endl;
		if (percent < 0.4)
		{
			Velocity = { -m_ballVelocity * 0.8f,-Velocity.y };

		}
		else if (percent > 0.6)
		{
			Velocity = { m_ballVelocity*0.8f,-Velocity.y };
		}
		else
		{
			float deviation = 0.5 - percent;
			float sign = copysignf(1, deviation);
			deviation *= sign;
			Velocity = { copysignf(m_ballVelocity*deviation, -Velocity.x),-Velocity.y };
		}
	
	
	


}

bool Ball::IsDestroyed()
{
	return false;
}
