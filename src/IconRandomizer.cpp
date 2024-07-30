#include <random>
#include <IconRandomizer.hpp>

using namespace geode::prelude;

#define SDI_ID "weebify.separate_dual_icons"
#define SDI_COLOR_1 "color1"
#define SDI_COLOR_2 "color2"
#define SDI_GLOW_COLOR "colorglow"
#define SDI_GLOW "glow"
#define SDI_CUBE "cube"
#define SDI_SHIP "ship"
#define SDI_BALL "roll"
#define SDI_UFO "bird"
#define SDI_WAVE "dart"
#define SDI_ROBOT "robot"
#define SDI_SPIDER "spider"
#define SDI_SWING "swing"
#define SDI_JETPACK "jetpack"
#define SDI_DEATH "death"
#define SDI_TRAIL "trail"
#define SDI_SHIP_FIRE "shiptrail"

void IconRandomizer::setupUnlockedIcons(IconType type) {
    // Get the game manager and the vector of unlocked icons for the icon type, then clear the vector.
    auto gameManager = GameManager::sharedState();
    auto& vec = UNLOCKED[gameManager->iconTypeToUnlockType(type)];
    vec.clear();

    // Get the amount of icons for the type, then iterate through them and add them to the vector if they are unlocked.
    auto amount = type == IconType::Item ? 20 : gameManager->countForType(type);
    for (int i = type == IconType::Item ? 18 : 1; i <= amount; i++) {
        if (gameManager->isIconUnlocked(i, type)) vec.push_back(i);
    }
}

void IconRandomizer::setupUnlockedColors(UnlockType type) {
    // Get the game manager and the vector of unlocked colors for the unlock type, then clear the vector.
    auto gameManager = GameManager::sharedState();
    auto& vec = UNLOCKED[type];
    vec.clear();

    // Iterate through the colors and add them to the vector if they are unlocked.
    for (int i = 0; i < 107; i++) {
        if (gameManager->isColorUnlocked(i, type)) vec.push_back(i);
    }
}

void IconRandomizer::init() {
    // Set up the unlocked icons and colors.
    setupUnlockedIcons(IconType::Cube);
    setupUnlockedColors(UnlockType::Col1);
    setupUnlockedColors(UnlockType::Col2);
    setupUnlockedIcons(IconType::Ship);
    setupUnlockedIcons(IconType::Ball);
    setupUnlockedIcons(IconType::Ufo);
    setupUnlockedIcons(IconType::Wave);
    setupUnlockedIcons(IconType::Robot);
    setupUnlockedIcons(IconType::Spider);
    setupUnlockedIcons(IconType::Special);
    setupUnlockedIcons(IconType::DeathEffect);
    setupUnlockedIcons(IconType::Item);
    setupUnlockedIcons(IconType::Swing);
    setupUnlockedIcons(IconType::Jetpack);
    setupUnlockedIcons(IconType::ShipFire);

    // Set the initialized flag to true.
    INITIALIZED = true;
}

int IconRandomizer::random(int min, int max) {
    // Cvolton had a much longer way of doing this that he grabbed from Stack Overflow, thank you, Copilot, for minimizing it.
    static std::mt19937 mt(std::random_device{}());
    return std::uniform_int_distribution<int>(min, max)(mt);
}

