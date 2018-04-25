#include "stdafx.h"
#include "banana.h"


banana::banana()
{
}


banana::~banana()
{
}

bool banana::Start()
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
	m_position = { 0.0f,0.0f,-40.0f };
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
}

void banana::Render(CRenderContext& rc)
{

}