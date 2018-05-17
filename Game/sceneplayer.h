#pragma once
#include "Camera.h"

enum EnEventNo {
	enEventNo_Koneta1,
	enEventNo_Koneta2,
	enEventNo_Nessie,
	enEventNo_news,
};
enum EnScoopLevel {
	enBigScoop,		//大ネタ,
	enMiddleScoop,	//中ネタ,
	enSmallScoop,	//小ネタ,
};
struct EventData {
	float invokeTime;		//イベント発生時間。
	EnScoopLevel netaLevel;	//スクープのレベル。
	EnEventNo eventNo;		//イベント番号。
};
class Camera;
class sceneplayer : public IGameObject
{
public:
	sceneplayer();
	~sceneplayer();
	void Update();
	void Init(EventData* eventDataTbl, int numEventData);

private:
	std::vector<EventData> m_eventDatas;	//!<イベントデータ。
	std::vector<int> m_invokeEventFlags;	//!<イベント起動フラグ。
	float m_timer = 0.0f;					//!<タイマー。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_position = CVector3::Zero;
	int m_renderTargetNo = 0;

	Camera m_camera;
	float hantei0 = 0;
	float hantei1 = 0;
	float hantei2 = 0;
	float timestanp0 = 0;
	float timestanp1 = 0;
	float timestanp2 = 0;

	float Smallhantei0 = 0;
	float Smallhantei1 = 0;
	float Smallhantei2 = 0;
	float Smalltimestanp0 = 0;
	float Smalltimestanp1 = 0;
	float Smalltimestanp2 = 0;

	float midlehantei0 = 0;
	float midlehantei1 = 0;
	float midlehantei2 = 0;
	float midletimestanp0 = 0;
	float midletimestanp1 = 0;
	float midletimestanp2 = 0;

};





//sceneplayer m_sceneplayer;




