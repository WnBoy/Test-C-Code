#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	//1.加载套接字库 版本号2.2
	WORD wVersionRequested = MAKEWORD(2,2);
	WSADATA wsaData;

	int nErr = WSAStartup(wVersionRequested, &wsaData);
	
	if (nErr != 0)
	{
		printf("加载套接字库失败.\n");
		return 0;
	}

	//2.判断加载套接字库版本是否与我们要加载的一致
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion)!=2)
	{
		printf("加载的套接字库版本号不一致.\n");
		return 0;
	}

	//3.创建套接字
	SOCKET sockClient = socket(
		AF_INET,	//地址族
		SOCK_STREAM,//流式套接字
		0
		);

	//4.连接服务器 127.0.0.1 
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("172.16.201.114");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(8000);

	//向服务器发出连接请求
	if (SOCKET_ERROR == connect(
		sockClient,				//即将建立连接的套接字
		(SOCKADDR*)&addrSrv,	//服务器的地址信息
		sizeof(SOCKADDR)		//服务器端地址的长度
		))
	{
		int nError = GetLastError();
		printf("连接服务器失败,错误代码:%d.\n", nError);
		return 0;
	}

	//5.接收数据
	char szRecvBuffer[100];
	memset(szRecvBuffer, 0, 100);

	recv(sockClient, szRecvBuffer, 100, 0);

	printf("服务器说:%s.\n",szRecvBuffer);

	//6.发送数据
	char szSendBuffer[100]="我是隔壁的老王";
	send(sockClient, szSendBuffer, strlen(szSendBuffer)+1, 0);

	return 0;
}