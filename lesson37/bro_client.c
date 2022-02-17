#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main() {

    // 1.创建一个通信的socket
    int fd = socket(PF_INET, SOCK_DGRAM, 0);
    
    if(fd == -1) {
        perror("socket");
        exit(-1);
    }   

    // 服务器的地址信息
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(fd, (struct sockaddr*)&saddr, sizeof(saddr));
    
    int num = 0;
    // 3.通信
    while(1) {

        // 发送数据
        char recvBuf[128];

        // 接收数据
        int num = recvfrom(fd, recvBuf, sizeof(recvBuf), 0, NULL, NULL);
        printf("server say : %s\n", recvBuf);

    }

    close(fd);
    return 0;
}