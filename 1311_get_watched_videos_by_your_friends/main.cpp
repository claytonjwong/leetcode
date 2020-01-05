/*
 * 1311. Get Watched Videos by Your Friends
 *
 * Q: https://leetcode.com/problems/get-watched-videos-by-your-friends/
 * A: https://leetcode.com/problems/get-watched-videos-by-your-friends/discuss/471415/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <ostream>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using VVI = vector<vector<int>>;
    using Queue = queue<int>;
    using Seen = unordered_set<int>;
    using Count = unordered_map<string, int>;
    using Pairs = vector<pair<int, string>>;
    VS watchedVideosByFriends(VVS& watchedVideos, VVI& friends, int id, int target, Count cnt = {}, Pairs p = {}, VS ans = {}) {
        Queue q{{id}};
        Seen seen{id};
        for (auto depth = 0; !q.empty() && depth < target; ++depth)
            for (auto n = q.size(); n--; q.pop())
                for (auto i: friends[q.front()])
                    if (seen.insert(i).second)
                        q.push(i);
        for (; !q.empty(); q.pop())
            for (auto k: watchedVideos[q.front()])
                ++cnt[k];
        for (auto& pair: cnt)
            p.push_back({pair.second, pair.first});
        sort(p.begin(), p.end());
        transform(p.begin(), p.end(), back_inserter(ans), [](auto& pair) { return pair.second; });
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VVS watchedVideos{
        {"vsb","ccxdjk","iqbl","c","mlx","dvki","q","dlzzux","tim","vs","snrmjhuj","btq","fh","nira","riqip","mwd","curlrr","t","oveec","vgp","ljfezm","mdteijvv","r","u","mxr","oa","tvnilnm","bdpybuww","z","d","qqy","rizsul","whzthdrl"},
        {"yb","nxlivu","t","nmljyko","utqe","k","qf","kywdsapg","ufmwhdh","kvhzvo","lpuyvxgn","mrdspiee","m","dzaucfo","vqzjeeq","ia","mzuwxzhr","arzhnfv","kvh","yr","fms"},
        {"nhzb","wqwt","hm"},
        {"dsubmcrd","bqhyaajo","xnfte","yruoqz","rfwmwmz","pile","sifyx","xl","eiiilm","soaee","hgczs","rnwh","rom","cuce","a","mnveste","hm","jgv","lxfhjwe","prjcqj","woaj","tl","itbbzkfz","udd","ushxgqq","dwgmvqe","xawdz","ysmv","rthibufv","niyv","mipdvef","o","p","mxrk","dcvx","n","gftqgqmq","ghlvsy","kb","btfejpbs","sm","mz","milpb","anjsxkze","ctzzy","nmqzas","bs","d","klyrbu","scpucr","kqzrafkl","eses","mk","lkitlbw","yu","ziym","sztcc","inc","jrx","hgdix","bxqjzzgr","rk","jqebol","nxfrbw","fghdses","xi","gzbloktx","huaapb","irb","h","qf","q","gojh","qlkmucgt","gvt","sntpl","wskkcun","wqzp","tvxsyotp","ivq","syzmt","ijaty","z","olhqogwp","wuemnb","lz","i","j","akkjszb","wckd","ey","ntkha","yyy","jjmnqo","gn","tbth","hwmm","texj","awwvjo","fvealnrk"},
        {"ktdsujzr","najyc","dqhtxuxi","lzhbdtq","ejb","ga","n","c","a","r","kzatar","pgij","hfgmb","rwob","kndasf","yf","hfjz","bz","xecoeh","x","lbsco","zhvf","bg","cz","jwiq","hxbxiyg","lloyvt","vmcnhpk","tud","cyzn","rjkyl","ollkmpq","l","jfj","rwx","fou","efc","hlukf","pjcne","odevkc","prb","ulxl","zquzvl","udfmbi","bhjk","hlybhjw","g","eh","qiefhc","sqqrt","osqpfql","nzci","hyee","afpl","bzl","th","couu","tkfs","prbblp","epcqkv","tkzsc","kncicvuk","f","hkiijp","ajfujbd","ntgilyu"},
        {"sjtivfke","dmlqxs","moep","bxuh","xc","q","spwkqzfs","mamrxrxo","ssl","x","lohwuv","coylg","eob","skzfsp","ashtbouf","modk","efkef","hrwno","qrjfqtqj","jvev","k","nm","too","lgbcxddr","eomfpoq","s","sopm","lyyft","fyarb","rh","kokxdmbx","inokqdfm","txpqeke","etghzz","oued","nb","elrkimam","wojxwjus","kyjfdpf","eodrdrkk","vrukxskr","kpwmrgfh","thby","tybkna","llttvn","zjhk","wmvyfam","tzythh","tk","gwjdnaz","cznedr","yke","nkruwqi","gffr","edo","nek","tealyf","hwps","bucerpse","lwei","cmpaqo","xhgw","biqgc","zy","mk","ow","vienluly","nnlrggc","hha","vmoz","sdbfqabn","nehwy","nyksxb","ewqlsbld","uudn","zal","eja","uapcyzsn","pr","er","utrnhqm","xkodcgst","ddldgd","aq","hcjptbs","rjmubvt","i","ohikypor","xwo","jssfkqvm","vrtmpyu","jace","dlijzrje"},
        {"obo","xskrlewa","yitz","zo","auixq","s","ddvkttu","ctpqksvb","fbtd","d","yzgfr","hgc","wsnite","szhct"},
        {"a","tjpnnzc","gyv","u","nllqefz","hzbl","ok","hiew","dpvxzta","jiyzwjgz","wum","z","oraehpu","jw","gqkdhhp","fp","wututn","rnyaume","ebjmtnu","gt","ptniq","kz","rwr","vvarv","yl","iydjezcn","apsxeyy","pzyhqam","n","hv","o","jt","l","c"},
        {"s","ljcrp","kyfulq","kthh","jjrk","savpi","ehfc","mgefr","km","fbog"},
        {"wj","xujq","kccchdqo","atfonrdg","h","gqtjj","lijba","u","bgckovjd","vdga","uett","o","r","pfra","ecae","scqrig","arilirm","qqroicf","smetgqaq","k","hkm","n","qzczwber","rmrisbg","jwmj","s","grqxr","hcg","fbvmjaez","bw","pfgsozv","vm","cekq","pqvlnsho","mlmzs","mtdf","canspb","duuyholq","kv","i","esfnvj","xhpxmaqi","ji","ku","hjx","fo","muyozv","vvdspscv","b","frptw","aokhhl","a"},
        {"mefh","mb","kao","bnh","vqogb","nmqniok","c","xxnfnfrq","inx","jlwomrmj","lrrz","iavc","wmfiy","pafpd","edmb","cdo","zabibqpx","ltod","kmumjc","xorl","nwxxnsi","ebk","mcuszk","eyx","rg","whltquwf","jfxe","nplwybr","al","egmo","ntkpk","st","y","rxp","cac","f","gxomw","wvirm","wm","hcxxkevt","u","ubjlyva","ksayrkxz","wyxbsvo","nm","sa","ylfmxbe","qwtnu","zsp","sztix","rsnekfo","srvequc","impxbzu","fuimi","ia","vz","oe"},
        {"zhbh","dd","s","bi","eldbzmz","frsp","ltm","kqc","a","docav","x","rjsty","omdzu","juvy","qqx","l","dnzveidl","ygkte","tahw","luenvknt","dibqjwqk","ghxh","liapyqe","ypcqzid","dnme","vo","fgil","lxisye","h","pytra","azfwgi","cnwl","yygdam","skvznk","mytiy","tcznht","lyjwadtq","f","yroj","mtacmex","pvmp","nz","wvp","ujry","j","zeiuq","penkq","gibjqs","pjifj","zkeim","vpxfmbcs","kbqx","bnzdt","ealhtl","whqcbka","afzxizvt","znju","bbp","rvvdmjn","nssptg"},
        {"kz","ufyhqpc","vmgiyaj","i","ft","yownj","jz","p","irg","bvm","s","axmkd","ftwgc","ywv","qsxahmv","v","q","ytzyfbx","ungfhct","rrkvvigq","mhvjt","wewui","sxiquh","rvad","ifxk","fuub","miig","mbybe","njlmyltg","izipt","zsl","mbc","cypgo","bikaw","znnnyltx","ygxnmjdc","wkl","wmdmbnt","dhwp","fvehtdw","kqozyf","upsfbqg","yedi","a","jgbjvv","ecw","sni","cgy","tng","rpftczp","gcve","gttw","ric","clqifv","nzrswrhe","zn","lhovrmk","byb","tofvxo","leogrp","tgeth","dvcuh","qgvjpwb","guwbjxj","nayo","nhudfq","x","faqpplr","autvnmh","r","u","ukbe","wfoeeiqm","qd","wm"},
        {"gbqnhp","fhgq","uwjpzy","ygjd","y","t","czqufo","nx","rbz","kvx","oxgmoz","ml","j","sllu","d","zymjwfjx","xkkg","b","w","tok","i","cwuha","ynl","zpbmd","wnyhh","siaazey","wyelcthr","eme","geetwd","ybt","ilaew","c","wnwmjvem","ylzoljp","iaj","wbpb","azuhewmz","hstifxg","ckl","dz","gkzr","zywcnslf","tdl","vpt","on","ccvu","kmlsk","qttucgn","qxplwd","kahjnvve","iwqt","f","bvdiu","fw","shonbepz","qjxmcs","evwqhnp","sx","rqfbwg","alhh","rnfzhah","u"},
        {"za","rih","kxedin","tbrbvo","x","jjvxmj","pjvdsvu","w","nc","duah","cgkgjjoo","womc","c","xtogx","nfutv","mxohhpa","ipply","sx","gw","mgnbxfyw"},
        {"nlqezcq","bsy","yqrx","ujjpeawo","vvslnwl","yigv","spivtnji","cdkovvjq","qkhe","iwh","avnmhec","fo","zzhjtmi","j","dxn","xvjwn","v","dyf","ndblukjb","zoblj","ixif","qkrcw","e","mkk","fjayiaru","n","yaztqmdd","z","cpglsbn","rkgaeppi","uqdnorq","zcbne","zygcol","st","zvdgtk","fky","gx","rscps","qomlqyuq","zfveafjf","gye","ozec","qrmmtuxn","pipevvg","bitzeog","mou","l","vejs","keztuxcv","vccaavc","er","bgnkv","vlgvf","cldnokq","av","ytwggcv","oqa","wztjvj","obb","fyatk","dhizu","pgcejauh","yvf","stod","g","uufidc","hmzjr","jej","jq","yy","omuy","az","puajwpp","fgprgq","enwx","wlph","h","lc","kxnooov","lbgvieqy","zy","gkdaxuh","wzmg","jvylh","tijf","al","wsy","poyvdht"}
    };
    Solution::VVI friends{{13,1,14,4,3,10,12,9,6,7},{9,10,0,7,5,13,6,14,2,3,11,15},{13,11,15,7,5,3,1,6,14,9},{14,5,12,0,2,8,1,15},{11,6,8,7,10,14,0,15,13,12},{7,3,8,9,1,10,2,13,12,15,6},{9,4,12,15,11,1,14,10,13,2,0,8,5},{12,5,8,4,15,1,2,11,14,10,0},{15,4,7,5,13,11,10,3,9,6},{6,12,1,5,11,15,0,10,8,14,2},{14,11,12,1,4,5,0,8,9,6,15,7},{4,2,10,12,9,8,6,14,7,1,15},{7,9,15,10,11,6,3,0,13,14,5,4},{0,2,8,1,5,12,6,4},{3,10,0,4,1,6,11,15,7,12,9,2},{8,12,7,6,2,9,14,4,3,10,1,5,11}};
    auto ans = solution.watchedVideosByFriends(watchedVideos, friends, 11, 1);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " ")), cout << endl;
    return 0;
}
