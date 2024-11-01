#pragma once
#include "Scene.h"

class Bat;
class Ball;

class GameScene :
    public Scene
{
protected:
	Bat* bat = nullptr;
	Ball* ball = nullptr;

	bool isBallActive = false;
public:
	GameScene();
	virtual ~GameScene() = default;

	virtual void Init();
	virtual void Enter();

	virtual void Update(float dt);

	virtual void Draw(sf::RenderWindow& window);
};

