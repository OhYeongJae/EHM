#define STS038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\KeepAlive.h"
#include "..\\Common\\ehmsg.h"

KeepAlive::KeepAlive(string id, IN_ADDR ip, int stsport, int smsgport, int fileport) {
	this->id = id;
	this->ip = ip;
	this->stsport = stsport;
	this->smsgport = smsgport;
	this->fileport = fileport;
}
KeepAlive::KeepAlive(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	ep->DePacketize(&ip,sizeof(ip));
	ep->DePacketize(&stsport, sizeof(stsport));
	ep->DePacketize(&smsgport, sizeof(smsgport));
	ep->DePacketize(&fileport, sizeof(fileport));
	this->id = id;
}
string KeepAlive::GetId()const
{
	return id;
}
IN_ADDR KeepAlive::GetIP()const
{
	return ip;
}
int KeepAlive::GetStsPort()const
{
	return stsport;
}
int KeepAlive::GetSmsgPort()const
{
	return smsgport;
}
int KeepAlive::GetFilePort()const
{
	return fileport;
}

void KeepAlive::Serialize(SOCKET sock)
{
	EHPacket ep(MID_KEEPALIVE);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	ep.Packetize(&ip, sizeof(ip));
	ep.Packetize(&stsport, sizeof(stsport));
	ep.Packetize(&smsgport, sizeof(smsgport));
	ep.Packetize(&fileport, sizeof(fileport));
	ep.Serialize(sock);
}