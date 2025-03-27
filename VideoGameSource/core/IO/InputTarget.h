#ifndef INPUTTARGET_H__
#define INPUTTARGET_H__
#include <core/IO/InputTypes.h>
#include <unordered_map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>

// Inherit this to gain input targeting, all input affects this object
class InputTarget
{
	sf::Sprite* _target;

public:
	InputTarget(sf::Sprite* target_);

	Input::Action lastAction;
	Input::Key lastKey;

	std::unordered_map<Input::Key, Input::Action>  actionMap = {
		{Input::Key::A, Input::Action::MoveLeft},
		{ Input::Key::D, Input::Action::MoveRight },
		{Input::Key::S, Input::Action::Crouch},
		{Input::Key::Enter,Input::Action::Attack},
		{Input::Key::Space,Input::Action::Defend},
		{Input::Key::M,Input::Action::Menu},
		{Input::Key::F,Input::Action::Select},
		{Input::Key::X ,Input::Action::Cancel}
	};

	std::unordered_map<sf::Keyboard::Key, Input::Key> lut = {
		{sf::Keyboard::Key::A, Input::Key::A },
		{sf::Keyboard::Key::D, Input::Key::D },
		{sf::Keyboard::Key::S, Input::Key::S },
		{sf::Keyboard::Key::Enter, Input::Key::Enter },
		{sf::Keyboard::Key::Space, Input::Key::Space },
		{sf::Keyboard::Key::F, Input::Key::F },
		{sf::Keyboard::Key::X, Input::Key::X },
		{sf::Keyboard::Key::M, Input::Key::M }
	};
	
	void handleAction(Input::Action type_);
	void unhandleAction(Input::Action type_);

	Input::Action getLastAction();
	Input::Key getLastKey();
	void updateInput();

	bool moveRight();
	bool moveLeft();
	bool select();
	bool cancel();
	bool attack();
	bool crouch();
	bool defend();


	bool _movingRight;
	bool _movingLeft;
	bool _selecting;
	bool _cancelling;
	bool _attacking;
	bool _crouching;
	bool _defending;
	bool _openingMenu;

};

#endif