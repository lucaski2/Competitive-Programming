#include <bits/stdc++.h>
using namespace std;
 
// We'll use 0-indexing throughout.
 
// Explanation of our approach:
//
// (1) In any addition table T with T[i][j]=A[i]+B[j] where A and B are permutations
//     of {1,...,N}, the multiset of entries is fixed: the number s (with 2<=s<=2N)
//     appears exactly
//         f(s)= s-1  for s<=N+1  and  f(s)=2N-s+1 for s>=N+1.
//     In particular, there is exactly one cell with value 2 and exactly one with value 2N.
//     Moreover, the “middle–value” N+1 appears exactly N times. (This fact can be shown
//     by a short counting–argument.)
//
// (2) Because type–3 operations (which “swap two numbers everywhere”) do not change the
//     pattern of equalities in the table, if F is the final table then there is a bijection
//         t : {values in F} -> {2,3,…,2N}
//     such that if we “undo” type–3 then the “pre–type–3” table T satisfies
//         T[i][j] = t(F[i][j])  for all i,j.
//     In particular, the pattern “which cells have the same number” is exactly the same
//     as in T. (Note that while t is unknown, its effect on the multiset of frequencies
//     is forced: if some v appears f times in F then t(v) must be a number s that appears
//     f times in an addition table – and it is not hard to check that if f<N there are exactly
//     two possibilities, namely s = f+1 or s = 2N-f+1; if f=N then s is forced to be N+1.)
//
// (3) One may prove that among all possible pre–type–3 tables (that is, all T of the form
//         T[i][j]=A[i]+B[j]   with A and B permutations)
//     that are isomorphic (by a relabeling of values) to F, the lexicographically smallest
//     one is obtained by “normalizing” F so that the unique cell that comes from N+1
//     (the “middle–value”) appears in the top–left corner. (In an addition table the number
//     N+1 appears exactly N times, and one may show that in the lex–minimal state the cell
//     (1,1) is the unique one forced by the frequency–N group.)
// 
// (4) After this “normalization” we determine for each distinct v in F (now in our normalized F)
//     the coordinates of its first occurrence (reading in row–major order). Then for each frequency f,
//     the allowed candidates are L = f+1 and H = 2N-f+1. (When f=N there is only one possibility.)
//     In each frequency group we sort the v’s (using their first–occurrence coordinates) and assign
//     the lower candidate L to the one that appears first and the higher candidate H to the second.
//     (It is a property of addition tables that in every frequency group (except f=N) there are exactly
//     two numbers.)
// 
// (5) Finally, one “recovers” an additive table by defining
//         A[i] = t( F[i][0] ) - ( t(F[0][0]) - 1 )
//         B[j] = t( F[0][j] ) - 1
//     and then T[i][j] = A[i] + B[j].
//     (One may check that with our forced choices T is indeed additive and that A and B are permutations
//     of {1,...,N}.)
//
// (6) We output T in the same “normalized” order (i.e. we do not further reorder rows and columns).
//
// The following code implements the above plan.
 
struct Cell {
    int r, c;
};
 
