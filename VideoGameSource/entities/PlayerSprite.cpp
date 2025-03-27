#include "PlayerSprite.h"
#include "Player.h"

PlayerSprite::PlayerSprite(sf::Texture* tex_)
	: sf::Sprite{*tex_}
	, InputTarget{this}
{
	currentTex = tex_;

	   _textures[{"Idle", "Right"}].loadFromFile("Assets/Textures/Knight_player/Idle_KG_2.png");
		_textures[{"Idle", "Left"}].loadFromFile("Assets/Textures/Knight_player/Idle_KG_2.png");
		_textures[{"Walk", "Right"}].loadFromFile("Assets/Textures/Knight_player/Walking_KG_2.png");
		 _textures[{"Walk", "Left"}].loadFromFile("Assets/Textures/Knight_player/Walking_KG_2.png");

		 currentTex = &_textures[{"Idle", "Right"}];
		 currAnim = "Idle";
		 currDir = "Right";
		 currentIndex = 0;

		 setTexture(*currentTex);

	_frames[{"Idle", "Right"}].reserve(4);
	_frames[{"Idle", "Left"}].reserve(4);
	_frames[{"Walk", "Right"}].reserve(4);
	_frames[{"Walk", "Left"}].reserve(4);

	for (int i = 0; i < 4; i++)
	{
		_frames[{"Idle", "Right"}].emplace_back(sf::IntRect({ i * 100, 0 }, { 100, 64 }));
		_frames[{"Idle", "Left"}].emplace_back(sf::IntRect({ 99 + i * 100, 0 }, { -100, 64 }));
		_frames[{"Walk", "Right"}].emplace_back(sf::IntRect({ i * 100, 0 }, { 100, 64 }));
		_frames[{"Walk", "Left"}].emplace_back(sf::IntRect({ 99 + i * 100, 0 }, { -100, 64 }));

	}
	for (int i = 4; i < 7; i++)
	{
		_frames[{"Walk", "Right"}].emplace_back(sf::IntRect({ i * 100, 0 }, { 100, 64 }));
		_frames[{"Walk", "Left"}].emplace_back(sf::IntRect({ 99 + i * 100, 0 }, { -100, 64 }));
	}

}

sf::Vector2f PlayerSprite::getVelocity()
{
	return _vel;
}

void PlayerSprite::input()
{
	InputTarget::updateInput();
}

void PlayerSprite::importData(Player* host_)
{
	data.name = host_->name;
	data.id = host_->id;
	data.xpos = host_->xpos;
	data.ypos = host_->ypos;
}

Player* PlayerSprite::exportData()
{
	return &data;
}

void PlayerSprite::update(sf::Time dt_)
{
	_dt = dt_;
	if (firstRun)
	{
		firstRun = false;
	}
	else
	{
		if (_movingLeft)
		{
			if (currAnim != "Walk" || currDir != "Left")
			{
				currentIndex = 0;
				currAnim = "Walk";
				currDir = "Left";
				_frameDelay = 0.0627f;
			}
			_vel.x = -1 * (float)playerSpeed;
			
		}
		else if (_movingRight)
		{
			if (currAnim != "Walk" || currDir != "Right")
			{
				currentIndex = 0;
				currAnim = "Walk";
				currDir = "Right";
				_frameDelay = 0.0627f;

			}
			_vel.x = (float)playerSpeed;
		}
		else
		{
			if (currAnim != "Idle")
			{
				currentIndex = 0;
				_frameDelay = 0.33f;
				currAnim = "Idle";
			}
			_vel.x = 0.f;
		}
	}

	frameTimeElapsed += dt_;
	if (frameTimeElapsed.asSeconds() > this->_frameDelay)
	{
		frameTimeElapsed = sf::seconds(0.f);
		currentIndex++;
		if (currentIndex >= _frames[{currAnim, currDir}].size())
		{
			currentIndex = 0;
		}
	}

	move(_vel * dt_.asSeconds());



	this->setTextureRect(_frames[{currAnim, currDir}][currentIndex]);
	this->setTexture(_textures[{currAnim, currDir}]);
	
}

void PlayerSprite::render(sf::RenderWindow& wnd_)
{
	wnd_.draw(*this);
}
