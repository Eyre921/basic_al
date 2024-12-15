#include <bits/stdc++.h>
using namespace std;
int check(int a) {}

int b1(int l, int r) //mid在分界线左边
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int b2(int l, int r) //mid在分界线右边
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

double b3(double l, double r)
{
    double x;
    for (int i = 1; i <= 100; i++)
    {
        double mid = (l + r) / 2;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    return l;
}

int main()
{
    string s = "hello world";
    stringstream ss(s);
    unordered_set<string> words;
    string word;
    while (ss >> word)
    {
        words.insert(word);
    }
    for (auto it: words) cout << it << " ";
}
