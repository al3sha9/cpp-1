import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect(('127.0.0.1', 8080))

message = "Hello from client!"
client_socket.send(message.encode())

response = client_socket.recv(1024).decode()
print(f"Server replied: {response}")

client_socket.close()
