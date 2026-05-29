#include "SceneBase.h"
#include <cassert>
#include "../World/GameObject.h"

SceneBase::SceneBase() = default;

SceneBase::~SceneBase()
{
	while (mRootObjects.size() > 0)
	{
		auto it = mRootObjects.begin();
		(*it)->Finalize();
		mRootObjects.erase(it);
	}
}

void SceneBase::UpdateRootObjects()
{
	// ゲームオブジェクトの更新処理を呼ぶ
	for (const auto& it : mRootObjects)
	{
		Update(it.get());
	}

	// 削除チェック
	for (const auto& it : mRootObjects)
	{
		it->CheckDestroy();
	}
}

void SceneBase::DrawRootObjects()
{
	// ゲームオブジェクトの描画処理を呼ぶ
	for (const auto& it : mRootObjects)
	{
		Draw(it.get());
	}
}

void SceneBase::Update(GameObject* gameObject)
{
	gameObject->Update();

	// 子オブジェクトについて再帰
	for (const auto& it : gameObject->GetTransform().GetChildren())
	{
		Update(it.get());
	}
}

void SceneBase::Draw(GameObject* gameObject)
{
	gameObject->Draw();

	// 子オブジェクトについて再帰
	for (const auto& it : gameObject->GetTransform().GetChildren())
	{
		Draw(it.get());
	}
}
