#include "GameObject.h"
#include <cassert>
#include <memory>
#include <vector>
#include "Components/Transform.h"

GameObject::GameObject() :
	mTransform(),
	mIsCalledDestroy(false),
	mParent(nullptr),
	mChildren()
{
}

GameObject::~GameObject()
{
	// 子オブジェクトを削除する
	while (mChildren.size() > 0)
	{
		auto it = mChildren.begin();
		(*it)->Finalize();
		mChildren.erase(it);
	}

	mParent = nullptr;
}

bool GameObject::CheckDestroy()
{
	// 自身のイテレータを取得してコンテナから削除する
	if (mIsCalledDestroy && mParent)
	{
		// 終了処理を呼ぶ
		Finalize();

		auto& siblings = mParent->GetChildren();
		auto it = std::find_if(siblings.begin(), siblings.end(),
			[this](const std::unique_ptr<GameObject>& ptr)
			{
				return this == ptr.get();
			});
		if (it == siblings.end())
		{
			assert(false && "GameObject // 親オブジェクトに自身が含まれていませんでした");
			return false;
		}

		siblings.erase(it);

		return true;
	}

	// 子オブジェクトについて再帰
	for (auto i = 0; i < mChildren.size();)
	{
		if (mChildren[i]->CheckDestroy()) continue;

		i++;
	}

	return false;
}

void GameObject::Add(std::unique_ptr<GameObject> gameObject)
{
	gameObject->Init();
	gameObject->mParent = this;
	mChildren.emplace_back(std::move(gameObject));
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
