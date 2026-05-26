#pragma once

#include "../GameObject.h"

/// <summary>
/// カメラを制御するクラス
/// 動きなどは派生クラスで実装する
/// </summary>
class Camera : public GameObject
{
public:

	Camera();
	virtual ~Camera() = default;

	void Init();

	void Update();

	void SetTarget(Transform* target) { mTarget = target; }

protected:

	/// <summary>
	/// 手前のクリップ距離
	/// </summary>
	float mNearClip;

	/// <summary>
	/// 奥のクリップ距離
	/// </summary>
	float mFarClip;

	/// <summary>
	/// 視野角
	/// </summary>
	float mFOV;

	/// <summary>
	/// 被写体までの距離
	/// </summary>
	float mDistanceToTarget;

	/// <summary>
	/// オフセット座標
	/// </summary>
	Vector3 mOffsetPos;

	/// <summary>
	/// 被写体のトランスフォーム
	/// </summary>
	Transform* mTarget;
};
