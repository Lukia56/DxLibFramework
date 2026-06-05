#pragma once

/// <summary>
/// リソース系クラスの基底
/// </summary>
class Resource
{
public:

	Resource() = default;
	virtual ~Resource() = default;

	/// <summary>
	/// 解放処理がリソースごとに違うため純粋仮想化
	/// </summary>
	virtual void Delete() = 0;

	virtual int GetHandle() const = 0;
};

/// <summary>
/// テクスチャを管理するクラス
/// </summary>
class Texture : public Resource
{
public:

	Texture(int handle) : mHandle(handle) {}
	~Texture() = default;

	void Delete() override;

	int GetHandle() const override { return mHandle; }

private:

	int mHandle;
};
