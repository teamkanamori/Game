#pragma once
#include "Game.h"
#include "sceneplayer.h"
class modoru:public IGameObject
{
public:
	modoru();
	~modoru();
	bool Start();
	void Update();
	Game *game = nullptr;
	sceneplayer m_sceneplayer;
};

