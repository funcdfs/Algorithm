#define dbg(...) pr("(", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__)

template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& x: v) is >> x; return is; }
auto re = [](auto&&... args) { (cin >> ... >> args); };

template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1,T2> p) 
{ os << "(" << p.first << ", " << p.second << ")"; return os; }

#define Vout(Con) template<class T> ostream& operator<<(ostream& os, Con<T>& v) { bool fst = 1; os << "{"; \
for(auto& x: v) { if(!fst) os << ", "; os << x; fst = 0; } os << "}"; return os; }
#define Vout2(Con) template<class T1, class T2> ostream& operator<<(ostream& os, Con<T1,T2>& v) { bool fst = 1; os << "{"; \
for(auto& [x, y]: v) { if(!fst) os << ", "; os << x << ": " << y; fst = 0; } os << "}"; return os; }
Vout(vector) Vout(set) Vout(multiset) Vout2(map)

#define Out(f, delim, lst) auto f = [](auto&& arg, auto&&... args) { cerr << arg; ((cerr << delim << args), ...); cerr << lst; };
Out(pr, "", "") Out(pw, ' ', ' ') Out(ps, ' ', '\n';) Out(pc, ", ", "]" << '\n';)

auto ptrace = [](const char* name, auto&& A, auto&&... rest) {
    const char* open = strchr(name, '['); cerr.write(name, open-name);
    ((cerr << '[' << rest << ']'), ...); cerr << " = " << A << '\n';;
};
// #define dline() cerr << "\n"
// #define dbg(...) 42