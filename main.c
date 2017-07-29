#include <stdio.h>
#include "network.h"

#define MAX_PORT 4500


void portscanner(char* ip){
  int socket = socket_creation();
  int open_ports[MAX_PORT];
  int i = 1, index = 0;

  printf("Starting portscanning...\n");
  while(i <= MAX_PORT){
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

int main(){
  portscanner("google.com");
  return 0;
}
