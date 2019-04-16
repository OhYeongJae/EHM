#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\ChangeSts.h"
#include "..\\Common\\ehmsg.h"
ChangeSts::ChangeSts(string id, int status)
{
	this->id = id;
	this->status = status;
}
ChangeSts::ChangeSts(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	this->id = id;
	ep->DePacketize(&status, sizeof(status));
}
string ChangeSts::GetId()const
{
	return id;
}

int ChangeSts::GetStatus()const
{
	return status;
}
void ChangeSts::Serialize(SOCKET sock)
{
	EHPacket ep(MID_CHANGESTS);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	ep.Packetize(&status, sizeof(status));
	ep.Serialize(sock);
}