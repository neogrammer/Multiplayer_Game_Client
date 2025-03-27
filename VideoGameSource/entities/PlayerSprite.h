#pragma once
#include <core/IO/InputTarget.h>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Player.h"
#include <map>


class PlayerSprite : public sf::Sprite, public InputTarget
{
	bool firstRun{ true };
	int playerSpeed{ 350 };
	sf::Time _dt{ sf::seconds(0.f) };
	sf::Vector2f _vel{ 0.f,0.f };
	float _frameDelay{ 0.33f };
	sf::Time frameTimeElapsed{ sf::seconds(0.f) };
	std::string currAnim{ "Idle" };
	std::string currDir{ "Right" };
	std::map<std::pair<std::string, std::string>, sf::Texture> _textures =
	{
		{{"Idle","Right"},std::move(sf::Texture{})},
		{{"Idle","Left"},std::move(sf::Texture{})},
		{{"Walking","Right"},std::move(sf::Texture{})},
		{{"Walking","Left"},std::move(sf::Texture{})}
	};
	std::map<std::pair<std::string, std::string>, std::vector<sf::IntRect>> _frames =
	{
		{{"Idle","Right"}, std::move(std::vector<sf::IntRect>{})},
		{{"Idle","Left"}, std::move(std::vector<sf::IntRect>{})},
		{{"Walk","Right"}, std::move(std::vector<sf::IntRect>{})},
		{{"Walk","Left"}, std::move(std::vector<sf::IntRect>{})}
	};


public:
	Player data;

	PlayerSprite(sf::Texture* tex_);
	sf::Vector2f getVelocity();
	void input();
	void importData(Player* host_);
	Player* exportData();
	void update(sf::Time dt_);
	void render(sf::RenderWindow& wnd_);
	sf::IntRect currentFrame() { return _frames[{currAnim, currDir}][currentIndex]; };
	int currentIndex{ 0 };
	sf::Texture* currentTex{ nullptr };

	inline sf::Time getPrevGameTime() const { return _dt; }
};