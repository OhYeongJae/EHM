#pragma once
#include "Dbm.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class DBM_DLL IDExist
{
	string id;
public:
	IDExist(string id);
	IDExist(EHPacket *ep);
	string GetId()const;
	void Serialize(SOCKET sock);
};