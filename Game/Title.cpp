#include "stdafx.h"
#include "Title.h"


Title::Title()
{
}


Title::~Title()
{
}

bool Title::Start()
{
	//カメラを設定。
	MainCamera().SetTarget({ 180.0f,50.0f,-20.0f });		//カメラの向き
	MainCamera().SetPosition({ 175.0f,70.0f,-400.0f });	//カメラの位置
	MainCamera().Update();

	//アニメーションクリップのロード。
	m_animClip[enAnimClip_jj].Load(L"animdata/title.tka");
	//スキンモデルレンダラーを作成。
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Title.cmo", m_animClip, enAnimClip_num);
	m_skinModelRender->SetScale({ 5.0f,5.0f,5.0f });
	//なんかようわからんけどループ
	m_animClip[enAnimClip_jj].SetLoopFlag(true);

	return true;
}

void Title::Update()
{

}
