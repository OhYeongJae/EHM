#pragma once
#include "Reg.h"
#pragma warning(disable:4251)
#include <string>
using namespace std;

class REG_DLL RegReq
{
	string id;
	string pw;
	string name;
public:
	RegReq(string id, string pw, string name); // 가입 요청 메시지를 보내는 곳에서 사용할 생성자
	RegReq(EHPacket *ep); // 받은 패킷을 가지고 RegReq 개체를 만드는 생성자를 선언
	string GetId()const;
	string GetName()const;
	string GetPW()const;
	void Serialize(SOCKET sock);
};