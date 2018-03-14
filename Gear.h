//
// Created by USER on 2018/3/3.
//
#ifndef GEARDEMO_GEAR_H
#define GEARDEMO_GEAR_H

#include <vector>
#include <exception>
#include <stdexcept>

#include "utils/AngleUtils.h"

using namespace std;

class Gear {
private:
    vector<int> teethNumberSet = {1, 3, (int)teeth};
    vector<double> x;
    vector<double> y;

    double space;

    double a0;
    double b0;

    double r1;
    double lp1 = 0;
    double lpu;

    double a;
    double b;

    double rd;

    double alph;

public:
    Gear();

    ~Gear();

    void setAddenCoefficient(double addenCoefficient) {
        this->addenCoefficient = addenCoefficient;
    }

    void setDenCoefficient(double denCoefficient) {
        this->denCoefficient = denCoefficient;
    }

    void setModule(double module) {
        this->module = module;
    }

    void setTeeth(double teeth) {
        this->teeth = teeth;
        if (isUndercut()) {
            throw invalid_argument("teeth is undercut");
        }
    }

    void setPressWithDegree(double press) {
        this->press = AngleUtils();
        this->press.setDegree(press);
    }

    void setShift(double shift) {
        this->shift = shift;
    }

    void setBacklash(double backlash) {
        this->backlash = backlash;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    void setWorkinkNumber(int workinkNumber) {
        this->workinkNumber = workinkNumber;
    }

    void setFilletNumber(int filletNumber) {
        this->filletNumber = filletNumber;
    }

    void setTeethNumber(int teethNumber)  {
        this->teethNumber = teethNumber;
        for (int num : teethNumberSet) {
            if (num == teethNumber) {
                return;
            }
        }
        throw invalid_argument("It should be 1, 3, teeth");
    }

    double getAddenCoefficient() {
        return addenCoefficient;
    }

    double getDenCoefficient() {
        return denCoefficient;
    }

    double getModule() {
        return module;
    }

    double getTeeth() {
        return teeth;
    }

    AngleUtils getPress() {
        return press;
    }

    double getShift() {
        return shift;
    }

    double getBacklash() {
        return backlash;
    }

    double getRadius() {
        return radius;
    }

    int getWorkinkNumber() {
        return workinkNumber;
    }

    int getFilletNumber() {
        return filletNumber;
    }

    int getTeethNumber() {
        return teethNumber;
    }

    class GearType {
    public:
        static const int FULL_DEPTH = 0;
        static const int STUB = 1;
        static const int USER_DEFINE = 2;
    };


protected:
    //Type Related
    int type;
    double addenCoefficient = 0.0;
    double denCoefficient = 0.0;

    double module;
    double teeth = 0.0;
    AngleUtils press;
    double shift = 0.0;

    double backlash;
    double radius = 0.0;
    int workinkNumber = 0;
    int filletNumber = 0;
    int teethNumber = 0;

    void init(double module, double teeth, double press, double shift, double backlash, double radius,
              int workinkNUmber, int filletNumber, int teethNumber);

    void generateDedndumCircle();

    void generateFilletNumber();

    inline bool isUndercut();
};
#endif //GEARDEMO_GEAR_H
