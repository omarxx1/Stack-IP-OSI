#include "network.h"
#include "datalink.h"
#include <stdio.h>
#include <string.h>

void network_send(const unsigned char *data, size_t len, unsigned char src, unsigned char dest) {
  unsigned char packet[len + 2];
  packet[0] = src;
  packet[1] = dest;
  memcpy(packet + 2, data, len);

  printf("[Network] Routing packet from %02X to %02X, %zu bytes\n", src, dest, len+2);
  datalink_send(packet, len + 2);

  printf("\n");
  return;
}

void network_receive(const unsigned char *packet, size_t len) {
  if (len < 2) return;
  unsigned char src = packet[0];
  unsigned char dest = packet[1];
  size_t data_len = len - 2;
  unsigned char data[data_len];
  memcpy(data, packet + 2, data_len);

  printf("[Network] Packet from %02X to %02X\n", src, dest);
  extern void transport_receive(const unsigned char *data, size_t len);
  transport_receive(data, data_len);

  printf("\n");
  return;
}