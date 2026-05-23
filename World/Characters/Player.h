#pragma once

#include "../GameObject.h"

class Player : public GameObject
{
public:

	Player() = default;
	~Player();

	/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	void Init() override;

	/// <summary>
	/// I—¹ˆ—
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// XVˆ—
	/// </summary>
	void Update() override;
};