// A helper “pair‐ordering” for positions.
bool posLess(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    if(!(cin >> N)) return 1;
    vector<vector<int>> F(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> F[i][j];
        }
    }
 
    // (A) Compute frequency and first-occurrence in the original F.
    // We also record the overall minimum occurrence for each value.
    // (Because F is the result after type–3, the only property that remains is the equality pattern.)
    struct Info { int cnt; pair<int,int> first; };
    unordered_map<int, Info> info;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int v = F[i][j];
            if (info.find(v)==info.end()){
                info[v] = {1, {i,j}};
            } else {
                info[v].cnt++;
                if( posLess({i,j}, info[v].first) )
                    info[v].first = {i,j};
            }
        }
    }
 
    // (B) In any addition table T=A[i]+B[j], the “middle–value” (which equals N+1)
    // appears exactly N times. In the relabeling t this value must be the image of the
    // unique F–value v0 that appears N times.
    int centerF = -1;
    for(auto &p : info){
        if(p.second.cnt == N) {
            centerF = p.first;
            break;
        }
    }
    if(centerF == -1){
        // Should not happen (the answer is guaranteed to exist)
        cerr << "No value with frequency N found!\n";
        return 1;
    }
 
    // (C) Find any occurrence of centerF and “normalize” F by swapping that row into row 0
    // and that column into column 0.
    int r0 = -1, c0 = -1;
    for (int i = 0; i < N && r0<0; i++){
        for (int j = 0; j < N; j++){
            if(F[i][j]==centerF){
                r0 = i; c0 = j;
                break;
            }
        }
    }
    // swap row r0 with row 0
    if(r0 != 0) {
        swap(F[r0], F[0]);
    }
    // swap column c0 with column 0 (for every row)
    if(c0 != 0){
        for (int i = 0; i < N; i++){
            swap(F[i][c0], F[i][0]);
        }
    }
 
    // (D) Now “recompute” first–occurrence for each distinct value in the normalized F.
    // (We use the reading order of the normalized F.)
    unordered_map<int, pair<int,int>> pos;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int v = F[i][j];
            if(pos.find(v)==pos.end()){
                pos[v] = {i,j};
            }
        }
    }
 
    // (E) For each distinct value v, the allowed candidates (if v appears f times) are:
    //       L = f+1   and   H = 2*N - f + 1   (if f < N; if f==N then only L = N+1 is allowed).
    // Group v’s by frequency.
    unordered_map<int, vector<int>> groups; // frequency -> list of v's
    for(auto &p : info){
        int v = p.first;
        int f = p.second.cnt;
        groups[f].push_back(v);
    }
    // For each frequency group, sort the v’s by their normalized first occurrence.
    for(auto &g : groups){
        sort(g.second.begin(), g.second.end(), [&](int a, int b){
            return pos[a] < pos[b];
        });
    }
 
    // (F) Now assign our “inverse–type–3” mapping t.
    // We will store t(v) for every distinct v.
    unordered_map<int,int> tval;
    for(auto &g : groups){
        int f = g.first;
        // allowed lower candidate:
        int L = f + 1;
        // allowed higher candidate (if f < N):
        int H = (f == N ? L : (2*N - f + 1));
        if(g.second.size() == 1){
            tval[g.second[0]] = L;
        } else if(g.second.size() == 2){
            // assign the one whose first occurrence in normalized F is earlier the lower candidate
            tval[g.second[0]] = L;
            tval[g.second[1]] = H;
        } else {
            // (should not happen for a valid addition table)
            tval[g.second[0]] = L;
            for (size_t i = 1; i < g.second.size(); i++){
                tval[g.second[i]] = H;
            }
        }
    }
    // In particular, note that the center value (which appears N times) must be mapped to N+1.
    if(tval[centerF] != N+1){
        // force it
        tval[centerF] = N+1;
    }
 
    // (G) Now “recover” an additive table.
    // In any additive table T = A[i] + B[j] one may “normalize” by insisting that
    // the top–left cell equals t(F[0][0]). (In our normalized F, F[0][0]==centerF so t(centerF)==N+1.)
    // Then one may define
    //    A[i] = t(F[i][0]) - ( t(F[0][0]) - 1 )   and   B[j] = t(F[0][j]) - 1.
    // (One may then check that T[i,j]=A[i]+B[j] is additive and that A and B are permutations of {1,...,N}.)
    int base = tval[ F[0][0] ]; // this equals N+1
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++){
        A[i] = tval[ F[i][0] ] - ( base - 1 );
    }
    for (int j = 0; j < N; j++){
        B[j] = tval[ F[0][j] ] - 1;
    }
 
    // Form T with T[i][j] = A[i] + B[j] (using the normalized order of F).
    vector<vector<int>> Tmat(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            Tmat[i][j] = A[i] + B[j];
        }
    }
 
    // (H) Finally, output the table Tmat.
    // (This Tmat is a possible state of the table after row and column swaps – and it can be shown that
    //  among all possibilities it is lexicographically smallest.)
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << Tmat[i][j] << (j==N-1 ? "\n" : " ");
        }
    }
 
    return 0;
}
