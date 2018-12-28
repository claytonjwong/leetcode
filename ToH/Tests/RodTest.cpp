//
//  RodTest.cpp
//  ToH
//
//  Created by CLAYTON WONG on 4/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "TestHarness.h"
#include "Rod.h"
#include "Disk.h"

TEST(create,Rod){
    int rodHeight=100;
    Rod rod(sf::Vector2f(0,0),sf::Vector2f(5,rodHeight),sf::Color(255,255,255));
    CHECK_EQUAL(rod.getDiskHeight(),rodHeight-Disk::HEIGHT);
}

TEST(changeDiskHeight,Rod){
    int rodHeight=100;
    Rod rod(sf::Vector2f(0,0),sf::Vector2f(5,rodHeight),sf::Color(255,255,255));
    int currHeight=rodHeight-Disk::HEIGHT;
    CHECK_EQUAL(rod.getDiskHeight(),currHeight);
    int up=30,down=up;
    rod.incrementDiskHeight(up);
    CHECK_EQUAL(rod.getDiskHeight(),currHeight-up);
    rod.decrementDiskHeight(down);
    CHECK_EQUAL(rod.getDiskHeight(),currHeight);
    rod.decrementDiskHeight(down);
    CHECK_EQUAL(rod.getDiskHeight(),currHeight+down);
}


