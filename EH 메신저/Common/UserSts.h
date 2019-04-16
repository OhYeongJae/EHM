#pragma once
#include "Dbm.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class DBM_DLL UserSts
{
	string id;
public:
	UserSts(string id);
	UserSts(EHPacket *ep);
	string GetId()const;
	void Serialize(SOCKET sock);
};