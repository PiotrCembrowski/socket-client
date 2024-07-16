#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(void) {

    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    char* ip = "142.250.188.46";
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);

    int result = connect(socket_file_descriptor, &address, sizeof address );

    if(result == 0)
        printf("Connection was successful.\n");

    char* buffer;
    buffer = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socket_file_descriptor,buffer, strlen(buffer), 0);

    return 0;
}
