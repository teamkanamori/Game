#include "stdafx.h"
#include "Game.h"
#include "testscene.h"
#include "Title.h"
#include "Nessie.h"
#include "picture.h"
#include"koneta1.h"
#include "koneta2.h"
#include "sceneplayer.h"
#include"banana.h"
#include "ike.h"
#include"finish.h"




Game::Game()
{
}


Game::~Game()
{

	DeleteGO(m_spriteRender);
}
bool Game::Start()
{	
	m_camera.Start();

	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 50.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(200.0f);
	MainCamera().SetPosition({ 0.0f, 10.0f, -50.0f });
	MainCamera().Update();

	/*m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });*/
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/stage1.cmo");
	m_skinModelRender->SetScale({ 0.15f, 0.15f, 0.15f });
   
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/skydome.cmo");
	m_skinModelRender->SetScale({0.1f, 0.1f, 0.1f });



	
		//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
		//m_skinModelRender->Init(L"modelData/news.cmo");
		//m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
		////newsはPostRenderで描画する。
		//m_skinModelRender->SetModelDrawOnRenderFunction(false);
		
	
	

	//スプライトを初期化。
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Finder.dds", 1280, 720);
	/*m_spriteRender->Init(L"sprite/sky.dds", 1280, 720);*/


	time += GameTime().GetFrameDeltaTime();
	/*NewGO<finish>(0, "finish");*/
	NewGO<banana>(0, "banana");
	NewGO<ike>(0, "ike");
	NewGO<Nessie>(0, "Nessie");
	m_fade = FindGO<Fade>("Fade");
	m_fade->StartFadeIn();
	m_state = enState_FadeIn;

	NewGO<ike>(0, "ike");
	picture* pic1 = NewGO<picture>(0, "picture");
	pic1->m_position.y = 20.0f;
	pic1->m_position.z = -40.0f;
	pic1->m_renderTargetNo = 0;
	picture* pic2 = NewGO<picture>(0, "picture");
	pic2->m_position.y = 13.0f;        
	pic2->m_position.z = -40.0f;                 
	pic2->m_renderTargetNo = 1;                   
	picture* pic3 = NewGO<picture>(0, "picture");
	pic3->m_position.y = 6.0f;
	pic3->m_position.z = -40.0f;
	pic3->m_renderTargetNo = 2;

	EventData eventDataTbl[] = {
		{5.0f, enBigScoop, enEventNo_Koneta1 },
		{30.0f, enMiddleScoop, enEventNo_Koneta2 },
	    {60.0f, enSmallScoop, enEventNo_news },
		/*{3.0f, enEventNo_Koneta1 },*/
	};
	m_sceneplayer.Init(eventDataTbl, sizeof(eventDataTbl) / sizeof(eventDataTbl[0]));
	return true;
}
void Game::Update()
{
	NewGO<Title>(0, "Title");
	DeleteGO(this);
	//スペースキーでテストシーンへ
	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<testscene>(0, "testscene"); 



	
	m_sceneplayer.Update();

	m_camera.Update();

	//m_position = { 0.0f,290.0f,200.0f };
	m_position = { 0.0f,0.0f,0.0f };

	m_spriteRender->SetPosition(m_position);

	switch (m_state) {
	case enState_FadeIn:
		GraphicsEngine().GetTonemap().Reset();
		if (!m_fade->IsFade()) {
			m_state = enState_InGame;
		}
		break;
	case enState_InGame: {
		m_sceneplayer.Update();
		m_waitTimer += GameTime().GetFrameDeltaTime();
		if (m_waitTimer < 0.1f) {
			//ゲームが開始して0.1秒経過するまでトーンマップの明暗順応はやらない。
			GraphicsEngine().GetTonemap().Reset();
		}

		break;
	}

	}
	/*
	m_texture.CreateFromDDSTextureFromFile(L"sprite/Finder.dds");
	m_sprite.Init(m_texture, 1280, 720);



	


	//ワールド行列の更新。
	m_sprite.Update({ 0.0f,0.0f,0.0f }, CQuaternion::Identity, CVector3::One);
	
	m_spriteRender->SetPosition(m_position);*/

}
void Game::Render(CRenderContext& rc)
{
	m_camera.Render(rc);
	
}

