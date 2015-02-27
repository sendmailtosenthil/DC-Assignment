# DC-Assignment

The dictionary.x file is having definition for interface
You can generate stubs using below command

rpcgen -C dictionary.x

Client compliation is as follows
cc -o client client.c  dictionary_clnt.c dictionary_xdr.c -lnsl
This will generate exe called client (2nd param). Please change to different name.

Server compilation is as follows
cc -o server -DRPC_SVC_FG server.c dictionary_svc.c dictionary_xdr.c -lnsl
This will generate exe called server (2nd param). Please change to different name.

How to use?

1. Run server in a first terminal
2. Run client in second terminal.
	Client will ask you to provide host name.
	You will be asked to enter I or S or D option

Play with it.

References
	https://www.cs.rutgers.edu/~pxk/rutgers/notes/content/ra-sunrpc.pdf  -> Good to understand
	http://docs.freebsd.org/44doc/psd/23.rpc/paper.pdf -> More information about RPC internals
	http://www.eng.auburn.edu/cse/classes/cse605/examples/rpc/stevens/SUNrpc.html - Sample date program
	http://stackoverflow.com/questions/10448696/error-on-trying-to-run-a-simple-rpc-progarm - Any error in running simple RPC
	http://www.tutorialspoint.com/compile_c_online.php - Online C compiler to play with
	https://cs.nyu.edu/courses/spring00/V22.0480-002/class07.html -> Data structures available in RPC
