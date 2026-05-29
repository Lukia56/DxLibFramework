#include "UI.h"
#include <DxLib.h>
#include "../Components/Sprite.h"

namespace
{
	const char* const kGraphHandlePath = "Resource\\Sprite\\impostor.png";
}

UI::UI() :
	mGraphHandle(-1),
	mSprite(nullptr)
{
	mSprite = std::make_unique<Sprite>(this);
}

UI::~UI()
{
	mSprite = nullptr;

	DeleteGraph(mGraphHandle);
}

void UI::Init()
{
	GameObject::mTransform.localPosition = Vector3(320.0f, 240.0f, 0.0f);

	mGraphHandle = LoadGraph(kGraphHandlePath);

	mSprite->Load(kGraphHandlePath);
}

void UI::Update()
{

}

void UI::Draw()
{
	//DrawGraph(64, 64, mGraphHandle, true);

	mSprite->Draw();
}
