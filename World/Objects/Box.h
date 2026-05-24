#pragma once

#include "../GameObject.h"

class Box : public GameObject
{
public:

	Box() = default;
	~Box();

	/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	void Init() override;

	/// <summary>
	/// XVˆ—
	/// </summary>
	void Update() override;
};

