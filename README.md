# httpServer

own implementation of
* https://github.com/OsasAzamegbe/http-server
* https://osasazamegbe.medium.com/showing-building-an-http-server-from-scratch-in-c-2da7c0db6cb7

In summary, our server will have a socket that:

* listens for incoming network connections and puts them on a Queue
* accepts a network connection from the Queue one at a time
* reads the data (Request) sent from the client over the network connection
* sends data (Response) to the client over the network connection.

## socket 

définition d'un socket pour les connexions serveur