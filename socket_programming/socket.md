socket is an endpoint for two-way communication between two process on a network.

### Client - Server model
![[Pasted image 20250908091459.png]]

### Structure
```c
struct sockaddr_in
{
	short   sin_family;
	u_short sin_port;
	struct in_addr sin_addr;
	char sin_zero[8];
};
```


### Function
- **socket**

create a socket descriptor that represents the endpoint
```c
int socket(int domain, int type, int protocol);
```
![[Pasted image 20250908095557.png]]

- **bind**

When an application has a socket descriptor, it can bind a unique name to the socket
```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```


- **listen**

The listen() API indicates a willingness to accept client connection requests
```c
int listen(int sockfd, int backlog);
```
The  `backlog`  argument defines the maximum length to which the queue of pending connections for sockfd may grow

- **accept**

Accept connection request
```c
 int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

- **connect**

Establish a connection to a socket
```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```