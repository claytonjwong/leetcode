//
//  Controller.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Controller_h
#define Controller_h


#include "Model.h"
#include "View.h"

class Controller {
public:
    enum State { WAITING, MOVING, DONE };
    
    /* constructors */
    Controller(Model model, View view, sf::Vector2i dim)
    : myWindow(sf::VideoMode(dim.x,dim.y), "Towers of Hanoi"), myModel{model}, myView{view}, myState{WAITING} {}
    
    Controller(const Controller& src)=delete;
    Controller& operator=(const Controller& rhs)=delete;
    
    void init();
    void play();
    
    void setIcon();
    void initSound();
    
    void processEvents();
    
    /* state machine */
    void processState();
    void changeState_WAITING();
    void processState_WAITING();
    void changeState_MOVING();
    void processState_MOVING();
    void changeState_DONE();
    void processState_DONE();
    

    
private:
    sf::RenderWindow myWindow;
    Model myModel;
    View myView;
    int myState;
    Move myCurrMove;
    sf::Music myMoveSound;
    sf::Clock myWaitClock,myMoveClock;
    sf::Time myWaitTime=myWaitClock.restart(),myMoveTime=myMoveClock.restart();
    float myWaitDuration=0,myMoveDuration=0;
};

#endif /* Controller_h */