RandomizeType IconRandomizer::fromConstant(int type) {
    // Convert the constant to a randomize type.
    switch (type) {
        case 0: return ICON_RANDOMIZER_API_COLOR_1;
        case 1: return ICON_RANDOMIZER_API_COLOR_2;
        case 2: return ICON_RANDOMIZER_API_GLOW_COLOR;
        case 3: return ICON_RANDOMIZER_API_GLOW;
        case 4: return ICON_RANDOMIZER_API_CUBE;
        case 5: return ICON_RANDOMIZER_API_SHIP;
        case 6: return ICON_RANDOMIZER_API_BALL;
        case 7: return ICON_RANDOMIZER_API_UFO;
        case 8: return ICON_RANDOMIZER_API_WAVE;
        case 9: return ICON_RANDOMIZER_API_ROBOT;
        case 10: return ICON_RANDOMIZER_API_SPIDER;
        case 11: return ICON_RANDOMIZER_API_SWING;
        case 12: return ICON_RANDOMIZER_API_JETPACK;
        case 13: return ICON_RANDOMIZER_API_DEATH_EFFECT;
        case 14: return ICON_RANDOMIZER_API_TRAIL;
        case 15: return ICON_RANDOMIZER_API_SHIP_FIRE;
        case 16: return ICON_RANDOMIZER_API_ANIMATION;
        default: return ICON_RANDOMIZER_API_CUBE;
    }
}

RandomizeAllType IconRandomizer::fromAllConstant(int type) {
    // Convert the constant to a randomize all type.
    switch (type) {
        case 0: return ICON_RANDOMIZER_API_ALL_ICONS;
        case 1: return ICON_RANDOMIZER_API_ALL_SPECIAL;
        case 2: return ICON_RANDOMIZER_API_ALL_COLORS;
        default: return ICON_RANDOMIZER_API_ALL_ICONS;
    }
}

RandomizeType IconRandomizer::randomizeTypeFromIconType(IconType type) {
    // Convert the icon type to a randomize type.
    switch (type) {
        case IconType::Cube: return ICON_RANDOMIZER_API_CUBE;
        case IconType::Ship: return ICON_RANDOMIZER_API_SHIP;
        case IconType::Ball: return ICON_RANDOMIZER_API_BALL;
        case IconType::Ufo: return ICON_RANDOMIZER_API_UFO;
        case IconType::Wave: return ICON_RANDOMIZER_API_WAVE;
        case IconType::Robot: return ICON_RANDOMIZER_API_ROBOT;
        case IconType::Spider: return ICON_RANDOMIZER_API_SPIDER;
        case IconType::Swing: return ICON_RANDOMIZER_API_SWING;
        case IconType::Jetpack: return ICON_RANDOMIZER_API_JETPACK;
        case IconType::DeathEffect: return ICON_RANDOMIZER_API_DEATH_EFFECT;
        case IconType::Special: return ICON_RANDOMIZER_API_TRAIL;
        case IconType::Item: return ICON_RANDOMIZER_API_ANIMATION;
        case IconType::ShipFire: return ICON_RANDOMIZER_API_SHIP_FIRE;
        default: return ICON_RANDOMIZER_API_CUBE;
    }
}

int IconRandomizer::fromIconType(IconType type) {
    // Deprecated function, kept for compatibility.
    return randomizeTypeFromIconType(type);
}

UnlockType IconRandomizer::unlockTypeFromRandomizeType(RandomizeType type) {
    // Convert the randomize type to an unlock type.
    switch (type) {
        case ICON_RANDOMIZER_API_COLOR_1: return UnlockType::Col1;
        case ICON_RANDOMIZER_API_COLOR_2: return UnlockType::Col2;
        case ICON_RANDOMIZER_API_GLOW_COLOR: return UnlockType::Col2;
        case ICON_RANDOMIZER_API_GLOW: return UnlockType::Streak;
        case ICON_RANDOMIZER_API_CUBE: return UnlockType::Cube;
        case ICON_RANDOMIZER_API_SHIP: return UnlockType::Ship;
        case ICON_RANDOMIZER_API_BALL: return UnlockType::Ball;
        case ICON_RANDOMIZER_API_UFO: return UnlockType::Bird;
        case ICON_RANDOMIZER_API_WAVE: return UnlockType::Dart;
        case ICON_RANDOMIZER_API_ROBOT: return UnlockType::Robot;
        case ICON_RANDOMIZER_API_SPIDER: return UnlockType::Spider;
        case ICON_RANDOMIZER_API_SWING: return UnlockType::Swing;
        case ICON_RANDOMIZER_API_JETPACK: return UnlockType::Jetpack;
        case ICON_RANDOMIZER_API_DEATH_EFFECT: return UnlockType::Death;
        case ICON_RANDOMIZER_API_TRAIL: return UnlockType::Streak;
        case ICON_RANDOMIZER_API_SHIP_FIRE: return UnlockType::ShipFire;
        case ICON_RANDOMIZER_API_ANIMATION: return UnlockType::GJItem;
        default: return UnlockType::Cube;
    }
}

