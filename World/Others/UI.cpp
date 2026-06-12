#include "UI.h"
#include <DxLib.h>
#include "../Components/Rendering/SpriteRenderer.h"
#include "../Components/Rendering/TextRenderer.h"
#include "System/ResourceManager.h"
#include "System/Resource/Resource.h"
#include "Utility/Color.h"

namespace
{
	const char* const kGraphHandlePath = "Resource\\Sprite\\impostor.png";

	const char* const kFontHandlePath = "Resource\\Font\\JFDotK12.dft";
	//const char* const kFontHandlePath = "Resource\\Font\\MisakiGothic.dft";
}

UI::UI() :
	mGraphHandle(-1),
	mSprite(nullptr),
	mText(nullptr)
{
	mSprite = std::make_unique<SpriteRenderer>(this);
	mText = std::make_unique<TextRenderer>(this);
}

UI::~UI()
{
	mSprite = nullptr;

	DeleteGraph(mGraphHandle);
}

void UI::Init()
{
	GameObject::mTransform.localPosition = Vector3(60.0f, 60.0f, 0.0f);

	mGraphHandle = LoadGraph(kGraphHandlePath);

	mSprite->Load(kGraphHandlePath);

	mText->Load(kFontHandlePath);
	mText->SetDisplayText("テストテキスト");
}

void UI::Update()
{

}

void UI::Draw()
{
	mSprite->Draw();

	mText->Draw();
}
