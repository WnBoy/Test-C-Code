#include<stdio.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")  
void CreateServer();
DWORD WINAPI threadproClient(LPVOID pParam);
DWORD WINAPI threadproServer(LPVOID pParam);
int CheckIP(char*cIP);
void CreateClient();
void ExitSystem();

//�ͻ��˷��͸�����˵���Ϣ����
#define CLIENTSEND_EXIT 1
#define CLIENTSEND_TRAN 2
#define CLIENTSEND_LIST 3

//����˷��͸��ͻ��˵���Ϣ����
#define SERVESEND_SELFID 1
#define SERVESEND_NEWUSR 2
#define SERVESEND_SHOWMSG 3
#define SERVESEND_ONLINE 4

//�����¼�����¼���ļ�ָ��
FILE*ioutfileServer;
FILE*ioutfileClient;

//������������Ϣ�Ľṹ�壬�ͻ���ʹ������ṹ��������
struct CReceivePackage
{
	int iType;              //�����������
	int iToID;             //���Ŀ���û�ID
	int iFromlD;          //���ԭ�û�ID
	char cBuffer[1024];  //�����Ϣ����
};

//����˷�����Ϣ�Ľṹ�壬������ʹ������ṹ��������
struct CSendPacksge
{
	int iType;             //��Ϣ����
	int iCurConn;         //��ǰ�û���������
	char cBuffer[1024];  //�����Ϣ����
};

//�������洢�����û���Ϣ�Ľṹ��
struct CUserSocketinfo
{
	int ID;                 //�û���ID
	char cDstIP[64];        //�û���IP��ַ����չʹ��
	int iPort;              //�û�Ӧ�ó���˿���չʹ��
	SOCKET sUserSocket;     //������
};

//�ͻ��˴洢�����û��б�Ľṹ��
struct CUser
{
	int ID;                //�û���ID
	char cDstIP[64];       //�û���IP��ַ��չʱʹ��
};

struct CUser usr[20];                  //�ͻ��˴洢�û���Ϣ�Ķ���
int bSend = 0;                         //�Ƿ���Է�������
int iMyself;                           //�Լ���ID
int iNew = 0;                          //�����û���
struct CUserSocketinfo usrinfo[20];    //����˴洢�û���Ϣ�Ķ���

int main(void)
{
	int iSel = 0;
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	do
	{
		printf("ѡ��������ͣ�\n");
		printf("��Ե����ˣ�1\n");
		printf("��Ե�ͻ��ˣ�2\n");
		printf("��������ת����ˣ�3\n");
		printf("��������ת�ͻ��ˣ�4\n");
		scanf("%d", &iSel);
	} while (iSel < 0 || iSel>4);
	switch (iSel)
	{
	case 1:CreateServer();break;
	case 2:CreateClient();break;
	
	}
	printf("�˳�ϵͳ\n");
	return 0;
}

