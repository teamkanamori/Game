#include "stdafx.h"
#include "testscene.h"
#include"koneta1.h"
<<<<<<< HEAD
#include"banana.h"
#include"koneta2.h"
#include"ike.h"
=======
#include "Fade.h"
//テストシーンでフェイドインさせる。
>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b

testscene::testscene()
{
}


testscene::~testscene()
{
}


bool testscene::Start()
{
	m_camera.Start();

	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 40.0f, 20.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
<<<<<<< HEAD

	NewGO<koneta1>(0, "koneta1");
	NewGO<banana>(0, "banana");
	NewGO<koneta2>(0, "koneta2");
	NewGO<ike>(0, "ike");
=======
	
	
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

		

>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b
	return true;
}
void testscene::Update()
{
<<<<<<< HEAD
	m_camera.Update();
=======
enState_FadeIn:
	GraphicsEngine().GetTonemap().Reset();
	if (!m_fade->IsFade()) {
		m_state = enState_InGame;
	}
>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b
}

void testscene::Render(CRenderContext& rc)
{
<<<<<<< HEAD
	m_camera.Render(rc);
=======
	///*if (m_currentAlpha > 0.0f) {
	//	m_sprite.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
	//	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetViewProjectionMatrix());
	//}*/
>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b
}
