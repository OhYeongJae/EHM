#pragma once
// 가입 관련 메시지 아이디
#define MID_REGREQ        0x00010001
#define MID_REGRES        0x00010002
#define MID_UNREGREQ      0x00010003

// 로그인 관련 메시지 아이디
#define MID_LOGINREQ      0x00020001
#define MID_LOGINRES      0x00020002
#define MID_LOGOUTREQ     0x00020003

// 상태 관련 메시지 아이디
#define MID_KEEPALIVE     0x00030001
#define MID_USERINFO      0x00030002
#define MID_IDEXIST       0x00040001
#define MID_IDEXISTACK    0x00040002

// 데이터 계층 관련 메시지 아이디 
#define MID_ADDUSERINFO   0x00040003
#define MID_USERSTS       0x00040004
#define MID_USERSTSACK    0x00040005
#define MID_ISCORRECT     0x00040006
#define MID_ISCORRECTACK  0x00040007
#define MID_CHANGESTS     0x00040008
#define MID_REMOVEUSER    0x00040009

// 서비스에서 사용할 포트
#define FEND_PORT         10200
#define REG_PORT          10202
#define LOG_PORT          10204
#define STS_PORT          10206
#define DBM_PORT          10208