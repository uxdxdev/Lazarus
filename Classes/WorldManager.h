#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

//Includes
#include "Subject.h"
#include "TwitchModel.h"
#include "GameObject.h"


using namespace std;

class WorldManager : public Subject
{
public:
	//Return World Manager instance
	static WorldManager* getInstance();

	//Initialize the World Manager
	bool init();

	//Clean up all resources created by the World Manager
	void cleanUp();
	std::shared_ptr<TwitchModel> getTwitchModel();

	//register gameobject with world manager
	void registerWithWorldManger(std::shared_ptr<gameobject::GameObject> pGameObj){ gameObjects.push_back(pGameObj); }
	vector<std::shared_ptr<gameobject::GameObject>> getGameObects(){
		return gameObjects;
	}

private:
	//Private singleton ctor and dtor
	WorldManager();
	~WorldManager();

	//Static reference for system wide access
	static WorldManager* m_Instance;
	std::shared_ptr<TwitchModel> m_tModel;
	vector<std::shared_ptr<gameobject::GameObject>> gameObjects;


};
#endif