#pragma once
#include "Sts.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;

class STS_DLL OtherUserInfo
{
	string id;
	IN_ADDR ip;
	int smsgport;
	int fileport;
public:
	OtherUserInfo(string id, IN_ADDR ip, int smsgport = 0, int fileport = 0);
	OtherUserInfo(EHPacket *ep);
	string GetId()const;
	IN_ADDR GetIP()const;
	int GetSmsgPort()const;
	int GetFilePort()const;
	void Serialize(SOCKET sock);
};