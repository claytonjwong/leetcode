//
//  View.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include <SFML/Window/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Model.h"
#include "View.h"

using namespace std;

View::View(Model& model, sf::Vector2i dim) :
myHeight{dim.y}, myWidth{dim.x},
myColors{sf::Color(255,0,0),sf::Color(255,127,0),sf::Color(255,255,0),
         sf::Color(0,255,0),sf::Color(0,0,255),sf::Color(148,0,211),
}
{
    // generate rod shapes and push onto vector
    int space=myWidth/4,x=space,y=100;
    for (int i=0; i<model.RODS; ++i){
        Rod rod(sf::Vector2f(x,y),sf::Vector2f(5,dim.y-y),sf::Color(250,250,250));
        myRods.push_back(rod);
        x+=space;
    }
    
    // generate disk shapes and push onto vector
    // draw disks bottom up, then reverse order, so that index 0 is the smallest disk on top
    for (int i=model.getDiskCount()-1; i>=0; --i){
        int x=myRods[model.SRC].getShape().getPosition().x,y=myRods[model.SRC].getDiskHeight();
        int diskWidth=(i+1)*Disk::WIDTH_FACTOR;
        sf::Vector2f pos(x-diskWidth/2,y);
        sf::Vector2f dim(diskWidth,Disk::HEIGHT);
        Disk disk(pos,dim,myColors[i]);
        myDisks.push_back(disk);
        myRods[model.SRC].incrementDiskHeight(Disk::HEIGHT);
    }
    reverse(myDisks.begin(),myDisks.end());
}

void View::moveDisk(Move& m){
    int x=myRods[m.dstRod].getShape().getPosition().x-myDisks[m.diskID].getShape().getSize().x/2;
    int y=myRods[m.dstRod].getDiskHeight();
    myDisks[m.diskID].setPosition(sf::Vector2f(x,y));
    myRods[m.srcRod].decrementDiskHeight(Disk::HEIGHT);
    myRods[m.dstRod].incrementDiskHeight(Disk::HEIGHT);
}

void View::draw(sf::RenderWindow& window){
    
    // Clear screen
    window.clear(sf::Color::Black);
    
    // draw rods
    for (auto rod: myRods)
        window.draw(rod.getShape());
    
    // draw disks
    for (auto disk: myDisks)
        window.draw(disk.getShape());
    
    // Update the window
    window.display();
}

std::vector<Rod> View::getRods() const {
    return myRods;
}

std::vector<Disk> View::getDisks() const {
    return myDisks;
}


