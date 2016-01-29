#ifndef NET_NET_MANAGER_H_
#define NET_NET_MANAGER_H_

#include <string> // string

namespace net{

#define MAX_BUFFER_SIZE 13

class NetManager {
public:

	enum State{
		CONNECTED,
		CONNECTION_FAILED,
	};

	enum PacketCode{
		GAMEWORLD,
		PATH,
		NODE,
		END,
		EMPTY,
		CELL_BLOCKED,
		CELL_OPEN
	};

	NetManager();

	int Init(std::string hostname, std::string service);

	State GetState(){ return m_eState; }

	int SendData(char* buffer);

	int ReadData(char* buffer, int size = MAX_BUFFER_SIZE);
	
private:

	void CleanUp();

	int m_iSocketFileDescriptor;

	State m_eState;

	std::string m_strHostname;
	std::string m_strService;

	char* m_SendBuffer;
	char* m_ReadBuffer;
};

}

#endif