//
//  Rod.h
//  ToH
//
//  Created by CLAYTON WONG on 3/27/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Rod_h
#define Rod_h

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Rod {
public:
    Rod(sf::Vector2f pos, sf::Vector2f dim, sf::Color color);
    
    int getDiskHeight() const;
    sf::RectangleShape getShape();
    
    void incrementDiskHeight(int amount);
    void decrementDiskHeight(int amount);
    
private:
    int myHeight;
    sf::RectangleShape myShape;
};

#endif /* Rod_h */
