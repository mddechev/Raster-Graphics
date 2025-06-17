#ifndef _RASTER_GRAPHICS_EDITOR_HPP_
#define _RASTER_GRAPHICS_EDITOR_HPP_

#include "commands/CommandInterpreter.hpp"
#include "session/SessionEditor.hpp"
#include "commands/Command.hpp"
#include <iostream>

class RasterGraphicsEditor {
public:

    static RasterGraphicsEditor& get_instance();

    void run(std::istream& input = std::cin, std::ostream& output = std::cout);
    
private:
    RasterGraphicsEditor() = default;

    RasterGraphicsEditor(const RasterGraphicsEditor&) = delete;
    RasterGraphicsEditor& operator=(const RasterGraphicsEditor&) = delete;

    RasterGraphicsEditor(RasterGraphicsEditor&&) = delete;
    RasterGraphicsEditor& operator=(RasterGraphicsEditor&&) = delete;
};

#endif