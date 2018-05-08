#pragma once

#include "Camera.h"
#include "tkEngine/graphics/effect/tkEffect.h"
#include"sceneplayer.h"
#include "Fade.h"
#include "Camera.h"
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
	prefab::CSpriteRender* m_spriteRender;
	CAnimationClip m_animClip[enAnimClip_num];				//アニメーションクリップ。
	CVector3 m_pos = CVector3::Zero;
	sceneplayer m_sceneplayer;

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
	float m_waitTimer = 0.0f;
	Camera m_camera;
	CVector3 m_position = CVector3::Zero;

	float time = 0;
};

