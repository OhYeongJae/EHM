#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\IDExist.h"
#include "..\\Common\\ehmsg.h"
IDExist::IDExist(string id)
{
	this->id = id;
}
IDExist::IDExist(EHPacket *ep) {
	int idlen = 0;
	char id[256]="";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	this->id = id;
}
string IDExist::GetId()const
{
	return id;
}
void IDExist::Serialize(SOCKET sock)
{
	EHPacket ep(MID_IDEXIST);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	ep.Serialize(sock);
}