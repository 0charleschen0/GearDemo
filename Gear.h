//
// Created by USER on 2018/3/3.
//

#ifndef GEARDEMO_GEAR_H
#define GEARDEMO_GEAR_H
class Gear {
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
    }

    void setPress(double press) {
        this->press = press;
    }

	void setShift(double shift) {
		this->shift = shift;
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

    double getPress() {
        return press;
    }

    double getShift() {
        return shift;
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

    double module = 0.0;
    double teeth = 0.0;
    double press = 0.0;
    double shift = 0.0;

	inline bool isUndercut();
};
#endif //GEARDEMO_GEAR_H
