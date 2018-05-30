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

	//À•W‚ðÝ’èB
	m_skinModelRender->SetPosition(m_pos);
	//m_skinModelRender.Update(m_pos, /*m_rotation*/CQuaternion::Identity, CVector3::One);
	//if (m_pos.y <= 50.0f) {
	//	m_pos.y += 1.0f;
	//}
}