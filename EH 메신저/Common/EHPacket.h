#pragma once
#include <WinSock2.h>

#ifdef EHPACK037DIECUEMFHCUEKUEJDI
#define EH_DLL __declspec(dllexport)
#else
#define EH_DLL __declspec(dllimport)
#endif // EHPACK037DIECUEMFHCUEKUEJDI

#define EH_PACKET_SIZE 2000 // EH 메시지 패킷의 최대 크기

class EH_DLL EHPacket
{
	char base[EH_PACKET_SIZE]; // 패킷 버퍼
	char *ptr; // 패킷의 내용을 디캡슐할 위치
public:
	EHPacket(int msgid); // 메시지를 패킷으로 만들 때 사용할 생성자
	EHPacket(SOCKET sock); // 소켓에서 데이터 수신하여 패킷을 만드는 생성자
	int GetMsgId()const; // 패킷의 메시지 아이디 반환
	bool Packetize(void *data, int dlen); // 데이터를 패킷의 데이터로 캡슐화하는 메서드
	bool DePacketize(void *buf, int blen); // 패킷의 데이터를 디캡슐화하는 메서드
	int Serialize(SOCKET sock); // 패킷을 소켓으로 전송하는 메서드
private:
	char *GetBody(); // EHPacket 클래스 내부에서 메시지 바디 위치를 구하는 메서드
};