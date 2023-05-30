import socket

class Client:
    def __init__(self, server_host, server_port):
        self.server_host = server_host
        self.server_port = server_port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def __del__(self):
        self.close()

    def connect(self):
        try:
            self.socket.connect((self.server_host, self.server_port))
            print("Connecté au serveur {} sur le port {}".format(self.server_host, self.server_port))
        except ConnectionRefusedError:
            print("Impossible de se connecter au serveur")

    def send_message(self, message):
        try:
            self.socket.sendall(message.encode())
        except ConnectionResetError:
            print("La connexion avec le serveur a été interrompue")

    def receive_message(self):
        try:
            message = self.socket.recv(1024)
            return message.decode()
        except ConnectionResetError:
            print("La connexion avec le serveur a été interrompue")
            return None

    def close(self):
        self.socket.close()
        print("Connexion fermée")
