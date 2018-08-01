#include "../../includes/ft_p.h"
#include <stdio.h>

void    usage(char *str)
{
    printf("Usage: %s <addr> <port>\n", str);
    exit(-1);
}

int     create_client(char *addr, int port)
{
    int                 sock;
    struct protoent     *proto;
    struct sockaddr_in  sin;

    if (!(proto = getprotobyname("tcp")))
        return (-1);
    sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);   
    sin.sin_family = AF_INET;
    sin.sin_port =  htons(port);
    sin.sin_addr.s_addr = inet_addr(addr);
    if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
        printf("Connection error.\n");
        return (-1);
    }
    return (sock);
}

int     main(int ac, char **av)
{
    int                 port;
    int                 sock;
    
    if (ac != 3)
        usage(av[0]);
    port = atoi(av[2]);
    sock = create_client(av[1], port);
    write(sock, "hello!", 6);
    close(sock);
    return (0);
}