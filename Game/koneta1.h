#pragma once
#include"NetaBase.h"

class koneta1 : public NetaBase
{
public:
	koneta1();
	~koneta1();
	bool Start();
	void Update();
	enum EnAnimClip {
		enAnimClip_idle,        //待機アニメーション。
		enAnimClip_slip,		//コケるモーション
		enAnimClip_wakeup,		//起き上がりモーション。
		enAnimClip_num,			//アニメーションデータの数。
	};
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CAnimationClip m_animClip[enAnimClip_num];				//アニメーションクリップ。
	int flag = 0;
};

