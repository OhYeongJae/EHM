#pragma once
#include "Sts.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;

class STS_DLL KeepAlive
{
	string id;
	IN_ADDR ip;
	int stsport;
	int smsgport;
	int fileport;
public:
	KeepAlive(string id, IN_ADDR ip, int stsport = 0, int smsgport = 0, int fileport = 0);
	KeepAlive(EHPacket *ep);
	string GetId()const;
	IN_ADDR GetIP()const;
	int GetStsPort()const;
	int GetSmsgPort()const;
	int GetFilePort()const;
	void Serialize(SOCKET sock);
};