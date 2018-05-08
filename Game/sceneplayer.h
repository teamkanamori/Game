#pragma once

enum EnEventNo {
	enEventNo_Koneta1,
	enEventNo_Koneta2,
	enEventNo_news,
};
struct EventData {
	float invokeTime;		//イベント発生時間。
	EnEventNo eventNo;		//イベント番号。
};
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
};



//sceneplayer m_sceneplayer;




