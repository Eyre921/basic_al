#include <bits/stdc++.h>
using namespace std;

// 论文结构体
struct Paper {
    string title;                     // 论文标题
    long long citations;              // 被引用次数
    int index;                        // 输入顺序
    unordered_set<string> words;      // 标题中的单词集合（小写）
};

// 将字符串转换为小写
string toLower(const string &s) {
    string res = s;
    for (auto &c : res) c = tolower(c);
    return res;
}

// 将标题分割成单词，并转换为小写
unordered_set<string> splitToWords(const string &title) {
    unordered_set<string> wordSet;
    string word;
    stringstream ss(title);
    while (ss >> word) {
        wordSet.insert(toLower(word));
    }
    return wordSet;
}

// 读取N篇论文的信息
vector<Paper> readPapers(int N) {
    vector<Paper> papers;
    papers.reserve(N);
    for (int i = 0; i < N; i++) {
        string title;
        getline(cin, title); // 读取标题
        long long K;
        cin >> K;             // 读取被引用次数
        cin.ignore();         // 忽略换行符
        Paper p;
        p.title = title;
        p.citations = K;
        p.index = i;          // 输入顺序
        p.words = splitToWords(title); // 分词并转换为小写
        papers.push_back(p);
    }
    return papers;
}

// 读取M个查询
vector<string> readQueries(int M) {
    vector<string> queries(M);
    for (int i = 0; i < M; i++) {
        getline(cin, queries[i]);
    }
    return queries;
}

// 比较两个论文的函数，用于排序
bool comparePapers(const Paper &a, const Paper &b) {
    if (a.citations != b.citations) {
        return a.citations > b.citations; // 被引用次数降序
    }
    return a.index < b.index;             // 输入顺序升序
}

// 处理单个查询，返回匹配的论文列表
vector<Paper> processQuery(const string &query, const vector<Paper> &papers) {
    vector<Paper> matched;
    // 分割查询关键词并转换为小写
    vector<string> keywords;
    string word;
    stringstream ss(query);
    while (ss >> word) {
        keywords.push_back(toLower(word));
    }

    // 遍历所有论文，检查是否包含所有关键词
    for (const auto &p : papers) {
        bool flag = true;
        for (const auto &kw : keywords) {
            if (p.words.find(kw) == p.words.end()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            matched.push_back(p);
        }
    }

    // 排序匹配的论文
    sort(matched.begin(), matched.end(), comparePapers);
    return matched;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; // 论文数量
    while (cin >> N) {
        if (N == 0) break; // 输入结束
        cin.ignore();       // 忽略换行符

        // 读取N篇论文
        vector<Paper> papers = readPapers(N);

        int M; // 查询数量
        cin >> M;
        cin.ignore(); // 忽略换行符

        // 读取M个查询
        vector<string> queries = readQueries(M);

        // 处理每个查询
        for (const auto &query : queries) {
            vector<Paper> matched = processQuery(query, papers);
            // 输出匹配的论文标题
            for (const auto &p : matched) {
                cout << p.title << "\n";
            }
            // 输出"***"
            cout << "***\n";
        }

        // 输出"---"表示一组数据结束
        cout << "---\n";
    }

    return 0;
}
/*
【问题描述】

       谷歌、百度等搜索引擎已经成为了互连网中不可或缺的一部分。在本题中，你的任务也是设计一个搜索论文的搜索引擎，当然，本题的要求比起实际的需求要少了许多。
       本题的输入将首先给出一系列的论文，对于每篇论文首先给出标题，然后给出它被引用的次数。然后会有一系列的搜索询问，询问标题中包含特定关键词的论文有哪些。
       每一个询问可能包含多个关键词，你需要找出标题包含所有关键词的论文。
    “包含”必须是标题中有一个词正好是给定的关键词，不区分大小写。
      对每个询问，都按被引用的次数从多到少输出满足条件的论文的标题。如果有被引用的次数相同的论文，则按照论文在输入中的顺序排列，先给出的论文排在前面。

【输入形式】输入包含多组数据。
     每组数据首先有一行包含一个整数N(1<=N<=1000)，表示论文的数目，N=0表示输入结束。每组论文的信息第一行是论文的标题，由字母（大小写均可）和空格组成，不超过10个词，每个词不超过20个字符，标题总共不超过250个字符。第二行是一个整数K(0<=K&lt;=108)，表示它被引用的次数。在论文信息结束以后，有一行包含一个整数M(1<=M<=100)，表示询问的数目。接下来有M行，每行是一个询问，由L(1<=L<=10)个空格分开的词构成，每个词不超过20个字符。

【输出形式】

      对每个询问，按照题目给定的顺序输出满足条件的论文的标题；如果没有满足条件的论文，就不输出。在每组询问的输出之后输出一行“***”，在每组数据的输出之后输出一行“---”。

【样例输入1】

6
Finding the Shortest Path
120
Finding the k Shortest Path
80
Find Augmenting Path in General Graph
80
Matching in Bipartite Graph
200
Finding kth Shortest Path
50
Graph Theory and its Applications
40
6
shortest path
k shortest path
graph
path
find
application
0

【样例输出1】

Finding the Shortest Path
Finding the k Shortest Path
Finding kth Shortest Path
***
Finding the k Shortest Path
***
Matching in Bipartite Graph
Find Augmenting Path in General Graph
Graph Theory and its Applications
***
Finding the Shortest Path
Finding the k Shortest Path
Find Augmenting Path in General Graph
Finding kth Shortest Path
***
Find Augmenting Path in General Graph
***

***
---

【样例输入2】

1
Finding the Shortest Path
120
2
Path

Pat
0

【样例输出2】

Finding the Shortest Path

***

***

---

【样例说明】

需要查询的内容为“k shortest path”，他包含了3个独立的关键词。

【运行时限制】

最大运行时间为2秒，最大运行内存为512MB。
 */