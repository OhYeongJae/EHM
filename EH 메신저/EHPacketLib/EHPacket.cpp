#define EHPACK037DIECUEMFHCUEKUEJDI
#include "..\\common\\EHPacket.h"
#pragma comment(lib,"ws2_32")

struct MsgHead
{
	int msgid;
	int bdlen;
};
// 메시지를 보내는 곳에서 사용하는 EHPacket 생성자
EHPacket::EHPacket(int msgid)
{
	MsgHead *mh = (MsgHead *)base;
	mh->msgid = msgid;
	mh->bdlen = 0;
	ptr = GetBody();
}

// 데이터를 수신하여 EHPacket을 생성하는 생성자
EHPacket::EHPacket(SOCKET sock)
{
	MsgHead *mh = (MsgHead *)base;
	ptr = GetBody();
	recv(sock, (char *)mh, sizeof(MsgHead), 0);
	recv(sock, ptr, mh->bdlen, 0);
}
// 메시지 아이디를 반환하는 메서드
int EHPacket::GetMsgId()const
{
	MsgHead *mh = (MsgHead *)base;
	return mh->msgid;
}
// 데이터를 패킷에 캡슐화하는 메서드
bool EHPacket::Packetize(void *data, int dlen)
{
	MsgHead *mh = (MsgHead *)base;
	char *body = GetBody();
	if (mh->bdlen + dlen + sizeof(MsgHead) > EH_PACKET_SIZE)
	{
		return false;
	}
	memcpy(body + mh->bdlen, data, dlen);
	mh->bdlen += dlen;
	return true;
}
// 패킷의 데이터를 디캡슐화하는 메서드
bool EHPacket::DePacketize(void *buf, int blen)
{
	MsgHead *mh = (MsgHead *)base;
	char *body = GetBody();
	int gap = ptr - body;
	if (mh->bdlen < gap + blen)
	{
		return false;
	}
	memcpy(buf, ptr, blen);
	ptr += blen;
	return true;
}
// 패킷을 전송하는 메서드 구현
int EHPacket::Serialize(SOCKET sock)
{
	MsgHead *mh = (MsgHead *)base;
	int total = mh->bdlen + sizeof(MsgHead);
	return send(sock, base, total, 0);
}
// 바디 위치를 구하는 메서드
char *EHPacket::GetBody()
{
	return base + sizeof(MsgHead);
}