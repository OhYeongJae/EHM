#define REG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\RegRes.h"
#include "..\\Common\\ehmsg.h"
// 생성자 구현
RegRes::RegRes(int result)
{
	this->result = result;
}
RegRes::RegRes(EHPacket *ep)
{
	ep->DePacketize(&result, sizeof(result));
}
// 가입 요청 결과를 반환하는 메서드
int RegRes::GetResult()const
{
	return result;
}
// 가입 요청 결과를 소켓으로 직렬화하는 메서드
void RegRes::Serialize(SOCKET sock)
{
	EHPacket ep(MID_REGRES);
	ep.Packetize(&result, sizeof(result));
	ep.Serialize(sock);
}