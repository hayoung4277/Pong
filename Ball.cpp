#include "stdafx.h"
#include "Ball.h"

Ball::Ball(const std::string& name)
	:GameObject(name)
{
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Ball::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Ball::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void Ball::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void Ball::Init()
{
	float raidus = 10.f;
	body.setRadius(raidus);
	body.setFillColor(sf::Color::White);
	SetOrigin(Origins::BC);

	float halfWidth = raidus * 0.5f;

	movableBounds = FRAMEWORK.GetWindowBounds();
	movableBounds.left += halfWidth;
	movableBounds.width -= raidus;
	movableBounds.top += raidus * 2.f;
	movableBounds.height -= raidus * 2.f;
}

void Ball::Reset()
{
	direction = sf::Vector2f(0.f, 0.f);
	speed = 0.f;
}

void Ball::Update(float dt)
{
	auto newPos = position + direction * speed * dt;
	SetPosition(newPos);

	if (newPos.y < movableBounds.top)
	{
		newPos.y = movableBounds.top;
		direction.y *= -1.f;
	}
	else if (newPos.y > movableBounds.top + movableBounds.height)
	{
		newPos.y = movableBounds.top + movableBounds.height;
		direction.y *= -1.f;
	}

	if (newPos.x < movableBounds.left)
	{
		newPos.x = movableBounds.left;
		direction.x *= -1.f;
	}
	else if (newPos.x > movableBounds.left + movableBounds.width)
	{
		newPos.x = movableBounds.left + movableBounds.width;
		direction.x *= -1.f;
	}

	SetPosition(newPos);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
