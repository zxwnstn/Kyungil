#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
#include "HeaderShared.h"
#include "MemoryStream.h"
#pragma comment(lib, "ws2_32")
#define PACKET_MAX 1470

enum class PacketTpye
{
	//TODO : Define your packet type
};

//packet interface
class Packet {
public:
	virtual void Write(OutputMemoryStream& outStream) = 0;
	virtual void Read(InputMemoryStream& inStream) = 0;
	virtual void show() = 0;
};
