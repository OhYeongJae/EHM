#pragma once
#include "Dbm.h"
#define RES_ID_NOTEXIST 0
#define RES_ID_EXIST 1
class DBM_DLL IDExistAck {
	int result;
public:
	IDExistAck(int result);
	IDExistAck(EHPacket *ep);
	int GetResult()const;
	void Serialize(SOCKET sock);
};
