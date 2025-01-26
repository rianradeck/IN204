/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Handles network communication between the players, just as receiving and sending packets through the established network connection
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Network.hpp"
#include <iostream>

int NetworkManager::listen() {
    socket.setBlocking(false);
    std::cout << socket.getRemoteAddress() << std::endl;
    if (socket.getRemoteAddress() != sf::IpAddress::None) {
        connectionStatus = sf::Socket::Done;
        std::cout << "Already connected to a client" << std::endl;
        return 0;
    }
    if (listener.listen(serverPort) != sf::Socket::Done) {
        std::cerr << "Error starting server" << std::endl;
        return -1;
    }
    std::cout << "Server started " << myAddress << ":" << serverPort << std::endl;
    std::cout << "Waiting for connection - Is blocking? " << (listener.isBlocking() ? "Yes" : "No") << std::endl;
    
    return 0;
}

int NetworkManager::accept() {
    if ((connectionStatus = listener.accept(socket)) != sf::Socket::Done) {
        // std::cerr << "No connection to accept" << std::endl;
        return -1;
    }
    std::cout << "Connection accepted" << std::endl;

    return 0;
}

int NetworkManager::connectToServer(sf::IpAddress address) {
    if ((connectionStatus = socket.connect(address, serverPort)) != sf::Socket::Done) {
        std::cerr << "Error connecting to server" << std::endl;
        return -1;
    }
    std::cout << "Connected to server" << std::endl;

    return 0;
}

int NetworkManager::send(sf::Packet &packet) {
    if (socket.send(packet) != sf::Socket::Done) {
        std::cerr << "Error sending packet" << std::endl;
        return -1;
    }

    return 0;
}

int NetworkManager::receive(sf::Packet &packet) {
    if (socket.receive(packet) != sf::Socket::Done) {
        std::cerr << "Error receiving packet" << std::endl;
        return -1;
    }

    return 0;
}

sf::Socket::Status NetworkManager::getConnectionStatus() {
    return connectionStatus;
}

void NetworkManager::disconnect() {
    socket.setBlocking(true);
    socket.disconnect();
    listener.close();
    connectionStatus = sf::Socket::Disconnected;
}

bool NetworkManager::isServer() {
    return socket.isBlocking() == false;
}