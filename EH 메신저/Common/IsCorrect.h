#pragma once
#include "Dbm.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;
class DBM_DLL IsCorrect
{
	string id;
	string pw;
public:
	IsCorrect(string id, string pw);
	IsCorrect(EHPacket *ep);
	string GetId()const;
	string GetPW()const;
	void Serialize(SOCKET sock);
};