UnlockType IconRandomizer::toUnlockType(int type) {
    // Deprecated function, kept for compatibility.
    return unlockTypeFromRandomizeType(fromConstant(type));
}

int IconRandomizer::randomize(RandomizeType type, bool dual) {
    // Initialize the API if it hasn't been already.
    if (!INITIALIZED) {
        init();
        INITIALIZED = true;
    }

    // If the type is invalid, return -1.
    if (type < 0 || type > 16) return -1;

    // Get the UnlockType from the randomize type, and get the vector of unlocked icons.
    auto& vec = UNLOCKED[unlockTypeFromRandomizeType(type)];

    // If it is an animation, randomly enable or disable the animations, and return 0.
    if (type == ICON_RANDOMIZER_API_ANIMATION) {
        auto gameStatsManager = GameStatsManager::sharedState();
        for (int i = 0; i < vec.size(); i++) {
            gameStatsManager->toggleEnableItem(UnlockType::GJItem, vec[i], random(0, 1));
        }
        return 0;
    }

    // Get the game manager and the Separate Dual Icons mod. If the mod is enabled and the dual parameter is true, use separate dual icons.
    // Then get a random number from the vector of unlocked icons.
    auto gameManager = GameManager::sharedState();
    auto separateDualIcons = Loader::get()->getLoadedMod(SDI_ID);
    auto useDual = separateDualIcons && dual;
    auto num = vec[(size_t)random(0, vec.size() - 1)];
    auto glow = type == ICON_RANDOMIZER_API_GLOW ? (bool)random(0, 1) : false;

    // Then, set the icon to the random number.
    // If Separate Dual Icons is enabled and the dual parameter is true, set the value in the mod.
    // Otherwise, set the value in the game manager.
    switch (type) {
        case ICON_RANDOMIZER_API_COLOR_1:
            if (useDual) setSDIValue(separateDualIcons, SDI_COLOR_1, num);
            else gameManager->setPlayerColor(num);
            return num;
        case ICON_RANDOMIZER_API_COLOR_2:
            if (useDual) setSDIValue(separateDualIcons, SDI_COLOR_2, num);
            else gameManager->setPlayerColor2(num);
            return num;
        case ICON_RANDOMIZER_API_GLOW_COLOR:
            if (useDual) setSDIValue(separateDualIcons, SDI_GLOW_COLOR, num);
            else gameManager->setPlayerColor3(num);
            return num;
        case ICON_RANDOMIZER_API_GLOW:
            if (useDual) setSDIValue<bool>(separateDualIcons, SDI_GLOW, glow);
            else gameManager->setPlayerGlow(glow);
            return glow;
        case ICON_RANDOMIZER_API_CUBE:
            if (useDual) setSDIValue(separateDualIcons, SDI_CUBE, num);
            else gameManager->setPlayerFrame(num);
            return num;
        case ICON_RANDOMIZER_API_SHIP:
            if (useDual) setSDIValue(separateDualIcons, SDI_SHIP, num);
            else gameManager->setPlayerShip(num);
            return num;
        case ICON_RANDOMIZER_API_BALL:
            if (useDual) setSDIValue(separateDualIcons, SDI_BALL, num);
            else gameManager->setPlayerBall(num);
            return num;
        case ICON_RANDOMIZER_API_UFO:
            if (useDual) setSDIValue(separateDualIcons, SDI_UFO, num);
            else gameManager->setPlayerBird(num);
            return num;
        case ICON_RANDOMIZER_API_WAVE:
            if (useDual) setSDIValue(separateDualIcons, SDI_WAVE, num);
            else gameManager->setPlayerDart(num);
            return num;
        case ICON_RANDOMIZER_API_ROBOT:
            if (useDual) setSDIValue(separateDualIcons, SDI_ROBOT, num);
            else gameManager->setPlayerRobot(num);
            return num;
        case ICON_RANDOMIZER_API_SPIDER:
            if (useDual) setSDIValue(separateDualIcons, SDI_SPIDER, num);
            else gameManager->setPlayerSpider(num);
            return num;
        case ICON_RANDOMIZER_API_SWING:
            if (useDual) setSDIValue(separateDualIcons, SDI_SWING, num);
            else gameManager->setPlayerSwing(num);
            return num;
        case ICON_RANDOMIZER_API_JETPACK:
            if (useDual) setSDIValue(separateDualIcons, SDI_JETPACK, num);
            else gameManager->setPlayerJetpack(num);
            return num;
        case ICON_RANDOMIZER_API_DEATH_EFFECT:
            if (useDual) setSDIValue(separateDualIcons, SDI_DEATH, num);
            else gameManager->setPlayerDeathEffect(num);
            return num;
        case ICON_RANDOMIZER_API_TRAIL:
            if (useDual) setSDIValue(separateDualIcons, SDI_TRAIL, num);
            else gameManager->setPlayerStreak(num);
            return num;
        case ICON_RANDOMIZER_API_SHIP_FIRE:
            if (useDual) setSDIValue(separateDualIcons, SDI_SHIP_FIRE, num);
            else gameManager->setPlayerShipStreak(num);
            return num;
        default:
            return -1;
    }
}

