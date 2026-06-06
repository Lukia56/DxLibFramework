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

Resource* ResourceManager::GetImage(const std::string& path)
{
	// ‰‰ñ“Ç‚İ‚İ
	if (!mResources.contains(path))
	{
		int handle = LoadGraph(path.c_str());
		auto resource = std::make_unique<Texture>(handle);
		Resource* ptr = resource.get();

		mResources.emplace(path, std::move(resource));

		return ptr;
	}

	return mResources.at(path).get();
}

Resource* ResourceManager::GetModel(const std::string& path)
{
	// ‰‰ñ“Ç‚İ‚İ
	if (!mResources.contains(path))
	{
		int handle = MV1LoadModel(path.c_str());
		auto resource = std::make_unique<Model>(handle);
		Resource* ptr = resource.get();

		mResources.emplace(path, std::move(resource));

		return ptr;
	}

	return mResources.at(path).get();
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
