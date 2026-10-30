#ifndef SORTIEHDMI_H
#define SORTIEHDMI_H
#include<SortieAudio.h>
class SortieHDMI : public SortieAudio {
public:
    void ouvrir() override {
        std::cout << "[SortieHDMI] Handshake HDMI / ARC" << std::endl;
    }
    void jouer(const std::string& son) override {
        std::cout << "[SortieHDMI] Envoi signal numerique: " << son << std::endl;
    }
    void fermer() override {
        std::cout << "[SortieHDMI] Coupure signal" << std::endl;
    }
};
#endif // SORTIEHDMI_H
