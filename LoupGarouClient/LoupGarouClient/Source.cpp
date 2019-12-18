#include "Header.h"

void chatReceiverThread(SOCKET sock, char* buffer);
void programeExit(void);
SOCKET sock;
int main()
{
	char pseudo[255];
	char buffer[255] = { NULL };
	char line[255] = { NULL };
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	SOCKADDR_IN sin;
	
	printf("Veuillez entrer votre pseudo pour la partie\n");
	scanf("%s", &pseudo);
	sin.sin_addr.s_addr = /*INADDR_LOOPBACK*/ inet_addr("127.0.0.1"); // qui définit l'adresse du serveur. Si vous codez un serveur, vous n'avez pas à définir d'adresse, vous utiliseriez donc : sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET; //  la "famille" du socket, le type si on veut. Pour l'Internet, les programmeurs utilisent généralement AF_INET. 
	sin.sin_port = htons(9999); // port sur lequel on écoute
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		send(sock, pseudo, sizeof(pseudo), 0);
	};
	std::thread chatreceiver(chatReceiverThread, sock, buffer);//Démarre la fonction découte pour le chat
	while (1)
	{
		scanf("%s", &line);
		send(sock, line, sizeof(line), 0);
	}
	closesocket(sock);
	atexit(programeExit);
	return 0;
}

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