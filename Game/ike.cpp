#include "stdafx.h"
#include "ike.h"


ike::ike()
{
}


ike::~ike()
{
	DeleteGO(m_skinModelRender);
}

bool ike::Start()
{
	////カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 10.0f, -50.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/banana.cmo");
	m_skinModelRender->SetScale({ 0.03f, 0.03f, 0.03f });
	
	m_position = { 20.0f,-1.0f,-33.0f };

	/*m_position.x -= 10.0f;
	m_position.z = +20.0f;*/
	//座標を設定。
	m_skinModelRender->SetPosition(m_position);
	return true;
}

void ike::Update()
{
	/*m_position.x = -10.0f;
	m_position.z = +20.0f;*/
	//座標を設定。
	m_skinModelRender->SetPosition(m_position);

	float time = 0;
	time = GameTime().GetFrameDeltaTime();
	if (time > 60 && Pad(0).IsPress(enButtonSelect)) {
		DeleteGO(this);
	}
}

void ike::Render(CRenderContext& rc)
{

}
