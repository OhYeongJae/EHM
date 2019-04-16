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
	RegReq(string id, string pw, string name); // ���� ��û �޽����� ������ ������ ����� ������
	RegReq(EHPacket *ep); // ���� ��Ŷ�� ������ RegReq ��ü�� ����� �����ڸ� ����
	string GetId()const;
	string GetName()const;
	string GetPW()const;
	void Serialize(SOCKET sock);
};