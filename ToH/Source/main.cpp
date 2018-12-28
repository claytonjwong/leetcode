
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp" // Here is a small helper for you! Have a look.
#include "Model.h"
#include "View.h"
#include "Controller.h"


int main(int, char const**)
{
    
    sf::Vector2i dim(1200,300);
    int disks=6;
    Model model(disks);
    View view(model,dim);
    Controller controller(model,view,dim);
    controller.init();
    controller.play();
    
    return EXIT_SUCCESS;
}


