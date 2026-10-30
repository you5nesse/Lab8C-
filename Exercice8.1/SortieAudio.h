#ifndef SORTIEAUDIO_H
#define SORTIEAUDIO_H
#include <iostream>
#include <string>

// 1. La classe abstraite demandée
class SortieAudio {
public:
    virtual ~SortieAudio() {} // destructeur virtuel obligatoire

    virtual void ouvrir() = 0;
    virtual void jouer(const std::string& son) = 0;
    virtual void fermer() = 0;
};
#endif // SORTIEAUDIO_H
