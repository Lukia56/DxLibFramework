#pragma once

#include "SceneBase.h"

class SceneInit :  public SceneBase
{
public:

	SceneInit() = default;
	~SceneInit() = default;

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init() override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>次のシーンのポインタ</returns>
	std::unique_ptr<SceneBase> Update() override;
};
