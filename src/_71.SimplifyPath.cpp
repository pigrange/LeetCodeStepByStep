#include <iostream>
#include <vector>

using namespace std;
//这个题有毒
class Solution {
 public:
  string simplifyPath(string path) {
    path.push_back('/');
    char* res = new char[path.size() + 1];
    int stackPtr = 0, opPtr = 0;
    res[stackPtr] = '/';
    for (int i = 1; i < path.size(); i++) {
      if (path[i] == '/' && opPtr - stackPtr > 0) {
        if (opPtr - stackPtr > 2) {
          stackPtr = opPtr;
          res[++stackPtr] = path[i];
        } else {
          while (stackPtr > 0 && opPtr - stackPtr == 2)
            if (path[--stackPtr] == '/') break;
          opPtr = stackPtr;
        }
      } else if (path[i] == '.' && res[stackPtr == '/']) {
        res[++opPtr] = path[i];
      } else {
        if (path[i] == '/' && res[stackPtr] == '/') continue;
        res[++stackPtr] = path[i];
        opPtr++;
      }
    }
    res[stackPtr + 1] = 0;
    return string(res);
  }
};

//看不懂的解法
// class Solution {
//  public:
//   string simplifyPath(string path) {
//     string res, tmp;
//     vector<string> stk;
//     stringstream ss(path);
//     while (getline(ss, tmp, '/')) {
//       if (tmp == "" or tmp == ".") continue;
//       if (tmp == ".." and !stk.empty())
//         stk.pop_back();
//       else if (tmp != "..")
//         stk.push_back(tmp);
//     }
//     for (auto str : stk) res += "/" + str;
//     return res.empty() ? "/" : res;
//   }
// };

int main() {
  Solution sol;
  //   string str = "/home//foo/";
  string str = "/a/..";
  cout << "res is " << sol.simplifyPath(str) << endl;
  return 0;
}