#pragma once
#include <WinSock2.h>

#ifdef EHPACK037DIECUEMFHCUEKUEJDI
#define EH_DLL __declspec(dllexport)
#else
#define EH_DLL __declspec(dllimport)
#endif // EHPACK037DIECUEMFHCUEKUEJDI

#define EH_PACKET_SIZE 2000 // EH �޽��� ��Ŷ�� �ִ� ũ��

class EH_DLL EHPacket
{
	char base[EH_PACKET_SIZE]; // ��Ŷ ����
	char *ptr; // ��Ŷ�� ������ ��ĸ���� ��ġ
public:
	EHPacket(int msgid); // �޽����� ��Ŷ���� ���� �� ����� ������
	EHPacket(SOCKET sock); // ���Ͽ��� ������ �����Ͽ� ��Ŷ�� ����� ������
	int GetMsgId()const; // ��Ŷ�� �޽��� ���̵� ��ȯ
	bool Packetize(void *data, int dlen); // �����͸� ��Ŷ�� �����ͷ� ĸ��ȭ�ϴ� �޼���
	bool DePacketize(void *buf, int blen); // ��Ŷ�� �����͸� ��ĸ��ȭ�ϴ� �޼���
	int Serialize(SOCKET sock); // ��Ŷ�� �������� �����ϴ� �޼���
private:
	char *GetBody(); // EHPacket Ŭ���� ���ο��� �޽��� �ٵ� ��ġ�� ���ϴ� �޼���
};