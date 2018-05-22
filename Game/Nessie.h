#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

class Nessie : public IGameObject
{
public:
	Nessie();
	~Nessie();
	bool Start();
	void Update();
	/*void Render(CRenderContext& rc);*/
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。

	CVector3 m_pos = CVector3::Zero;
	int NFlag = 0;
};

