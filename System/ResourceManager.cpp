#include "ResourceManager.h"
#include <DxLib.h>
#include "Resource/Resource.h"

void ResourceManager::Init()
{
}

void ResourceManager::Finalize()
{
	ReleaseAll();
}

void ResourceManager::ReleaseAll()
{
	for (auto& it : mResources)
	{
		it.second->Delete();
	}
	mResources.clear();
}

ResourceManager& ResourceManager::GetInstance()
{
	static ResourceManager instance;

	return instance;
}
