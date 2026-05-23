#pragma once

#include "../Utility/Math.h"
#include "../Utility/Vector.h"

/// <summary>
/// 位置、回転、拡縮を管理する構造体
/// </summary>
struct Transform
{
	Vector3 position{ 0.0f, 0.0f, 0.0f };

	Vector3 rotation{ 0.0f, 0.0f, 0.0f };

	Vector3 scale{ 1.0f, 1.0f, 1.0f };

	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="vec">移動成分のベクトル</param>
	void Translate(const Vector3& vec) { position += vec; }

	/// <summary>
	/// 回転 引数のベクトルはラジアン角
	/// </summary>
	/// <param name="vec">回転成分のベクトル</param>
	void RotateRad(const Vector3& vec) { rotation += vec; }

	/// <summary>
	/// 回転 引き数のベクトルはデグリー角
	/// </summary>
	/// <param name="vecDeg">回転成分のベクトル</param>
	void RotateDeg(const Vector3& vecDeg)
	{
		rotation.x += Math::ToRadian(vecDeg.x);
		rotation.y += Math::ToRadian(vecDeg.y);
		rotation.z += Math::ToRadian(vecDeg.z);
	}

	/// <summary>
	/// 角度を指定 引数のベクトルはデグリー角
	/// </summary>
	/// <param name="vecDeg">回転成分のベクトル</param>
	void SetRotateDeg(const Vector3& vecDeg)
	{
		rotation.x = Math::ToDegree(vecDeg.x);
		rotation.y = Math::ToDegree(vecDeg.y);
		rotation.z = Math::ToDegree(vecDeg.z);
	}

	/// <summary>
	/// 回転の値をデグリー角で取得 デバッグで使用する想定
	/// </summary>
	/// <returns>デグリー角の回転成分</returns>
	Vector3 GetRotateDeg() const
	{
		return
		{
			Math::ToDegree(rotation.x),
			Math::ToDegree(rotation.y),
			Math::ToDegree(rotation.z)
		};
	}

	/// <summary>
	/// Transformを初期状態に戻す
	/// </summary>
	void Reset()
	{
		position = { 0.0f, 0.0f, 0.0f };
		rotation = { 0.0f, 0.0f, 0.0f };
		scale = { 1.0f, 1.0f, 1.0f };
	}
};
