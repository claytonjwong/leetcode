//
//  Disk.h
//  ToH
//
//  Created by CLAYTON WONG on 3/27/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Disk_h
#define Disk_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Rod.h"
#include "Move.h"

class Disk {
public:
    static const int HEIGHT=15,WIDTH_FACTOR=50;
    
    /* constructors */
    Disk(sf::Vector2f pos, sf::Vector2f dim, sf::Color& color);

    /* accessors */
    sf::RectangleShape getShape() const;
    
    /* mutators */
    void setPosition(sf::Vector2f pos);
    
private:
    sf::RectangleShape myShape;
};

#endif /* Disk_h */
