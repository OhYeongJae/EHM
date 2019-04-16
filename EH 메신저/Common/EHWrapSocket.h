#pragma once
#include <WinSock2.h>
#ifdef EHWRAP037DIECUEMFHCUEKUEJDI
#define EHWRAP_DLL __declspec(dllexport)
#else
#define EHWRAP_DLL __declspec(dllimport)
#endif

class EHWRAP_DLL EHWrapSocket {
public:
	static IN_ADDR GetDefaultIPAddr();
	static SOCKET CreateTCPServer(int port, int blog);
	static SOCKET CreateTCPServer2(int *port, int blog);
	static SOCKET Connect(const char *ip, int port);
private:
	EHWrapSocket();
};
