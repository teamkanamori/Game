#include "stdafx.h"
#include "error.h"
#include "Camera.h"


error::error()
{
}


error::~error()
{
	DeleteGO(m_spriteRender);
}

bool error::Start() {

	//スプライトを初期化。
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/error.dds", 1280, 720);

	return true;
}
void error::Update() {
	if (Pad(0).IsPress(enButtonA)) {
		DeleteGO(this);
	}
}
