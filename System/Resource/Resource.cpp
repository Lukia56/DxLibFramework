#include "Resource.h"
#include <DxLib.h>

void Texture::Delete()
{
	DeleteGraph(mHandle);
}

void Model::Delete()
{
	MV1DeleteModel(mHandle);
}
