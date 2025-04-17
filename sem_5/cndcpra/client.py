import socket

socketClient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socketClient.connect(('127.0.0.1', 8080))

message = "Hello ali shan from client"
socketClient.send(message.encode())

response = socketClient.recv(1024).decode()
print(f"server replied {response}")

socketClient.close()
