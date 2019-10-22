//
// Created by 1655664358@qq.com on 2019/9/30.
//

//#include <stdio.h>
//
//#include <winsock2.h>
//#include <string.h>
//#include <stdlib.h>
//#include <windows.h>
//#pragma comment(lib,"ws2_32.ib")
//
//int main()
//{
//
//    WSADATA wsadata;
//
//    WSAStartup(MAKEWORD(2,2),&wsadata);
//
//    SOCKET sockfd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
//
//    struct sockaddr_in address;
//    memset(&address,0, sizeof(address));
//    address.sin_family = AF_INET;
//    address.sin_port = htons(9501);
//    address.sin_addr.s_addr = inet_addr("47.110.136.62");
//
//    connect(sockfd,(SOCKADDR*)&address, sizeof(address));
//
//    char *str = "GET /testi HTTP/1.1\r\n";
//    send(sockfd,str, strlen(str)+ sizeof(char),0);
//
//    char content[1024] = {0};
//    recv(sockfd,content, sizeof(content),0);
//    printf("content=%s\n",content);
//    closesocket(sockfd);
//    closesocket(sockfd);
//
//    WSACleanup();
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll
int main(){
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //向服务器发起请求
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("47.110.136.62");
    sockAddr.sin_port = htons(9501);
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    char *request = "GET /index.asp HTTP/1.1\r\n"
                    "Accept:image/gif.image/jpeg,*/*\r\n"
                    "Accept-Language:zh-cn\r\n"
                    "Connection:Keep-Alive\r\n"
                    "Host:localhost\r\n"
                    "User-Agent:Mozila/4.0(compatible;MSIE5.01;Window NT5.0)\r\n"
                    "Accept-Encoding:gzip,deflate\r\n"
                    " \r\n"
                    "username=jinqiao&password=1234";
    int ret = send(sock,request,strlen(request),0);
    printf("send result: %d\n", ret);
    //接收服务器传回的数据
    char szBuffer[MAXBYTE] = {0};
    ret = recv(sock, szBuffer, MAXBYTE, 0);
    //输出接收到的数据
    printf("Message form server: %s%d\n", szBuffer,ret);
    //关闭套接字
    closesocket(sock);
    //终止使用 DLL
    WSACleanup();
    system("pause");
    return 0;
}