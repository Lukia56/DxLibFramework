#include "Box.h"
#include <cassert>

Box::~Box()
{
	assert(false && "Box // デストラクタが呼ばれました");
}

void Box::Init()
{

}

void Box::Finalize()
{
	assert(false && "Box // Finalizeが呼ばれました");
}

void Box::Update()
{

}
