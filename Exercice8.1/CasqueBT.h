#ifndef CASQUEBT_H
#define CASQUEBT_H
#include<SortieAudio.h>
class CasqueBT : public SortieAudio {
public:
    void ouvrir() override {
        std::cout << "[CasqueBT] Recherche + appairage Bluetooth..." << std::endl;
    }
    void jouer(const std::string& son) override {
        std::cout << "[CasqueBT] Streaming Bluetooth: " << son << std::endl;
    }
    void fermer() override {
        std::cout << "[CasqueBT] Deconnexion BT" << std::endl;
    }
};
#endif // CASQUEBT_H
