#include "stdafx.h"
#include "testscene.h"
#include"koneta1.h"
#include"banana.h"
#include"koneta2.h"
#include"ike.h"
#include "Fade.h"

#include"Nessie.h"
#include"picture.h"
#include "finish.h"
//テストシーンでフェイドインさせる。

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
	MainCamera().SetPosition({ 30.0f, 10.0f, -50.0f });
	MainCamera().Update();

	/*m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });*/
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/stage1.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });

	//スプライトを初期化。
	/*m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/sky.dds", 1280, 720);*/
	

	time += GameTime().GetFrameDeltaTime();
	//シーンプレイヤーを使うとき、
	//timeに　＝＝の文は使えない
	// if(time > 1 &&  一度も再生されていないというflgが必要)
	
	NewGO<koneta1>(0, "koneta1");
	NewGO<banana>(0, "banana");
    NewGO<koneta2>(0, "koneta2");
		
	NewGO<ike>(0, "ike");

	NewGO<Nessie>(0, "Nessie");

	picture* pic1 = NewGO<picture>(0, "picture");
	pic1->m_position.y = 23.0f;
	pic1->m_position.z = 24.0f;
	pic1->m_renderTargetNo = 0;
	picture* pic2 = NewGO<picture>(0, "picture");
	pic2->m_position.y = 16.0f;
	pic2->m_position.z = 24.0f;
	pic2->m_renderTargetNo = 1;
	picture* pic3 = NewGO<picture>(0, "picture");
	pic3->m_position.y = 9.0f;
	pic3->m_position.z = 24.0f;
	pic3->m_renderTargetNo = 2;


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

m_camera.Update();

m_position = { 0.0f,290.0f,200.0f };
   
   m_spriteRender->SetPosition(m_position);


	GraphicsEngine().GetTonemap().Reset();
	if (!m_fade->IsFade()) {
		m_state = enState_InGame;
	}

	
}

void testscene::Render(CRenderContext& rc)
{
	m_camera.Render(rc);
	///*if (m_currentAlpha > 0.0f) {
	//	m_sprite.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
	//	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetViewProjectionMatrix());
	//}*/
}
