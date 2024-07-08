# Icon Randomizer API
A mod that provides an API for randomizing icons and colors.

# Usage
To use this API, you must first add the following dependency to your `mod.json` file:
```json
{
    "dependencies": [
        {
            "id": "hiimjustin000.icon_randomizer_api",
            "version": ">=1.0.0",
            "importance": "required"
        }
    ]
}
```

Then, you can use the API. For example:
```cpp
// This includes <Geode/Geode.hpp> for you
#include <hiimjustin000.icon_randomizer_api/include/IconRandomizer.hpp>

using namespace geode::prelude;

// Initialize the randomizer
IconRandomizer::init();

// Randomize an icon or color
IconRandomizer::randomize(ICON_RANDOMIZER_API_CUBE);
IconRandomizer::randomize(ICON_RANDOMIZER_API_COLOR_1);

// Randomize all of a certain type
IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_ICONS);
IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_SPECIAL);
IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_COLORS);

// Refresh unlocked icons and colors
IconRandomizer::init();

// Randomize a separate dual icon or color (Requires the Separate Dual Icons mod by Weebify)
IconRandomizer::randomize(ICON_RANDOMIZER_API_CUBE, true);
IconRandomizer::randomize(ICON_RANDOMIZER_API_COLOR_1, true);

// Randomize all of a certain type for a separate dual icon or color
IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_ICONS, true);
IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_SPECIAL, true);
IconRandomizer::randomizeAll(ICON_RANDOMIZER_API_ALL_COLORS, true);
```
Full documentation can be found [here](./include/IconRandomizer.hpp).

# Constants
The following constants are available for use:
```cpp
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
```

# License
This mod is licensed under the [MIT License](./LICENSE).