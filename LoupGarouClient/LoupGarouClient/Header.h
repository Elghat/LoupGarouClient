#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <thread>



#pragma warning (disable:4996)
#pragma warning (disable:6031)
#pragma comment(lib,"ws2_32.lib") //Winsock Library

void Connection();
void Deconnection();