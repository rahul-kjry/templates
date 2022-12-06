class union_find {
    public:
    vector<int> prnt, rank;
    union_find(int N) {
        prnt.resize(N, -1);
        rank.resize(N, 0);
    }

    int find_op(int v) {
        if (prnt[v] == -1) {
            return v;
        }
        return prnt[v] = find_op(prnt[v]);
    }

    void union_op(int v1, int v2) {
        v1 = find_op(v1);
        v2 = find_op(v2);
        if (v1 == v2) {
            return;
        }
        if (rank[v1] > rank[v2]) {
            prnt[v2] = v1;
        }
        else if (rank[v1] < rank[v2]) {
            prnt[v1] = v2;
        }
        else {
            prnt[v1] = v2;
            ++ rank[v2];
        }
    }
};