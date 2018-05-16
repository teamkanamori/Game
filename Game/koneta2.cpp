#include "stdafx.h"
#include "koneta2.h"
#include"ike.h"


koneta2::koneta2()
{
}


koneta2::~koneta2()
{
}

bool koneta2::Start()
{
	m_animClip[enAnimClip_idle].Load(L"animData/idle.tka");
	m_animClip[enAnimClip_slip].Load(L"animData/slip.tka");
	m_animClip[enAnimClip_wakeup].Load(L"animData/wakeup.tka");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/kokeruhito.cmo", m_animClip, enAnimClip_num);
	m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });

	m_position = { -30.0f,0.0f,-30.0f };

	return true;

}

void koneta2::Update()
{

	m_position.x = +20.0f;
	m_position.z -= 0.1f;

	//À•W‚ðÝ’èB
	m_skinModelRender->SetPosition(m_position);

	ike*gl = FindGO<ike>("ike");
	CVector3 diff = CVector3::Zero;
	diff.z = m_position.z - gl->m_position.z;
	if (diff.Length() <= 1.0f)
	{
		if (flag == 1) {
			return;
		}
		m_skinModelRender->PlayAnimation(enAnimClip_slip);

		m_position.y -= 5.0f;

		flag = 1;
	}
}

void koneta2::Render(CRenderContext& rc)
{

}