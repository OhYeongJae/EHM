#define REG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\Common\\RegReq.h"
#include "..\\Common\\ehmsg.h"

// 가입 요청을 보내는 곳에서 사용할 생성자
RegReq::RegReq(string id, string pw, string name)
{
	this->id = id;
	this->pw = pw;
	this->name = name;
}

// 수신한 EHPacket으로 RegReq개체를 만드는 생성자
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
// Id, name, pw 반환하는 메서드
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
// 소켓으로 전송하는 메서드를 구현
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