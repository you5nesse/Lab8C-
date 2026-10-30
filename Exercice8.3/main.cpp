#include <iostream>
#include <vector>
#include <memory>
#include "Plugin.h"

int main(){
    std::cout << "Entrez votre texte :\n";
    std::string texte;
    std::getline(std::cin, texte);

    // Simulation chargement dynamique
    std::vector<std::unique_ptr<Plugin>> plugins;
    plugins.push_back(Plugin::creerPlugin("correcteur"));
    plugins.push_back(Plugin::creerPlugin("traducteur"));
    plugins.push_back(Plugin::creerPlugin("analyseur"));

    std::string courant = texte;
    for(auto& p : plugins){
        courant = p->traiter(courant);
        std::cout << "\n--- Apres [" << p->nom() << "] ---\n";
        std::cout << courant << "\n";
    }
    return 0;
}
