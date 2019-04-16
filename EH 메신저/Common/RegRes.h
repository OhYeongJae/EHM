#pragma once
#include "Reg.h"

#define REG_RES_OK 0
#define REG_RES_FAIL 1

class REG_DLL RegRes
{
	int result;
public:
	RegRes(int result); // 가입 요청 결과를 보내는 곳에서 사용할 생성자
	RegRes(EHPacket *ep); // 수신한 패킷으로 RegRes개체를 생성하는 생성자
	int GetResult()const; // 결과를 반환하는 메서드
	void Serialize(SOCKET sock); // 소켓으로 메시지를 전송하는 메서드
};