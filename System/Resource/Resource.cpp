#include "Resource.h"
#include <DxLib.h>
#include "../ResourceManager.h"

void Texture::Load(const std::string& path)
{
	mHandle = LoadGraph(path.c_str());
}

void Texture::Delete()
{
	DeleteGraph(mHandle);
}

void Model::Load(const std::string& path)
{
	mHandle = MV1LoadModel(path.c_str());
}

void Model::Delete()
{
	MV1DeleteModel(mHandle);
}

void Sound::Load(const std::string& path)
{
	mHandle = LoadSoundMem(path.c_str());
}

void Sound::Delete()
{
	DeleteSoundMem(mHandle);
}

void Font::Load(const std::string& path)
{
	mHandle = LoadFontDataToHandle(path.c_str());
}

void Font::Delete()
{
	DeleteFontToHandle(mHandle);
}
