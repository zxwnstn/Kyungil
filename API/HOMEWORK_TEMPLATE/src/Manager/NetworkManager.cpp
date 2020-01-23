#include "NetworkManager.h"
DEFINITION_SINGLE(NetworkManager)

NetworkManager::NetworkManager()
{
}


NetworkManager::~NetworkManager()
{
}

bool NetworkManager::init(string _ip)
{
	WSADATA wsaData;
	auto err = WSAStartup(MAKEWORD(2, 2), &wsaData);

	SocketAddressFactory fac;
	SocketAddress clientAddr;
	server_ip = _ip;
	clientAddr = *fac.CreateIPv4FromString(server_ip);

	clientSock = SocketUtil::CreateTCPSocket(INET);
	clientSock->Connect(clientAddr);

	//temp
	std::cout << TEXT("Now you connected server!") << std::endl;	
	return true;
}

void NetworkManager::release()
{
	WSACleanup();
}
