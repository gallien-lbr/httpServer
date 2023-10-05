# httpServer

own implementation of
https://github.com/OsasAzamegbe/http-server

In summary, our server will have a socket that:

* listens for incoming network connections and puts them on a Queue
* accepts a network connection from the Queue one at a time
* reads the data (Request) sent from the client over the network connection
* sends data (Response) to the client over the network connection.