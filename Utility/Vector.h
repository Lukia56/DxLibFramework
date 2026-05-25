#pragma once

#include <cassert>
#include <cmath>
#include <DxLib.h>

/// <summary>
/// 2次元ベクトル
/// </summary>
struct Vector2
{
	// 座標
	float x, y;

	/// <summary>
	/// 各成分を0で初期化
	/// </summary>
	constexpr Vector2() : x(0.0f), y(0.0f) {};

	/// <summary>
	/// 各成分を指定して初期化
	/// </summary>
	constexpr Vector2(float x, float y) : x(x), y(y) {};

	// 演算子

	constexpr Vector2 operator-() const { return Vector2(-x, -y); }

	constexpr Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
	constexpr Vector2 operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
	constexpr Vector2 operator*(const float s) const { return Vector2(x * s, y * s); }
	constexpr Vector2 operator/(const float s) const
	{
		if (s == 0.0f)
		{
			assert(false && "Vector2 // 0除算が行われました");
			return Vector2::Zero;
		}

		return Vector2(x / s, y / s);
	}

	constexpr Vector2& operator+=(const Vector2& v)
	{
		x += v.x;
		y += v.y;

		return *this;
	}
	constexpr Vector2& operator-=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}
	constexpr Vector2& operator*=(const float s)
	{
		x *= s;
		y *= s;

		return *this;
	}
	constexpr Vector2& operator/=(const float s)
	{
		if (s == 0.0f)
		{
			assert(false && "Vector2 // 0除算が行われました");
			return *this;
		}

		x /= s;
		y /= s;

		return *this;
	}

	float operator[](int index) const
	{
		return *(&x + index);
	}

	constexpr bool operator==(const Vector2& v) const { return x == v.x && y == v.y; }
	constexpr bool operator!=(const Vector2& v) const { return x != v.x || y != v.y; }

	// ヘルパー関数

	/// <summary>
	/// 内積を計算する
	/// </summary>
	constexpr float Dot(const Vector2& v) const
	{
		return (x * v.x) + (y * v.y);
	}

	/// <summary>
	/// 外積を計算する
	/// </summary>
	constexpr float Cross(const Vector2& v) const
	{
		return (x * v.y) - (y * v.x);
	}

	/// <summary>
	/// ベクトルの長さを取得する
	/// 処理が重いため非推奨
	/// </summary>
	inline float GetLength() const
	{
		return std::sqrt(GetSqLength());
	}

	/// <summary>
	/// ベクトルの長さの2乗を取得する
	/// </summary>
	constexpr float GetSqLength() const
	{
		return x * x + y * y;
	}

	/// <summary>
	/// 正規化したベクトルを取得する
	/// </summary>
	constexpr Vector2 GetNormalize() const
	{
		if (*this == Vector2::Zero)
		{
			assert(false && "Vector2 // 0除算が行われました");
			return Vector2::Zero;
		}

		return *this / GetLength();
	}

	/// <summary>
	/// DxLibのベクトルに変換する
	/// </summary>
	inline VECTOR GetAsDxLibVector() const
	{
		return VGet(x, y, 0.0f);
	}

	// 定数

	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 XAxis;
	static const Vector2 NegaXAxis;
	static const Vector2 YAxis;
	static const Vector2 NegaYAxis;
};

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3
{
	// 座標
	float x, y, z;

	/// <summary>
	/// 各成分を0で初期化
	/// </summary>
	constexpr Vector3() : x(0.0f), y(0.0f), z(0.0f) {};

	/// <summary>
	/// 各成分を指定して初期化
	/// </summary>
	constexpr Vector3(float x, float y, float z) : x(x), y(y), z(z) {};

	// 演算子

	constexpr Vector3 operator-() const { return Vector3(-x, -y, -z); }

	constexpr Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
	constexpr Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
	constexpr Vector3 operator*(const float s) const { return Vector3(x * s, y * s, z * s); }
	constexpr Vector3 operator/(const float s) const
	{
		if (s == 0.0f)
		{
			assert(false && "Vector3 // 0除算が行われました");
			return Vector3::Zero;
		}

		return Vector3(x / s, y / s, z / s);
	}

	constexpr Vector3& operator+=(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}
	constexpr Vector3& operator-=(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}
	constexpr Vector3& operator*=(const float s)
	{
		x *= s;
		y *= s;
		z *= s;

		return *this;
	}
	constexpr Vector3& operator/=(const float s)
	{
		if (s == 0.0f)
		{
			assert(false && "Vector3 // 0除算が行われました");
			return *this;
		}

		x /= s;
		y /= s;
		z /= s;

		return *this;
	}

	float operator[](int index) const
	{
		return *(&x + index);
	}

	constexpr bool operator==(const Vector3& v) const { return x == v.x && y == v.y && z == v.z; }
	constexpr bool operator!=(const Vector3& v) const { return x != v.x || y != v.y || z != v.z; }

	// ヘルパー関数

	/// <summary>
	/// 内積を計算する
	/// </summary>
	constexpr float Dot(const Vector3& v) const
	{
		return (x * v.x) + (y * v.y) + (z * v.z);
	}

	/// <summary>
	/// 外積を計算する
	/// </summary>
	constexpr Vector3 Cross(const Vector3& v) const
	{
		return Vector3(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}

	/// <summary>
	/// ベクトルの長さを取得する
	/// 処理が重いため非推奨
	/// </summary>
	inline float GetLength() const
	{
		return std::sqrt(GetSqLength());
	}

	/// <summary>
	/// ベクトルの長さの2乗を取得する
	/// </summary>
	constexpr float GetSqLength() const
	{
		return x * x + y * y + z * z;
	}

	/// <summary>
	/// 正規化したベクトルを取得する
	/// </summary>
	constexpr Vector3 GetNormalize() const
	{
		if (*this == Vector3::Zero)
		{
			assert(false && "Vector3 // 0除算が行われました");
			return Vector3::Zero;
		}

		return *this / GetLength();
	}

	/// <summary>
	/// DxLibのベクトルに変換する
	/// </summary>
	inline VECTOR GetAsDxLibVector() const
	{
		return VGet(x, y, z);
	}

	// 定数

	static const Vector3 Zero;
	static const Vector3 One;
	static const Vector3 XAxis;
	static const Vector3 NegaXAxis;
	static const Vector3 YAxis;
	static const Vector3 NegaYAxis;
	static const Vector3 ZAxis;
	static const Vector3 NegaZAxis;
};
