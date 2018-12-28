//
//  View.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef View_h
#define View_h

#include <SFML/Window/Window.hpp>
#include <vector>
#include "Model.h"
#include "Rod.h"
#include "Disk.h"

class View {
public:
    
    /* constructor */
    View(Model& model, sf::Vector2i dim);

    /* helpers */
    void moveDisk(Move& m);
    
    void draw(sf::RenderWindow& myWindow);
    
    /* accessors */
    //int getDirection() const;
    std::vector<Rod> getRods() const;
    std::vector<Disk> getDisks() const;
    
private:
    int myHeight,myWidth;
    std::vector<Rod> myRods;
    std::vector<Disk> myDisks;
    std::vector<sf::Color> myColors;
};

#endif /* View_h */
