//
//  Model.h
//  ToH
//
//  Created by CLAYTON WONG on 3/23/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#ifndef Model_h
#define Model_h

#include "Move.h"
#include <vector>
#include <memory>

class Model {
public:
    
    const unsigned int MAX_DISKS=6,RODS=3,SRC=0,DST=1,AUX=2;
    
    /* constructors */
    Model(unsigned int disks) : myCurrMoveIndex{-1} {
        myDiskCount=disks>MAX_DISKS ? MAX_DISKS : disks;
        generateMoves();
    }
    Model(const Model& src) : Model(src.getDiskCount()) {}
    Model& operator=(const Model& rhs)=default;
    
    /* accessors */
    int getDiskCount() const;

    /* mutators */
    Move getNextMove() {
        if (++myCurrMoveIndex < myMoves.size())
            return myMoves[myCurrMoveIndex];
        return Move(Move::DONE,Move::DONE,Move::DONE);
    }

private:
    unsigned int myDiskCount;
    int myCurrMoveIndex;
    std::vector<Move> myMoves;

    /* helpers */
    void generateMoves();
    void go(int N, int src, int dst, int aux, std::vector<Move>& moves);
};

#endif /* Model_h */
