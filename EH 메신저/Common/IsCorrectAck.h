#pragma once
#include "Dbm.h"
#define IDPW_NOTCORRECT 0
#define IDPW_CORRECT 1
class DBM_DLL IsCorrectAck
{
	int result;
public:
	IsCorrectAck(int result);
	IsCorrectAck(EHPacket *ep);
	int GetResult()const;
	void Serialize(SOCKET sock);
};