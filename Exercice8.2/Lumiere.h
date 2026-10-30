#ifndef LUMIERE_H
#define LUMIERE_H

#include <cmath>

struct Vec3 {
    float x,y,z;
    Vec3(float x=0,float y=0,float z=0):x(x),y(y),z(z){}
    Vec3 operator-(const Vec3& o) const { return {x-o.x, y-o.y, z-o.z}; }
    float length() const { return std::sqrt(x*x + y*y + z*z); }
    Vec3 normalized() const { float l=length(); return l>0?Vec3(x/l,y/l,z/l):Vec3(); }
    float dot(const Vec3& o) const { return x*o.x + y*o.y + z*o.z; }
};
class Lumiere {
public:
    virtual ~Lumiere() = default;
    virtual float intensite(const Vec3& position) const = 0;
};
#endif // LUMIERE_H
