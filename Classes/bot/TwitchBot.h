#ifndef BOT_TWITCH_BOT_H
#define BOT_TWITCH_BOT_H

#include <memory>

#include "net\NetManager.h"

#define MAX_BUFFER_SIZE 255

namespace bot{

	class TwitchBot{
	public:
		// TwitchBot("NICK myUserName\r\n", "USER myUserName\r\n", "PASS oauth:some123numbers123\r\n")
		TwitchBot(std::string nickname, std::string username, std::string password);

		~TwitchBot();

		void Update();

	private:

		void Start();

		void LoginToChatServer();

		void JoinChannel(std::string channel);
		
		void ProcessMsg();

		std::unique_ptr<net::NetManager> m_NetManager;
		
	 	char m_cSendBuffer[MAX_BUFFER_SIZE];
		char m_cRecvBuffer[MAX_BUFFER_SIZE];

		std::string m_strNickname;
		std::string m_strUsername;
		std::string m_strPassword;
	};

}
#endif