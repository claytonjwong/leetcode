//
//  clone_linked_list_TEST.cpp
//  clone_linked_list
//
//  Created by CLAYTON WONG on 7/28/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "TestHarness.h"
#include "clone_linked_list.hpp"

TEST(null,clone_linked_list){
    Solution s;
    ListNode* in=nullptr;
    auto out=s.clone(in);
    CHECK(out==nullptr);
}

TEST(single_ptr_to_self,clone_linked_list){
    Solution s;
    ListNode* in=new ListNode(nullptr);
    in->val=in;
    CHECK(in->val==in);
    auto out=s.clone(in);
    CHECK(out->val==out);
}

TEST(one_two_three_example,clone_linked_list){
    Solution s;
    ListNode* in_one=new ListNode(nullptr),*in=in_one;
    ListNode* in_two=new ListNode(nullptr);
    ListNode* in_three=new ListNode(nullptr);
    in_one->next=in_two; in_two->next=in_three;
    in_one->val=in_three;
    in_two->val=in_two;
    in_three->val=in_one;
    
    
    // check "in"
    
    //
    // 1 ---> 2 ---> 3 ---> NULL
    //
    CHECK(in_one->next==in_two && in_two->next==in_three && in_three->next==nullptr);
    
    //
    //    ---------------
    //    |     ---     |
    //    |     | |     |
    //    V     | V     V
    //    1 ---> 2 ---> 3 ---> NULL
    //
    CHECK(in_one->val==in_three);
    CHECK(in_two->val==in_two);
    CHECK(in_three->val==in_one);
    
    auto out=s.clone(in),
         out_one=out,
         out_two=out_one->next,
         out_three=out_two->next;
    
    
    // check "out"
    
    //
    // 1 ---> 2 ---> 3 ---> NULL
    //
    CHECK(out_one->next==out_two && out_two->next==out_three && out_three->next==nullptr);
    
    //
    //    ---------------
    //    |     ---     |
    //    |     | |     |
    //    V     | V     V
    //    1 ---> 2 ---> 3 ---> NULL
    //
    CHECK(out_one->val==out_three);
    CHECK(out_two->val==out_two);
    CHECK(out_three->val==out_one);
    
    
    // check "in"
    
    //
    // 1 ---> 2 ---> 3 ---> NULL
    //
    CHECK(in_one->next==in_two && in_two->next==in_three && in_three->next==nullptr);
    
    //
    //    ---------------
    //    |     ---     |
    //    |     | |     |
    //    V     | V     V
    //    1 ---> 2 ---> 3 ---> NULL
    //
    CHECK(in_one->val==in_three);
    CHECK(in_two->val==in_two);
    CHECK(in_three->val==in_one);
}

TEST(one_two_three_four,clone_linked_list){
    Solution s;
    ListNode* in_one=new ListNode(nullptr),*in=in_one;
    ListNode* in_two=new ListNode(nullptr);
    ListNode* in_three=new ListNode(nullptr);
    ListNode* in_four=new ListNode(nullptr);
    in_one->next=in_two; in_two->next=in_three; in_three->next=in_four;
    in_one->val=in_two; in_two->val=in_three; in_three->val=in_four; in_four->val=in_one;
    
    // check "in"
    
    //
    // 1 ---> 2 ---> 3 ---> 4 ---> NULL
    //
    CHECK(in_one->next==in_two && in_two->next==in_three && in_three->next==in_four && in_four->next==nullptr);

    //
    //   ------------------------
    //   |  -----  -----  ----- |
    //   | |    | |    | |    | |
    //   V |    V |    V |    V |
    //    1 ---> 2 ---> 3 ---> 4 ---> NULL
    //
    CHECK(in_one->val==in_two && in_two->val==in_three && in_three->val==in_four && in_four->val==in_one);
 
    auto out=s.clone(in),
         out_one=out,
         out_two=out_one->next,
         out_three=out_two->next,
         out_four=out_three->next;
    
    
    // check "out"
    
    //
    // 1 ---> 2 ---> 3 ---> 4 ---> NULL
    //
    CHECK(out_one->next==out_two && out_two->next==out_three && out_three->next==out_four && out_four->next==nullptr);

    //
    //   ------------------------
    //   |  -----  -----  ----- |
    //   | |    | |    | |    | |
    //   V |    V |    V |    V |
    //    1 ---> 2 ---> 3 ---> 4 ---> NULL
    //
    CHECK(out_one->val==out_two && out_two->val==out_three && out_three->val==out_four && out_four->val==out_one);
    
    
    // check "in"
    
    //
    // 1 ---> 2 ---> 3 ---> 4 ---> NULL
    //
    CHECK(in_one->next==in_two && in_two->next==in_three && in_three->next==in_four && in_four->next==nullptr);
    
    //
    //   ------------------------
    //   |  -----  -----  ----- |
    //   | |    | |    | |    | |
    //   V |    V |    V |    V |
    //    1 ---> 2 ---> 3 ---> 4 ---> NULL
    //
    CHECK(in_one->val==in_two && in_two->val==in_three && in_three->val==in_four && in_four->val==in_one);
}
