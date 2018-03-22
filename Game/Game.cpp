#include "stdafx.h"
#include "Game.h"
#include "testscene.h"
#include"koneta1.h"


Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{		
	//////カメラを設定。
	//MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	//MainCamera().SetNear(0.1f);
	//MainCamera().SetFar(100.0f);
	//MainCamera().SetPosition({ 30.0f, 10.0f, 0.0f });
	//MainCamera().Update();
	//
	//m_animClip[enAnimClip_slip].Load(L"animData/slip.tka");
	//m_animClip[enAnimClip_wakeup].Load(L"animData/wakeup.tka");
	//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/kokeruhito.cmo", m_animClip, enAnimClip_num, CSkinModel::enFbxUpAxisY);
	//m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f } );
	return true;
}
void Game::Update()
{
	//スペースキーでテストシーンへ
	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<testscene>(0, "testscene");
	}
	//if (Pad(0).IsPress(enButtonA)) {
	//	//Aボタンが押されたrあ。
	//	m_skinModelRender->PlayAnimation(enAnimClip_slip);
	//}
	//if (Pad(0).IsPress(enButtonB)) {
	//	//Bボタンが押されたら。
	//	m_skinModelRender->PlayAnimation(enAnimClip_wakeup);
	//}
}
void Game::Render(CRenderContext& rc)
{
}