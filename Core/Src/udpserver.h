/*
 * udpserver.h
 *
 *  Created on: Jul 22, 2026
 *      Author: dogukan.tuncer
 */

#ifndef INC_UDPSERVER_H_
#define INC_UDPSERVER_H_
void udpServer_init(void);
void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);


#endif /* INC_UDPSERVER_H_ */
