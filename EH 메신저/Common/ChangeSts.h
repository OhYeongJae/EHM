#pragma once
#include "Dbm.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class DBM_DLL ChangeSts
{
	string id;
	int status;
public:
	ChangeSts(string id, int status);
	ChangeSts(EHPacket *ep);
	string GetId()const;
	int GetStatus()const;
	void Serialize(SOCKET sock);
};