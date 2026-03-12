//
// Created by Luka on 11.03.2026.
//

#include "Product-Liquid-Solid.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int Product::GetPrice() const {
    return price;
}

int Product::GetId() const {
    return id;
}

std::string Product::GetName() const {
    return name;
}

char Product::GetSize() const {
    return size;
}

void Product::ChangePrice(int NewPrice) {
    if (NewPrice < 0) {
        throw std::invalid_argument("Ошибка: цена не может быть отрицательной");
    }
    price = NewPrice;
}

void Product::display(std::ostream& os) const {
    os << "ID: " << id
       << ", Name: " << name
       << ", Price: " << price
       << ", Size: " << size;
}

void Product::give() const {}




LiquidProduct::LiquidProduct(const std::string& name, int id, int price, char size,
                             int V, bool Sprkl)
    : Product(name, id, price, size), VolumeML(V), IsSparkling(Sprkl) {
    if (V <= 0) {
        throw std::invalid_argument("Ошибка: объем должен быть положительным");
    }
}

void LiquidProduct::ChangeVolume(int NewVolume) {
    if (NewVolume <= 0) {
        throw std::invalid_argument("Ошибка: объем должен быть положительным");
    }
    VolumeML = NewVolume;
}

int LiquidProduct::GetVolumeML() const {
    return VolumeML;
}

bool LiquidProduct::GetIsSparkling() const {
    return IsSparkling;
}

void LiquidProduct::display(std::ostream& os) const {
    Product::display(os);
    os << ", Volume: " << VolumeML << " ml"
       << ", Sparkling: " << (IsSparkling ? "Yes" : "No")
       << '\n';
}

void LiquidProduct::give() const {
    // <Выдача твердого товара> --> драйвера автомата
}



SolidProduct::SolidProduct(const std::string& name, int id, int price, char size,
                           int M, bool CrflDsp)
    : Product(name, id, price, size), MassGR(M), CarefulDisp(CrflDsp) {
    if (M <= 0) {
        throw std::invalid_argument("Ошибка: масса должна быть положительной");
    }
}

void SolidProduct::ChangeMass(int NewMass) {
    if (NewMass <= 0) {
        throw std::invalid_argument("Ошибка: масса должна быть положительной");
    }
    MassGR = NewMass;
}

int SolidProduct::GetMass() const {
    return MassGR;
}

bool SolidProduct::GetCarefulDisp() const {
    return CarefulDisp;
}

void SolidProduct::display(std::ostream& os) const {
    Product::display(os);
    os << ", Mass: " << MassGR << " g"<< ", Careful: " << (CarefulDisp ? "Yes" : "No")<< '\n';
}

void SolidProduct::give() const {
    // <Выдача твердого товара> --> драйвера автомата
}