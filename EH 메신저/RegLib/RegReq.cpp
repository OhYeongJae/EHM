#define REG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\Common\\RegReq.h"
#include "..\\Common\\ehmsg.h"

// ���� ��û�� ������ ������ ����� ������
RegReq::RegReq(string id, string pw, string name)
{
	this->id = id;
	this->pw = pw;
	this->name = name;
}

// ������ EHPacket���� RegReq��ü�� ����� ������
RegReq::RegReq(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);

	int pwlen = 0;
	char pw[256] = "";
	ep->DePacketize(&pwlen, sizeof(pwlen));
	ep->DePacketize(pw, pwlen);

	int namelen = 0;
	char name[256] = "";
	ep->DePacketize(&namelen, sizeof(namelen));
	ep->DePacketize(name, namelen);

	this->id = id;
	this->pw = pw;
	this->name = name;
}
// Id, name, pw ��ȯ�ϴ� �޼���
string RegReq::GetId()const
{
	return id;
}
string RegReq::GetPW()const
{
	return pw;
}
string RegReq::GetName()const
{
	return name;
}
// �������� �����ϴ� �޼��带 ����
void RegReq::Serialize(SOCKET sock)
{
	EHPacket ep(MID_REGREQ);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);

	int pwlen = pw.length() + 1;
	ep.Packetize(&pwlen, sizeof(pwlen));
	ep.Packetize((void *)pw.c_str(), pwlen);

	int namelen = name.length() + 1;
	ep.Packetize(&namelen, sizeof(namelen));
	ep.Packetize((void *)name.c_str(), namelen);

	ep.Serialize(sock);
}