#include "Paddle.h"
#include "Ball.h"


void Paddle::move(float t_deltaX)
{
	
	float totalX = 1366 - 700;
	totalX /= 2;
	float totalXP = totalX + 700;

	if (Sprite.getPosition().x + m_size.x / 2 + t_deltaX > totalXP || Sprite.getPosition().x - m_size.x / 2 + t_deltaX < totalX)
	{
		Sprite.move({ 0,0 });
		if (isBallAttached)
		{
			p_ball->move(0);
		}
	}
	else
	{
		Sprite.move({ t_deltaX,0 });
		if (isBallAttached)
		{
			p_ball->move(t_deltaX);
		}
	}

}
void Paddle::initializeFiring()
{
	std::thread firingThread(&Paddle::startBulletFiringRoutine, this);
	firingThread.detach();
}

Paddle::Paddle()
{

}


Paddle::~Paddle()
{
}

Paddle::Paddle(sf::Vector2f t_position, Ball * t_ball, std::vector<std::unique_ptr<Bullet>>* t_instance) :p_ball(t_ball), m_bulletList(t_instance)
{
	Name = "Paddle";
	m_texture.loadFromFile("paddle.png");
	Sprite.setTexture(m_texture);
	Sprite.setColor(sf::Color(255, 255, 255, 200));
	Sprite.setPosition(t_position);

	sf::Vector2f scale = { 0.1f, 0.1f };
	Sprite.setScale(scale);

	sf::Vector2f size = (sf::Vector2f)Sprite.getTexture()->getSize();
	Sprite.setOrigin(size.x / 2, size.y / 2);
	box = AABB(Sprite.getPosition(), { size.x*scale.x,size.y*scale.y });

	m_size = { size.x*scale.x,size.y*scale.y };



}

void Paddle::startBulletFiringRoutine()
{
	sf::Clock clk;
	while (clk.getElapsedTime() < sf::seconds(25))
	{
		sf::Clock clk2;
		while (clk2.getElapsedTime() < sf::seconds(0.50f))
		{

		}
		sf::Vector2f pos = Sprite.getPosition();
		std::unique_ptr<Bullet> b0(new Bullet({ pos.x - 40,pos.y - 25 }));
		std::unique_ptr<Bullet> b1(new Bullet({ pos.x + 40,pos.y - 25 }));
		m_bulletList->push_back(std::move(b0));
		m_bulletList->push_back(std::move(b1));

	}
}

void Paddle::SetSize(float t_percent)
{
	Sprite.setScale({ Sprite.getScale().x + t_percent,Sprite.getScale().y });
	sf::Vector2f scale = Sprite.getScale();
	sf::Vector2f size = (sf::Vector2f)Sprite.getTexture()->getSize();
	Sprite.setOrigin(size.x / 2, size.y / 2);
	m_size = { size.x*scale.x,size.y*scale.y };
}
sf::Vector2f Paddle::getSize() const
{
	return m_size;
}
void Paddle::Update()
{
	if (!isInputLocked)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{

			move(-5);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

			move(5);

		}
		else
		{
			move(0);

		}

	}
	if (!isInputLocked)
	{

		if (isBallAttached && GameParameters::instance()->getEvent().type == sf::Event::KeyReleased &&
			GameParameters::instance()->getEvent().key.code == sf::Keyboard::Space)
		{
			isBallAttached = false;
			p_ball->launchBall();
		}

		box.updatePosition(Sprite.getPosition());
	}



}

void Paddle::Draw(sf::RenderWindow & window) const
{
	window.draw(Sprite);
}

bool Paddle::CollisionCheck(ICollidable & other)
{
	if (ifColliding(box, other.box))
	{
		OnCollisionEnter(other);
		if (other.Name == "Collectible")
		{
			std::cout << "Hit Power Up";
		}
		return true;
	}
	return false;
}

void Paddle::OnCollisionEnter(ICollidable & other)
{

	other.OnCollisionEnter(*static_cast<ICollidable*>(this));
	//GameParameters::instance()->getSoundPlayer().playEffect(SFX::BALL_HIT_PADDLE);
	//std::cout << "Paddle Collided with ball \n";
}
bool Paddle::IsDestroyed()
{
	return false;
}
