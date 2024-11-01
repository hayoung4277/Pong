#pragma once
#include "GameObject.h"

class Bat;

class Ball :
    public GameObject
{
protected:
	sf::CircleShape body;

	sf::Vector2f direction;
	float speed = 0.f;

	sf::FloatRect movableBounds;

	Bat* bat = nullptr;

public:
	Ball(const std::string& name = "");
	~Ball() = default;

	void SetPosition(const sf::Vector2f& pos) override;

	void SetScale(const sf::Vector2f& s) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	
	void Fire(const sf::Vector2f& d, float s)
	{
		direction = d;
		speed = s;
	}

	void SetBat(Bat* bat) { this->bat = bat; }
};

