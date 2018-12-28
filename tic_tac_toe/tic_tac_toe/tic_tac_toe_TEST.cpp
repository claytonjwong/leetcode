//
//  tic_tac_toe_TEST.cpp
//  tic_tac_toe
//
//  Created by CLAYTON WONG on 7/28/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "TestHarness.h"
#include "tic_tac_toe.hpp"

using namespace TicTacToe;

TEST(init,Model){
    int N=3,K=1;
    Model m(N,K);
    CHECK(m.getSize()==3);
    CHECK(m.getWinLen()==1);
}

TEST(illegalMoves,Model){
    int N=3,K=3;
    Model m(N,K);
    CHECK(m.makeMove(N, N, Player::O)==false);
    CHECK(m.makeMove(-1, -1, Player::O)==false);
    CHECK(m.makeMove(N, 0, Player::O)==false);
    CHECK(m.makeMove(0, N, Player::O)==false);
    CHECK(m.makeMove(-1, 1, Player::O)==false);
    CHECK(m.makeMove(1, -1, Player::O)==false);
}

TEST(singleMoveWin,Model){ // K=1
    int N=3,K=1;
    Model m(N,K);
    CHECK(m.makeMove(0, 0, Player::X));
    CHECK(m.isWin(0, 0));
}

TEST(overwriteMove,Model){
    int N=3,K=3;
    Model m(N,K);
    CHECK(m.makeMove(0, 0, Player::X));
    CHECK(m.makeMove(0, 0, Player::O)==false);
    
    CHECK(m.makeMove(1, 2, Player::O));
    CHECK(m.makeMove(1, 2, Player::X)==false);
}

TEST(xWinHorizontal1,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(0,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(0,1,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(0,2,Player::X);
    CHECK(m.isWin(0,0)==true);
    CHECK(m.isWin(0,1)==true);
    CHECK(m.isWin(0,2)==true);
}

TEST(xWinHorizontal2,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(1,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(1,1,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(1,2,Player::X);
    CHECK(m.isWin(1,0)==true);
    CHECK(m.isWin(1,1)==true);
    CHECK(m.isWin(1,2)==true);
}

TEST(xWinHorizontal3,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(2,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(2,1,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(2,2,Player::X);
    CHECK(m.isWin(2,0)==true);
    CHECK(m.isWin(2,1)==true);
    CHECK(m.isWin(2,2)==true);
}

TEST(xWinVertical1,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(0,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(1,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(2,0,Player::X);
    CHECK(m.isWin(0,0)==true);
    CHECK(m.isWin(1,0)==true);
    CHECK(m.isWin(2,0)==true);
}

TEST(xWinVertical2,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(0,1,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(1,1,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(2,1,Player::X);
    CHECK(m.isWin(0,1)==true);
    CHECK(m.isWin(1,1)==true);
    CHECK(m.isWin(2,1)==true);
}

TEST(xWinVertical3,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(0,2,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(1,2,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(2,2,Player::X);
    CHECK(m.isWin(0,2)==true);
    CHECK(m.isWin(1,2)==true);
    CHECK(m.isWin(2,2)==true);
}

TEST(xNotWin1,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(0,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(0,1,Player::O);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(0,2,Player::X);
    CHECK(m.isWin(0,0)==false);
    CHECK(m.isWin(0,1)==false);
    CHECK(m.isWin(0,2)==false);
}

TEST(xNotWin2,Model){
    int N=3,K=3;
    Model m(N,K);
    m.makeMove(0,0,Player::X);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(0,1,Player::O);
    CHECK(m.isWin(0,0)==false);
    m.makeMove(0,2,Player::X);
    CHECK(m.isWin(0,0)==false);
    CHECK(m.isWin(0,1)==false);
    CHECK(m.isWin(0,2)==false);
    CHECK(m.makeMove(1,0,Player::X));
    CHECK(m.makeMove(2,0,Player::O));
    CHECK(m.isWin(0,0)==false);
    CHECK(m.isWin(1,0)==false);
    CHECK(m.isWin(2,0)==false);
}

TEST(bottomUpWin1,Model){
    int N=3,K=3;
    Model m(N,K);
    CHECK(m.makeMove(2,0,Player::X));
    CHECK(m.makeMove(1,1,Player::X));
    CHECK(m.makeMove(0,2,Player::X));
    CHECK(m.isWin(2,0));
    CHECK(m.isWin(1,1));
    CHECK(m.isWin(0,2));
}

TEST(bottomUpWin2,Model){
    int N=4,K=3;
    Model m(N,K);
    CHECK(m.makeMove(1,0,Player::X));
    CHECK(m.makeMove(2,1,Player::X));
    CHECK(m.makeMove(3,2,Player::X));
    CHECK(m.isWin(1,0));
    CHECK(m.isWin(2,1));
    CHECK(m.isWin(3,2));
}

TEST(bottomUpWin3,Model){
    int N=5,K=3;
    Model m(N,K);
    CHECK(m.makeMove(3,4,Player::X));
    CHECK(m.makeMove(2,3,Player::X));
    CHECK(m.makeMove(1,2,Player::X));
    CHECK(m.isWin(3,4));
    CHECK(m.isWin(2,3));
    CHECK(m.isWin(1,2));
}

TEST(topDownWin1,Model){
    int N=3,K=3;
    Model m(N,K);
    CHECK(m.makeMove(0,0,Player::O));
    CHECK(m.makeMove(1,1,Player::O));
    CHECK(m.makeMove(2,2,Player::O));
    CHECK(m.isWin(0,0));
    CHECK(m.isWin(1,1));
    CHECK(m.isWin(2,2));
}

TEST(topDownWin2,Model){
    int N=4,K=3;
    Model m(N,K);
    CHECK(m.makeMove(1,0,Player::O));
    CHECK(m.makeMove(2,1,Player::O));
    CHECK(m.makeMove(3,2,Player::O));
    CHECK(m.isWin(1,0));
    CHECK(m.isWin(2,1));
    CHECK(m.isWin(3,2));
}

TEST(topDownWin3,Model){
    int N=5,K=3;
    Model m(N,K);
    CHECK(m.makeMove(1,2,Player::O));
    CHECK(m.makeMove(2,3,Player::O));
    CHECK(m.makeMove(3,4,Player::O));
    CHECK(m.isWin(1,2));
    CHECK(m.isWin(2,3));
    CHECK(m.isWin(3,4));
}


