#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

//Includes
#include "Subject.h"
#include "TwitchModel.h"

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


private:
	//Private singleton ctor and dtor
	WorldManager();
	~WorldManager();

	//Static reference for system wide access
	static WorldManager* m_Instance;
	std::shared_ptr<TwitchModel> m_tModel;


};
#endif