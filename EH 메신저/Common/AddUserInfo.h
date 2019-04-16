#pragma once
#include "Dbm.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class DBM_DLL AddUserInfo
{
	string id;
	string pw;
	string name;
public:
	AddUserInfo(string id, string pw, string name);
	AddUserInfo(EHPacket *ep);
	string GetId()const;
	string GetName()const;
	string GetPW()const;
	void Serialize(SOCKET sock);
};