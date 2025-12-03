#include "Sale.h"

namespace miit::cinema
{
    Sale::Sale() : saleDate(0), quantity(0)
    {
    }

    Sale::Sale(std::time_t saleDate, int quantity)
        : saleDate(saleDate), quantity(quantity)
    {
    }

    std::time_t Sale::getSaleDate() const
    {
        return saleDate;
    }

    int Sale::getQuantity() const
    {
        return quantity;
    }

    void Sale::setSaleDate(std::time_t saleDate)
    {
        this->saleDate = saleDate;
    }

    void Sale::setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
}