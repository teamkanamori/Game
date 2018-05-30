#include "stdafx.h"
#include "banana.h"


banana::banana()
{
}


banana::~banana()
{
	DeleteGO(m_skinModelRender);
}

bool banana::Start()
{
	////カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 10.0f, 10.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/banana.cmo");
	m_skinModelRender->SetScale({ 0.03f, 0.03f, 0.03f });
	m_position = { 0.0f,1.0f,-15.0f };
	/*m_position.z = +20.0f;*/
	//座標を設定。
	m_skinModelRender->SetPosition(m_position);
	return true;
}

void banana::Update()
{
	/*m_position.z = -20.0f;*/
	//座標を設定。
	m_skinModelRender->SetPosition(m_position);

	float time = 0;
	time = GameTime().GetFrameDeltaTime();
	if (time > 60 && Pad(0).IsPress(enButtonSelect)) {
		DeleteGO(this);
	}
}

void banana::Render(CRenderContext& rc)
{

}