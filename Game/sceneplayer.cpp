#include "stdafx.h"
#include "sceneplayer.h"
#include"koneta1.h"
#include"koneta2.h"




sceneplayer::sceneplayer()
{
}


sceneplayer::~sceneplayer()
{
}

void sceneplayer::Init(EventData* eventDataTbl, int numEventData)
{
	m_eventDatas.resize(numEventData);
	m_invokeEventFlags.resize(numEventData);
	
	for (int i = 0; i < m_invokeEventFlags.size(); i++) {
		//イベント起動フラグはすべて0にする。
		m_invokeEventFlags[i] = 0;
		m_eventDatas[i] = eventDataTbl[i];
		
	}
}

void sceneplayer::Update() 
{	
	m_timer += GameTime().GetFrameDeltaTime();

	for (int i = 0; i < m_invokeEventFlags.size(); i++) {
		
		if (/*イベントが起動していなければ*/m_invokeEventFlags[i] == 0) {
			if (m_timer>m_eventDatas[i].invokeTime/*m_timerがイベントの起動時間よりも大きくなっている*/) {
				//イベントを起動する。
				if (m_timer > 5&& m_timer<30) {
					NewGO<koneta1>(0, "koneta1");
				}

				if (m_timer > 30&& m_timer<60) {
					NewGO<koneta2>(0, "koneta2");
				}

				if (m_timer > 60) {
					
					m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
					m_skinModelRender->Init(L"modelData/news.cmo");
					m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
					//m_skinModelRender->SetModelDrawOnRenderFunction(false);
				}


				
				//イベントの起動フラグを1にする。
				m_invokeEventFlags[i] = 1;
			}
		}
	}
}

