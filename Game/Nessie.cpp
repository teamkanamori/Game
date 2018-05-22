#include "stdafx.h"
#include "Nessie.h"


Nessie::Nessie()
{
}


Nessie::~Nessie()
{
}

bool Nessie::Start()
{

	//カメラを設定。
	//MainCamera().SetTarget({ 0.0f, 10.0f, 0.0f });
	//MainCamera().SetNear(0.1f);
	//MainCamera().SetFar(100.0f);
	//MainCamera().SetPosition({ 30.0f, 40.0f, 20.0f });

	////カメラを設定。
	//MainCamera().SetTarget({ 0.0f, 10.0f, 50.0f });
	//MainCamera().SetNear(0.1f);
	//MainCamera().SetFar(100.0f);
	//MainCamera().SetPosition({ 0.0f, 10.0f, -50.0f });
	//MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Nessie.cmo");
	m_skinModelRender->SetScale({ 0.3f, 0.3f, 0.3f });


	m_pos = { 0.0f,-20.0f,0.0f };
	return true;
}
void Nessie::Update()
{
	
	if(NFlag == 1){
		m_pos.y -= 0.5f;
	}
	else{
		m_pos.y += 0.5f;
	}
	if (m_pos.y > -1.5f) {
		NFlag = 1;
	}


	//座標を設定。
	m_skinModelRender->SetPosition(m_pos);
	//m_skinModelRender.Update(m_pos, /*m_rotation*/CQuaternion::Identity, CVector3::One);
	//if (m_pos.y <= 50.0f) {
	//	m_pos.y += 1.0f;
	//}
}
//void Nessie::Render(CRenderContext& rc)
//{
//}