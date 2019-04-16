#pragma once
#include "Log.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;

class LOG_DLL LogInReq
{
	string id;
	string pw;
public:
	LogInReq(string id, string pw);
	LogInReq(EHPacket *ep);
	string GetId()const;
	string GetPW()const;
	void Serialize(SOCKET sock);
};