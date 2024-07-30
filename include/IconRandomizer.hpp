#include <Geode/Geode.hpp>

#ifdef GEODE_IS_WINDOWS
    #ifdef ICON_RANDOMIZER_API_EXPORTING
        #define ICON_RANDOMIZER_API_DLL __declspec(dllexport)
    #else
        #define ICON_RANDOMIZER_API_DLL __declspec(dllimport)
    #endif
#else
    #define ICON_RANDOMIZER_API_DLL __attribute__((visibility("default")))
#endif

/**
 * The types of icons and colors that can be randomized.
 */
enum RandomizeType {
    ICON_RANDOMIZER_API_COLOR_1 = 0,
    ICON_RANDOMIZER_API_COLOR_2 = 1,
    ICON_RANDOMIZER_API_GLOW_COLOR = 2,
    ICON_RANDOMIZER_API_GLOW = 3,
    ICON_RANDOMIZER_API_CUBE = 4,
    ICON_RANDOMIZER_API_SHIP = 5,
    ICON_RANDOMIZER_API_BALL = 6,
    ICON_RANDOMIZER_API_UFO = 7,
    ICON_RANDOMIZER_API_WAVE = 8,
    ICON_RANDOMIZER_API_ROBOT = 9,
    ICON_RANDOMIZER_API_SPIDER = 10,
    ICON_RANDOMIZER_API_SWING = 11,
    ICON_RANDOMIZER_API_JETPACK = 12,
    ICON_RANDOMIZER_API_DEATH_EFFECT = 13,
    ICON_RANDOMIZER_API_TRAIL = 14,
    ICON_RANDOMIZER_API_SHIP_FIRE = 15,
    ICON_RANDOMIZER_API_ANIMATION = 16
};

/**
 * The types of groups of icons and colors that can be randomized.
 */
enum RandomizeAllType {
    ICON_RANDOMIZER_API_ALL_ICONS = 0,
    ICON_RANDOMIZER_API_ALL_SPECIAL = 1,
    ICON_RANDOMIZER_API_ALL_COLORS = 2
};

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

    // A helper function to convert a ICON_RANDOMIZER_API constant to a randomize type, for backwards compatibility.
    static RandomizeType fromConstant(int type);

    // A helper function to convert a ICON_RANDOMIZER_API_ALL constant to a randomize all type, for backwards compatibility.
    static RandomizeAllType fromAllConstant(int type);
public:
    /**
     * The function to initalize the Icon Randomizer API.
     * It is recommended that this function is called before any other functions in the API, but it is done automatically if forgotten.
     * This function can be rerun to refresh the unlocked icons and colors.
     */
    static void init();

    /**
     * A function to get a random number using the mersenne twister algorithm.
     * @param min The minimum number to generate.
     * @param max The maximum number to generate.
     * @returns A random number between min and max.
     */
    static int random(int min, int max);

    /**
     * A function to convert an icon type to a randomize type.
     * @param type The icon type to convert.
     * @returns The randomize type for the icon type.
     */
    static RandomizeType randomizeTypeFromIconType(IconType type);

    /**
     * A function to convert an icon type to an ICON_RANDOMIZER_API constant.
     * This function is deprecated and is only used for backwards compatibility.
     * @param type The type of icon to convert.
     * @returns The ICON_RANDOMIZER_API constant for the icon type.
     */
    [[deprecated("Use randomizeTypeFromIconType instead.")]]
    static int fromIconType(IconType type);

    /**
     * A function to convert a randomize type to an icon type.
     * @param type The randomize type to convert.
     * @returns The unlock type for the randomize type.
     */
    static UnlockType unlockTypeFromRandomizeType(RandomizeType type);

    /**
     * A function to convert an ICON_RANDOMIZER_API constant to an unlock type.
     * This function is deprecated and is only used for backwards compatibility.
     * @param type The ICON_RANDOMIZER_API constant to convert.
     * @returns The unlock type for the ICON_RANDOMIZER_API constant.
     */
    [[deprecated("Use unlockTypeFromRandomizeType instead.")]]
    static UnlockType toUnlockType(int type);

    /**
     * The function to randomize an icon or color.
     * @param type The type of icon or color to randomize.
     * @param dual Whether or not to randomize the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     * @returns The ID of the randomized icon.
     */
    static int randomize(RandomizeType type, bool dual = false);

    /**
     * The function to randomize an icon or color.
     * This function is deprecated and is only used for backwards compatibility.
     * @param type The type of icon or color to randomize. (Use the ICON_RANDOMIZER_API constants for this.)
     * @param dual Whether or not to randomize the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     * @returns The ID of the randomized icon.
     */
    [[deprecated("Use randomize with the RandomizeType enum instead.")]]
    static int randomize(int type, bool dual = false);

    /**
     * The function to randomize multiple types of icons or colors at once.
     * @param type The types of icons to randomize.
     * @param dual Whether or not to randomize the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     */
    static void randomizeAll(RandomizeAllType type, bool dual = false);

    /**
     * The function to randomize multiple types of icons or colors at once.
     * This function is deprecated and is only used for backwards compatibility.
     * @param type The types of icons to randomize. (Use the ICON_RANDOMIZER_API_ALL constants for this.)
     * @param dual Whether or not to randomize the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     */
    [[deprecated("Use randomizeAll with the RandomizeAllType enum instead.")]]
    static void randomizeAll(int type, bool dual = false);

    /**
     * Gets the current icon or color ID for a specific type.
     * @param type The type of icon or color to get the ID for.
     * @param dual Whether or not to get the ID for the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     * @returns The ID of the current icon.
     */
    static int active(RandomizeType type, bool dual = false);

    /**
     * Gets the current icon or color ID for a specific type.
     * This function is deprecated and is only used for backwards compatibility.
     * @param type The type of icon or color to get the ID for. (Use the ICON_RANDOMIZER_API constants for this.)
     * @param dual Whether or not to get the ID for the separate dual icon or color. (Requires the mod "Separate Dual Icons" by Weebify)
     * @returns The ID of the current icon.
     */
    [[deprecated("Use active with the RandomizeType enum instead.")]]
    static int active(int type, bool dual = false);
};
