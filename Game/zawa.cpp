#include "stdafx.h"
#include "zawa.h"
#include "Game.h"

zawa::zawa()
{
}


zawa::~zawa()
{
	DeleteGO(m_spriteRender);
}

bool zawa::Start()
{
		//スプライトを初期化。
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/zawazawa.dds", 1280, 720);

	return true;
}

void zawa::Update()
{
	time += GameTime().GetFrameDeltaTime();
	if (time > 50) {
		DeleteGO(this);
	}
}