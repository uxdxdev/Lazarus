#include "bot/TwitchBot.h"

#include <iostream>
#include <time.h>

namespace bot{

	TwitchBot::TwitchBot(std::string nickname, std::string username, std::string password)
	{
		std::unique_ptr<net::NetManager> m_NetManager(new net::NetManager());
		m_strNickname = nickname;
		m_strUsername = username;
		m_strPassword = password;
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
		sprintf(m_cSendBuffer, "%s", m_strNickname);
		m_NetManager->SendData(m_cSendBuffer);

		sprintf(m_cSendBuffer, "%s", m_strUsername);
		m_NetManager->SendData(m_cSendBuffer);

		sprintf(m_cSendBuffer, "%s", m_strPassword);
		m_NetManager->SendData(m_cSendBuffer);
	}

	void TwitchBot::JoinChannel(std::string channel)
	{
		sprintf(m_cSendBuffer, "%s", channel);
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
		m_NetManager->ReadData(m_cRecvBuffer, MAX_BUFFER_SIZE);
		ProcessMsg();
	}

	void TwitchBot::ProcessMsg()
	{
		std::cout << "ProcessMsg()" << std::endl;
	}
}
