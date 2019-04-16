#define STS038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\OtherUserInfo.h"
#include "..\\Common\\ehmsg.h"
OtherUserInfo::OtherUserInfo(string id, IN_ADDR ip, int smsgport, int fileport)
{
	this->id = id;
	this->ip = ip;
	this->smsgport = smsgport;
	this->fileport = fileport;
}
OtherUserInfo::OtherUserInfo(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	ep->DePacketize(&ip, sizeof(ip));
	ep->DePacketize(&smsgport, sizeof(smsgport));
	ep->DePacketize(&fileport, sizeof(fileport));
	this->id = id;
}
string OtherUserInfo::GetId()const
{
	return id;
}
IN_ADDR OtherUserInfo::GetIP()const
{
	return ip;
}
int OtherUserInfo::GetSmsgPort()const
{
	return smsgport;
}
int OtherUserInfo::GetFilePort()const
{
	return fileport;
}
void OtherUserInfo::Serialize(SOCKET sock)
{
	EHPacket ep(MID_USERINFO);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	ep.Packetize(&ip, sizeof(ip));
	ep.Packetize(&smsgport, sizeof(smsgport));
	ep.Packetize(&fileport, sizeof(fileport));
	ep.Serialize(sock);
}