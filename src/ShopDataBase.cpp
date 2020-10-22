#include "ShopDataBase.hpp"

    void ShopDataBase::addShop(const std::shared_ptr<Shop>& shop) {
        shopMap_.emplace(std::make_pair(shop->getLocation(), shop));
    }
    void ShopDataBase::removeShop(const std::shared_ptr<Shop>& shop) {
        shopMap_.erase(shop->getLocation());
    }
