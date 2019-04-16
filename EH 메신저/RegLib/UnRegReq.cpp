#define REG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\UnRegReq.h"
#include "..\\Common\\ehmsg.h"

UnRegReq::UnRegReq(string id)
{
	this->id = id;
}
UnRegReq::UnRegReq(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	this->id = id;
}
string UnRegReq::GetId()const
{
	return id;
}
void UnRegReq::Serialize(SOCKET sock)
{
	EHPacket ep(MID_UNREGREQ);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void*)id.c_str(), idlen);
	ep.Serialize(sock);
}