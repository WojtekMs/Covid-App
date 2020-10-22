#include "Application.hpp"

const std::shared_ptr<Shop> Application::getNearestShop(const Location& location) const
{
    std::shared_ptr<Shop> theClosestShop{};
    auto theLeastDistance = std::numeric_limits<double>::max();
    for (const auto& [shopName, shop] : shops_->getShops()) {
        if (Location::Distance(shop->getLocation(), location) < theLeastDistance) {
            theLeastDistance = Location::Distance(shop->getLocation(), location);
            theClosestShop = shop;
        }
    }
    return theClosestShop;
}

const std::shared_ptr<Shop>& Application::getShop(const Location& location) const {
    return shops_->getShops().at(location);
}

