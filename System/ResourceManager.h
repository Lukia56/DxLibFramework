#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class Resource;

class ResourceManager
{
private:

	ResourceManager() = default;
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;

public:

	~ResourceManager() = default;

	void Init();
	void Finalize();

	/// <summary>
	/// ‰æ‘œ‚ğæ“¾‚·‚é
	/// ‰‰ñŒÄ‚Ño‚µ‚Í“Ç‚İ‚ñ‚Åæ“¾
	/// 2‰ñ–ÚˆÈ~‚Íæ“¾‚Ì‚İ
	/// </summary>
	/// <returns>‰æ‘œƒnƒ“ƒhƒ‹</returns>
	Resource* GetImage(const std::string& path);

	void ReleaseAll();

	static ResourceManager& GetInstance();

private:

	std::unordered_map<std::string, std::unique_ptr<Resource>> mResources;
};
