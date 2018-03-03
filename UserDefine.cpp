//
// Created by USER on 2018/3/3.
//
#include "Gear.h"
#include "UserDefine.h"

class UserDefine : public Gear {
    UserDefine::UserDefine(double addenCoefficient, double denCoefficient) {
        this->type = GearType::USER_DEFINE;
        this->addenCoefficient = addenCoefficient;
        this->denCoefficient = denCoefficient;
    }
};
