#include "stdafx.h"
#include "Game.h"
#include "testscene.h"
#include "Nessie.h"


Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	
	
	

	

	////カメラを設定。
	//MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	//MainCamera().SetNear(0.1f);
	//MainCamera().SetFar(100.0f);
	//MainCamera().SetPosition({ 30.0f, 10.0f, 0.0f });
	//MainCamera().Update();
	//
	// m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/unityChan.cmo");
	//m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f } );
	return true;
}
void Game::Update()
{
	//スペースキーでテストシーンへ
	if (Pad(0).IsPress(enButtonSelect)) {
		//NewGO<testscene>(0, "testscene");
		NewGO<Nessie>(0, "Nessie");
	}
}
void Game::Render(CRenderContext& rc)
{
}