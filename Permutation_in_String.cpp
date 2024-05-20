#include <bits/stdc++.h>
using namespace std;

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⣤⢤⡤⣤⠤⣔⡲⡔⢦⣒⠦⡤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⢻⢥⣛⡜⢮⣼⢲⣙⢦⢳⡹⢲⡍⣞⡱⢫⡜⣝⡢⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⡿⢣⣿⢾⡱⢮⣽⢧⢣⢏⣾⢣⡝⣣⠞⣥⢏⣳⢚⣬⠳⣍⠶⣩⠦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⣫⣾⣽⣿⠟⡦⢽⣾⣏⢮⡓⢮⢞⡗⣮⢱⡛⢦⣋⣖⢫⠖⡽⢬⡓⢧⡛⡼⣡⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⡀⠁⠀⠈⡐⠈⠀⠀⠀⠀⠀⢀⣼⣿⡿⣱⣿⣿⣿⢏⡞⣭⣿⣿⢚⢦⣋⠗⣮⣿⣜⡣⣝⢣⡳⢬⡳⣋⢾⡥⢫⠧⣝⢲⢣⡝⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠂⠀⢠⠀⠀⠀⠃⠀⠈⠀⠀⠀⢠⣿⣿⡿⣱⡿⣿⣿⡟⡼⣘⣾⣿⣯⡙⣶⡏⡞⢦⠽⣧⣓⢎⡧⣝⢣⡳⠽⣞⢯⢣⣛⡬⣓⢯⡜⡜⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀⢠⣿⣿⣿⣳⣿⣿⣎⡻⣸⡱⢻⡟⠁⡧⡝⡏⣷⣙⢮⣙⣿⣎⡷⢞⡬⢧⣙⢧⣋⢿⣷⡘⠶⣍⠾⣝⡼⡸⠄⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⢀⡄⠀⠀⡄⠀⠀⠀⠀⠀⠀⠁⠀⣾⣿⣿⣷⣿⣿⣿⣿⢣⢎⡺⠋⠀⠇⡷⣙⢃⢺⡱⢎⡞⡼⣧⣳⠈⢺⡱⢎⡶⣩⠶⣹⡭⣛⢬⡛⣼⠶⣹⢹⡀⠀⠀⠀⠀⠀⠀⠀
// ⢀⠂⠀⠀⠀⠀⠠⠀⠀⠀⡀⠀⠀⠘⣰⣿⣿⢿⣿⣿⠻⣿⡟⡜⢮⠋⠀⠀⠈⡷⣹⠀⢀⢏⠷⣸⡱⢿⣏⡀⠀⠹⣇⡞⣥⢛⡴⣏⠳⣎⡵⢎⣷⢣⢧⢣⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠁⠀⠀⢃⠀⠀⠀⡇⠀⠀⠀⢹⣿⣿⣿⣿⣿⣷⣄⡙⠭⡇⠀⠁⠄⠀⢱⣹⠀⠀⠨⣯⠵⣩⢛⣯⡇⠀⠀⠙⢜⠶⣩⠶⣩⢗⡣⢞⣱⢚⡧⡞⣭⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⡃⠀⠀⡤⠀⠀⠀⢇⠀⠀⠀⠈⣿⣿⣿⣷⣿⣿⣿⠜⡕⠀⠀⠀⠀⠀⠂⣿⡀⠀⠀⠀⠻⡥⣋⢿⡅⢠⠠⠂⠈⢛⠦⣏⠵⣪⠝⣮⣱⢋⣷⣙⠖⣆⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⡇⠀⠀⠸⠂⠀⠀⠉⠀⠀⠀⠀⢼⣿⣿⣾⣿⣿⣿⡞⡇⠀⠀⢀⣀⣤⣄⠸⡌⠀⠀⠀⠀⠘⢭⢖⣇⠀⣀⣠⣀⡈⠳⣎⢻⡥⣛⣼⡣⢏⣼⣹⡞⣱⣄⠀⠀⠀⠀⠀
// ⠀⠀⠐⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠸⣿⣿⣿⣿⣿⣷⡿⠀⢠⣾⠟⢋⣭⣟⣆⠁⠀⠀⠀⠀⠀⠀⠙⢼⢰⣟⣯⣛⠻⢷⣽⣙⡶⢣⣾⣏⠳⣼⡇⣟⡴⢫⢦⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠉⠿⠿⢿⣿⣻⣿⡇⠀⡿⠁⢠⣿⣽⣤⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣧⣧⠈⣿⠙⣽⢣⣿⣿⡳⣜⠯⣵⢺⡟⠚⢵⢠⡀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢀⠠⠀⠀⠀⠀⠃⢀⠀⠀⠀⠀⢹⣿⣿⣷⠀⠘⠅⢸⣿⣿⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⣿⣿⣿⡿⠀⠏⠰⣹⢾⡟⢿⣿⣎⡟⡼⣇⢿⠀⠀⠀⠉⠉
// ⠀⠀⠀⠀⡀⠄⠀⠀⠀⠀⠀⡀⢀⢀⠐⠀⠀⠀⠀⣼⡿⣸⢻⣧⠀⠀⠂⡣⣦⠾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠾⠴⠾⠁⠀⠀⠀⡝⣾⢭⢻⣿⡜⣣⣝⡷⣊⡇⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠐⠁⠰⠀⠀⠀⢀⣿⡱⢣⢏⡞⣣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⡧⢎⡳⣿⠼⡱⢎⡷⣩⢶⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⢸⣷⢭⡓⡞⡼⣕⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣗⡫⣕⣻⢭⠳⣭⣿⣱⢺⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣷⣯⣼⣵⢎⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣵⣿⣇⡗⣎⢾⣍⠳⣖⣿⡧⢻⠀⠀⠀⠀
// ⠀⢢⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣷⣞⣢⠀⠀⠀⠀⠀⠀⠔⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⡗⡼⣊⢶⢪⢽⣞⣿⣓⣻⠀⠀⠀⠀
// ⠀⠀⠣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣟⣿⣱⠳⣍⢮⡓⢾⣿⡿⣒⠇⠀⠀⠀⠀
// ⠀⠀⢠⣆⠀⠀⠀⠀⠀⠀⠀⢀⡀⢀⠀⠔⠁⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣀⢄⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⣴⣶⣿⣿⡿⣿⣿⣿⢔⡻⣜⢲⡙⢾⠟⢧⣹⠀⠀⠀⠀⠀
// ⠀⠀⠸⣿⡇⠤⠭⠀⠀⠁⠉⠁⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⠒⢁⠀⠄⠀⢠⠐⠀⠀⢿⣿⣿⢿⡿⠁⣿⣿⣏⠮⣕⢎⢧⡻⡏⠀⢮⠁⠀⠀⠀⠀⠀
// ⠀⠀⠀⢹⣿⡀⠐⡀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠐⠤⠀⠁⠀⠀⠱⠈⣿⣿⡟⠁⠀⣹⣿⢥⡛⡜⣎⢾⢳⠀⠀⠁⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⣿⣿⠀⠣⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⣈⠔⠀⢠⣿⣿⣿⣦⠀⣿⡟⢦⣹⠕⠁⣸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⢹⣿⡀⠀⠈⠠⢀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⣠⣆⠥⡀⠀⢸⣿⣿⣿⣿⣿⣤⠛⠊⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣿⣷⡀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠏⡖⡡⢯⡢⡌⣿⣿⣿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠘⣿⣿⣶⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⡼⡁⣿⡄⣷⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠐⣻⠐⣿⣿⡌⢷⡘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢨⡇⠎⡿⡿⣗⢨⢁⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⠿⠿⠿⠿⠿⠻⠟⠿⠟⠿⠟⠿⠿⠻⠿⠟⠿⠿⠻⠿⠟⠿⠿⠇⠘⠤⠇⠏⠜⠆⠣⠿⠻⠟⠿⠻⠟⠿⠻⠟⠿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

class Solution {
public:

    bool checkIfSame(vector<int>& v1, vector<int>& v2) {
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> freq_arr(26, 0);
        int len1 = s1.size(), len2 = s2.size();
        if(len2 < len1) return false;
        for(int i = 0; i < len1; i++) {
            freq_arr[s1[i]-'a']++;
        }
        int start = 1;
        vector<int> dupe(26, 0);
        for(int i = 0; i < len1; i++) {
            dupe[s2[i]-'a']++;
        }
        if(checkIfSame(dupe, freq_arr)) return true;
        for(int end = len1; end < len2; end++) {
            dupe[s2[start-1]-'a']--;
            dupe[s2[end]-'a']++;
            if(checkIfSame(dupe, freq_arr)) return true;
            start++;
        }
        return false;
    }
};

int main() {

    return 0;
}