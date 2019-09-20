#include<iostream>
#include<deque>
#include<queue>
 
using namespace std;
 
int info[2][10][10][1011];
int food[10][10];
int winter[10][10];
 
struct TREE {
    int r, c, age, num;
    TREE() :r(0), c(0) { }
    TREE(int r, int c) : r(r), c(c) {}
};
 
 
int n, m, k;
int dr[] = { -1,-1,-1,0,0 ,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };
 
inline bool isout(int r, int c) { return r < 0 || c < 0 || r >= n || c >= n; }
 
deque<TREE> spring[2];
queue<TREE> summer;
 
void go(int y) {
    int next = y % 2;
    int cur = next ^ 1;
 
    for(int i = 0; i < spring[cur].size(); i++) {
        TREE now = spring[cur][i];
 
        int remain = food[now.r][now.c];
        int tnum = info[cur][now.r][now.c][now.age];    //나무 수
        int lnum = remain / now.age;                    //살 수 있는 나무 수 
 
        lnum = lnum > tnum ? tnum : lnum;
        int dnum = tnum - lnum;                            //죽은 나무 수
 
        //봄
        food[now.r][now.c] -= lnum * now.age;
 
        if (dnum) {
            TREE dead = now;
            dead.num = dnum;
            summer.push(dead);
        }
 
        if (lnum) {
            //가을
            if ((now.age + 1) % 5 == 0) {
                for (int d = 0; d < 8; d++) {
                    TREE child = now;
                    child.r += dr[d];
                    child.c += dc[d];
                    child.age = 1;
 
                    if (isout(child.r, child.c)) continue;
                    if (info[next][child.r][child.c][1] == 0) spring[next].push_front(child);
                    info[next][child.r][child.c][1] += lnum;
                }
            }
 
            TREE live = now;
            live.age++;
 
            spring[next].push_back(live);
        }
 
        info[next][now.r][now.c][now.age + 1] = lnum;
        info[cur][now.r][now.c][now.age] = 0;
    }
 
    //여름
    while (summer.size()) {
        TREE now = summer.front(); summer.pop();
        food[now.r][now.c] += (now.age / 2)*now.num;
    }
    spring[cur].clear();
 
    //겨울
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) food[i][j] += winter[i][j];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> n >> k >> m;
 
    for (register int i = 0; i < n; i++)
        for (register int j = 0; j < n; j++) {
            cin >> winter[i][j];
            food[i][j] = 5;
        }
 
    while (k--) {
        TREE tree;
        cin >> tree.r >> tree.c >> tree.age;
        tree.r--, tree.c--;
 
        spring[m % 2].push_back(tree);
        info[m % 2][tree.r][tree.c][tree.age]++;
    }
 
    while (m--) go(m);
 
    int res = 0;
 
    while (spring[0].size()) {
        TREE now = spring[0].front(); spring[0].pop_front();
        res += info[0][now.r][now.c][now.age];
    }
 
    cout << res;
 
    return 0;
}
