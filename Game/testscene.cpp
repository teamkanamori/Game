#include "stdafx.h"
#include "testscene.h"
#include"koneta1.h"
#include "Fade.h"
//テストシーンでフェイドインさせる。

testscene::testscene()
{
}


testscene::~testscene()
{
}


bool testscene::Start()
{
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 40.0f, 20.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
	
	
	NewGO<koneta1>(0, "koneta1");

	m_texture.CreateFromDDSTextureFromFile(L"sprite/fade.dds");
	m_sprite.Init(
		m_texture,
		GraphicsEngine().GetFrameBufferWidth(),
		GraphicsEngine().GetFrameBufferHeight());

	m_fade = FindGO<Fade>("Fade");
	m_fade->StartFadeIn();
	m_state = enState_FadeIn;

//enState_FadeIn:
//		m_currentAlpha -= 2.0f * GameTime().GetFrameDeltaTime();
//		if (m_currentAlpha <= 0.0f) {
//			m_currentAlpha = 0.0f;
//			m_state = enState_Idle;
//		}

		

	return true;
}
void testscene::Update()
{
enState_FadeIn:
	GraphicsEngine().GetTonemap().Reset();
	if (!m_fade->IsFade()) {
		m_state = enState_InGame;
	}
}

void testscene::Render(CRenderContext& rc)
{
	///*if (m_currentAlpha > 0.0f) {
	//	m_sprite.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
	//	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetViewProjectionMatrix());
	//}*/
}
