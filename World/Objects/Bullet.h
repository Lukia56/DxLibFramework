#pragma once

#include "../GameObject.h"

class Bullet : public GameObject
{
public:

	Bullet() = default;
	~Bullet();

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

