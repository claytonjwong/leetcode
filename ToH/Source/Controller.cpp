//
//  Controller.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Controller.h"
#include "View.h"

void Controller::init(){
    setIcon();
    initSound();
    changeState_WAITING();
}

void Controller::play(){
    while (myWindow.isOpen()) {
        processEvents();
        myView.draw(myWindow);
        processState();
    }
}

void Controller::setIcon(){
    sf::Image icon;
    icon.loadFromFile(resourcePath() + "icon.png");
    myWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Controller::initSound(){
    myMoveSound.openFromFile(resourcePath() + "move.ogg");
}

void Controller::processEvents() {
    sf::Event event;
    while (myWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            myWindow.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            myWindow.close();
        }
    }
}

void Controller::processState(){
    if (myState==WAITING)
        processState_WAITING();
    if (myState==MOVING)
        processState_MOVING();
}

void Controller::changeState_WAITING(){
    myState=WAITING;
    myWaitTime=myWaitClock.restart();
    myWaitDuration=myWaitTime.asSeconds();
}

void Controller::processState_WAITING(){

    myWaitDuration+=myWaitTime.asSeconds();
    
    if (myWaitDuration > 30.0f)
        changeState_MOVING();
}

void Controller::changeState_MOVING(){
    myState=MOVING;
    myMoveTime=myMoveClock.restart();
    myMoveDuration=myMoveTime.asSeconds();
    myCurrMove=myModel.getNextMove();
}

void Controller::processState_MOVING(){

    myMoveDuration+=myMoveTime.asSeconds();
    
    if (myMoveDuration > 30.0f){
        if (myCurrMove.diskID==Move::DONE){ // *** DONE ***
            changeState_DONE();
        } else {
            myView.moveDisk(myCurrMove);
            myMoveSound.play();
            changeState_WAITING();
        }
    }
}

void Controller::changeState_DONE(){
    myState=DONE;
}

void Controller::processState_DONE(){
    // no-op
}





