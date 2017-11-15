#ifndef SERVER_H
#define SERVER_H

#include <SDL.h>
#include <SDL_net.h>
#include <iostream>
#include <vector>
#include <cstring>

struct Data {
	TCPsocket socket;
	Uint32 timeout;
	int id; // player/client ID
	int positionX;
	int positionY;
	Data(TCPsocket sock, Uint32 t, int i,
		int mPosX, int mPosY) :socket(sock),
		timeout(t), id(i), positionX(mPosX),
		positionY(mPosY) {}
};


class Server
{
public:
	bool ServerInit();
	void ServerRun(int mPosx, int mPosY);
	void CheckPlayerDisconnect();
	void ServerClose();

	int curid = 0;
	int playernum = 0;
	SDL_Event event;

	IPaddress ip;

	std::vector<Data> socketvector;
	char tmp[1400];
	bool running = true;

	SDLNet_SocketSet sockets;
	TCPsocket server;

private:

};
#endif // !SERVER_H





