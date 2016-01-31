//Includes
#include <iostream>
#include "WorldManager.h"

WorldManager* WorldManager::m_Instance = 0;

WorldManager* WorldManager::getInstance()
{
	//Create the World Manager and return it
	if (m_Instance == nullptr)
		m_Instance = new WorldManager();
	return m_Instance;
}

WorldManager::WorldManager()
{
	if (!init())
	{
		printf("Failed to initialize WorldManager!\n");
	}
}

WorldManager::~WorldManager()
{
	//Clean up all resources created by the World Manager
	this->cleanUp();
}

bool WorldManager::init()
{
	bool success = true;
	m_tModel = TwitchModel::create();
	this->addObserver(m_tModel.get());

	return success;
}

void WorldManager::cleanUp()
{
	delete m_Instance;
	m_Instance = nullptr;
}

void WorldManager::updateGameObjects(float dt)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->Update(dt);
	}
}

std::shared_ptr<TwitchModel> WorldManager::getTwitchModel()
{
	return m_tModel;
}

void WorldManager::SetGameBoard(BoardLayer *board)
{
	m_GameBoard = board;
}

BoardLayer *WorldManager::GetGameBoard()
{
	return m_GameBoard;
}
