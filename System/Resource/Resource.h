#pragma once

#include <string>

class ResourceManager;

/// <summary>
/// リソース系クラスの基底
/// </summary>
class Resource
{
public:

	Resource() : mHandle(-1) {};
	virtual ~Resource() = default;

	virtual int GetHandle() const { return mHandle; };

protected:

	int mHandle;

private:

	friend ResourceManager;
	
	/// <summary>
	/// 読み込み処理がリソースごとに違うため純粋仮想化
	/// </summary>
	virtual void Load(const std::string& path) = 0;

	/// <summary>
	/// 解放処理がリソースごとに違うため純粋仮想化
	/// </summary>
	virtual void Delete() = 0;
};

/// <summary>
/// テクスチャを管理するクラス
/// </summary>
class Texture : public Resource
{
public:

	Texture() = default;
	~Texture() = default;

private:

	void Load(const std::string& path) override;

	void Delete() override;
};

/// <summary>
/// モデルを管理するクラス
/// </summary>
class Model : public Resource
{
public:

	Model() = default;
	~Model() = default;

private:

	void Load(const std::string& path) override;

	void Delete() override;
};
