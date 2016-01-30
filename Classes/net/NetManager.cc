#include "net/NetManager.h"

#include <cstring> // strlen()
#include <iostream>

#include "socket/socket.h" // libsocket

namespace net{

NetManager::NetManager()
{
		
}

int NetManager::Init(std::string hostname, std::string service)
{
	printf("hostname: %s server: %s\n", hostname.c_str(), service.c_str());
	// Store hostname and service for reconnection attempts
	m_strHostname = hostname;
	m_strService = service;

	// Initialize connection to the raig server
	m_iSocketFileDescriptor = Connection(m_strHostname.c_str(), m_strService.c_str(), TYPE_CLIENT, SOCK_STREAM);

	if (m_iSocketFileDescriptor == -1)
	{
		m_eState = CONNECTION_FAILED;
		printf("InitConnection() Connection failed. Socketfd %d\n", m_iSocketFileDescriptor);
		return -1;
	}

	std::cout << "Init() connection successful" << std::endl;

	m_eState = CONNECTED;
	SetNonBlocking(m_iSocketFileDescriptor);

	return m_iSocketFileDescriptor;
}

int NetManager::SendData(char* buffer)
{
	size_t size = strlen(buffer) + 1;
	int flags = 0;
	int bytesSents = 0;

	bytesSents = Send(m_iSocketFileDescriptor, buffer, size, flags);

	return bytesSents;
}

int NetManager::ReadData(char* buffer, int size)
{
	int flags = 0;
	int bytesRecv = 0;
	
	bytesRecv = Recv(m_iSocketFileDescriptor, buffer, size, flags);
	
	// Server shutdown connection
	if (bytesRecv == 0 && m_eState == CONNECTED)
	{
		m_eState = CONNECTION_FAILED;
	}

	return bytesRecv;
}

} // namespace net