#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define MAXLINE 80
#define SERV_PORT 8000

const char *inet_ntop(int af, const void *src, char *dst, socklen_t cnt);//这个函数转换网络二进制结构到ASCII类型的地址，参数的作用和上面相同，只是多了一个参数socklen_t cnt,他是所指向缓存区dst的大小，避免溢出，如果缓存区太小无法存储地址的值，则返回一个空指针，并将errno置为ENOSPC
int toupper(int c);

int main(void)
{
    /* Structure describing a generic socket address.  */
    struct sockaddr;
    /* Structure describing an Internet socket address.  */
    struct sockaddr_in servaddr, cliaddr; // sockaddr_in中的成员struct in_addr sin_addr表示32位的IP地址。但是我们通常用点分十进制的字符串表示IP地址,https://blog.csdn.net/will130/article/details/53326740
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    bind(listenfd, (struct sockaddr *)&servaddr,
    sizeof(servaddr));
    listen(listenfd, 20);
    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd,
        (struct sockaddr *)&cliaddr,
        &cliaddr_len);
        n = read(connfd, buf, MAXLINE);
        printf("received from %s at PORT %d\n",
        inet_ntop(AF_INET, &cliaddr.sin_addr, str,
        sizeof(str)),
        ntohs(cliaddr.sin_port));
        for (i = 0; i < n; i++)
        buf[i] = toupper(buf[i]);
        write(connfd, buf, n);
        close(connfd);
    }
}