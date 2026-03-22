#include "application.h"
#include <string.h>
#include <stdio.h>

int main() {
  printf("\n\n");
  char msg[200]; //*msg = NULL; // "Questo è un test completo dello stack OSI in C! Vediamo tutti i layer in azione.";
  
  printf("Inserisci un comando(msg)> ");  // prompt
    fgets(msg, sizeof(msg), stdin);       // leggi input utente

    printf("\n=> Hai scritto: %s", msg); printf("\n");


  printf("=== Avvio dello stack OSI ===\n\n");

  application_send((const unsigned char*)msg, strlen(msg));

  printf("=== Messaggio inviato attraverso tutti i layer ===\n");
  return 0;
}