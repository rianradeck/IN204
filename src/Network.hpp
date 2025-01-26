/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Definition of class for network handlers
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <SFML/Network.hpp>

class NetworkManager {
private:
    sf::TcpListener listener;
    sf::TcpSocket socket;
    sf::IpAddress serverAddress, myAddress;
    unsigned short serverPort;
    sf::Socket::Status connectionStatus;
public:
    NetworkManager() : serverPort(25564), myAddress(sf::IpAddress::getLocalAddress()) {
        listener.setBlocking(false);
        socket.setBlocking(true);
    }
    int listen();
    int accept();
    int connectToServer(sf::IpAddress address);

    int send(sf::Packet &packet);
    int receive(sf::Packet &packet);

    template <typename T>
    int send_data(T data) {
        sf::Packet packet;
        packet << data;
        return send(packet);
    }

    template <typename T>
    int receive_data(T &data) {
        sf::Packet packet;
        int status = receive(packet);
        if (status == 0) {
            packet >> data;
        }
        return status;
    }

    sf::Socket::Status getConnectionStatus();

    void disconnect();
    bool isServer();
};
    