#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <thread>



#pragma warning (disable:4996)
#pragma comment(lib,"ws2_32.lib") //Winsock Library

void Connection();