#pragma once

#include <memory>
#include <vector>
#include "Utility/Math.h"
#include "Utility/Vector.h"

class GameObject;

/// <summary>
/// 位置、回転、拡縮とゲームオブジェクトの階層構造を管理するクラス
/// </summary>
class Transform
{
public:

	using GameObjectContainer = std::vector<std::unique_ptr<GameObject>>;

	Transform(GameObject* owner);
	~Transform();

	/// <summary>
	/// ローカル座標
	/// 親からの相対座標
	/// </summary>
	Vector3 localPosition;
	/// <summary>
	/// ローカル角度
	/// 親からの相対角度
	/// </summary>
	Vector3 localRotation;
	/// <summary>
	/// ローカルスケール
	/// 親からの相対スケール
	/// </summary>
	Vector3 localScale;

	/// <summary>
	/// 親トランスフォームを設定する
	/// すでに親が設定されている場合用
	/// nullptrなら解放する
	/// </summary>
	/// <param name="newParent">新しい親トランスフォーム</param>
	void SetParent(Transform* newParent);

	/// <summary>
	/// 親トランスフォームを設定する
	/// まだ親が設定されていない場合用
	/// </summary>
	void SetParent(std::unique_ptr<GameObject> gameObject, Transform* newParent);

	/// <summary>
	/// ワールド座標を取得する
	/// </summary>
	Vector3 GetWorldPosition() const;

	/// <summary>
	/// ワールド角度を取得する
	/// </summary>
	Vector3 GetWorldRotation() const;

	/// <summary>
	/// ワールドスケールを取得する
	/// </summary>
	Vector3 GetWorldScale() const;

public:

	/// <summary>
	/// 自身の所有者のゲームオブジェクトを取得する
	/// </summary>
	//GameObject* GetOwner() const { return mOwner; }

	/// <summary>
	/// 親トランスフォームを取得する
	/// </summary>
	Transform* GetParent() const { return mParent; }

	/// <summary>
	/// 子オブジェクトを取得する
	/// </summary>
	GameObjectContainer& GetChildren() { return mChildren; }

private:

	/// <summary>
	/// 自身の所有権を持ったオブジェクト
	/// </summary>
	GameObject* mOwner;

	/// <summary>
	/// 親トランスフォーム
	/// </summary>
	Transform* mParent;

	/// <summary>
	/// 自身の子オブジェクト
	/// </summary>
	GameObjectContainer mChildren;
};
