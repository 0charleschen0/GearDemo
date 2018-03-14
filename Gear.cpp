//
// Created by USER on 2018/3/3.
//
#include <cmath>
#define _USE_MATH_DEFINES // for C++

#include "Gear.h"

Gear::Gear() {}

void Gear::init(double module, double teeth, double press, double shift, double backlash, double radius,
          int workinkNUmber, int filletNumber, int teethNumber) {
    setModule(module);
    setTeeth(teeth);
    setPressWithDegree(press);
    setShift(shift);
    setBacklash(backlash);
    setRadius(radius);
    setWorkinkNumber(workinkNUmber);
    setFilletNumber(filletNumber);
    setTeethNumber(teethNumber);

    x = std::vector(workinkNUmber+filletNumber);
    y = std::vector(workinkNUmber+filletNumber);

    space = 2*M_PI/teeth;
    a0 = addenCoefficient*module;
    b0 = (M_PI*module/2.0 - backlash)/2.0;

    r1=module*teeth/2.0;
    lpu = lpu=(a0+addenCoefficient*module)/getPress().cos();

    a = -a0*radius*getPress().toComplementary().cos();
    b = -b0 -a0*getPress().tan() - radius*getPress().toComplementary().sin();

    double phi1 = b/r1;

    AngleUtils Phi1 = AngleUtils();
    Phi1.setRadian(phi1);

    double xf = (a-radius+shift*module)*Phi1.cos() - b*Phi1.sin() + r1*(Phi1.cos() + phi1*Phi1.sin());
    double yf = (a-radius+shift*module)*Phi1.sin() + b*Phi1.cos() + r1*(Phi1.sin() - phi1*Phi1.cos());
    rd = sqrt(pow(xf, 2) + pow(yf, 2));
    alph = atan(yf/xf);
}

void Gear::generateDedndumCircle() {
    for(double i=space/2;i>=fabs(alph);i=i-(space-fabs(alph))/(filletNumber/2.0)) {
        x.push_back(rd*cos(i));
        y.push_back(rd*sin(i));
    }
}

void Gear::generateFilletNumber() {
    AngleUtils Theta = AngleUtils();
    double pressValue = getPress().getDegreeValue();

    for(double i=0.0; i<(90.0 - pressValue); i=i + (90.0-pressValue)/filletNumber) {
        Theta.setDegree(i);
        double a = -a0 + radius*press.toComplementary().cos();
        double b = -b0 - a0*press.tan() - radius*press.toComplementary().sin();
        double phi1 = (a*Theta.sin() + b*Theta.cos())/(r1*Theta.cos());
        double xf = (a-radius*Theta.cos() + shift*module)*cos(phi1) - (b+radius*Theta.sin())*sin(phi1)
                  + r1*(cos(phi1)+phi1*sin(phi1));
        double yf = (a - radius*Theta.cos() + shift*module) * sin(phi1) + (b + radius*Theta.sin()) * cos(phi1)
                    + r1*(sin(phi1) - phi1*cos(phi1));
        x.push_back(xf);
        y.push_back(yf);
        /*printf("The coordinates are--->xf=%f,yf=%f\n",xf,yf);*/
        /*printf("theda=%f,%f,%f\n",theda*180/PI,yf,xf);*/
        /*printf("%f,%f\n",yf,xf);*/
    }
}

inline bool Gear::isUndercut() {
    int undercut = (int)(2.0*(this->addenCoefficient - this->shift) / (pow(press.sin(), 2) + 1.0));
    return undercut < this->teeth;
}

