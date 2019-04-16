#pragma once
#include "Reg.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class REG_DLL UnRegReq
{
	string id;
public:
	UnRegReq(string id);
	UnRegReq(EHPacket *ep);
	string GetId()const;
	void Serialize(SOCKET sock);
};