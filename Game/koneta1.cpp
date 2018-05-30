#include "stdafx.h"
#include "koneta1.h"
#include"banana.h"



koneta1::koneta1()
{
	DeleteGO(m_skinModelRender);
}


koneta1::~koneta1()
{
}

bool koneta1::Start()
{
	m_pos = { 0.0f,2.0f,-10.0f };

	m_animClip[enAnimClip_idle].Load(L"animData/idle.tka");
	m_animClip[enAnimClip_slip].Load(L"animData/slip.tka");
	m_animClip[enAnimClip_wakeup].Load(L"animData/wakeup.tka");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/kokeruhito.cmo", m_animClip, enAnimClip_num);
	m_skinModelRender->SetScale({ 0.03f, 0.03f, 0.03f });
	return true;
}

void koneta1::Update()
{
	m_pos.z -= 0.1f;
	
	//À•W‚ðÝ’èB
	m_skinModelRender->SetPosition(m_pos);

	banana*gl = FindGO<banana>("banana");
	CVector3 diff = CVector3::Zero;
	diff.z = m_pos.z - gl->m_position.z;
	if (diff.Length() <= 1.0f)
	{
		if (flag == 1) {
			return;
		}
			m_skinModelRender->PlayAnimation(enAnimClip_slip);

		flag = 1;
	}

	float time = 0;
	time = GameTime().GetFrameDeltaTime();
	if (time > 60 && Pad(0).IsPress(enButtonSelect)) {
		DeleteGO(this);
	}
}
