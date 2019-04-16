#define LOG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\LogOutReq.h"
#include "..\\Common\\ehmsg.h"

LogOutReq::LogOutReq(string id)
{
	this->id = id;
}
LogOutReq::LogOutReq(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	this->id = id;
}
string LogOutReq::GetId()const
{
	return id;
}
void LogOutReq::Serialize(SOCKET sock)
{
	EHPacket ep(MID_LOGOUTREQ);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void*)id.c_str(), idlen);
	ep.Serialize(sock);
}