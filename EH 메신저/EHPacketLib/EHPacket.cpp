#define EHPACK037DIECUEMFHCUEKUEJDI
#include "..\\common\\EHPacket.h"
#pragma comment(lib,"ws2_32")

struct MsgHead
{
	int msgid;
	int bdlen;
};
// �޽����� ������ ������ ����ϴ� EHPacket ������
EHPacket::EHPacket(int msgid)
{
	MsgHead *mh = (MsgHead *)base;
	mh->msgid = msgid;
	mh->bdlen = 0;
	ptr = GetBody();
}

// �����͸� �����Ͽ� EHPacket�� �����ϴ� ������
EHPacket::EHPacket(SOCKET sock)
{
	MsgHead *mh = (MsgHead *)base;
	ptr = GetBody();
	recv(sock, (char *)mh, sizeof(MsgHead), 0);
	recv(sock, ptr, mh->bdlen, 0);
}
// �޽��� ���̵� ��ȯ�ϴ� �޼���
int EHPacket::GetMsgId()const
{
	MsgHead *mh = (MsgHead *)base;
	return mh->msgid;
}
// �����͸� ��Ŷ�� ĸ��ȭ�ϴ� �޼���
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
// ��Ŷ�� �����͸� ��ĸ��ȭ�ϴ� �޼���
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
// ��Ŷ�� �����ϴ� �޼��� ����
int EHPacket::Serialize(SOCKET sock)
{
	MsgHead *mh = (MsgHead *)base;
	int total = mh->bdlen + sizeof(MsgHead);
	return send(sock, base, total, 0);
}
// �ٵ� ��ġ�� ���ϴ� �޼���
char *EHPacket::GetBody()
{
	return base + sizeof(MsgHead);
}