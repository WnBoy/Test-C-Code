#include <stdio.h>			//printf
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	//printf("Hello World\n");

	//1.�����׽��ֿ� �汾��2.2
	//unsigned short
	//typedef  �����е����������
	WORD wVersionRequested = MAKEWORD(2,2);
	WSADATA wsaData;

	//�ɹ����أ�0��ʧ�ܷ��ط�0
	int nErr = WSAStartup(wVersionRequested, &wsaData);

	if (nErr != 0)
	{
		printf("�����׽��ֿ�ʧ��.\n");
		return 0;
	}

	//2.�жϼ��ص��׽��ֿ�汾���Ƿ�һ��
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("���ص��׽��ֿ�汾��һ��.\n");
		return 0;
	}

	//3.�����׽���
	SOCKET sockSrv = socket(
			AF_INET,	//��ַ��
			SOCK_STREAM,//�׽��ֵ�����
			0			//�ض���ַ����ص�Э��
			);

	//h :host�� to :�� ;n:net; l: long �ĸ��ֽڣ�s:short������ 2���ֽ�
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//�������ֽ�˳��ת��Ϊ�����ֽ�˳��
	addrSrv.sin_family	= AF_INET;
	addrSrv.sin_port = htons(8000); //0-65535  0-1024 ϵͳ�˿ں� 1024���ϣ��û��Զ���˿ں�

	//4.���׽���
	if (SOCKET_ERROR == bind(
		sockSrv,				//Ҫ�󶨵��׽���
		(SOCKADDR*)&addrSrv,	//ָ�����׽��ֱ��ص�ַ��Ϣ
		sizeof(SOCKADDR)		//��ַ�ṹ�ĳ���
		))
	{
		printf("���׽���ʧ��\n");
		return 0;
	}

	//5.����
	if (SOCKET_ERROR == listen(
		sockSrv,	//Ҫ�������׽���
		5			//�ȴ����Ӷ��е���󳤶�
		))
	{
		printf("����ʧ��\n");
		return 0;
	}

	
	SOCKADDR_IN addrClient;
	int nLength = sizeof(SOCKADDR);

	while (1)
	{
		//6.�ȴ��ͻ��˵�����
		SOCKET sockConn = accept(
			sockSrv,				//�Ѿ��Ǵ��ڼ���״̬���׽���
			(SOCKADDR*)&addrClient,	//�������տͻ��˵ĵ�ַ��Ϣ	
			&nLength				//���ص�ַ��Ϣ�ĳ��ȴ�С
			);

	
		//7.�������ݸ��ͻ���
		char szSendBuffer[100];
		sprintf(szSendBuffer, "��ϲ�� : %s�������Ϸ�����.", inet_ntoa(addrClient.sin_addr));
		

		send(
			sockConn,				//�Ѿ��������ӵ��׽���
			szSendBuffer,			//���͵�����
			strlen(szSendBuffer)+1,	//�ַ�������
			0
			);

		//8.����һ�¿ͻ��˷�����������
		char szRecvBuffer[100];
		memset(szRecvBuffer, 0, 100);
		recv(sockConn, szRecvBuffer, 100, 0);
		printf("�ͻ���˵��%s.\n", szRecvBuffer);
	}

	return 0;
}