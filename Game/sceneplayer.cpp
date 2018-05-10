#include "stdafx.h"
#include "sceneplayer.h"
#include"koneta1.h"
#include"koneta2.h"
#include "Game.h"



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
	
	/*Camera* m_camera = FindGO<Camera>("Camera");*/

	m_timer += GameTime().GetFrameDeltaTime();

	for (int i = 0; i < m_invokeEventFlags.size(); i++) {
		
		if (/*イベントが起動していなければ*/m_invokeEventFlags[i] == 0) {
			if (m_timer > m_eventDatas[i].invokeTime) {
				//イベントを起動する。
				if (m_eventDatas[i].eventNo == enEventNo_Koneta1) {
					NewGO<koneta1>(0, "koneta1");
				}

				if (m_eventDatas[i].eventNo == enEventNo_Koneta2) {
					NewGO<koneta2>(0, "koneta2");
				}

				if (m_eventDatas[i].eventNo == enEventNo_news) {
					m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
					m_skinModelRender->Init(L"modelData/news.cmo");
					m_skinModelRender->SetScale({ 0.1f, 0.1f, 0.1f });
					m_position = { 0.0f,0.0f,0.0f };
                    m_skinModelRender->SetPosition(m_position);
					//m_skinModelRender->SetModelDrawOnRenderFunction(false);

					

					//テストシーンのインスタンスを検索する。このコードはGameでは使えないので修正する必要がある。
					Game* scene = FindGO<Game>("Game");
					//ディフューズテクスチャを差し替える。
					m_skinModelRender->FindMaterial([&](CModelEffect* material) {
						
						if (material->EqualMaterialName(L"01 - Default") == true) {
							//大ネタのイベントを探す。

							//大ネタのイベントが見つかったら、カメラのタイムスタンプの配列を全部調べて
							for (int j = 0; j < 2; j++) {
								m_camera.timestanp[j];


								/*	if (m_eventDatas[1].invokeTime <= m_camera->timestanp[j] && hantei <= 0)
									{
										hantei = m_camera->timestanp[j] - m_eventDatas[1].invokeTime;
									}
	*/
								hantei = m_camera.timestanp[i] - m_eventDatas[0].invokeTime;

							}

							//その差が一定値以下なら、大ネタ写真を差し替える。
							if (hantei < 5) {
								material->SetDiffuseTexture(scene->m_camera.renderTargets[0].GetRenderTargetSRV().GetBody());
								m_spriteRender = NewGO<prefab::CSpriteRender>(0);
								m_spriteRender->Init(L"sprite/clear.dds", 1280, 720);
							}
						}
						if (material->EqualMaterialName(L"02 - Default") == true) {
							material->SetDiffuseTexture(scene->m_camera.renderTargets[1].GetRenderTargetSRV().GetBody());
						}
						if (material->EqualMaterialName(L"03 - Default") == true) {
							material->SetDiffuseTexture(scene->m_camera.renderTargets[2].GetRenderTargetSRV().GetBody());
						}

						
					});
		
				}
				
				//イベントの起動フラグを1にする。
				m_invokeEventFlags[i] = 1;
			}
		}
	}
}

