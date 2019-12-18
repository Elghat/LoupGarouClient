#include "Header.h"

void Connection()
{
	char buffer[255] = {NULL};
	char line[255] = { NULL };
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	SOCKET sock;
	SOCKADDR_IN sin;

	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); // qui définit l'adresse du serveur. Si vous codez un serveur, vous n'avez pas à définir d'adresse, vous utiliseriez donc : sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET; //  la "famille" du socket, le type si on veut. Pour l'Internet, les programmeurs utilisent généralement AF_INET. 
	sin.sin_port = htons(9999); // port sur lequel on écoute
	sock = socket(AF_INET, SOCK_STREAM, 0);
	connect(sock, (SOCKADDR*)&sin, sizeof(sin));
	recv(sock, buffer, sizeof(buffer), 0);
	printf(buffer);
	//closesocket(sock);

	while (1)
	{
		
		scanf("%s", &line);

		
		//free(sock);
		//sock = socket(AF_INET, SOCK_STREAM, 0);

		send(sock, line, sizeof(line), 0);

		//free(line);

		

	}

	closesocket(sock);

}


void Deconnection()
{
	WSACleanup();
}