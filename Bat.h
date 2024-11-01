#pragma once
#include "GameObject.h"

class Bat : public GameObject
{
protected:
	sf::RectangleShape body;

	sf::Vector2f direction;
	sf::Vector2f initPos;
	float speed;

	float minX;
	float maxX;

public:
	Bat(const std::string& name = "");
	~Bat() = default;

	void SetPosition(const sf::Vector2f& pos) override;

	void SetScale(const sf::Vector2f& s) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

