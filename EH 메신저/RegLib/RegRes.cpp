#define REG038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\RegRes.h"
#include "..\\Common\\ehmsg.h"
// ������ ����
RegRes::RegRes(int result)
{
	this->result = result;
}
RegRes::RegRes(EHPacket *ep)
{
	ep->DePacketize(&result, sizeof(result));
}
// ���� ��û ����� ��ȯ�ϴ� �޼���
int RegRes::GetResult()const
{
	return result;
}
// ���� ��û ����� �������� ����ȭ�ϴ� �޼���
void RegRes::Serialize(SOCKET sock)
{
	EHPacket ep(MID_REGRES);
	ep.Packetize(&result, sizeof(result));
	ep.Serialize(sock);
}