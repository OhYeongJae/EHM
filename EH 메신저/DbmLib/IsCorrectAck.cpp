#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\IsCorrectAck.h"
#include "..\\Common\\ehmsg.h"
IsCorrectAck::IsCorrectAck(int result)
{
	this->result = result;
}
IsCorrectAck::IsCorrectAck(EHPacket *ep)
{
	ep->DePacketize(&result, sizeof(result));
}
int IsCorrectAck::GetResult()const
{
	return result;
}
void IsCorrectAck::Serialize(SOCKET sock)
{
	EHPacket ep(MID_ISCORRECTACK);
	ep.Packetize(&result, sizeof(result));
	ep.Serialize(sock);
}