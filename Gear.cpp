//
// Created by USER on 2018/3/3.
//
#include "Gear.h"

class Gear {
	inline bool Gear::isUndercut() {
		int undercut = (int)(2.0*(this->addenCoefficient - this->shift) / (sin(this->press*PI / 180.0)*sin(this->press*PI / 180.0))) + 1.0;
		return undercut < this->teeth;
	}
};

