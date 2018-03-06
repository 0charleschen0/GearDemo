//
// Created by USER on 2018/3/3.
//
#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "Gear.h"


Gear::Gear() {}

void Gear::init(double module, double teeth, double press, double shift, double backlash, double radius,
          int workinkNUmber, int filletNumber, int teethNumber) {
    setModule(module);
    setTeeth(teeth);
    setPress(press);
    setShift(shift);
    setBacklash(backlash);
    setRadius(radius);
    setWorkinkNumber(workinkNUmber);
    setFilletNumber(filletNumber);
    setTeethNumber(teethNumber);

    x = std::vector(workinkNUmber+filletNumber);
    y = std::vector(workinkNUmber+filletNumber);
}

inline bool Gear::isUndercut() {
    int undercut = (int)(2.0*(this->addenCoefficient - this->shift) / (pow(sin(toRadius(this->press)), 2) + 1.0));
    return undercut < this->teeth;
}

inline static double Gear::toRadius(double degree) {
    return degree * M_PI / 180.0;
}

