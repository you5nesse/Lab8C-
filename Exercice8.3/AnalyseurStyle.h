#ifndef ANALYSEURSTYLE_H
#define ANALYSEURSTYLE_H

#pragma once
#include "Plugin.h"

class AnalyseurStyle : public Plugin {
public:
    std::string nom() const override { return "AnalyseurStyle"; }

    std::string traiter(const std::string& texte) override {
        int phrasesLongues = 0;
        int nbMots = 0;
        int maxMotsPhrase = 0;
        int motsCourants = 0;

        for(char c : texte){
            if(c==' ' || c=='\n') nbMots++, motsCourants++;
            if(c=='.' || c=='!' || c=='?'){
                if(motsCourants > 20) phrasesLongues++;
                if(motsCourants > maxMotsPhrase) maxMotsPhrase = motsCourants;
                motsCourants = 0;
            }
        }
        
        if(motsCourants>0){
            nbMots++;
            if(motsCourants>20) phrasesLongues++;
        }

        std::string res = texte;
        res += "\n\n[Analyse] Mots: " + std::to_string(nbMots) +
               " | Phrases longues (>20 mots): " + std::to_string(phrasesLongues);
        if(phrasesLongues>0) res += " -> Attention, simplifiez vos phrases !";
        return res;
    }
};

#endif // ANALYSEURSTYLE_H
