//
//  DiskTest.cpp
//  ToH
//
//  Created by CLAYTON WONG on 4/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "TestHarness.h"
#include "Disk.h"


TEST(create,Disk){
    sf::Vector2f pos(200,300),dim(55,66);
    sf::Color color(255,255,255);
    Disk d(pos,dim,color);
    sf::RectangleShape shape=d.getShape();
    CHECK_EQUAL(shape.getPosition().x,200);
    CHECK_EQUAL(shape.getPosition().y,300);
    CHECK_EQUAL(shape.getSize().x,55);
    CHECK_EQUAL(shape.getSize().y,66);
    CHECK(shape.getFillColor()==color);
}

TEST(move,Disk){
    sf::Vector2f pos(200,300),dim(55,66);
    sf::Color color(255,255,255);
    Disk d(pos,dim,color);
    d.setPosition(sf::Vector2f(69,72));
    auto shape=d.getShape();
    CHECK_EQUAL(shape.getPosition().x,69);
    CHECK_EQUAL(shape.getPosition().y,72);
    
    d.setPosition(sf::Vector2f(178,392));
    shape=d.getShape();
    CHECK_EQUAL(shape.getPosition().x,178);
    CHECK_EQUAL(shape.getPosition().y,392);
}

