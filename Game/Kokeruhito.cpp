#include "stdafx.h"
#include "Kokeruhito.h"


Kokeruhito::Kokeruhito()
{
}


Kokeruhito::~Kokeruhito()
{
}

bool::Kokeruhito::Start()
{
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(100.0f);
	MainCamera().SetPosition({ 30.0f, 10.0f, 0.0f });
	MainCamera().Update();

	//スキンモデルレンダラーを作成。
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_skinModelRender->SetScale({ 0.1f,0.1f,0.1f });
	return true;
}

void Kokeruhito::Update()
{
}