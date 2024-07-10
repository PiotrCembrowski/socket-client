#include <stdio.h>
#include <sys/socket.h>

int main(void) {

    socket(AF_INET, SOCK_STREAM, 0);

    return 0;
}
