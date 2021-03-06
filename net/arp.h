/*
 *	Copied from Linux Monitor (LiMon) - Networking.
 *
 *	Copyright 1994 - 2000 Neil Russell.
 *	(See License)
 *	Copyright 2000 Roland Borde
 *	Copyright 2000 Paolo Scaffardi
 *	Copyright 2000-2002 Wolfgang Denk, wd@denx.de
 *	SPDX-License-Identifier:	GPL-2.0
 */

#ifndef __ARP_H__
#define __ARP_H__

#include <common.h>

extern IPaddr_t	NetArpWaitPacketIP;
/* MAC address of waiting packet's destination */
extern uchar *NetArpWaitPacketMAC;
extern int NetArpWaitTxPacketSize;
extern ulong NetArpWaitTimerStart;
extern int NetArpWaitTry;

void ArpInit(void);
void ArpRequest(void);
void arp_raw_request(IPaddr_t sourceIP, const uchar *targetEther,
	IPaddr_t targetIP);
int ArpTimeoutCheck(void);
void ArpReceive(struct ethernet_hdr *et, struct ip_udp_hdr *ip, int len);

#endif /* __ARP_H__ */
