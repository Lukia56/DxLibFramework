#pragma once

#include <random>

/// <summary>
/// 乱数を生成するクラス
/// </summary>
class Random
{
public:

	/// <summary>
	/// 初期化処理
	/// </summary>
	static void Init();

	/// <summary>
	/// 引数の範囲内での整数乱数を生成（引数を含む）
	/// </summary>
	/// <param name="min">最小値</param>
	/// <param name="max">最大値</param>
	template <std::integral T>
	static T Get(T min, T max);

	/// <summary>
	/// 引数の範囲内での実数乱数を生成（引数を含む）
	/// </summary>
	/// <param name="min">最小値</param>
	/// <param name="max">最大値</param>
	template <std::floating_point T>
	static T Get(T min, T max);

	/// <summary>
	/// 0.0～1.0の実数の乱数生成
	/// </summary>
	static float Get0To1();

	/// <summary>
	/// 確率判定
	/// </summary>
	/// <param name="percent">確率0～100</param>
	/// <returns>確率内ならtrue</returns>
	static bool Judge(float percent);

private:

	/// <summary>
	/// 乱数を生成する
	/// </summary>
	static std::mt19937& Engine();
};

template<std::integral T>
inline T Random::Get(T min, T max)
{
	std::uniform_int_distribution<T> dist(min, max);
	return dist(Engine());
}

template<std::floating_point T>
inline T Random::Get(T min, T max)
{
	std::uniform_real_distribution<T> dist(min, max);
	return dist(Engine());
}
