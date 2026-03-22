#include "session.h"
#include "transport.h"
#include <stdio.h>

static unsigned char SESSION_ID = 0x01;

void session_send(const unsigned char *data, size_t len) {
  printf("[Session %02X] Sending data %zu bytes\n", SESSION_ID, len);
  transport_send(data, len, 0x10, 0x20);

  printf("\n");
  return;
}

void session_receive(const unsigned char *data, size_t len) {
  printf("[Session %02X] Received data %zu bytes\n", SESSION_ID, len);
  extern void presentation_receive(const unsigned char *data, size_t len);
  presentation_receive(data, len);

  printf("\n");
  return;
}