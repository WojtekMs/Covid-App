#include "catch.hpp"

#include "Application.hpp"
#include "Shop.hpp"
#include "ShopDataBase.hpp"
#include "User.hpp"
#include "UserDataBase.hpp"
#include "Customer.hpp"
#include "ShopOwner.hpp"
#include "Location.hpp"

#include <iostream>
#include <memory>

TEST_CASE("user database tests")
{
    UserDataBase db;
    auto defaultUser = std::make_shared<User>();

    SECTION("user can be added to database")
    {
        db.addUser(defaultUser);
        REQUIRE(db.getUsers().size() == 1);
    }
    SECTION("user can be removed from the database")
    {
        db.addUser(defaultUser);
        db.removeUser(defaultUser);
        CHECK(db.getUsers().size() == 0);
    }
}

TEST_CASE("shop database tests")
{
    ShopDataBase shops;
    auto defaultShop = std::make_shared<Shop>();
    SECTION("shop can be added to the database")
    {
        shops.addShop(defaultShop);
        CHECK(shops.getShops().size() == 1);
    }
    SECTION("shop can be removed from the database")
    {
        shops.addShop(defaultShop);
        shops.removeShop(defaultShop);
        CHECK(shops.getShops().size() == 0);
    }
}

TEST_CASE("customer tests") {
    Customer user;
    auto shop = std::make_shared<Shop>();
    SECTION("when user clicks iAmInShop, number of clients in shop increments") {
        user.iAmInShop(shop);
        CHECK(shop->getClientsCount() == 1);
    }
    SECTION("when user clicks iFinishedShopping, number of clients in shop decrements") {
        user.iAmInShop(shop);
        user.iFinishedShopping(shop);
        CHECK(shop->getClientsCount() == 0);
    }

}

TEST_CASE("application tests") {
    Application app;
    User user;
    Shop someShop;
    app.getShop(someShop.getLocation());
    auto nearestShop = app.getNearestShop(user.getLocation());
    REQUIRE(nearestShop != nullptr);
    nearestShop->getAdditionalInfo();
    nearestShop->getClientsCount();
    nearestShop->getMaxClientsCount();
}

TEST_CASE("only shop owner can change additional shop info") {
    auto shop = std::make_shared<Shop>();
    auto owner = std::make_shared<ShopOwner>(shop);
    auto anotherOwner = std::make_shared<ShopOwner>(shop);
    Shop::AdditionalInfo info{"24h", 1.0, "blik"};
    owner->editAdditionalInfo(info);
    CHECK(shop->getAdditionalInfo().hoursOpened_ == info.hoursOpened_);
}
