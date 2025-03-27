#ifndef INPUTTYPES_H__
#define INPUTTYPES_H__

namespace Input
{
	enum class Key
	{
		A,
		D,
		S,
		Enter,
		Space,
		M,
		F,
		X
	};

	enum class Action
	{
		MoveRight,
		MoveLeft,
		Crouch,
		Attack,
		Attack2,
		Defend,
		Menu,
		Select,
		Cancel
	};
}

#endif