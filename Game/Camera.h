#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

class error;

class Camera : public IGameObject
{
public:
	struct SShutterData {
		float time;				//シャッターが押された時間。
		bool isExistNeta[3];	//ネタが発生しているかどうかのフラグ。
		CVector3 netaPos[3];	//ネタの座標。
		CMatrix mView;			//シャッターを押したときのカメラ行列。
	};
	Camera();
	~Camera();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	float time = 0;
	//float timestanp[3];
	SShutterData shutterData[3];
	int shattercount = 0;
	CRenderTarget renderTargets[3];
	CSprite m_sprite;	//シーンをペタッと張り付けるためのスプライト
	int flag = 0;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM用のサウンドソース。
	CVector3 m_pos = CVector3::Zero;
	
};