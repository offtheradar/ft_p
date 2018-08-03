/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinesibous <yacinesibous@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:30:08 by yacinesibou       #+#    #+#             */
/*   Updated: 2018/08/02 20:27:59 by yacinesibou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    int                 r;
    char                buff[1024];
    int                 client_sock;
    unsigned int        cs_len;
    struct sockaddr_in  client_sock_in;

    if (ac != 2)
        usage(av[0]);
    port = ft_atoi(av[1]);
    sock = create_server(port);
    ft_putendl("Listening on port 3000");
    while (1)
    {
        cs_len = sizeof(client_sock_in);
        if ((client_sock = accept(sock, (struct sockaddr *)&client_sock_in, &cs_len)) < 0)
        {
            ft_putendl("Error accepting the client.");
            return (1);
        }
        if ((r = read(client_sock, buff, 1023)) > 0)
        {
            printf("received %d bytes: [%s]\n", r, buff);
        }    
    }
    close(sock);
    return (0);
}