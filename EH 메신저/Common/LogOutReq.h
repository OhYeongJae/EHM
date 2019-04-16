#pragma once
#include "Log.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class LOG_DLL LogOutReq
{
	string id;
public:
	LogOutReq(string id);
	LogOutReq(EHPacket *ep);
	string GetId()const;
	void Serialize(SOCKET sock);
};