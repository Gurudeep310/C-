/*
Karl loves playing games on social networking sites. His current favorite is CandyMaker, where the goal is to make candies.
Karl just started a level in which he must accumulate  candies starting with  machines and  workers. In a single pass, he can make  candies. After each pass, he can decide whether to spend some of his candies to buy more machines or hire more workers. Buying a machine or hiring a worker costs  units, and there is no limit to the number of machines he can own or workers he can employ.
Karl wants to minimize the number of passes to obtain the required number of candies at the end of a day. Determine that number of passes.
Sample Input
3 1 2 12
Sample Output
3
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
typedef long long ll;

bool check(ll machines, ll workers, ll price, ll target, ll rounds) {
    if (machines >= (target+workers-1)/workers) return true;
    ll cur = machines*workers;
    rounds--;
    if (rounds == 0) return false;
    while (1) {
        ll rem = target - cur;
        ll rnds = (rem + machines*workers - 1) / (machines*workers);
        if (rnds <= rounds) return true;
        if (cur < price) {
          rem = price - cur;
          rnds = (rem + machines*workers - 1) / (machines*workers);
          rounds -= rnds;
          if (rounds < 1) return false;
          cur += rnds * machines * workers;
        }
        cur -= price;
        if (machines > workers) {
          workers++;
        } else {
          machines++;
        }
    }
    return false;
}

long minimumPasses(long m, long w, long p, long n) {
    ll a = 1, b = 1000000000000LL;
    while (a < b) {
        ll mid = (a + b) >> 1;
        if (check(m, w, p, n, mid)) {
          b = mid;
        } else {
          a = mid + 1;
        }
    }
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long m = stol(first_multiple_input[0]);

    long w = stol(first_multiple_input[1]);

    long p = stol(first_multiple_input[2]);

    long n = stol(first_multiple_input[3]);

    long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

