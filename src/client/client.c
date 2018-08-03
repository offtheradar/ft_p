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
    char                line[400];
    char                server_reply[2000];
    
    if (ac != 3)
        usage(av[0]);
    port = atoi(av[2]);
    sock = create_client(av[1], port);
    ft_putstr("Connecting to port 3000\nft_p>");
    while (1)
    {   
        ft_putendl("ft_p> ");
        scanf("%s", line);
        if (send(sock, line, ft_strlen(line), 0) < 0)
        {
            puts("Send failed.");
            return (1);
        }
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
    }
    close(sock);
    return (0);
}