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
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM用のサウンドソース。
	int NFlag = 0;
};