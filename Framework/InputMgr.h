#pragma once
#include <list>

class InputMgr
{
private:
	static std::list<int> downKeys;
	static std::list<int> heldKeys;
	static std::list<int> upKeys;

	static sf::Vector2i mousePosition;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);

	static bool GetMouseButtonDown(sf::Mouse::Button button);
	static bool GetMouseButton(sf::Mouse::Button button);
	static bool GetMouseButtonUp(sf::Mouse::Button button);

	static sf::Vector2i GetMousePosition() { return mousePosition; }

private:
	static bool Contains(const std::list<int>& list, int code);
	static void Remove(std::list<int>& list, int code);
};

