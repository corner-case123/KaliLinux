#include <bits/stdc++.h>
using namespace std;

struct State {
    array<int, 9> board;
    int zero_pos; // position of empty tile
    int g;        // cost so far (depth)
    int h;        // heuristic (Manhattan distance)
};

const int N = 3;
const array<int, 9> goal = {1,2,3,4,5,6,7,8,0};
const array<int, 4> dx = {1,-1,0,0};
const array<int, 4> dy = {0,0,1,-1};
const array<char, 4> moves = {'D','U','R','L'};

int manhattan(const array<int, 9> &board) {
    int dist = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) continue;
        int val = board[i] - 1;
        dist += abs(i / N - val / N) + abs(i % N - val % N);
    }
    return dist;
}

int dfs(State &cur, int threshold, vector<char> &path, vector<char> &best_path,
        unordered_set<string> &visited) {
    int f = cur.g + cur.h;
    if (f > threshold) return f; // return smallest cost beyond threshold
    if (cur.board == goal) {
        best_path = path;
        return -1; // found solution
    }

    string key;
    for (int x : cur.board) key += to_string(x) + ",";
    if (visited.count(key)) return INT_MAX;
    visited.insert(key);

    int x = cur.zero_pos / N;
    int y = cur.zero_pos % N;
    int min_excess = INT_MAX;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        int nz = nx * N + ny;
        swap(cur.board[cur.zero_pos], cur.board[nz]);
        int old_zero = cur.zero_pos;
        cur.zero_pos = nz;

        int old_h = cur.h;
        cur.g++;
        cur.h = manhattan(cur.board);

        path.push_back(moves[i]);
        int t = dfs(cur, threshold, path, best_path, visited);
        if (t == -1) return -1; // solution found
        if (t < min_excess) min_excess = t;
        path.pop_back();

        cur.h = old_h;
        cur.g--;
        swap(cur.board[cur.zero_pos], cur.board[old_zero]);
        cur.zero_pos = old_zero;
    }

    visited.erase(key);
    return min_excess;
}

int ida_star(State &start, vector<char> &result) {
    int threshold = start.h;
    vector<char> path, best_path;

    while (true) {
        unordered_set<string> visited;
        int t = dfs(start, threshold, path, best_path, visited);
        if (t == -1) {
            result = best_path;
            return best_path.size();
        }
        if (t == INT_MAX || t > 50) return -1; // unsolvable / too hard
        threshold = t; // jump to next needed threshold
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        State start;
        start.g = 0;
        start.zero_pos = -1;
        for (int i = 0; i < 9; i++) {
            cin >> start.board[i];
            if (start.board[i] == 0) start.zero_pos = i;
        }
        start.h = manhattan(start.board);

        vector<char> result;
        int res = ida_star(start, result);

        cout << "Case " << t << ": ";
        if (res == -1) {
            cout << "This puzzle is not solvable or too hard\n";
        } else {
            cout << res << "\n";
            for (char c : result) cout << c;
            cout << "\n";
        }
    }
    return 0;
}