int IconRandomizer::randomize(int type, bool dual) {
    // Convert the type to a randomize type and randomize it.
    return randomize(fromConstant(type), dual);
}

void IconRandomizer::randomizeAll(RandomizeAllType type, bool dual) {
    // Switch on the randomize all type and randomize all the icons of that type.
    switch (type) {
        case ICON_RANDOMIZER_API_ALL_ICONS:
            randomize(ICON_RANDOMIZER_API_CUBE, dual);
            randomize(ICON_RANDOMIZER_API_SHIP, dual);
            randomize(ICON_RANDOMIZER_API_BALL, dual);
            randomize(ICON_RANDOMIZER_API_UFO, dual);
            randomize(ICON_RANDOMIZER_API_WAVE, dual);
            randomize(ICON_RANDOMIZER_API_ROBOT, dual);
            randomize(ICON_RANDOMIZER_API_SPIDER, dual);
            randomize(ICON_RANDOMIZER_API_SWING, dual);
            randomize(ICON_RANDOMIZER_API_JETPACK, dual);
            break;
        case ICON_RANDOMIZER_API_ALL_SPECIAL:
            randomize(ICON_RANDOMIZER_API_DEATH_EFFECT, dual);
            randomize(ICON_RANDOMIZER_API_TRAIL, dual);
            randomize(ICON_RANDOMIZER_API_SHIP_FIRE, dual);
            randomize(ICON_RANDOMIZER_API_ANIMATION, dual);
            break;
        case ICON_RANDOMIZER_API_ALL_COLORS:
            randomize(ICON_RANDOMIZER_API_COLOR_1, dual);
            randomize(ICON_RANDOMIZER_API_COLOR_2, dual);
            randomize(ICON_RANDOMIZER_API_GLOW_COLOR, dual);
            randomize(ICON_RANDOMIZER_API_GLOW, dual);
            break;
    }
}

void IconRandomizer::randomizeAll(int type, bool dual) {
    // Convert the type to a randomize all type and randomize all the icons of that type.
    randomizeAll(fromAllConstant(type), dual);
}

