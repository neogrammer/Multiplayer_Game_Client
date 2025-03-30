#include "InputTarget.h"

InputTarget::InputTarget(sf::Sprite* target_)
	: _target{target_}
{
	

}



void InputTarget::handleAction(Input::Action type_)
{
	switch (type_)
	{
	case Input::Action::MoveLeft:
	{
		_movingLeft = true;
	}
	break;
	case Input::Action::MoveRight:
	{
		_movingRight = true;
	}
	break;
	case Input::Action::Crouch:
	{
		_crouching = true;
	}
	break;
	case Input::Action::Attack:
	{
		_attacking = true;
	}
	break;
	case Input::Action::Defend:
	{
		_defending = true;
	}
	break;
	case Input::Action::Menu:
	{
		_openingMenu = true;
	}
	break;
	case Input::Action::Select:
	{
		_selecting = true;
	}
	break;
	case Input::Action::Cancel:
	{
		_cancelling = true;
	}
	break;
	default:
	{}
	break;
	}
}

void InputTarget::unhandleAction(Input::Action type_)
{
	switch (type_)
	{
	case Input::Action::MoveLeft:
	{
		_movingLeft = false;
	}
	break;
	case Input::Action::MoveRight:
	{
		_movingRight = false;
	}
	break;
	case Input::Action::Crouch:
	{
		_crouching = false;
	}
	break;
	case Input::Action::Attack:
	{ _attacking = false; }
	break;
	case Input::Action::Defend:
	{
		_defending = false;
	}
	break;
	case Input::Action::Menu:
	{ _openingMenu = false; }
	break;
	case Input::Action::Select:
	{ _selecting = false; }
	break;
	case Input::Action::Cancel:
	{ _cancelling = false; }
	break;
	default:
	{}
	break;
	}
}

Input::Action InputTarget::getLastAction()
{
	return lastAction;
}

Input::Key InputTarget::getLastKey()
{
	return lastKey;
}

void InputTarget::updateInput()
{
	for (auto act : lut)
	{
		if (sf::Keyboard::isKeyPressed(act.first))
		{
			handleAction(actionMap[act.second]);
			lastAction = actionMap[act.second];
			lastKey = act.second;
		}
		else
		{
			unhandleAction(actionMap[act.second]);
		}
	}
}

bool InputTarget::moveRight()
{
	return _movingRight;
}

bool InputTarget::moveLeft()
{
	return _movingLeft;
}

bool InputTarget::select()
{
	return _selecting;
}

bool InputTarget::cancel()
{
	return _cancelling;
}

bool InputTarget::attack()
{
	return _attacking;
}

bool InputTarget::crouch()
{
	return _crouching;
}

bool InputTarget::defend()
{
	return _defending;
}