void CreateServer()
{
	SOCKET m_SockServer;
	struct sockaddr_in serveraddr;     //���ص�ַ��Ϣ
	struct sockaddr_in serveraddrfrom; //���ӵĵ�ַ��Ϣ
	int iPort = 4600;  //�趨Ϊ�̶��˿�
	int iBindResult = -1;  //�󶨽��
	int iWhileCount = 200;
	struct hostent*localHost;
	char *localIP;
	SOCKET m_Server;
	char cWelcomBuffer[] = "Welcome to you\0";
	int len = sizeof(struct sockaddr);
	int iWhileListenCount = 10;
	DWORD nThreadld = 0;
	int ires;  //���͵ķ���ֵ
	char cSendBuffer[1024];//������Ϣ����
	char cShowBuffer[1024];//������Ϣ����
	ioutfileServer = fopen("MessageServer.txt", "a");  //�򿪼�¼��Ϣ���ļ�
	m_SockServer = socket(AF_INET, SOCK_STREAM, 0);
	printf("�����󶨵Ķ˿ں�(����1024��");
	scanf("%d", &iPort);
	localHost = gethostbyname("");
	localIP = inet_ntoa(*(struct in_addr*)*localHost->h_addr_list);
	//���������ַ��Ϣ
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(iPort);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);
	//�󶨵�ַ��Ϣ
	iBindResult = bind(m_SockServer, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr));
	//����˿ڲ��ܱ��󶨣��������ö˿�
	while (iBindResult != 0 && iWhileCount > 0)
	{
		printf("��ʧ�ܣ��������룺");
		scanf("%d", iPort);
		//���������ַ��Ϣ
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(iPort);
		serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);
		//�󶨵�ַ��Ϣ
		iBindResult = bind(m_SockServer, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr));
		iWhileCount--;
		if (iWhileCount < 0)
		{
			printf("�˿ڰ�ʧ�ܣ��������г���\n");
			exit(0);
		}
	}
	while (iWhileListenCount > 0)
	{
		printf("start listen\n");
		listen(m_SockServer, 0);//����ֵ�жϵ��������Ƿ�ʱ
		m_Server = accept(m_SockServer, (struct sockaddr*)&serveraddrfrom, &len);
		if (m_Server != INVALID_SOCKET)
		{
			//�����ӳɹ������ͻ�ӭ��Ϣ
			send(m_Server, cWelcomBuffer, sizeof(cWelcomBuffer), 0);
			//����������Ϣ���߳�
			CreateThread(NULL, 0, threadproServer, (LPVOID)m_Server, 0, &nThreadld);
			break;
		}
		printf(".");
		iWhileListenCount--;
		if (iWhileListenCount <= 0)
		{
			printf("\n��������ʧ��\n");
			exit(0);
		}
	}
	while (1)
	{
		memset(cSendBuffer, 0, 1024);
		scanf("%s", cSendBuffer);//������Ϣ
		if (strlen(cSendBuffer) > 0)//������Ϣ����Ϊ��
		{
			ires = send(m_Server, cSendBuffer, strlen(cSendBuffer), 0);//������Ϣ
			if (ires < 0)
			{
				printf("����ʧ��");
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

//�ͻ��˽�����Ϣ���߳�
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

//����˽�����Ϣ���߳�
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
			//��¼��Ϣ
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

//IP��ַ����ȷ���
int CheckIP(char*cIP)
{
	char IPAddress[128];                     //IP��ַ�ַ���
	char IPNumber[4];                        //��ַ��ÿ�����ֵ
	int iSubIP = 0;                          //IP��ַ��4��֮һ
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
	int iWhileIP = 10;                  //ѭ������
	int iCnnRes;                        //���ӽ��
	DWORD nThreadld = 0;                //�߳�IDֵ
	char cSendBuffer[1024];             //���ͻ���
	char cShowBuffer[1024];             //��ʾ����
	char cRecvBuffer[1024];             //���ջ���
	int num;                            //���յ��ַ�����
	int ires;                           //������Ϣ�Ľ��
	int iIPRes;                         //���IP�Ƿ���ȷ
	m_SockClient = socket(AF_INET, SOCK_STREAM, 0);
	printf("������������ĵ�ַ��");
	scanf("%s", cServerIP);
	//IP��ַ�ж�
	if (strlen(cServerIP) == 0)
		strcpy(cServerIP, "127.0.0.1");          //û�������ַ��ʹ�ûػ���ַ
	else
	{
		iIPRes = CheckIP(cServerIP);
		while (!iIPRes&&iWhileIP > 0)
		{
			printf("������������ĵ�ַ��\n");
			scanf("%s", cServerIP);              //��������IP��ַ
			iIPRes = CheckIP(cServerIP);         //���IP��ַ�ĺϷ���
			iWhileIP--;
			if (iWhileIP <= 0)
			{
				printf("�����������\n");
				exit(0);
			}
		}
	}
	ioutfileClient = fopen("MessageServerClient.txt", "a");   //�򿪼�¼��Ϣ���ļ�
	clientaddr.sin_family = AF_INET;
	//�ͻ�������������Ķ˿ںţ�Ӧ�úͷ���˰󶨵�һ��
	clientaddr.sin_port = htons(4600);
	clientaddr.sin_addr.S_un.S_addr = inet_addr(cServerIP);
	iCnnRes = connect(m_SockClient, (struct sockaddr*)&clientaddr, sizeof(struct sockaddr));
	if (iCnnRes == 0)                                         //���ӳɹ�
	{
		num = recv(m_SockClient, cRecvBuffer, 1024,0);
		if (num > 0)
		{
			printf("Receive from severe :%s\n", cRecvBuffer);
			//����������Ϣ���߳�
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
					printf("����ʧ��\n");
				}
				else
				{
					sprintf(cShowBuffer, "Send to :%s\n", cSendBuffer);                     //����Ҫ��ʾ���ַ���
					printf("%s", cSendBuffer);
					fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileClient);//��¼������Ϣ
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
		printf("���Ӳ���ȷ\n");
	}
}

//��Ե��˳�ʵ��
void ExitSystem()
{
	if (ioutfileServer != NULL)
		fclose(ioutfileServer);
	if (ioutfileClient != NULL)
		fclose(ioutfileClient);
	WSACleanup();
	exit(0);
}