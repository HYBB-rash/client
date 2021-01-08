#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 100
int main () {

    char buffer[BUF_SIZE];

    while (true) {
        scanf("%s", buffer);
        if (strcmp(buffer, "stop") == 0) break;

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(1234);
        connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
        send(sock, buffer, strlen(buffer), 0);
        recv(sock, buffer, BUF_SIZE, 0);
        printf("Message: %s\n", buffer);
        memset(buffer, 0, BUF_SIZE);
        close(sock);
    }
    return 0;
}