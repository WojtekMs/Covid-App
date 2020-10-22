#include "ShopOwner.hpp"

void ShopOwner::editAdditionalInfo(const Shop::AdditionalInfo& info) {
    if (!shop_) {
        return;
    }
    shop_->setAdditionalInfo(info);
}

ShopOwner::ShopOwner(const std::shared_ptr<Shop>& shop)
:shop_(shop) {
}

