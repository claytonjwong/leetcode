/*
 * 1297. Maximum Number of Occurrences of a Substring
 *
 * Q: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
 * A: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/discuss/461476/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <unordered_map>

using namespace std;

// wrong answer (problem with updating m with proper count when j moves)
/*
class Solution {
public:
    using Map = unordered_map<int, int>;
    using Cand = unordered_map<string, int>;
    int maxFreq(string s, int L, int min, int max, Map m = {}, Cand cand = {}, int ans = 0) {
        int N = s.size();
        for (auto i = 0; i < min; ++i)
            ++m[s[i]];
        for (auto i = 0; i < N; ++i) {
            for (auto j = min; j <= max && i + j <= N; ++j) {
                if (m.size() <= L) {
                    auto ss = s.substr(i, j);
                    ans = std::max(ans, ++cand[ss]);
                }
                if (j < max && i + j < N)
                    ++m[s[i + j]];
            }
            if (--m[s[i]] <= 0)
                m.erase(s[i]);
        }
        return ans;
    }
};
*/

/*

Let's use a sliding window of [i..j) which oscillates between min/max size as it moves forward.

Use an unordered_map `m` to track the char count, if the count reaches zero, then delete the key, so we
can use the size() of the map to know the unique char count.

ok if: m.size() <= maxLetters  and  minSize <= j - i <= maxSize

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4

aababcaab
0123456789
i  j

m.size() == 2 -> cand = { 'aab' }
a: 2
b: 1


aababcaab
0123456789
i   j

m.size() == 2 -> cand = { 'aab': 1, 'aaba': 1 }
a: 3
b: 1


aababcaab
0123456789
 i  j

m.size() == 2 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1 }
a: 2
b: 1


aababcaab
0123456789
 i   j

m.size() == 2 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1 }
a: 2
b: 2

aababcaab
0123456789
  i  j

m.size() == 2 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1 }
a: 1
b: 2

aababcaab
0123456789
  i   j

m.size() == 3 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1 }
a: 1
b: 2
c: 1

aababcaab
0123456789
   i  j

m.size() == 3 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1 }
a: 1
b: 1
c: 1

aababcaab
0123456789
   i   j

m.size() == 3 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1 }
a: 2
b: 1
c: 1


aababcaab
0123456789
    i  j

m.size() == 3 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1 }
a: 1
b: 1
c: 1


aababcaab
0123456789
    i   j

m.size() == 3 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1 }
a: 2
b: 1
c: 1


aababcaab
0123456789
     i  j

m.size() == 2 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1, 'caa': 1 }
a: 2
c: 1


aababcaab
0123456789
     i   j

m.size() == 3 -> cand = { 'aab': 1, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1, 'caa': 1 }
a: 2
b: 1
c: 1


aababcaab
0123456789
      i  j

m.size() == 2 -> cand = { 'aab': 2, 'aaba': 1, 'aba': 1, 'abab': 1, 'bab': 1, 'caa': 1 }
a: 2
b: 1


Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3

aaaa
01234
i  j

m.size() == 1 -> cand = { 'aaa': 1 }
a: 3

aaaa
01234
 i  j

m.size() == 1 -> cand = { 'aaa': 2 }
a: 3


Example 3:

Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3

aabcabcab
0123456789
i j

m.size() == 1 -> cand = { 'aa': 1 }
a: 2


aabcabcab
0123456789
i  j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1 }
a: 2
b: 1


aabcabcab
0123456789
 i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 1 }
a: 1
b: 1


aabcabcab
0123456789
 i  j

m.size() == 3 -> cand = { 'aa': 1, 'aab': 1, 'ab': 1 }
a: 1
b: 1
c: 1


aabcabcab
0123456789
  i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 1, 'bc': 1 }
b: 1
c: 1


aabcabcab
0123456789
  i  j

m.size() == 3 -> cand = { 'aa': 1, 'aab': 1, 'ab': 1, 'bc': 1 }
a: 1
b: 1
c: 1


aabcabcab
0123456789
   i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 1, 'bc': 1, 'ca': 1 }
a: 1
c: 1


aabcabcab
0123456789
   i  j

m.size() == 3 -> cand = { 'aa': 1, 'aab': 1, 'ab': 1, 'bc': 1, 'ca': 1 }
a: 1
b: 1
c: 1


aabcabcab
0123456789
    i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 2, 'bc': 1, 'ca': 1 }
a: 1
b: 1


aabcabcab
0123456789
    i  j

m.size() == 3 -> cand = { 'aa': 1, 'aab': 1, 'ab': 2, 'bc': 1, 'ca': 1 }
a: 1
b: 1
c: 1


aabcabcab
0123456789
     i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 2, 'bc': 2, 'ca': 1 }
b: 1
c: 1


aabcabcab
0123456789
     i  j

m.size() == 3 -> cand = { 'aa': 1, 'aab': 1, 'ab': 2, 'bc': 2, 'ca': 1 }
a: 1
b: 1
c: 1


aabcabcab
0123456789
      i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 2, 'bc': 2, 'ca': 2 }
a: 1
c: 1


aabcabcab
0123456789
      i  j

m.size() == 3 -> cand = { 'aa': 1, 'aab': 1, 'ab': 2, 'bc': 2, 'ca': 2 }
a: 1
b: 1
c: 1


aabcabcab
0123456789
       i j

m.size() == 2 -> cand = { 'aa': 1, 'aab': 1, 'ab': 3, 'bc': 2, 'ca': 2 }
a: 1
b: 1


Example 4:

Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3

abcde
012345
i  j

m.size() == 3 -> cand = {}
a: 1
b: 1
c: 1




Algo:

cand = {}
i = 0
j = minSize
m = count of chars between [i..j)

for i from [0..N)
    for j from [i + minSize..i + maxSize] && j <= N
        if subs from [i..j) is ok, then add to cand map count
        ans = max(ans, curr cand map count)

return ans

*/

