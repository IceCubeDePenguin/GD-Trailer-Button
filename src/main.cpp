#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto trailerButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_trailerBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::ontrailerButton)
        );

        auto menu = this->getChildByID("bottom-menu");
        menu->addChild(trailerButton);
        trailerButton->setID("trailer-button"_spr);
        menu->updateLayout();
        return true;
    }
    void ontrailerButton(CCObject*) {
        web::openLinkInBrowser("https://www.youtube.com/watch?v=k90y6PIzIaE");
    };
};