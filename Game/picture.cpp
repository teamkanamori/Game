#include "stdafx.h"
#include "picture.h"
#include "Game.h"

picture::picture()
{
}


picture::~picture()
{
	DeleteGO(m_skinModelRender);

}


bool picture::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/picture.cmo");
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->Set2Dcamera(1);
	scene = FindGO<Game>("Game");
    return true;
}

void picture::Update()
{
	//テストシーンのインスタンスを検索する。このコードはGameでは使えないので修正する必要がある。

	//ディフューズテクスチャを差し替える。
	if (scene != NULL) {
		m_skinModelRender->SetOverrideDiffuseTexture(scene->m_camera.renderTargets[m_renderTargetNo].GetRenderTargetSRV().GetBody());
	}
	
	float time = 0;
	time = GameTime().GetFrameDeltaTime();
	if (Pad(0).IsPress(enButtonSelect)) {
		DeleteGO(this);
	}

}

void picture::Render(CRenderContext& rc)
{

}