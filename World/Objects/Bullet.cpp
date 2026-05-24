#include "Bullet.h"
#include <cassert>
#include <memory>
#include "../Objects/Box.h"

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	for (int i = 0; i < 1; i++)
	{
		Add(std::make_unique<Box>());
	}
}

void Bullet::Finalize()
{
}

void Bullet::Update()
{
}
