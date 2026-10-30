#include <iostream>

#include "SortieAudio.h"
#include "HautParleur.h"
#include "CasqueBT.h"
#include "SortieHDMI.h"
using namespace std;
void tester(SortieAudio* sortie) {
    sortie->ouvrir();
    sortie->jouer("musique.mp3");
    sortie->fermer();
}
int main() {

    SortieAudio* tab[3];

    tab[0] = new HautParleur();
    tab[1] = new CasqueBT();
    tab[2] = new SortieHDMI();


    for (int i = 0; i < 3; i++) {
        std::cout << "\n--- Test peripherique " << i << " ---" << std::endl;
        tester(tab[i]);
    }


    for (int i = 0; i < 3; i++) {
        delete tab[i];
    }

    return 0;
}
