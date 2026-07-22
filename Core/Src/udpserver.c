/*
 * udpserver.c
 *
 *  Created on: Jul 22, 2026
 *      Author: dogukan.tuncer
 */
#include "lwip/udp.h"
#include "lwip/pbuf.h"
#include <string.h>
void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
    if (p != NULL)
    {

        /* Gelen pakete karşılık echo (yankı) yaniti gonder */
        udp_sendto(upcb, p, addr, port);

        /* İşimiz bittiğinde pbuf'ı serbest bırakmalıyız */
        pbuf_free(p);
    }
}
void udpServer_init(void)
{
    struct udp_pcb *upcb;
    err_t err;

    /* 1. Create a new UDP control block */
    upcb = udp_new();

    /* 2. Bind the upcb to the STM32 static IP and port 7 */
    ip_addr_t myIPADDR;
    IP_ADDR4(&myIPADDR, 192, 168, 0, 111);

    err = udp_bind(upcb, &myIPADDR, 7);

    /* 3. Register the receive callback if bind succeeded */
    if(err == ERR_OK)
    {
        udp_recv(upcb, udp_receive_callback, NULL);
    }
    else
    {
        udp_remove(upcb);
    }
}

