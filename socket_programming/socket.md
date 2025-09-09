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


### Blocking I/O Model

When a communication function(accept, recv, send, ...) it block the process until it's work is done 

![[Pasted image 20250909095144.png]]

### I/O multiplexing model

We block in a call to `select`, `poll`,... waiting for the datagram socket to be readable. When the function returns that the socket is readable, we then call the appropriate function to proceed data.

![[Pasted image 20250909095823.png]]

- poll
```c
int poll (struct pollfd *fdarray, unsigned long nfds, int timeout);
```
First argument in poll system call

```c
struct pollfd {
  int     fd;       /* descriptor to check */
  short   events;   /* events of interest on fd */
  short   revents;  /* events that occurred on fd */
};
```
The conditions to be tested are specified by the `events` member, and the function returns the status for that descriptor in the corresponding `revents` member
![[Pasted image 20250909100839.png]]

