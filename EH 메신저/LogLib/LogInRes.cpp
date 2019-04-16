#define LOG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\LogInRes.h"
#include "..\\Common\\ehmsg.h"

LogInRes::LogInRes(int result)
{
	this->result = result;
}
LogInRes::LogInRes(EHPacket *ep)
{
	ep->DePacketize(&result, sizeof(result));
}
int LogInRes::GetResult()const
{
	return result;
}
void LogInRes::Serialize(SOCKET sock)
{
	EHPacket ep(MID_LOGINRES);
	ep.Packetize(&result, sizeof(result));
	ep.Serialize(sock);
}