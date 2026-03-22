#include "transport.h"
#include "network.h"
#include <stdio.h>
#include <string.h>

#define MAX_SEGMENT_SIZE 8

void transport_send(const unsigned char *data, size_t len, unsigned char src_port, unsigned char dest_port) {
  size_t offset = 0;
  while (offset < len) {
    size_t chunk = (len - offset > MAX_SEGMENT_SIZE) ? MAX_SEGMENT_SIZE : len - offset;
    unsigned char segment[chunk+2];
    segment[0] = src_port;
    segment[1] = dest_port;
    memcpy(segment + 2, data + offset, chunk);
    printf("[Transport] Sending segment %zu bytes\n", chunk + 2);
    network_send(segment, chunk+2, 0x01, 0x02);
    offset += chunk;
  }

  printf("\n");
  return;
}

void transport_receive(const unsigned char *segment, size_t len) {
  if (len < 2) return;
  unsigned char src_port = segment[0];
  unsigned char dest_port = segment[1];
  size_t data_len = len - 2;
  unsigned char data[data_len];
  memcpy(data, segment + 2, data_len);

  printf("[Transport] Received segment from port %02X to %02X, %zu bytes\n", src_port, dest_port, data_len);
  extern void session_receive(const unsigned char *data, size_t len);
  session_receive(data, data_len);

  printf("\n");
  return;
}