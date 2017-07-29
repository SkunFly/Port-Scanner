#ifndef NETWORK_H
#define NETWORK_H

int socket_creation();
int connect_to(int socket, char* address, int port);
int is_valid_ip(char *ip_str);

#endif
