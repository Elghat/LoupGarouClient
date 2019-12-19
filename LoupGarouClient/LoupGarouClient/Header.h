#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <thread>



#pragma warning (disable:4996)
#pragma warning (disable:6031)
#pragma comment(lib,"ws2_32.lib") //Winsock Library
SOCKET sock;

void Connection();
void Deconnection();


void chatReceiverThread(SOCKET sock, char* buffer)
{
	while (true)
	{
		recv(sock, buffer, sizeof(buffer), 0);
		printf("\n%s", buffer);
	}
}

void programeExit(void)
{
	closesocket(sock);
}