import socket

s_listen = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s_listen.bind(('127.0.0.1', 8080))
s_listen.listen(5)

print("Server is listening on port 8080...")

while True:
    s_new, addr = s_listen.accept()
    print(f"Connected to {addr}")

    data = s_new.recv(1024).decode()
    print(f"Received from client: {data}")

    response = f"Hello, you said: {data}"
    s_new.send(response.encode())

    s_new.close()
    print("Connection closed.\n")
