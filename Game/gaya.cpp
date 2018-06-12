#include "stdafx.h"
#include "gaya.h"


gaya::gaya()
{
}


gaya::~gaya()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_skinModelRender2);
	DeleteGO(m_skinModelRender3);
}

bool gaya::Start() {
	
	m_animClip[enAnimClip_walk].Load(L"animData/chara1.walk.tka");
	m_animClip[enAnimClip_walk].SetLoopFlag(true);
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/chara1.cmo",m_animClip,enAnimClip_num);
	m_skinModelRender->SetScale({ 0.03f, 0.03f, 0.03f });
	m_position = { 20.0f,1.8f,-10.0f };
	m_skinModelRender->SetPosition(m_position);

	m_animClip[enAnimClip_walk].Load(L"animData/chara5.walk.tka");
	m_animClip[enAnimClip_walk].SetLoopFlag(true);
	m_skinModelRender2 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender2->Init(L"modelData/chara5.cmo",m_animClip,enAnimClip_num);
	m_skinModelRender2->SetScale({ 0.03f, 0.03f, 0.03f });
	m_position2 = { -10.0f,1.8f,5.0f };
	m_skinModelRender2->SetPosition(m_position2);

	m_animClip[enAnimClip_walk].Load(L"animData/chara2.walk.tka");
	m_animClip[enAnimClip_walk].SetLoopFlag(true);
	m_skinModelRender3 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender3->Init(L"modelData/chara2.cmo");
	m_skinModelRender3->SetScale({ 0.03f, 0.03f, 0.03f });
	m_position3 = { 13.0f,4.7f,11.0f };
	m_skinModelRender3->SetPosition(m_position3);

	return true;
}

void gaya::Update() 
{
	
		
	CQuaternion qRot = CQuaternion::Identity;
		if (returnFlag == 0) {
			m_position.x += 0.1f;
			m_rotation.SetRotationDeg(CVector3::AxisY, 90.0f);
			m_rotation.Multiply(qRot);
		}
		if (m_position.x > 15.0f) {
			returnFlag = 1;
		}
		if (m_position.x < 1.0f) {
			returnFlag = 0;

		}
		if (returnFlag == 1) {
			m_position.x -= 0.1f;
			m_rotation.SetRotationDeg(CVector3::AxisY, -90.0f);
			m_rotation.Multiply(qRot);
		}

		m_rotation.SetRotationDeg(CVector3::AxisX, 90.0f);
		m_skinModelRender->SetRotation(m_rotation);
		m_skinModelRender->SetPosition(m_position);


		m_rotation2.SetRotationDeg(CVector3::AxisX, 180.0f);
	
		m_skinModelRender2->SetRotation(m_rotation2);
		m_skinModelRender2->SetPosition(m_position2);

		qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
		m_rotation3.Multiply(qRot);
		m_skinModelRender3->SetRotation(m_rotation3);

	
	
    float time = 0;
	time = GameTime().GetFrameDeltaTime();
	if (time > 60 && Pad(0).IsPress(enButtonSelect)) {
		DeleteGO(this);
	}

}
