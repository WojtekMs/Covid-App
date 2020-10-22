#pragma once
#include "Location.hpp"
#include "Shop.hpp"

#include <memory>
#include <unordered_map>

using ShopMap = std::unordered_map<Location, std::shared_ptr<Shop>>;

class ShopDataBase
{
    ShopMap shopMap_{};

   public:
    void addShop(const std::shared_ptr<Shop>& shop);
    void removeShop(const std::shared_ptr<Shop>& shop);
    const ShopMap& getShops() const { return shopMap_; }
    const std::shared_ptr<Shop>& getShop(const Location& shopLocation) const { return shopMap_.at(shopLocation); }
};
