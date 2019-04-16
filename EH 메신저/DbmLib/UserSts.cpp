#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\UserSts.h"
#include "..\\Common\\ehmsg.h"
UserSts::UserSts(string id)
{
	this->id = id;
}
UserSts::UserSts(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	this->id = id;
}
string UserSts::GetId()const
{
	return id;
}
void UserSts::Serialize(SOCKET sock)
{
	EHPacket ep(MID_USERSTS);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	ep.Serialize(sock);
}