#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "NetaBase.h"

class Nessie : public NetaBase
{
public:
	Nessie();
	~Nessie();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	int NFlag = 0;
};