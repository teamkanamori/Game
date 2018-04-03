#include "stdafx.h"
#include "Game.h"
#include "testscene.h"



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
	//スペースキーでテストシーンへ
	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<testscene>(0, "testscene");
		DeleteGO(this);
	}
}
void Game::Render(CRenderContext& rc)
{
}