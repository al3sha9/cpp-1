import socket

socketListen = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socketListen.bind(('127.0.0.0', 8080))
socketListen.listen(5)

print("Server is listening at 8080")

while True:
        sNew, addr = socketListen.accept()
        print(f"connected to port {addr}")

        data = sNew.recv(1024).decode()
        print(f"Recied from client: {data}")

        response = f"Hello you said: {data}"
        sNew.send(response.encode())

        sNew.close()
        print("connection closed")
