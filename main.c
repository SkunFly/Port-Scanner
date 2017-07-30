#include <stdio.h>
#include <stdlib.h>
#include "network.h"

#define MAX_PORT 4500


void portscanner(char* ip, int init, int end){
  int socket = socket_creation();
  int open_ports[MAX_PORT];
  int i = init, index = 0;

  printf("Starting portscanning...\n");
  while(i <= end){
    printf("Port %d: ", i);
    if(connect_to(socket, ip, i)){
      printf("Open\n");
      open_ports[index++] = i;
    } else { printf("Closed\n"); }
    i++;
  }
  printf("\n\nScan Completed\nOpen ports: ");
  if(index == 0){
    printf("None");
  } else{
    for(i = 0; i < index; i++)
      printf("%d ", open_ports[i]);
  }
  puts("");
}

int main(int argc, char** argv){
  int init, end;
  switch (argc) {
    case 2:
      portscanner(argv[1], 1, MAX_PORT);
      break;
    case 4:
      init = atoi(argv[2]);
      end = atoi(argv[3]);
      if(init > 0 && end > 0 && end >= init && end <=  MAX_PORT)
        portscanner(argv[1], init, end);
      break;
    case 1:
    case 3:
    default:
      printf("Usage: portscanner ip [first port] [last port]\n");
  }
  return 0;
}
