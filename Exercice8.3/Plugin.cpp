#include "Plugin.h"
#include "CorrecteurOrthographique.h"
#include "TraducteurAnglais.h"
#include "AnalyseurStyle.h"

std::unique_ptr<Plugin> Plugin::creerPlugin(const std::string& type){
    if(type=="correcteur") return std::make_unique<CorrecteurOrthographique>();
    if(type=="traducteur") return std::make_unique<TraducteurAnglais>();
    if(type=="analyseur") return std::make_unique<AnalyseurStyle>();
    return nullptr;
}
