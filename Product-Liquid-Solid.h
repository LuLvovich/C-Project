//
// Created by Luka on 11.03.2026.
//

#ifndef C_PROJECT_INVENTORY_H
#define C_PROJECT_INVENTORY_H

#include <string>



class Product{
protected:
    std::string name;
    int id;
    int price;
    char size;
public:
    Product(std::string name, int id, int price, char size);
    virtual ~Product() = default;

    void GetPrice() const;
    int GetId() const;
    std::string GetName() const;
    char getSize() const;

    void ChangePrice(int price);

    void display() const;
};

class LiquidProduct: public Product{};
class SolidProduct: public Product{};
#endif //C_PROJECT_INVENTORY_H