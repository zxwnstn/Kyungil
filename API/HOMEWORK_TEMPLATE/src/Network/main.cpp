//#include "PCH.h"
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include "MemoryStream.h"
//#include "protocol.h"
//
//#pragma comment(lib, "ws2_32")
//
//class Player
//{
//public:
//	int	mPlayerId = -1;
//	int	mPosX;
//	int	mPosY;
//
//	void Write(OutputMemoryStream& inStream) const;
//	void Read(InputMemoryStream& inStream)
//	{
//		inStream.Read(mPlayerId);
//		inStream.Read(mPosX);
//		inStream.Read(mPosY);
//		
//	}
//};
//void Player::Write(OutputMemoryStream& inStream) const
//{
//	inStream.Write(mPlayerId);
//	inStream.Write(mPosX);
//	inStream.Write(mPosY);
//}
//
//int clientNumber = 0; //critical section ó���ʿ���.
//Player c1{ };
//
//
//void print(const Player& remsg, const int thisclientNumber)
//{
//	std::cout << thisclientNumber << "�� Ŭ���̾�Ʈ ����" << std::endl;
//	std::cout << "�̸� : " << remsg.mPlayerId << std::endl;
//	std::cout << "������ġ : " << remsg.mPosX<< ", " << remsg.mPosY << '\n' << std::endl;
//}
//
//bool wait = true;
//std::mutex mtx;
//
//
//void echo(TCPSocketPtr ServSock, TCPSocketPtr ClientSocket)
//{
//	clientNumber++; // critical section
//	std::cout << clientNumber << "�� Ŭ���̾�Ʈ�� �����Ͽ����ϴ�!!" << std::endl;
//	int thisclientNumber = clientNumber;
//	while (true) {
//		Player user;
//
//		char* Buffer = static_cast<char*>(malloc(1470));
//
//		int size = ClientSocket->Receive(Buffer, 1470);
//		if (user.mPlayerId == -1) // ó�� ������ �� ���̵�ѹ� �ο�
//			user.mPlayerId = thisclientNumber;
//		if (size < 0) {
//			break;
//		}
//		InputMemoryStream in(Buffer, size);
//		user.Read(in);
//		print(user, thisclientNumber);
//		ClientSocket->Send(Buffer, size);
//
//		size = ClientSocket->Receive(Buffer, 1470);
//		if (size < 0) {
//			break;
//		}
//	}
//	std::cout << thisclientNumber << "�� Ŭ���̾�Ʈ ���� ����" << '\n' << std::endl;
//}
//
//int main()
//{
//	WSADATA wsaData;
//	auto err = WSAStartup(MAKEWORD(2, 2), &wsaData);
//
//	SocketAddressFactory fac;
//	SocketAddress servAddr(INADDR_ANY, 9190);//�߿�!
//	SocketAddress clientAddr;
//
//	TCPSocketPtr ServSock = SocketUtil::CreateTCPSocket(INET);
//
//	ServSock->Bind(servAddr);
//	std::cout << "������ �����մϴ�!" << std::endl;
//	std::cout << "Ŭ���̾�Ʈ ���� �����..." << std::endl;
//
//	ServSock->Listen(5);
//
//	while (true)
//	{
//		TCPSocketPtr ClientSocket;
//		ClientSocket = ServSock->Accept(clientAddr);
//
//		std::thread t1(echo, ServSock, ClientSocket);
//		t1.detach();
//	}
//
//	WSACleanup();
//}