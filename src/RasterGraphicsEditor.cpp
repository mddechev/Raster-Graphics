#include "../include/RasterGraphicsEditor.hpp"

RasterGraphicsEditor& RasterGraphicsEditor::get_instance() {
    static RasterGraphicsEditor instance;
    return instance;
}

void RasterGraphicsEditor::run(std::istream& input, std::ostream& output) {

    SessionEditor* editor = new SessionEditor();
    CommandInterpreter intepreter(editor);

    std::cout << "\n       ╔═══════════════════════════════════════════════════════╗\n"
              <<   "       ║          WELCOME TO RASTER GRAPHICS EDITOR            ║\n"
              <<   "       ╚═══════════════════════════════════════════════════════╝\n";

    try {
        while (true) {
            std::string command;
            std::cout << '\n' << "> ";
            std::getline(input, command);

            if (!intepreter.interpret(command)) {
                std::cout << '\n' << "Command failed. Please try again.\n";
            }

        }
    }
    catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << '\n';
    }
    delete editor;
}