#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

class Game : public IGameObject
{
public:
	enum EnAnimClip {
		enAnimClip_slip,		//コケるモーション
		enAnimClip_wakeup,		//起き上がりモーション。
		enAnimClip_num,			//アニメーションデータの数。
	};
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CAnimationClip m_animClip[enAnimClip_num];				//アニメーションクリップ。
	CVector3 m_pos = CVector3::Zero;
};

