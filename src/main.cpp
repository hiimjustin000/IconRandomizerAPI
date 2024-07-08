#include <IconRandomizer.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto menu = getChildByID("bottom-menu");
        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );
        myButton->setID("my-button"_spr);
        menu->addChild(myButton);
        menu->updateLayout();

        return true;
    }

    void onMyButton(CCObject*) {
        IconRandomizer::init();
        IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_ICONS);
        IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_ICONS, true);
    }
};
