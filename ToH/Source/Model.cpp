//
//  Model.cpp
//  ToH
//
//  Created by CLAYTON WONG on 3/24/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <stdio.h>
#include "Model.h"

using namespace std;

/* accessors */
int Model::getDiskCount() const {
    return myDiskCount;
}

/* helpers */
void Model::generateMoves(){
    go(myDiskCount,SRC,DST,AUX,myMoves);
}

void Model::go(int N,
               const int src, const int dst, const int aux,
               vector<Move>& moves){
    if (N==0) return;
    go(N-1,src,aux,dst,moves);
    moves.push_back(std::move(Move(N-1,src,dst))); // use N-1 for 0-based index for diskID
    go(N-1,aux,dst,src,moves);
}

