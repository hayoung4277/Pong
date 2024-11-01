#include "stdafx.h"
#include "Bat.h"

Bat::Bat(const std::string& name)
	:GameObject(name)
{
}

void Bat::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Bat::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Bat::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Bat::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Bat::Init()
{
	body.setSize({ 100.f, 5.f });
	body.setFillColor(sf::Color::White);
	SetOrigin(Origins::TC);

	auto windowSize = FRAMEWORK.GetWindowSizeF();
	initPos.x = windowSize.x * 0.5f;
	initPos.y = windowSize.y - 200.f;

	auto halfWidth = body.getSize().x * 0.5f;
	minX = halfWidth;
	maxX = windowSize.x - halfWidth;

	GameObject::Init();
}

void Bat::Reset()
{
	direction = sf::Vector2f(0.f, 0.f);
	SetPosition(initPos);

	GameObject::Reset();
}

void Bat::Update(float dt)
{
	
	GameObject::Update(dt);
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
