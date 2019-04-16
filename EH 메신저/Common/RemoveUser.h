#pragma once
#include "Dbm.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;

class DBM_DLL RemoveUser
{
	string id;
public:
	RemoveUser(string id);
	RemoveUser(EHPacket *ep);
	string GetId()const;
	void Serialize(SOCKET sock);
};