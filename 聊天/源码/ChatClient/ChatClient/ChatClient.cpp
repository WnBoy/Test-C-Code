#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	//1.�����׽��ֿ� �汾��2.2
	WORD wVersionRequested = MAKEWORD(2,2);
	WSADATA wsaData;

	int nErr = WSAStartup(wVersionRequested, &wsaData);
	
	if (nErr != 0)
	{
		printf("�����׽��ֿ�ʧ��.\n");
		return 0;
	}

	//2.�жϼ����׽��ֿ�汾�Ƿ�������Ҫ���ص�һ��
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion)!=2)
	{
		printf("���ص��׽��ֿ�汾�Ų�һ��.\n");
		return 0;
	}

	//3.�����׽���
	SOCKET sockClient = socket(
		AF_INET,	//��ַ��
		SOCK_STREAM,//��ʽ�׽���
		0
		);

	//4.���ӷ����� 127.0.0.1 
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("172.16.201.114");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(8000);

	//�������������������
	if (SOCKET_ERROR == connect(
		sockClient,				//�����������ӵ��׽���
		(SOCKADDR*)&addrSrv,	//�������ĵ�ַ��Ϣ
		sizeof(SOCKADDR)		//�������˵�ַ�ĳ���
		))
	{
		int nError = GetLastError();
		printf("���ӷ�����ʧ��,�������:%d.\n", nError);
		return 0;
	}

	//5.��������
	char szRecvBuffer[100];
	memset(szRecvBuffer, 0, 100);

	recv(sockClient, szRecvBuffer, 100, 0);

	printf("������˵:%s.\n",szRecvBuffer);

	//6.��������
	char szSendBuffer[100]="���Ǹ��ڵ�����";
	send(sockClient, szSendBuffer, strlen(szSendBuffer)+1, 0);

	return 0;
}