#include "Keyboard.h"
#include <DxLib.h>

void Keyboard::Update()
{
	GetHitKeyStateAll(mState);
}

bool Keyboard::IsDown(int keyCode)
{
	return mState[keyCode];
}

Keyboard& Keyboard::GetInstance()
{
	static Keyboard instance;

	return instance;
}
