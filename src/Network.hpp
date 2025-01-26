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
        socket.setBlocking(false);
    }
    int listen();
    int accept();
    int connectToServer(sf::IpAddress address);

    int send(sf::Packet &packet);
    int receive(sf::Packet &packet);

    sf::Socket::Status getConnectionStatus();

    void disconnect();
};
    