#pragma once
#include "..\\common\\EHPacket.h"
#pragma comment(lib,"..\\Debug\\EHPacketLib")
#ifdef DBM038IUPHDFJKDIFEWFKDSIFHWELKJFHOISUDFHK
#define DBM_DLL  __declspec(dllexport)
#else
#define DBM_DLL  __declspec(dllimport)
#endif

// 상태의 종류를 메크로 상수로 정의
#define STS_UNREG   0x00
#define STS_REG     0x01
#define STS_LOGGING 0x02
#define STS_LOGGED  0x03