// TLE -- naive, but correct solution to count the characters for each individual substring
/*
class Solution {
public:
    using Map = unordered_map<int, int>;
    using Cand = unordered_map<string, int>;
    int maxFreq(string s, int L, int min, int max, Map m = {}, Cand cand = {}, int ans = 0) {
        int N = s.size();
        auto cnt = [](const auto& s, Map m = {}) {
            for (auto c: s)
                ++m[c];
            return m.size();
        };
        for (auto i = 0; i < N; ++i) {
            for (auto j = min; j <= max && i + j <= N; ++j) {
                auto ss = s.substr(i, j);
                auto x = cnt(ss);
                if (x <= L)
                    ans = std::max(ans, ++cand[ss]);
            }
        }
        return ans;
    }
};
*/

// key -- simplify and only track min!!
class Solution {
public:
    using Map = unordered_map<int, int>;
    using Cand = unordered_map<string, int>;
    int maxFreq(string s, int T, int min, int _, int cnt = 0, Cand cand = {}, int ans = 0) {
        int i = 0, j = 0, m[123] = {}, N = s.size();
        auto inc = [&]() { if (++m[s[j++]] == 1) ++cnt; };
        auto dec = [&]() { if (--m[s[i++]] == 0) --cnt; };
        while (j <= N) {
            if (j - i > min) dec();
            if (j - i == min && cnt <= T) ans = max(ans, ++cand[s.substr(i, j - i)]);
            if (j - i <= min) inc();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.maxFreq("aababcaab", 2, 3, 4) << endl;
    cout << solution.maxFreq("aaaa", 1, 3, 3) << endl;
    cout << solution.maxFreq("aabcabcab", 2, 2, 3) << endl;
    cout << solution.maxFreq("abcde", 2, 3, 3) << endl;
    cout << solution.maxFreq("jkfdkmeighcmefihcfjcbeamcfdcdlglfakbkfceaabcakkigmekibfibmlegfmhfabljdehlbaaihkibbeemfhlfglhhfbegfkafdkimjjadamglgfhigbjbifkgagfalcibibaljdmefbfkhdbcickjbeigllcegjhgbhafmlakhccdlhbalbfgcdalmbjkmbjhbfglfjjjeadgchaechicldiecdmddekmhkijcmhmcldjjhmbmkhhgekggjkeehjmfgklfcemmafaffbeibgebakeeibcelfjeblaecgiefcljjjelkffhkhchjflechcbjlacgiegbflcefejbbmlhhfdgekblblkkbceeejeeideggmdjgickfckacklfmmmafmhmfjhgfmiegdgjeilhkkaiijjgdhlkhilkjgfeahhkleekleaegjadhlkgfeifldbjdkdkdhgmefkggggkcgjjcfkaefdgjjjgkdddjhldljhilldickgabhecelmidhheglmeldbehaifhllickifmiebmfijlicfiagmlmcfaldblbafehmgcgdmeiblidhbkfaehmdglbgeghgddgmhjbcbbefajejbfildmllkbffhkilkefadmfcmljgjklgedamiigecjdfabfblfbiagdhhjeefccclmiecdfalcjcgjfbmaekeamhejhdadegbdcbjigfmlllafhblfjmhmehlkmimggbeaglheajchchjbbicfceffhjckiacdkjhhmceifgbkagdmckdhbieejblaachcajlmekfehbeaadmhebehbelhgflabllfhkkaegbffimldfjegijdlaaflmbelbigacikcjeccmfcddecmfbibggfkdigkebjihllkflalcflmcmlkgmgbfgffiekmcecfbbfemldejcldeehjgjdjcahlkcmedcabjdfhcckkdbickfiibijcgfmhgkcekjgbagfkmkikilaflidliidgjajilmkclkajihdgjhchkjgdjmlcefellimgehkmbkghahbeiimmmidfeabjkbbiadjdjefcbljlilgcfjchijhakhdiimcahjaegchjemjjmdmfkibellichfgjjhfdkihmekmigblggackkkaiegdabmmjceibfiehddblccfjmaceikidkdcfaeeklihaeeemaadaejcdfkcedimgfdacamfmcjccmfcmedbedikkjefefjflgahecahbkhbcklmmhdbdblckcccfemciaglieimjciglmllkefjbdcdlbccedmldmjeijbikdeljijmbeadkajhkmbmhfikdiiklcemalealfggfackmiaahagjdkbjmhmlcgecfbhdialdblfjeigijhmgebgdijmjbaheffjelekcbcgamhbcldiaimedjlggjhedfjdfkeekdkldheelajjddmlfhfkkmdggkdlgjikecimakihkfkbhcfbajijdihkkfgklbjaeeilchadaebdcdkemalfimlblaliadjhejkfckdfgmjmigkiglkmejcdlbafeldlijgkbledehejaimdbbaimbffclbjajdgldhdklhbhkdeeacjiamcfjmfafdamglfhlgmafbigmgdmkhcgaeiajgailabeldadfhkmedahcbajlegceafjhhjfiifibkecaihaicjkcijjgeddibckeedhjmlkdeemfigaflcgjkbbehgdiafebbfmbbbdfmjchcgafgdcgeheblgfdhhilhljaelhckcjjjhgfaiihlclehjmalckmlaeceeifegjmjfgcccmidlkgjkecbmjkkdjkbkgafhldmlfajhgbgheadhglfhdkglldjfaleddgcagjfkhkhmmhamciefmhcdlmdfjeihkimjdihkmjadmhhadgmkmbleafemhebmlaehjmdhhkbdegfdlcamkiemhjjkbfhjdkmhjgcjjlabkdlccmccjgabbbkcbjhdmfhdllkicljieahhgamkljfgmeacflhfcchhmcmijmhgjhggbkhmklgfkdklmclhjdhmifaalhljjcbfjmjlbkajefhbkeifjmffhgljmfifblhaghjcckfdahbjaeicbdecciklkgdciibjbaajcecablghhkahfjlifdadaibimaikikkbbicdccbajmegbidkmgcdagdehmghdegfeliihfbakhcmfbfcfcakfhgleaejckkmbkkfdkgajakkmlecccakmgkcgcmamckkkacgicjaaklbbfhicmgllmbjflebbklamfjjmemlajfebjklccehmlglcaiejajmbdhgeadmfilcedglfbbfddbamabifikclidmigdihkhkfahicicdimidjeefmmacldaifkifeihgjkflfbcmabfcjbmcicdbblfbgdleebjjelfjahdbgkljdbbmmmdhagkddeikmicjlmllfcekkgefbdlhafibeikelggdfmamfafmajhlibaeklkjemjdceacicjifdhdllacmleeligdibdemejfhiccejfchimdcdladdmeifeaidmbaadjkghhfefjmhfhmacmlemaaklfbgghbdiacfmhclmlgkacdakkkbamehldcalemkhbdfebfhkgceeddbkaaakagjdefkbghblkfbifbkkemfdfhbkagdhkdakdjeaailhbhdgefhhkhaiffgajimjmifjdemidmecicbgdijcacecklmbmljdcemlljgfmidmfjaacjcdieifmhiekidcbaldfjegegijbhbkkkdalalaflmmikfagbmcbhageddhljlkjhdghjbbgbchbgfkbcjdkgikeilhfbbjhmmakcekfkhieaambmjbmlcmgmlecjkmiihfghhcgemlkkbklaahjgjjgclgbihjcjebikjjddffmeekgeidjmgadgkfahahfcbckmhblehmcbijlckdbbiicdalacfeammcfegemkmcghgcdbiahgcjaaageehldflclcmakmeggfagkidgbgimfeggjbdmaajfaabihklkcfeemdeiiifahfdeemcdjibjfehciibggkieeelldaeifcmihihifmgaamlhhikmbbfjddmabdhjjfghbkfakfmhckfikfielccbhcjheijjlaclhabkkkbiabccchghkmhfhbfbaejgajkcgfejdckhmmgdjekgikidmjgmhbmliaccbkdghaljdbhbbghhmdgbibclddcfbhljiahfellaidldgffgjlhcjchhdellhgldlfigihhmhfamkheiedhfkcibdilmfhkmjehgmmjcggadmmagekfbikdfjkakklkfadfghgjjkbmbjmakehjclcfhfjjaablfgfdacjcdlmdbiagfhcihfmejjmfmkcfkeihdlkjeiibdfcfaligdeagmgkcakieekaafjihejflhjhacblhaaciklleljkfldefeikfjcjgmidehfkiicglmabbkkmgmacjemijmgekecmkabicbkhjalhfljfmlcgchdjhdgjihklmdbihdmfhalcmbbcdchgifjbdbeicimjajemhfieieclfdekajdgeejijfjlkbbikbeeabgbhcdikmhhliejdkfdjemmlejmljfbabhhjdlghmikakjkeccgfagheijebccfidgcfcfeigemjmkchdgabamfmgmflbbdelcgkkagbfgmibicfjifcebalgkmkbllaakdmbgcilkbgmclkgfccmejmkbkdkbjfjegadbdlkbehdhefbigabjbjiimfbakkmjblgdhjmejmbclmaajffcamegbjcgeaflgfekmijlhmkaclecmdifgdbcbblmfhkklhflkicjdkfhbgkijiecijbhdijhdmfmgcbmfjgjldkkddelgamfmmfldfgijdlcemklgkkkeammfmadkgckmllllkbgbhcjjklclfiideiaichiamgechjjimmmaicefiblmcfaaccimmbdjkccakjdbilgggcfdgddjllllelmklghmfikgfalbddcebagihjmfcmbjdjekhigmbgjdibjfcagjcjbifejcgkkbhcbcmkckkfmakbflkkdaihadfgailkadaeajjajdfekdhmlmghdlgegflmiaabcfjgefhlfemdfkkdmlagmjlfmbdhhbhckglbfkbkefdljelielfmibkdhdffcdjgbfcmhilbehhkladbeljgedjchfdlhfdikeimgdbbbccebmgibgmmcffhjgfikmgiifmgdfbgbfllfilhbjibebljmafklfiecddcfklflbhadimdmlmhifmfikfmiafcjmfeidgmmbkmafacljdajhchhdcmgehlmlaebjmecgejlajcdfllgbgkbidieifbagilbbkiddlmbhaggadflkmdfdhmdlmgkgcmmadbjeggjkimhhbmhkjmebdcmbdbbbmfmbmghjehcgeecfhhiglmjhilkchmcmgdlglkehegjalibmlbkjdhmgjdiebjmcgcmkjjfdlmjmbemdedcajihlhmlkeddbkahhedikldhffjbmahbabgjeeifhfmcelliahhgigdbalikgafjhlhejgihjkfblelmgjimakalcmbihmfmmiahjjfidbghdccjiijhakmedajikhjjfhigddcjhifihhfabdiifidjcibkafkfaeffddbmmjjlmiagkbfcljhldahcimbdjdabdjchkdjhffmgdfmgkllgffhkblelbmjljhjajaafkllbidhhimiamihajakedcdhecffcgkkefbfjgcifiemfbigamialiaehheegecabcfijijiijchlbkjbcigmhdlejidjjhbhjgaedhffhfibccbcjgmifickgkcgcklmehdfmgagcfkjhejcckefadmgcecjkmgajkimmjghdhbkfemfibabkilgfddebgdimfjjljlciggdfjhghlbfmhadfhkkchcihfcbfjfbiejdkddkihgllgjfbmgiigkhhcgfhlggfdbmmjglcmkimjhbdcghegliidijlhkjiblgidfggeehmhiaglhikfcdhgddfcglgmbghkekcaheldkfdgehamfjfekghjcdjjdhhbfcehemilkdhlbgmmkkbbfafdekkajbjidfgmjkfdkckjichmgmkbhgacbihjegdiefdbegmjlblfjkmagllcbgdbheeijflfdkmdgeammlccmbkmddllceghlilhddglgemjalimcekidihbmldffbihihmbajeilceihakfjmiihhcjdmiakfldggcjlgmfklhhlcjkkemdggidjccibfkgklkfflkafhfgelfejkdfcghjkbekfabeiklcgbkcjjiekkfjimdlfmkjejeegkdhhigffjeacgdbhaidhhbbdhkdhkggljchbhihmgalijdbdkcabmmbdmeaemkmfiglmekfchliegfhljecadladgdgjkmleailmiiambiclblaijccdkajgifldgmiakmmcbmlfjccklhciedlldccdihchlafabjadcceljbeeigdefcjeidgfgjllamllkfejlbkbhdfmmgagihbafgljieeldidchkfkgkchbaaaifdieajeglbalfeiakiljfglmjfkkjgcbekjhbmkibfkaejafhkielhhcmgkggdhldhjgiiadcheffdagijlcalbifggclbdgcbkihakfgajmmdegbiiablllldaejmkichaelhgmmgamajkkflkmcihheadcfchifjhfjdcackdmbkilkfimfdlkgfldfmglajifbbmgcdmfmkkgmkhkmdllglcgcelagdgadlmbklghdbgdljjlffmdeaifkbkcllecmmefjfkdlejhgfccfagaacdfikkkfllkglhmfijcajcdhmmcjbkmcmjmbgemmjihachejlkgfbgifbkabidimcdafccbcggdcfemmebdcllhhcjbgbhihhhgjiacjlbhljceflhlcelbjadcfgjgfgljkkdldmfkeefceiajfbccjiihebkegbhljkfjlgimggifiihdmafgdigkkjcfdedhkdlbideaadcbclebleldjaeaifjebceeekfggiiilefgdiahmlaehgcffdfklmmmfklmemdddhemfifcfcldbecbhlbleeihbhbgciamakbmhkebcmcafijhgkadhglgammmfgagcgiefjgbeialbcidicddgamelbjmchdjfbfgbbdjeklhcdimjdhlkdjgcaclcabdhbfhccalfjckgbbemdekdaahckblhgddihdfbjjkdlfifckldmlfkmbilmlclbdmehfhdlicedgcdfljhfmgbclgakcmbkimmmlchlkgdedalcabedhlcgfkdjjmkbdekfdgkabcibbelehmeiledjbhbaajmcgfihfahjmjfcbbcjlmbhfkdamhmlelifaiammllcfecfjhfjhjlhhdahgfacildkfeecihmelefkjagfjcebbjgaiefjhkgakjdhfdcffkldmmidggkjcdejckbblikgfgggigcgiabmdijlflaamcafcilafckembidbgghadmdmjmkjifimgcmbbjddjcaahjgeimlgbehgmgdjhfafkfclcdhklkacfcflhaahcdejhbegibjfcjadcfkflbcebjbhkjhjeeidjehajbaakkmffhedhbglhbfhblgjbjghmfjfbfcmglekkhjhfifdbccfhmdkeklbmdlhlmghdkfbdckjhckgggalihefcjbdefafgcakafafjfaeahbiileagkfagaammicmceadliicmmhchgbiglhhdlliiaebeekegmlhldjielbjadhhdhicakdjcgcflegfhaiibaffchcghlemmiejbbjgcbkabaemgkbdmbfgcfbjlflahdblglhdlhaldekhlkkbafmebjgcmkfgfefmlmjhbgebfiklbmjiacgafkekchfjdejdeibmfchkbbigajhhhlflimhimbdlfccmhggcehmeifdkjbacahchfbakjkcdjfdcligmgcihdeeeehihhfdifgcclimielmemacijbahgclbdhfmdljgihljbccdcacaeglecaedekdkcdihlejljhdbbgfgajdjdfffidbegaedibcecaiefbdgdlehfkahhaebfacejggjfedkgehgcedllcfadiklbdalemgfeafhgihigjmijclhbjegjdgdlemfbfemfbaccjihlmajklalieakaebbhdjafijgddfefijmkmhakjbgfccbjedhljhmbmehbhfcembefaialgighddakkefkmfmibaddmilcldmifdcjikiiagclagegdcggaehkdillilcckeikfidimfmilhlmeecgdbidmibkjdgjbcgmeebmhjekchbhgdabkibcjgmdaammhcbifbjmddekbeekgafmijhmekffdgeacdiieemekegfmgiaicigddmieajdfakejbghkkmegmcdjgegmjdidedhelhieckglmiejeighmgdgejimkijfmgejedadbilchfefkdagmfkciibbaclbcmjgdafdejiblbkiidcbcemifimaembbgbbmakafjmecklljdaehddjfiiflchdcmlfcdgllemhlmibdlkjmmggiekhiafcbglfddeeliidlbilbdiihkmjhfiimalimikcacdkikajfkihhcfabdiegacfgjegemcacjekimjefelgbblggacfdgjebcmcjmbjmemjkghimkmhbkceelmcfkddekeajclgefbkmambhkgaabcdcjgfjdhmfllbfhmdmleimkikekaahdfhkibhkeaeaejhiffmfmdmgifdhgjlmcgegcaagilckbbjakcfafbikbmldcghfehdgllghggdkiaahgmhghjfaghmgibblakieilelhmhkhbfhgcfdeimgeeaciegeghdidhlgbmikblambdefadkmlicjglmbdaifekfhkdjkcajegcbjlgeccmdehmmkdmhiekkjlijfjfflbegjacbiibfgecbamkbggeifmfidibehfjcebabmkhlkgecklecdeekchhhkjehgdclllclgkaidkeeihfckacfdkagiejlmmdaekbkkdlfgdghmbacedkfjhghlfigclclmjmmalagcfcgeehgfdmckkmmhkfidmbiglmjkmfhhagkldcjcjlecdhkghjiadhjjbfihjgcdfgfigjeekjdfkhmchjiammbeglggkckbjhcichacfamhljfljgkfleagjhcehfeejdbaekhjhcgkibhfkmbmbihimfgcjihgiljamajhbhggecaehfmhlhmjekcecgldllhffibhbmecbjcbkcfhjfkffaajfdglbcemgkabmihaldbhidfkhdkjkekaaemghbdjdfijillhaikbgmlffjlhekacaeaccgcfhjdhfaeehilllkbjmlmkmcaifihfjfeckdbjegafkdllcjccdijkcebagbbbmahhmfbemlmcihklhkebibifaegjgbjgkkmhljjiehdjilmijgmimdkmbkiedekcakmcafhbfhkhhkfkfamdlfbmdfeabbijkbbgfehhmbamagjkdkebcdbhfhekjfchclaihjafdmdhghgbdedciihbbichlmikfhgjjdgakhhlcfcgijlaicdjgfdjkemagaffhfmmdhcfkgiiagcbidfkgcefhlbcfejbliieldeddiikkmigceieaaeaeekfbmifgmggchclaeblakjeeiibhkiiihkfcgceaiefdhmdicmdmecgfgfedlcjkhhlmdimmajffgbafikgmkchjcaemcdbfaeajdickdbabdgijgkdceiihakimgfkimllbljkffbdlhdbilaehihhiegadfcmkfljckhamiadchgajmbcehamjeahefgdmjbhidamghgmbfblklihmacmfheldmafjfgkmkjfdmalaabeambmdemkddfehjckjadjbddmijjjlagicagligfjkdkkjlhgkbfkkeiifimcmibbkiicfdfhggcbekmmialilhfjhmhdhkdlamdlajdgdlglklkhjddgdabaadgiijahajbgfegijakcjggfaamihhaalegdcegadfifdhhlacflghjabiffcjiajhhkcggdhkfklhhiffbalagimdfchhamfemgbfikecagebmikbkgfdmjeakleamdkkmemdkhalfhllcgcedlbfidbgmlmbcmmbkicejhbhmejfgieakkccmgkedfbgcafajlkbjgcdmjgmfghjbaeiailkegjghhkgmghahelggjgbhakdebhaehelcdjbgbihhfgldmlfahmkeebgigfcfcehhiahjdmlgajcecjlhlagidgjkdejgichmafjmlecahcjdkjafejjkahkebimjcaaajailkdlgiefjbllejkfmgffkagbdbjijmekdjbfakgfgckhbfagmmafihgmafbhljaadbcabiaiagkkhglcjkcafadligjgeabaaklmfckelfiikakgjdcmgddbimeeefaahmddfbhdjmbblmbifbgmchaehbgdkdcjacfbfadcgcifdefjbiemkbgbchdkcfheaegkgfifmbdllibhmdfbkbceebdkmhjmcabbihafbkkijgjhamamg", 6, 8, 26) << endl;

    return 0;
}
