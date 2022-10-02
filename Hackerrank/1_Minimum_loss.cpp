/*
Lauren has a chart of distinct projected prices for a house over the next several years. She must buy the house in one year and sell it in another, and she must do so at a loss. She wants to minimize her financial loss.
Function Description
Complete the minimumLoss function in the editor below.
minimumLoss has the following parameter(s):
int price[n]: home prices at each year
Returns
int: the minimum loss possible
Input Format
The first line contains an integer n, the number of years of house data.
The second line contains n space-separated long integers that describe each price[i].
Sample Input 0
3
5 10 3
Sample Output 0
2
Sample Input 1
5
20 7 8 2 5
Sample Output 1
2
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int minimumLoss(vector<long> price) {
   
    int n = price.size();
    sort(price.begin(), price.end());

    long long ans = (long long)1e18;
   for(int i = 1; i < n; i++)
   {
       if(price.at(i) < price.at(i-1))
       {
        if(ans > price.at(i) - price.at(i-1))
            ans = price.at(i) - price.at(i-1);
       }
   }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split(rtrim(price_temp_temp));

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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
