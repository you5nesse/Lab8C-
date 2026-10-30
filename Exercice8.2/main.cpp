#include <iostream>
#include <vector>
#include <memory>
#include "LumiereDirectionnelle.h"
#include "LumierePonctuelle.h"
#include "LumiereSpot.h"

std::vector<std::unique_ptr<Lumiere>> scene;

float calculerEclairage(const Vec3& point) {
    float total = 0;
    for (auto& l : scene) total += l->intensite(point);
    return total;
}

int main() {
    scene.push_back(std::make_unique<LumiereDirectionnelle>(Vec3(0,-1,0)));
    scene.push_back(std::make_unique<LumierePonctuelle>(Vec3(0,5,0), 0.05f));
    scene.push_back(std::make_unique<LumiereSpot>(Vec3(0,5,5), Vec3(0,-1,-1), 30.0f));

    Vec3 points[] = {{0,0,0}, {0,0,4}, {10,0,0}};
    for (auto& p : points)
        std::cout << "Point ("<<p.x<<","<<p.y<<","<<p.z<<") -> "<<calculerEclairage(p)<<"\n";
    return 0;
}
