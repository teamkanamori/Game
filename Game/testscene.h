#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "Camera.h"
#include "Fade.h"

class testscene : public IGameObject
{
public:
	testscene();
	~testscene();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	void StartFadeIn()
	{
		m_state = enState_FadeIn;
	}

	enum EnState {
		enState_FadeIn,		//!<フェードイン中。
		enState_FadeOut,		//!<フェードアウト中。
		enState_Idle,		//!<アイドル中。
		enState_InGame
	};

	Fade* m_fade = nullptr;
	EnState m_state = enState_Idle;	//!<状態。
	float m_currentAlpha = 1.0f;		//!<現在のα値。
	CSprite m_sprite;
	CShaderResourceView m_texture;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_position = CVector3::Zero;	//座標。
	CVector3 m_position2 = CVector3::Zero;	//座標。
	CAnimationClip m_animClip[1];							//アニメーションクリップ。
	CAnimation m_animation;
	Camera m_camera;
	CVector3 m_pos = CVector3::Zero;

	float time = 0;
	int flag = 0;


};
