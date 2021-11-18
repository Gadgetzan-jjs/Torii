//
// Created by andilyliao on 16-12-6.
//

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "Analyse.h"
#include "File.h"
#include "doepoll.h"
#include "math.h"
#define MAXSIZE     1024
#define IPADDRESS   "127.0.0.1"
#define SERV_PORT   8080
#define FDSIZE        1024
#define EPOLLEVENTS 20
#define LISTENQ     5
#include "InitConfig.h"
//void add_event(int epollfd,int fd,int state);
//void delete_event(int epollfd,int fd,int state);
//void modify_event(int epollfd,int fd,int state);

//=============================================================================================
/*函数声明*/
/*创建套接字并进行绑定*/
int socket_bind(const char* ip,int port);
Config *config=(Config *)malloc(sizeof(Config));
int init_config(char * filepath){
    config->conffilepath=(char *)malloc(101);
    config->port=(char *)malloc(6);
    config->ipaddress=(char *)malloc(15);
    confconfig(config,filepath);
    int portlen=strlen(config->port);
    int port=0;
    for (int i = 0; i < portlen; ++i) {
        port+=(pow(10,(portlen-i-1)))*(config->port[i]-48);
    }
    return port;
}
int serverepoll(char * filepath){
    int port=init_config(filepath);
    int  listenfd;
    listenfd = socket_bind(config->ipaddress,port);
    listen(listenfd,LISTENQ);//listen进行了进入内核三次握手，之后又返回出来。
//c语言想要广播，得自己去配置。

    do_epoll(listenfd);
    return 0;
}
int socket_bind(const char* ip,int port){
    int  listenfd;
    struct sockaddr_in servaddr;
    listenfd = socket(AF_INET,SOCK_STREAM,0);

    if (listenfd == -1){
        close(listenfd);
        perror("socket error:");
        exit(1);
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&servaddr.sin_addr);
    servaddr.sin_port = htons(port);

    if (bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) == -1){
        close(listenfd);
        perror("bind error: ");

        exit(1);
    }
    return listenfd;
}




