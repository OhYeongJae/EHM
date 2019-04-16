#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\IDExistAck.h"
#include "..\\Common\\ehmsg.h"

IDExistAck::IDExistAck(int result)
{
	this->result = result;
}
IDExistAck::IDExistAck(EHPacket *ep)
{
	ep->DePacketize(&result, sizeof(result));
}
int IDExistAck::GetResult()const
{
	return result;
}
void IDExistAck::Serialize(SOCKET sock)
{
	EHPacket ep(MID_IDEXISTACK);
	ep.Packetize(&result, sizeof(result));
	ep.Serialize(sock);
}