#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

#include <cstddef>

namespace constants {

    const char PBM_MAGIC_NUMBER[] = "P1";
    const char PGM_MAGIC_NUMBER[] = "P2";
    const char PPM_MAGIC_NUMBER[] = "P3";

    const char PBM_EXTENSION[] = "pbm";
    const char PGM_EXTENSION[] = "pgm";
    const char PPM_EXTENSION[] = "ppm";

    const char LOAD_COMMAND_NAME[] = "load";
    const char SAVE_COMMAND_NAME[] = "save";
    const char SAVE_AS_COMMAND_NAME[] = "saveas";
    const char GRAYSCALE_COMMAND_NAME[] = "grayscale";
    const char MONOCHROME_COMMAND_NAME[] = "monochrome";
    const char NEGATIVE_COMMAND_NAME[] = "negative";
    const char INFO_COMMAND_NAME[] = "info";
    const char EXIT_COMMAND_NAME[] = "exit";
    const char SWITCH_COMMAND_NAME[] = "switch";
    const char CLOSE_COMMAND_NAME[] = "close";
    const char ADD_COMMAND_NAME[] = "add";
    const char ROTATE_COMMAND_NAME[] = "rotate";
    const char ROTATE_LEFT_DIRECTION[] = "left";
    const char ROTATE_RIGHT_DIRECTION[] = "right";
    const size_t SUPPORTED_COMMANDS_COUNT = 12;
}

#endif