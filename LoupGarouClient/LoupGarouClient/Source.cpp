#include "Header.h"


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
	sin.sin_addr.s_addr =  inet_addr("127.0.0.1"); // qui d�finit l'adresse du serveur. Si vous codez un serveur, vous n'avez pas � d�finir d'adresse, vous utiliseriez donc : sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET; //  la "famille" du socket, le type si on veut. Pour l'Internet, les programmeurs utilisent g�n�ralement AF_INET. 
	sin.sin_port = htons(9999); // port sur lequel on �coute
	sock = socket(AF_INET, SOCK_STREAM, 0);
	//D�s que le client se connecte la premi�re ch�se qu'il fait c'est d'envoyer son pseudo
	if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		send(sock, pseudo, sizeof(pseudo), 0);
	};
	//D�marre la fonction d�coute pour le chat
	std::thread chatreceiver(chatReceiverThread, sock, buffer);
	//Boucle infinie pour envoyer des messages
	while (1)
	{
		scanf("%s", &line);
		send(sock, line, sizeof(line), 0);
	}
	//Fonction qui s'appelle a la fermeture du programme pour �tre sur qu'on se d�connecte
	atexit(programeExit);
	return 0;
}
