#include "stdafx.h"
#include "ike.h"


ike::ike()
{
}


ike::~ike()
{
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
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
	
	m_position = { 20.0f,0.0f,-35.0f };

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
}

void ike::Render(CRenderContext& rc)
{

}
