#include "stdafx.h"
#include "Game.h"
<<<<<<< HEAD
#include "testscene.h"

=======
//#include "testscene.h"
#include"koneta1.h"
>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b


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
	
	/*if (Pad(0).IsPress(enButtonA)) {
		DeleteGO(this);
     }*/

	//スペースキーでテストシーンへ
<<<<<<< HEAD
	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<testscene>(0, "testscene");
		DeleteGO(this);
	}
=======
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
>>>>>>> dae8e8d0d75ec67f4530fa746ae4d112d9ce492b
}
void Game::Render(CRenderContext& rc)
{
}