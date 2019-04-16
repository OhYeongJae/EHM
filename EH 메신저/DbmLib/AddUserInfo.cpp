#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\AddUserInfo.h"
#include "..\\Common\\ehmsg.h"
AddUserInfo::AddUserInfo(string id, string pw, string name)
{
	this->id = id;
	this->pw = pw;
	this->name = name;
}
AddUserInfo::AddUserInfo(EHPacket *ep)
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
string AddUserInfo::GetId()const
{
	return id;
}
string AddUserInfo::GetName()const
{
	return name;
}
string AddUserInfo::GetPW()const
{
	return pw;
}
void AddUserInfo::Serialize(SOCKET sock)
{
	EHPacket ep(MID_ADDUSERINFO);

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