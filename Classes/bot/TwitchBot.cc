#include "bot/TwitchBot.h"

#include <cstring>

#include <iostream>
#include <time.h>

#include "cocos2d.h"

namespace bot{

	TwitchBot::TwitchBot(std::string nickname, std::string username, std::string password)
	{
		CCLOG("TwitchBot()");
		std::unique_ptr<net::NetManager> netManager(new net::NetManager());
		m_NetManager = std::move(netManager);
		m_strNickname = nickname;
		m_strUsername = username;
		m_strPassword = password;
		m_cSendBuffer[0] = '\0';
		m_cRecvBuffer[0] = '\0';

		Start();
	}

	TwitchBot::~TwitchBot()
	{
	}

	void TwitchBot::Start()
	{		
		//m_NetManager->Init("irc.twitch.tv", "6667");
		m_NetManager->Init("localhost", "27000");
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

	void TwitchBot::Update()
	{
		m_NetManager->ReadData(m_cRecvBuffer, MAX_BUFFER_SIZE);
		if (m_NetManager->GetState() == net::NetManager::CONNECTED)
		{			
			ProcessMsg();
		}		
	}

	void TwitchBot::ProcessMsg()
	{
		// Needed by the twitch server
		if (strstr(m_cRecvBuffer, "PING"))
		{
			sprintf(m_cSendBuffer, "%s", "PONG :tmi.twitch.tv");
			m_NetManager->SendData(m_cSendBuffer);			
		}
		
		// Game commands
		if (strstr(m_cRecvBuffer, "!chant"))
		{
			// Create event
			CCLOG("Hail Helix!....or Dome, depends....");
		}	

		if (strstr(m_cRecvBuffer, "!tower"))
		{
			// Create event
			CCLOG("BUILD DA TOWERS!!");
		}

		if (strstr(m_cRecvBuffer, "!attack"))
		{
			// Create event
			CCLOG("ZAP! ZAP! ZAP!");
		}

		if (strstr(m_cRecvBuffer, "!up"))
		{
			// Create event
			CCLOG("Moving target up");
		}

		if (strstr(m_cRecvBuffer, "!down"))
		{
			// Create event
			CCLOG("Moving target down");
		}
		
		if (strcmp(m_cRecvBuffer, "0") != 0)
		{
			std::string message(m_cRecvBuffer);
			std::size_t start = message.find(":");			
			std::size_t end = message.find("!");

			if (start != std::string::npos && end != std::string::npos && end > start)
			{
				std::string username = message.substr(start + 1, end - start);	
				username[end - start - 1] = '\0';
				CCLOG("Username : %s", username.c_str());
			}			
		}		

		// Add more commands

	}
}
