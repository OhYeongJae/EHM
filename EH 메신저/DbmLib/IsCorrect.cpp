#define DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#include "..\\common\\IsCorrect.h"
#include "..\\Common\\ehmsg.h"
IsCorrect::IsCorrect(string id, string pw)
{
	this->id = id;
	this->pw = pw;
}
IsCorrect::IsCorrect(EHPacket *ep)
{
	int idlen = 0;
	char id[256] = "";
	ep->DePacketize(&idlen, sizeof(idlen));
	ep->DePacketize(id, idlen);

	int pwlen = 0;
	char pw[256] = "";
	ep->DePacketize(&pwlen, sizeof(pwlen));
	ep->DePacketize(pw, pwlen);

	this->id = id;
	this->pw = pw;
}
string IsCorrect::GetId()const
{
	return id;
}
string IsCorrect::GetPW()const
{
	return pw;
}
void IsCorrect::Serialize(SOCKET sock)
{
	EHPacket ep(MID_ISCORRECT);
	int idlen = id.length() + 1;
	ep.Packetize(&idlen, sizeof(idlen));
	ep.Packetize((void *)id.c_str(), idlen);
	int pwlen = pw.length() + 1;
	ep.Packetize(&pwlen, sizeof(pwlen));
	ep.Packetize((void *)pw.c_str(), pwlen);
	ep.Serialize(sock);
}