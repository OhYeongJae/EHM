#define EHWRAP037DIECUEMFHCUEKUEJDI
#include "..\\common\\EHWrapSocket.h"
#pragma comment(lib,"ws2_32")

// 자신의 디폴트 IP주소를 반환한느 메서드
IN_ADDR EHWrapSocket::GetDefaultIPAddr()
{
	char hostname[256] = "";
	gethostname(hostname, 255);
	hostent *hentry = gethostbyname(hostname);
	struct in_addr addr = { 0 };
	while (hentry && hentry->h_name)
	{
		if(hentry->h_addrtype == AF_INET)
		{
			memcpy(&addr, hentry->h_addr_list[0], sizeof(addr));
			return addr;
		}
		hentry++;
	}
	return addr;
}
// TCP 서버를 설정하는 메서드
SOCKET EHWrapSocket::CreateTCPServer(int port, int blog) {
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1)
		return -1;
	SOCKADDR_IN servaddr = { 0 };
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr = GetDefaultIPAddr();
	servaddr.sin_port = htons(port);
	if (bind(sock, (SOCKADDR *)&servaddr, sizeof(servaddr)) == -1)
	{
		return -1;
	}
	if (listen(sock, blog) == -1)
	{
		return -1;
	}
	return sock;
}

// 포트 번호를 설정한 변수의 주수롤 받아 bind 실패하면 포드틑 변경하면서 bind를 성공하는 포트로 설정
SOCKET EHWrapSocket::CreateTCPServer2(int *port, int blog) {
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1)
	{
		return -1;
	}
	SOCKADDR_IN servaddr = { 0 };
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr = GetDefaultIPAddr();
	servaddr.sin_port = htons(*port);
	while (bind(sock,(SOCKADDR *)&servaddr,sizeof(servaddr)) ==-1)
	{
		*port += 2;
		servaddr.sin_port = htons(*port);
	}
	if(listen(sock,blog) == -1)
	{
		return -1;
	}
	return sock;
}
// TCP 서버에 연결하는 메서드
SOCKET EHWrapSocket::Connect(const char *ip, int port)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		return - 1;
	}
	SOCKADDR_IN servaddr = { 0 };
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(ip);
	servaddr.sin_port = htons(port);
	if (connect(sock, (SOCKADDR *)&servaddr, sizeof(servaddr)) == -1) {
		return -1;
	}
	return sock;
}