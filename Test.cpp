#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct Node {
    int x, next;
}e[200005];

int N, head[100005], idx, ret, sum[100005], hash[100005];

void insert(int x, int y) {
    ++idx;
    e[idx].x = y;
    e[idx].next = head[x];
    head[x] = idx;
}

int update(int x) {
    hash[x] = 1;
    if (head[x] == -1) {
        return sum[x] = 1;
    } else {
        sum[x] = 1;
        for (int i = head[x]; i != -1; i = e[i].next) {
            if (!hash[e[i].x]) {
                sum[x] += update(e[i].x);
            }
        }
        if (!(sum[x] & 1)) ++ret;
        return sum[x];
    }
}

int main() {
    int ans;
    while (scanf("%d", &N) == 1) {
        memset(head, 0xff, sizeof (head));
        memset(hash, 0, sizeof (hash));
        int x, y;
        idx = ret = -1;
        for (int i = 1; i < N; ++i) {
            scanf("%d %d", &x, &y);
            insert(x, y); // 对这个树进行构边
            insert(y, x); // 构建的双向边
        }
        update(1);
        printf("%d\n", ret);
    }
    return 0;
}
