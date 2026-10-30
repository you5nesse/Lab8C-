#ifndef HAUTPARLEUR_H
#define HAUTPARLEUR_H
#include<SortieAudio.h>

class HautParleur : public SortieAudio {
public:
    void ouvrir() override {
        std::cout << "[HautParleur] Initialisation du driver" << std::endl;
    }
    void jouer(const std::string& son) override {
        std::cout << "[HautParleur] Lecture: " << son << std::endl;
    }
    void fermer() override {
        std::cout << "[HautParleur] Arret" << std::endl;
    }
};

#endif // HAUTPARLEUR_H
