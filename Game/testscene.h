#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "Camera.h"

class testscene : public IGameObject
{
public:
	testscene();
	~testscene();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CAnimationClip m_animClip[1];							//アニメーションクリップ。
	CAnimation m_animation;
	Camera m_camera;
	CVector3 m_pos = CVector3::Zero;
};
