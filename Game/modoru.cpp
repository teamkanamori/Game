#include "stdafx.h"
#include "modoru.h"


modoru::modoru()
{
}


modoru::~modoru()
{
	DeleteGO(game);

}

bool modoru::Start()
{
	game = FindGO<Game>("Game");

	
	return true;
}

void modoru::Update()
{
	if (game->m_sceneplayer.modoruFlag == 1) {
		
		DeleteGO(this);
	}
}