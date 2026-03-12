//
// Created by Luka on 11.03.2026.
//

#ifndef PRODUCT_LIQUID_SOLID_H
#define PRODUCT_LIQUID_SOLID_H

#include <string>



class Product{
protected:
    std::string name;
    int id;
    int price;
    char size;
public:
    Product()=delete;
    virtual ~Product() = default;

    void GetPrice() const;
    int GetId() const;
    std::string GetName() const;
    char GetSize() const;

    void ChangePrice(int NewPrice);

    virtual void display() const;
    virtual void give() const;
};

class LiquidProduct: public Product{
protected:
    int VolumeML;
    bool IsSparkling;

public:
    LiquidProduct(const std::string& name, int id, int price, char size, int V, bool Sprkl);


    void ChangeVolume(int NewVolume);

    int GetVolumeML() const;
    bool GetIsSparkling() const;

    virtual void display() const override;
    virtual void give() const override;
   };


class SolidProduct: public Product{
protected:
    int MassGR;
    bool CarefulDisp;
public:
    SolidProduct(const std::string& name, int id, int price, char size, int M, bool CrflDsp);


    void ChangeMass(int NewMass);

    int GetMass() const;
    bool GetCarefulDisp() const;

    virtual void display() const override;
    virtual void give() const override;
};
#endif