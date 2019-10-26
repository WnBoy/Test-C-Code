#include <stdio.h>			//printf
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	//printf("Hello World\n");

	//1.加载套接字库 版本号2.2
	//unsigned short
	//typedef  给先有的类型起别名
	WORD wVersionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;

	//成功返回：0；失败返回非0
	int nErr = WSAStartup(wVersionRequested, &wsaData);

	if (nErr != 0)
	{
		printf("加载套接字库失败.\n");
		return 0;
	}

	//2.判断加载的套接字库版本号是否一致
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("加载的套接字库版本不一致.\n");
		return 0;
	}

	//3.创建套接字
	SOCKET sockSrv = socket(
		AF_INET,	//地址族
		SOCK_STREAM,//套接字的类型
		0			//特定地址族相关的协议
	);

	//h :host； to :到 ;n:net; l: long 四个字节；s:short短整型 2个字节
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//将主机字节顺序转换为网络字节顺序
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(8000); //0-65535  0-1024 系统端口号 1024以上：用户自定义端口号

									//4.绑定套接字
	if (SOCKET_ERROR == bind(
		sockSrv,				//要绑定的套接字
		(SOCKADDR*)&addrSrv,	//指定的套接字本地地址信息
		sizeof(SOCKADDR)		//地址结构的长度
	))
	{
		printf("绑定套接字失败\n");    //成功返回0，失败返回SOCKET_ERROR
		return 0;
	}

	//5.监听
	if (SOCKET_ERROR == listen(
		sockSrv,	//要监听的套接字
		5			//等待连接队列的最大长度
	))
	{
		printf("监听失败\n");     //成功返回0，失败返回SOCKET_ERROR
		return 0;
	}

	SOCKADDR_IN addrClient;
	int nLength = sizeof(SOCKADDR);

	//6.等待客户端的连接
	SOCKET sockConn = accept(           //accept返回一个新的套接字，它对应于已经接受的客户端，后续操作都用这个套接字
		sockSrv,				//已经是处于监听状态的套接字
		(SOCKADDR*)&addrClient,	//用来接收客户端的地址信息	
		&nLength				//返回地址信息的长度大小
	);

	//7.发送数据给客户端
	char szSendBuffer[100];
	sprintf(szSendBuffer, "恭喜你 : %s，连接上服务器.", inet_ntoa(addrClient.sin_addr));

	send(
		sockConn,				//已经建立连接的套接字
		szSendBuffer,			// 
		strlen(szSendBuffer) + 1,	//字符串长度
		0
	);

	//8.接收一下客户端发过来的数据
	char szRecvBuffer[100];
	while (1)
	{
	    memset(szRecvBuffer, 0, 100);
	    int num = recv(sockConn, szRecvBuffer, 100, 0);
		if (num >= 0)
		printf("客户端说：%s.\n", szRecvBuffer);

		memset(szSendBuffer, 0, 100);
		printf("服务端请开始你的表演：");
		scanf("%s", szSendBuffer);
		if (strlen(szSendBuffer) > 0)
		{
			int ers = send(sockConn, szSendBuffer, strlen(szSendBuffer) + 1, 0);
			if (ers < 0)
				printf("发送失败");
			if (strcmp("exit", szSendBuffer) == 0)
				exit(0);
		}  
      }
	return 0;
}