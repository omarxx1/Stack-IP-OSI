#include "datalink.h"
#include "physical.h"
#include <stdio.h>
#include <string.h>

#define FRAME_HEADER 0xAA
#define FRAME_FOOTER 0xBB

static unsigned char compute_checksum(const unsigned char *data, size_t len) {
  unsigned char sum = 0;
  for (size_t i = 0; i < len; i++) sum ^= data[i];
  return sum;
}

void datalink_send(const unsigned char *data, size_t len) {
  unsigned char frame[len + 3];
  frame[0] = FRAME_HEADER;
  memcpy(frame + 1, data, len);
  frame[len + 1] = compute_checksum(data, len);
  frame[len + 2] = FRAME_FOOTER;

  printf("[DataLink] Sending frame with checksum %02X\n", frame[len + 1]);
  physical_send(frame, len + 3);

  printf("\n");
  return;
}

void datalink_receive(const unsigned char *frame, size_t len) {
  if (len < 3 || frame[0] != FRAME_HEADER || frame[len-1] != FRAME_FOOTER) {
    printf("[DataLink] Frame error\n");
    return;
  }

  size_t data_len = len - 3;
  unsigned char data[data_len];
  memcpy(data, frame + 1, data_len);
  unsigned char checksum = frame[len - 2];

  if (compute_checksum(data, data_len) != checksum) {
    printf("[DataLink] Checksum error, discarding frame\n");
    return;
  }

  printf("[DataLink] Received valid frame, %zu bytes\n", data_len);
  extern void network_receive(const unsigned char *data, size_t len);
  network_receive(data, data_len);

  printf("\n");
  return;
}