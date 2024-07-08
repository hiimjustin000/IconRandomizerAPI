#include <Geode/Geode.hpp>

#ifdef GEODE_IS_WINDOWS
    #ifdef ICON_RANDOMIZER_API_EXPORTING
        #define ICON_RANDOMIZER_API_DLL __declspec(dllexport)
    #else
        #define ICON_RANDOMIZER_API_DLL __declspec(dllimport)
    #endif
#else
    #define ICON_RANDOMIZER_API_DLL // Android and macOS have symbols public by default
#endif

#define ICON_RANDOMIZER_API_COLOR_1 0
#define ICON_RANDOMIZER_API_COLOR_2 1
#define ICON_RANDOMIZER_API_GLOW_COLOR 2
#define ICON_RANDOMIZER_API_GLOW 3
#define ICON_RANDOMIZER_API_CUBE 4
#define ICON_RANDOMIZER_API_SHIP 5
#define ICON_RANDOMIZER_API_BALL 6
#define ICON_RANDOMIZER_API_UFO 7
#define ICON_RANDOMIZER_API_WAVE 8
#define ICON_RANDOMIZER_API_ROBOT 9
#define ICON_RANDOMIZER_API_SPIDER 10
#define ICON_RANDOMIZER_API_SWING 11
#define ICON_RANDOMIZER_API_JETPACK 12
#define ICON_RANDOMIZER_API_DEATH_EFFECT 13
#define ICON_RANDOMIZER_API_TRAIL 14
#define ICON_RANDOMIZER_API_SHIP_FIRE 15
#define ICON_RANDOMIZER_API_ANIMATION 16

#define ICON_RANDOMIZER_API_ALL_ICONS 0
#define ICON_RANDOMIZER_API_ALL_SPECIAL 1
#define ICON_RANDOMIZER_API_ALL_COLORS 2

/**
 * The class for the Icon Randomizer API.
 */
class ICON_RANDOMIZER_API_DLL IconRandomizer {
private:
    // A list of the IDs the player has unlocked for each type of icon.
    inline static std::map<UnlockType, std::vector<int>> UNLOCKED = {
        { UnlockType::Cube, {} },
        { UnlockType::Col1, {} },
        { UnlockType::Col2, {} },
        { UnlockType::Ship, {} },
        { UnlockType::Ball, {} },
        { UnlockType::Bird, {} },
        { UnlockType::Dart, {} },
        { UnlockType::Robot, {} },
        { UnlockType::Spider, {} },
        { UnlockType::Streak, {} },
        { UnlockType::Death, {} },
        { UnlockType::GJItem, {} },
        { UnlockType::Swing, {} },
        { UnlockType::Jetpack, {} },
        { UnlockType::ShipFire, {} }
    };

    // A flag to check if the API has been initialized.
    inline static bool INITIALIZED = false;

    // The icon part of the initialization function.
    // This takes a parameter for the type of icon to initialize.
    static void setupUnlockedIcons(IconType type);

    // The color part of the initialization function.
    // This takes a parameter for the type of color to initialize.
    static void setupUnlockedColors(UnlockType type);

    // A helper function to get a saved value from the Separate Dual Icons mod by Weebify.
    // This takes the mod, a string for the name of the setting, and a parameter for the default value of the setting.
    template <class T>
    static T getSDIValue(geode::Mod* mod, std::string const& key, T const& defaultValue) {
        // Get the mod's saved value if it exists, otherwise return the default value.
        return mod ? mod->getSavedValue(key, defaultValue) : defaultValue;
    }

    // A helper function to set a saved value from the Separate Dual Icons mod by Weebify.
    // This takes the mod, a string for the name of the setting, and a parameter for the value of the setting.
    template <class T>
    static void setSDIValue(geode::Mod* mod, std::string const& key, T const& value) {
        // Set the mod's saved value, if the mod is actually loaded.
        if (mod) mod->setSavedValue(key, value);
    }
public:
    /**
     * The function to initalize the Icon Randomizer API.
     * It is recommended that this function is called before any other functions in the API, but it is done automatically if forgotten.
     * This function can be rerun to refresh the unlocked icons and colors.
     */
    static void init();

    /**
     * A function to get a random number using the merseene twister algorithm.
     * @param min The minimum number to generate.
     * @param max The maximum number to generate.
     * @returns A random number between min and max.
     */
    static int random(int min, int max);

    /**
     * A function to convert an icon type to an ICON_RANDOMIZER_API constant.
     * @param type The type of icon to convert.
     * @returns The ICON_RANDOMIZER_API constant for the icon type.
     */
    static int fromIconType(IconType type);

    /**
     * A function to convert an ICON_RANDOMIZER_API constant to an unlock type.
     * @param type The ICON_RANDOMIZER_API constant to convert.
     * @returns The unlock type for the ICON_RANDOMIZER_API constant.
     */
    static UnlockType toUnlockType(int type);

    /**
     * The function to randomize an icon or color.
     * @param type The type of icon or color to randomize. (Use the ICON_RANDOMIZER_API constants for this.)
     * @param dual Whether or not to randomize the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     * @returns The ID of the randomized icon.
     */
    static int randomize(int type, bool dual = false);

    /**
     * The function to randomize multiple types of icons or colors at once.
     * @param type The types of icons to randomize. (Use the ICON_RANDOMIZER_API_ALL constants for this.)
     * @param dual Whether or not to randomize the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     */
    static void randomizeAll(int type, bool dual = false);

    /**
     * Gets the current icon or color ID for a specific type.
     * @param type The type of icon or color to get the ID for. (Use the ICON_RANDOMIZER_API constants for this.)
     * @param dual Whether or not to get the ID for the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     * @returns The ID of the current icon.
     */
    static int active(int type, bool dual = false);
};
