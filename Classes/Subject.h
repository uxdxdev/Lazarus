#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_OBSERVERS 5
/*
Subject.h
Subject contains an array of registered observers
@author	David Morton K00179391, Tommaso Marenzi k00180522
@date	17.4.15
*/
//Includes
#include "Observer.h"
#include <vector>

class Subject
{
private:
	// Vector of registered observers
	std::vector<Observer*> m_AObservers;

public:

	void notify(cocos2d::Node* entity, cocos2d::EventCustom* event)
	{
		// Walk the array and notify each observer
		for (int i = 0; i < m_AObservers.size; i++)
		{
			m_AObservers[i]->onNotify(entity, event);
		}
	}

	// Register an observer
	void addObserver(Observer* observer)
	{
			m_AObservers.push_back(observer);
	}

	// Remove an observer
	void removeObserver(Observer* observer)
	{
		for (int i = 0; i < m_AObservers.size; i++)
		{
			if (m_AObservers[i] == observer)
			{
				m_AObservers.erase(m_AObservers.begin() + i);
			}
		}
	}

};

#endif