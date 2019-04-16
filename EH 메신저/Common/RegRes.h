#pragma once
#include "Reg.h"

#define REG_RES_OK 0
#define REG_RES_FAIL 1

class REG_DLL RegRes
{
	int result;
public:
	RegRes(int result); // ���� ��û ����� ������ ������ ����� ������
	RegRes(EHPacket *ep); // ������ ��Ŷ���� RegRes��ü�� �����ϴ� ������
	int GetResult()const; // ����� ��ȯ�ϴ� �޼���
	void Serialize(SOCKET sock); // �������� �޽����� �����ϴ� �޼���
};