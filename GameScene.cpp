#include "stdafx.h"
#include "GameScene.h"
#include "Bat.h"
#include "Ball.h"

GameScene::GameScene()
	:Scene(SceneIds::Game)
{
}

void GameScene::Init()
{
	bat = AddGo(new Bat("Bat"));
	ball = AddGo(new Ball("Ball"));

	Scene::Init();
}

void GameScene::Enter()
{
	isBallActive = false;

	Scene::Enter();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	if (!isBallActive)
	{
		ball->SetPosition(bat->GetPosition());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		ball->Fire({ 1.f, -1.f }, 500.f);
		isBallActive = true;
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
