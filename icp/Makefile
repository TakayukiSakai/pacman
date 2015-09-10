
fifo: fifo_sender.c fifo_receiver.c
	clang ./fifo_sender.c -o fifo_sender.out
	clang ./fifo_receiver.c -o fifo_receiver.out

socket: socket_sender.c socket_receiver.c
	clang ./socket_sender.c -o socket_sender.out
	clang ./socket_receiver.c -o socket_receiver.out

server: ./stage1/http_server.c ./stage1/http_client.c
	clang ./stage1/http_server.c -o server.out
	clang ./stage1/http_client.c -o client.out

clean:
	rm *.out
