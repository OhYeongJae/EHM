#pragma once
#include "Log.h"

#define LOGIN_RES_OK	0;
#define LOGIN_RES_NOEXIST 1;
#define LOGIN_RES_LOGGED 2;
#define LOGIN_RES_NOTCORRECT 3;

class LOG_DLL LogInRes {
	int result;
public:
	LogInRes(int result);
	LogInRes(EHPacket *ep);
	int GetResult()const;
	void Serialize(SOCKET sock);
};