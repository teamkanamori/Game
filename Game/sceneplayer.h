#pragma once
#include "Camera.h"

enum EnEventNo {
	enEventNo_Koneta1,
	enEventNo_Koneta2,
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
	std::vector<EventData> m_eventDatas ;	//!<イベントデータ。
	std::vector<int> m_invokeEventFlags;	//!<イベント起動フラグ。
	float m_timer = 0.0f;					//!<タイマー。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_position = CVector3::Zero;
	int m_renderTargetNo = 0;
    
	Camera m_camera;
	float hantei = 6;
	
	
};





//sceneplayer m_sceneplayer;




