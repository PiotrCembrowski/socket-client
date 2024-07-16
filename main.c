#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int createTCPIpv4Socket();

void createIPv4Address();

int main(void) {

    int socket_file_descriptor = createTCPIpv4Socket();

    struct sockaddr_in address;
    createIPv4Address(&address);

    int result = connect(socket_file_descriptor, &address, sizeof address );

    if(result == 0)
        printf("Connection was successful.\n");

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socket_file_descriptor,message, strlen(message), 0);

    char buffer[1024];
    recv(socket_file_descriptor, buffer, 1024, 0);

    printf("Response was %s ", buffer);

    return 0;
}

int createTCPIpv4Socket(void) {
    return socket(AF_INET, SOCK_STREAM, 0);
}

void createIPv4Address(struct sockaddr_in *address) {
    char* ip = "142.250.188.46";
    address->sin_family = AF_INET;
    address->sin_port = htons(80);
    inet_pton(AF_INET, ip, &address->sin_addr.s_addr);
}