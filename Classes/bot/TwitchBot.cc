#include "bot/TwitchBot.h"

#include <iostream>
#include <time.h>

#include "cocos2d.h"

namespace bot{

	TwitchBot::TwitchBot(std::string nickname, std::string username, std::string password)
	{
		CCLOG("TwitchBot()");
		m_NetManager = new net::NetManager();
		m_strNickname = nickname;
		m_strUsername = username;
		m_strPassword = password;
		m_cSendBuffer[0] = '\0';
		m_cRecvBuffer[0] = '\0';
	}

	TwitchBot::~TwitchBot()
	{

	}

	void TwitchBot::Start()
	{		
		m_NetManager->Init("irc.twitch.tv", "6667");
		LoginToChatServer();

		JoinChannel("JOIN #damortonx\r\n");
	}

	void TwitchBot::LoginToChatServer()
	{
		// Send login details after connecting to the server
		sprintf(m_cSendBuffer, "%s", m_strPassword.c_str());
		m_NetManager->SendData(m_cSendBuffer);

		sprintf(m_cSendBuffer, "%s", m_strUsername.c_str());
		m_NetManager->SendData(m_cSendBuffer);

		sprintf(m_cSendBuffer, "%s", m_strNickname.c_str());
		m_NetManager->SendData(m_cSendBuffer);				
	}

	void TwitchBot::JoinChannel(std::string channel)
	{
		sprintf(m_cSendBuffer, "%s", channel.c_str());
		m_NetManager->SendData(m_cSendBuffer);			
	}

	char *TwitchBot::TimeNow()
	{
		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		return asctime(timeinfo);
	}

	void TwitchBot::Update()
	{
		if (m_NetManager->GetState() == net::NetManager::CONNECTED)
		{
			m_NetManager->ReadData(m_cRecvBuffer, MAX_BUFFER_SIZE);
			ProcessMsg();
		}		
	}

	void TwitchBot::ProcessMsg()
	{
		std::cout << "ProcessMsg()" << std::endl;

		if (strstr(m_cRecvBuffer, "PING"))
		{
			sprintf(m_cSendBuffer, "%s", "PONG :tmi.twitch.tv");
			m_NetManager->SendData(m_cSendBuffer);			
		}

		if (strstr(m_cRecvBuffer, "chant"))
		{
			// Create event
			CCLOG("Hail Helix");
		}		

		m_NetManager->ClearBuffer(m_cRecvBuffer);
	}
}
