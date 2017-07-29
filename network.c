#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DELIM "."

int socket_creation(){
  int sock;
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    perror("\nSocket creation error");
    exit(-1);
  }
  return sock;
}


/*
  Upon successful connection, returns 1. Otherwise, returns 0.
*/
int connect_to(int socket, char* address, int port){
  struct sockaddr_in serv_addr;
  struct hostent *host;
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(&host, '0', sizeof(host));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  if((inet_pton(AF_INET, address, &serv_addr.sin_addr)) == 1){
    //printf("Valid ip address...\n");
  }else if((host = gethostbyname(address)) != 0){
    //printf("Ip address resolved...\n");
    strncpy((char*)&serv_addr.sin_addr , (char*)host->h_addr , sizeof serv_addr.sin_addr);
  }else{
    perror("Invalid ip adress");
    exit(-1);
  }

  if(connect(socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0){
    return 0;
  }else{
    return 1;
  }
}
