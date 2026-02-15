#include <iostream>
#include <memory>
#include <string>
#include "tcpserver.h"
#include "Manager.h"

const int PORT = 3331;

int main() {
    auto manager = std::make_shared<Manager>();

    manager->createPhoto("Eiffel", "eiffel.jpg", 48.8, 2.2);
    manager->createVideo("Chat", "cat.mp4", 30);
    manager->createGroup("Vacances")->push_back(manager->createPhoto("Plage", "beach.jpg", 0, 0));

    std::cout << "--- Serveur Multimedia ---" << std::endl;

    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        return manager->processRequest(request, response);
    });

    std::cout << "Lancement du serveur sur le port " << PORT << std::endl;
    int status = server->run(PORT);

    if (status < 0) {
        std::cerr << "Erreur: Impossible de lancer le serveur !" << std::endl;
        return 1;
    }

    return 0;
}