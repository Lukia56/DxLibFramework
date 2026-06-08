#include "UI.h"
#include <DxLib.h>
#include "../Components/Rendering/SpriteRenderer.h"
#include "System/ResourceManager.h"
#include "System/Resource/Resource.h"
#include "Utility/Color.h"

namespace
{
	const char* const kGraphHandlePath = "Resource\\Sprite\\impostor.png";

	const char* const kFontHandlePath = "Resource\\Font\\MisakiGothic.dft";
}

UI::UI() :
	mGraphHandle(-1),
	mSprite(nullptr)
{
	mSprite = std::make_unique<SpriteRenderer>(this);
}

UI::~UI()
{
	mSprite = nullptr;

	DeleteGraph(mGraphHandle);
}

void UI::Init()
{
	GameObject::mTransform.localPosition = Vector3(240.0f, 240.0f, 0.0f);

	mGraphHandle = LoadGraph(kGraphHandlePath);

	mSprite->Load(kGraphHandlePath);
}

void UI::Update()
{

}

void UI::Draw()
{
	mSprite->Draw();

	int handle = ResourceManager::GetInstance().GetResource<Font>(kFontHandlePath)->GetHandle();
	DrawStringToHandle(240, 100, "テストテキスト", Color::white.GetAsHexRGB(), handle);
}
