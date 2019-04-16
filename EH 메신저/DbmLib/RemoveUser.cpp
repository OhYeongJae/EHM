#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\RemoveUser.h"
#include "..\\Common\\ehmsg.h"
RemoveUser::RemoveUser(string id)
{
	this->id = id;
}


RemoveUser::RemoveUser(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);
	this->id = id;
}
string RemoveUser::GetId()const
{
	return id;
}
void RemoveUser::Serialize(SOCKET sock)
{
	EHPacket ep(MID_REMOVEUSER);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	ep.Serialize(sock);
}