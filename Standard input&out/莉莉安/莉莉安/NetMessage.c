#include<stdio.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")  
void CreateServer();
DWORD WINAPI threadproClient(LPVOID pParam);
DWORD WINAPI threadproServer(LPVOID pParam);
int CheckIP(char*cIP);
void CreateClient();
void ExitSystem();

//客户端发送给服务端的消息类型
#define CLIENTSEND_EXIT 1
#define CLIENTSEND_TRAN 2
#define CLIENTSEND_LIST 3

//服务端发送给客户端的消息类型
#define SERVESEND_SELFID 1
#define SERVESEND_NEWUSR 2
#define SERVESEND_SHOWMSG 3
#define SERVESEND_ONLINE 4

//定义记录聊天记录的文件指针
FILE*ioutfileServer;
FILE*ioutfileClient;

//服务器接受消息的结构体，客户端使用这个结构发送数据
struct CReceivePackage
{
	int iType;              //存放数据类型
	int iToID;             //存放目标用户ID
	int iFromlD;          //存放原用户ID
	char cBuffer[1024];  //存放消息内容
};

//服务端发送消息的结构体，服务器使用这个结构发送数据
struct CSendPacksge
{
	int iType;             //消息类型
	int iCurConn;         //当前用户在线数量
	char cBuffer[1024];  //存放消息内容
};

//服务器存储在线用户信息的结构体
struct CUserSocketinfo
{
	int ID;                 //用户的ID
	char cDstIP[64];        //用户的IP地址，扩展使用
	int iPort;              //用户应用程序端口扩展使用
	SOCKET sUserSocket;     //网络句柄
};

//客户端存储在线用户列表的结构体
struct CUser
{
	int ID;                //用户的ID
	char cDstIP[64];       //用户的IP地址扩展时使用
};

struct CUser usr[20];                  //客户端存储用户信息的对象
int bSend = 0;                         //是否可以发送数据
int iMyself;                           //自己的ID
int iNew = 0;                          //在线用户数
struct CUserSocketinfo usrinfo[20];    //服务端存储用户信息的对象

int main(void)
{
	int iSel = 0;
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	do
	{
		printf("选择程序类型：\n");
		printf("点对点服务端：1\n");
		printf("点对点客户端：2\n");
		printf("服务器中转服务端：3\n");
		printf("服务器中转客户端：4\n");
		scanf("%d", &iSel);
	} while (iSel < 0 || iSel>4);
	switch (iSel)
	{
	case 1:CreateServer();break;
	case 2:CreateClient();break;
	
	}
	printf("退出系统\n");
	return 0;
}

void CreateServer()
{
	SOCKET m_SockServer;
	struct sockaddr_in serveraddr;     //本地地址信息
	struct sockaddr_in serveraddrfrom; //连接的地址信息
	int iPort = 4600;  //设定为固定端口
	int iBindResult = -1;  //绑定结果
	int iWhileCount = 200;
	struct hostent*localHost;
	char *localIP;
	SOCKET m_Server;
	char cWelcomBuffer[] = "Welcome to you\0";
	int len = sizeof(struct sockaddr);
	int iWhileListenCount = 10;
	DWORD nThreadld = 0;
	int ires;  //发送的返回值
	char cSendBuffer[1024];//发送消息缓存
	char cShowBuffer[1024];//接受消息缓存
	ioutfileServer = fopen("MessageServer.txt", "a");  //打开记录消息的文件
	m_SockServer = socket(AF_INET, SOCK_STREAM, 0);
	printf("本机绑定的端口号(大于1024）");
	scanf("%d", &iPort);
	localHost = gethostbyname("");
	localIP = inet_ntoa(*(struct in_addr*)*localHost->h_addr_list);
	//设置网络地址信息
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(iPort);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);
	//绑定地址信息
	iBindResult = bind(m_SockServer, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr));
	//如果端口不能被绑定，重新设置端口
	while (iBindResult != 0 && iWhileCount > 0)
	{
		printf("绑定失败，重新输入：");
		scanf("%d", iPort);
		//设置网络地址信息
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(iPort);
		serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);
		//绑定地址信息
		iBindResult = bind(m_SockServer, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr));
		iWhileCount--;
		if (iWhileCount < 0)
		{
			printf("端口绑定失败，重新运行程序\n");
			exit(0);
		}
	}
	while (iWhileListenCount > 0)
	{
		printf("start listen\n");
		listen(m_SockServer, 0);//返回值判断单个监听是否超时
		m_Server = accept(m_SockServer, (struct sockaddr*)&serveraddrfrom, &len);
		if (m_Server != INVALID_SOCKET)
		{
			//有链接成功，发送欢迎消息
			send(m_Server, cWelcomBuffer, sizeof(cWelcomBuffer), 0);
			//启动接收消息的线程
			CreateThread(NULL, 0, threadproServer, (LPVOID)m_Server, 0, &nThreadld);
			break;
		}
		printf(".");
		iWhileListenCount--;
		if (iWhileListenCount <= 0)
		{
			printf("\n建立连接失败\n");
			exit(0);
		}
	}
	while (1)
	{
		memset(cSendBuffer, 0, 1024);
		scanf("%s", cSendBuffer);//输入消息
		if (strlen(cSendBuffer) > 0)//输入消息不能为空
		{
			ires = send(m_Server, cSendBuffer, strlen(cSendBuffer), 0);//发送消息
			if (ires < 0)
			{
				printf("发送失败");
			}
			else
			{
				sprintf(cShowBuffer, "Send to:%s\n", cSendBuffer);
				printf("%s", cShowBuffer);
				fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileServer);
			}
			if (strcmp("exit", cSendBuffer) == 0)
			{
				ExitSystem();
			}
		}
	}
}

