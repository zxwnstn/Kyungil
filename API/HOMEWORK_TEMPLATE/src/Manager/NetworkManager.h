#include "Network/packet.h"
#include "stdafx.h"

class NetworkManager{
public:
	bool init(string _ip);
	void release();

	//TODO : implement your Packet protocol

private:
	string server_ip;
	TCPSocketPtr clientSock;
	int grantedID;

private:
	DECLARE_SINGLE(NetworkManager)
};