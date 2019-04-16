#define EHWRAP037DIECUEMFHCUEKUEJDI
#include "..\\common\\EHWrapSocket.h"
#pragma comment(lib,"ws2_32")

// �ڽ��� ����Ʈ IP�ּҸ� ��ȯ�Ѵ� �޼���
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
// TCP ������ �����ϴ� �޼���
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

// ��Ʈ ��ȣ�� ������ ������ �ּ��� �޾� bind �����ϸ� ����z �����ϸ鼭 bind�� �����ϴ� ��Ʈ�� ����
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
// TCP ������ �����ϴ� �޼���
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