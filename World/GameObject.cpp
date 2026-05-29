#include "GameObject.h"
#include <cassert>
#include <memory>
#include <vector>
#include "Components/Transform.h"

GameObject::GameObject() :
	mTransform(this),
	mIsCalledDestroy(false)
{
}

GameObject::~GameObject()
{
}

bool GameObject::CheckDestroy()
{
	// 自身のイテレータを取得してコンテナから削除する
	if (mIsCalledDestroy && mTransform.GetParent())
	{
		// 終了処理を呼ぶ
		Finalize();

		mTransform.SetParent(nullptr);

		return true;
	}

	// 子オブジェクトについて再帰
	for (int i = 0; i < mTransform.GetChildren().size();)
	{
		if (mTransform.GetChildren()[i]->CheckDestroy()) continue;

		i++;
	}

	return false;
}

void GameObject::Add(std::unique_ptr<GameObject> gameObject)
{
	GameObject* ptr = gameObject.get();
	ptr->Init();
	ptr->GetTransform().SetParent(std::move(gameObject), &mTransform);
}

void GameObject::Destroy(GameObject* gameObject)
{
	if (gameObject == nullptr)
	{
		assert(false && "GameObject // 削除しようとしたゲームオブジェクトはnullptrです");
		return;
	}
	gameObject->mIsCalledDestroy = true;
}
