#define LOG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\LogInReq.h"
#include "..\\Common\\ehmsg.h"

LogInReq::LogInReq(string id, string pw)
{
	this->id = id;
	this->pw = pw;
}
LogInReq::LogInReq(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	int pwlen = 0;
	char pw[256] = "";
	ep->DePacketize(&pwlen, sizeof(pwlen));
	ep->DePacketize(pw, pwlen);
	this->id = id;
	this->pw = pw;
}
string LogInReq::GetId()const
{
	return id;
}
string LogInReq::GetPW()const
{
	return pw;
}
void LogInReq::Serialize(SOCKET sock)
{
	EHPacket ep(MID_LOGINREQ);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	int pwlen = pw.length() + 1;
	ep.Packetize(&pwlen, sizeof(pwlen));
	ep.Packetize((void *)pw.c_str(), pwlen);
	ep.Serialize(sock);
}