#include "Resource.h"
#include <DxLib.h>

void Texture::Delete()
{
	DeleteGraph(mHandle);
}
