#include "stdafx.h"
#include "selectstage.h"
#include "Game.h"


selectstage::selectstage()
{
}


selectstage::~selectstage()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_spriteRender1);
	DeleteGO(m_spriteRender2);
	DeleteGO(m_spriteRender3);
	DeleteGO(m_spriteRender4);
	
	
}

bool selectstage::Start() {
	m_spriteRender1 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender1->Init(L"sprite/key.dds", 400, 250);

	m_position = { 0.0f,40.0f,0.0f };
	m_spriteRender1->SetPosition(m_position);

	m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/key.dds", 400, 250);

	m_position = { 425.0f,40.0f,0.0f };
	m_spriteRender2->SetPosition(m_position);

	m_spriteRender3 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender3->Init(L"sprite/key.dds", 350, 200);

	m_position = { -268.0f,-270.0f,0.0f };
	m_spriteRender3->SetPosition(m_position);

	m_spriteRender4 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender4->Init(L"sprite/key_gold.dds", 350, 200);

	m_position = { 214.0f,-270.0f,0.0f };
	m_spriteRender4->SetPosition(m_position);

	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	//スキンモデルレンダラーを作成。
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/StageSelect.cmo");


	m_fade = FindGO<Fade>("Fade");
	m_fade->StartFadeIn();
	m_state = enState_FadeIn;

	return true;
}

void selectstage::Update() 
{

	
	if (m_isWaitFadeout) {
		if (!m_fade->IsFade()) {
			
			 NewGO<Game>(0, "Game");
			DeleteGO(this);
		}
	}
	else {
		if (Pad(0).IsPress(enButtonA)) {
			m_isWaitFadeout = true;
			m_fade->StartFadeOut();

		}
	}

	switch (m_state) {
	case enState_FadeIn:
		GraphicsEngine().GetTonemap().Reset();
		if (!m_fade->IsFade()) {
			m_state = enState_InGame;
		}
		break;
	case enState_InGame: {
		m_waitTimer += GameTime().GetFrameDeltaTime();
		if (m_waitTimer < 0.1f) {
			//ゲームが開始して0.1秒経過するまでトーンマップの明暗順応はやらない。
			GraphicsEngine().GetTonemap().Reset();
		}

		break;
	}

	}
}