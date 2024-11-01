#include "stdafx.h"

std::list<int> InputMgr::downKeys;
std::list<int> InputMgr::heldKeys;
std::list<int> InputMgr::upKeys;
sf::Vector2i InputMgr::mousePosition;

void InputMgr::Init()
{
}

void InputMgr::Clear()
{
	upKeys.clear();
	downKeys.clear();
}

bool InputMgr::Contains(const std::list<int>& list, int code)
{
	return std::find(list.begin(), list.end(), code) != list.end();
}

void InputMgr::Remove(std::list<int>& list, int code)
{
	list.remove(code);
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		{
			int code = ev.key.code;
			if (!Contains(heldKeys, code))
			{
				heldKeys.push_back(code);
				downKeys.push_back(code);
			}
		}
		break;
	case sf::Event::KeyReleased:
		{
			int code = ev.key.code;
			Remove(heldKeys, code);
			upKeys.push_back(code);
		}
		break;
	case sf::Event::MouseButtonPressed:
		{
			int code = sf::Keyboard::KeyCount + ev.mouseButton.button;
			if (!Contains(heldKeys, code))
			{
				heldKeys.push_back(code);
				downKeys.push_back(code);
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		{
			int code = sf::Keyboard::KeyCount + ev.mouseButton.button;
			Remove(heldKeys, code);
			upKeys.push_back(code);
		}
		break;
	case sf::Event::MouseMoved:
		mousePosition.x = ev.mouseMove.x;
		mousePosition.y = ev.mouseMove.y;
		break;
	}
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(downKeys, key) || Contains(heldKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgr::GetMouseButtonDown(sf::Mouse::Button button)
{
	return Contains(downKeys, sf::Keyboard::KeyCount + button);
}

bool InputMgr::GetMouseButton(sf::Mouse::Button button)
{
	int code = sf::Keyboard::KeyCount + button;
	return Contains(downKeys, code) || Contains(heldKeys, code);
}

bool InputMgr::GetMouseButtonUp(sf::Mouse::Button button)
{
	return Contains(upKeys, sf::Keyboard::KeyCount + button);
}

