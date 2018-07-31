#include "../../includes/ft_p.h"
#include <stdio.h>

void    usage(char *str)
{
    printf("Usage: %s <port>\n", str);
    exit(-1);
}

int     create_server(int port)
{
    int                 sock;
    struct protoent     *proto;
    struct sockaddr_in  sin;

    if (!(proto = getprotobyname("tcp")))
        return (-1);
    sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);   
    sin.sin_family = AF_INET;
    sin.sin_port =  htons(port);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sock, (const struct sockaddr *)&sin, sizeof(sin));
    listen(sock, 42);
    return (sock);
}

int     main(int ac, char **av)
{
    int                 port;
    int                 sock;
    int                 client_sock;
    unsigned int        cs_len;
    struct sockaddr_in  client_sock_in;

    if (ac != 2)
        usage(av[0]);
    port = atoi(av[1]);
    sock = create_server(port);
    client_sock = accept(sock, (struct sockaddr *)&client_sock_in, &cs_len);
    close(client_sock);
    close(sock);
    return (0);
}