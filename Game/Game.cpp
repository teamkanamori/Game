#include "stdafx.h"
#include "Game.h"
#include "testscene.h"
#include "Nessie.h"
#include"koneta1.h"


Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{		
	return true;
}
void Game::Update()
{
	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<testscene>(0, "testscene");
		//NewGO<Nessie>(0, "Nessie");
	}

	/*if (Pad(0).IsPress(enButtonA)) {
		DeleteGO(this);
	 }*/

	 //スペースキーでテストシーンへ

	 //if (Pad(0).IsPress(enButtonSelect)) {
	 //	NewGO<testscene>(0, "testscene");
	 //}
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