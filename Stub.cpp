//
// Created by USER on 2018/3/3.
//
#include "Gear.h"
#include "Stub.h"

class Stub : public Gear {
    Stub::Stub() {
        this->type = GearType::STUB;
        this->addenCoefficient = 0.8;
        this->denCoefficient = 1.0;
    }
};