int IconRandomizer::active(RandomizeType type, bool dual) {
    // Get the UnlockType from the randomize type, then get the game manager and the Separate Dual Icons mod.
    // If the mod is enabled and the dual parameter is true, use separate dual icons.
    auto unlockType = unlockTypeFromRandomizeType(type);
    auto gameManager = GameManager::sharedState();
    auto separateDualIcons = Loader::get()->getLoadedMod(SDI_ID);
    auto useDual = separateDualIcons && dual;

    // Get the value from the Separate Dual Icons mod if it is enabled and the dual parameter is true, otherwise get the value from the game manager.
    switch (type) {
        case ICON_RANDOMIZER_API_COLOR_1:
            return useDual ? getSDIValue(separateDualIcons, SDI_COLOR_1, 0) : gameManager->getPlayerColor();
        case ICON_RANDOMIZER_API_COLOR_2:
            return useDual ? getSDIValue(separateDualIcons, SDI_COLOR_2, 0) : gameManager->getPlayerColor2();
        case ICON_RANDOMIZER_API_GLOW_COLOR:
            return useDual ? getSDIValue(separateDualIcons, SDI_GLOW_COLOR, 0) : gameManager->getPlayerGlowColor();
        case ICON_RANDOMIZER_API_GLOW:
            return useDual ? getSDIValue(separateDualIcons, SDI_GLOW, false) : gameManager->getPlayerGlow();
        case ICON_RANDOMIZER_API_CUBE:
            return useDual ? getSDIValue(separateDualIcons, SDI_CUBE, 1) : gameManager->getPlayerFrame();
        case ICON_RANDOMIZER_API_SHIP:
            return useDual ? getSDIValue(separateDualIcons, SDI_SHIP, 1) : gameManager->getPlayerShip();
        case ICON_RANDOMIZER_API_BALL:
            return useDual ? getSDIValue(separateDualIcons, SDI_BALL, 1) : gameManager->getPlayerBall();
        case ICON_RANDOMIZER_API_UFO:
            return useDual ? getSDIValue(separateDualIcons, SDI_UFO, 1) : gameManager->getPlayerBird();
        case ICON_RANDOMIZER_API_WAVE:
            return useDual ? getSDIValue(separateDualIcons, SDI_WAVE, 1) : gameManager->getPlayerDart();
        case ICON_RANDOMIZER_API_ROBOT:
            return useDual ? getSDIValue(separateDualIcons, SDI_ROBOT, 1) : gameManager->getPlayerRobot();
        case ICON_RANDOMIZER_API_SPIDER:
            return useDual ? getSDIValue(separateDualIcons, SDI_SPIDER, 1) : gameManager->getPlayerSpider();
        case ICON_RANDOMIZER_API_SWING:
            return useDual ? getSDIValue(separateDualIcons, SDI_SWING, 1) : gameManager->getPlayerSwing();
        case ICON_RANDOMIZER_API_JETPACK:
            return useDual ? getSDIValue(separateDualIcons, SDI_JETPACK, 1) : gameManager->getPlayerJetpack();
        case ICON_RANDOMIZER_API_DEATH_EFFECT:
            return useDual ? getSDIValue(separateDualIcons, SDI_DEATH, 1) : gameManager->getPlayerDeathEffect();
        case ICON_RANDOMIZER_API_TRAIL:
            return useDual ? getSDIValue(separateDualIcons, SDI_TRAIL, 1) : gameManager->getPlayerStreak();
        case ICON_RANDOMIZER_API_SHIP_FIRE:
            return useDual ? getSDIValue(separateDualIcons, SDI_SHIP_FIRE, 1) : gameManager->getPlayerShipFire();
        default:
            return -1;
    }
}

int IconRandomizer::active(int type, bool dual) {
    // Convert the type to a randomize type and get the active value.
    return active(fromConstant(type), dual);
}
