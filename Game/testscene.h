#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
<<<<<<< HEAD
#include "Camera.h"

=======
#include "Fade.h"
>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b
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
	CAnimationClip m_animClip[1];							//アニメーションクリップ。
	CAnimation m_animation;
	Camera m_camera;
	CVector3 m_pos = CVector3::Zero;
};
