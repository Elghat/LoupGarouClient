#include "Header.h"

void connection()
{
	char buffer[255];
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	SOCKET sock;
	SOCKADDR_IN sin;

	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(9999);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	connect(sock, (SOCKADDR*)&sin, sizeof(sin));
	recv(sock, buffer, sizeof(buffer), 0);
	closesocket(sock);

	WSACleanup();
}