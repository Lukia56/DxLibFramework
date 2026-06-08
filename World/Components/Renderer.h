#pragma once

#include <string>
#include "System/ResourceManager.h"
#include "System/Resource/Resource.h"

class GameObject;

/// <summary>
/// グラフィックリソースの描画管理の基底クラス
/// </summary>
template<class T>
requires std::derived_from<T, Resource>
class Renderer
{
public:

	Renderer(GameObject* owner) : mResource(nullptr), mOwner(owner) {}

	virtual ~Renderer()
	{
		mResource = nullptr;
		mOwner = nullptr;
	}

	virtual void Load(const std::string& filePath)
	{
		mResource = ResourceManager::GetInstance().GetResource<T>(filePath);
	}

	virtual void Draw() = 0;

protected:

	Resource* mResource;

	GameObject* mOwner;
};
