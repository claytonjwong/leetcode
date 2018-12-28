//
//  ModelTest.cpp
//  ToH
//
//  Created by CLAYTON WONG on 4/5/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "TestHarness.h"
#include "Model.h"

/*
Model(unsigned int disks) : myCurrMoveIndex{-1} {
    myDiskCount=disks>MAX_DISKS ? MAX_DISKS : disks;
    generateMoves();
}
Model(const Model& src) : Model(src.getDiskCount()) {}
Model& operator=(const Model& rhs)=default;

int getDiskCount() const;

Move getNextMove() {
    if (++myCurrMoveIndex < myMoves.size())
        return myMoves[myCurrMoveIndex];
    return Move(Move::DONE,Move::DONE,Move::DONE);
}
*/

TEST(create,Model){
    Model m(3);
    CHECK_EQUAL(m.getDiskCount(),3);
}

TEST(moves,Model){
    int N=6;
    Model model(N);
    std::vector<Move> moves;
    while (true){
        Move move=model.getNextMove();
        if (move.srcRod==Move::DONE)
            break;
        moves.push_back(move);
    }
    CHECK_EQUAL(model.getDiskCount(),N);
    CHECK_EQUAL(moves.size(),(1<<N)-1); // 2^n-1
}

TEST(copy,Model){
    int N=6;
    Model model(N);
    std::vector<Move> moves;
    while (true){
        Move move=model.getNextMove();
        if (move.srcRod==Move::DONE)
            break;
        moves.push_back(move);
    }
    Model copyCtor(model);
    CHECK_EQUAL(model.getDiskCount(),copyCtor.getDiskCount());
    for (int i=0; i<model.getDiskCount(); ++i){
        Move a=moves[i],b=copyCtor.getNextMove();
        CHECK_EQUAL(a.srcRod,b.srcRod);
        CHECK_EQUAL(a.dstRod,b.dstRod);
        CHECK_EQUAL(a.diskID,b.diskID);
    }
}