//客户端接收消息的线程
DWORD WINAPI threadproClient(LPVOID pParam)
{
	SOCKET hsock = (SOCKET)pParam;
	char cRecvBuffer[1024];
	char cShowBuffer[1024];
	int num = 0;
	if (hsock != INVALID_SOCKET)printf("start:\n");
	while (1)
	{
		num = recv(hsock, cRecvBuffer, 1024, 0);
		if (num >= 0)
		{
			cRecvBuffer[num] = '\0';
			sprintf(cShowBuffer, "to me:%s\n", cRecvBuffer);
			printf("%s", cShowBuffer);
			fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileClient);
			fflush(ioutfileClient);
			if (strcmp("exit", cRecvBuffer) == 0)
			{
				ExitSystem();
			}
		}
	}
	return 0;
}

//服务端接收消息的线程
DWORD WINAPI threadproServer(LPVOID pParam)
{
	SOCKET hsock = (SOCKET)pParam;
	char cRecvBuffer[1024];
	char cShowBuffer[1024];
	int num = 0;
	if (hsock != INVALID_SOCKET)printf("start:\n");
	while (1)
	{
		num = recv(hsock, cRecvBuffer, 1024, 0);
		if (num >= 0)
		{
			cRecvBuffer[num] = '\0';
			sprintf(cShowBuffer, "to me:%s\n", cRecvBuffer);
			printf("%s", cShowBuffer);
			//记录消息
			fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileServer);
			fflush(ioutfileServer);
			if (strcmp("exit", cRecvBuffer) == 0)
			{
				ExitSystem();
			}
		}
	}
	return 0;
}

//IP地址的正确检查
int CheckIP(char*cIP)
{
	char IPAddress[128];                     //IP地址字符串
	char IPNumber[4];                        //地址中每组的数值
	int iSubIP = 0;                          //IP地址中4段之一
	int iDot = 0;
	int iResult = 0;
	int iIPResult = 1;
	int i;
	memset(IPNumber, 0, 4);
	strncpy(IPAddress, cIP, 128);

	for (i = 0;IPAddress[i]!='\0';i++)
	{
		
		if (IPAddress[i] == '.')
		{
			iDot++;
			iSubIP = 0;
			if (atoi(IPNumber) > 255)
				iIPResult = 0;
			memset(IPNumber, 0, 4);
		}
		else
		{
			IPNumber[iSubIP++] = IPAddress[i];
			
		}
		if(iDot == 3 && iIPResult != 0) 
			iResult = 1;
	}
	return iResult;
}

void CreateClient()
{
	SOCKET m_SockClient;
	struct sockaddr_in clientaddr;
	char cServerIP[128];
	int iWhileIP = 10;                  //循环次数
	int iCnnRes;                        //连接结果
	DWORD nThreadld = 0;                //线程ID值
	char cSendBuffer[1024];             //发送缓存
	char cShowBuffer[1024];             //显示缓存
	char cRecvBuffer[1024];             //接收缓存
	int num;                            //接收的字符个数
	int ires;                           //发送消息的结果
	int iIPRes;                         //检查IP是否正确
	m_SockClient = socket(AF_INET, SOCK_STREAM, 0);
	printf("请输入服务器的地址：");
	scanf("%s", cServerIP);
	//IP地址判断
	if (strlen(cServerIP) == 0)
		strcpy(cServerIP, "127.0.0.1");          //没有输入地址，使用回环地址
	else
	{
		iIPRes = CheckIP(cServerIP);
		while (!iIPRes&&iWhileIP > 0)
		{
			printf("请输入服务器的地址：\n");
			scanf("%s", cServerIP);              //重新输入IP地址
			iIPRes = CheckIP(cServerIP);         //检测IP地址的合法性
			iWhileIP--;
			if (iWhileIP <= 0)
			{
				printf("输入次数过多\n");
				exit(0);
			}
		}
	}
	ioutfileClient = fopen("MessageServerClient.txt", "a");   //打开记录消息的文件
	clientaddr.sin_family = AF_INET;
	//客户端向服务端请求的端口号，应该和服务端绑定的一致
	clientaddr.sin_port = htons(4600);
	clientaddr.sin_addr.S_un.S_addr = inet_addr(cServerIP);
	iCnnRes = connect(m_SockClient, (struct sockaddr*)&clientaddr, sizeof(struct sockaddr));
	if (iCnnRes == 0)                                         //连接成功
	{
		num = recv(m_SockClient, cRecvBuffer, 1024,0);
		if (num > 0)
		{
			printf("Receive from severe :%s\n", cRecvBuffer);
			//启动接收消息的线程
			CreateThread(NULL, 0, threadproClient, (LPVOID)m_SockClient, 0, &nThreadld);
		}
		while (1)
		{
			memset(cSendBuffer, 0, 1024);
			scanf("%s", cSendBuffer);
			if (strlen(cSendBuffer) > 0)
			{
				ires = send(m_SockClient, cSendBuffer, strlen(cSendBuffer), 0);
				if (ires < 0)
				{
					printf("发送失败\n");
				}
				else
				{
					sprintf(cShowBuffer, "Send to :%s\n", cSendBuffer);                     //整理要显示的字符串
					printf("%s", cSendBuffer);
					fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileClient);//记录发送消息
					fflush(ioutfileClient);
				}
				if (strcmp("exit", cSendBuffer) == 0)
				{
					ExitSystem();
				}
			}
		}
	}
	else 
	{
		printf("连接不正确\n");
	}
}

//点对点退出实现
void ExitSystem()
{
	if (ioutfileServer != NULL)
		fclose(ioutfileServer);
	if (ioutfileClient != NULL)
		fclose(ioutfileClient);
	WSACleanup();
	exit(0);
}