#include <bits/stdc++.h>
using namespace std;
enum { ACC, S, R, ERROR };
class Table {
 public:
  vector<pair<string, vector<string>>> reduce_action;
  vector<string> actions;
  vector<string> gotos;
  class State {
   public:
    vector<pair<int, int>> actions;
    vector<int> gotos;
  };
  vector<State> states;
  int action_pos(string s) {
    for (int i = 0; i < actions.size(); i++) {
      if (s == actions[i]) return i;
    }
    return -1;
  }
  int goto_pos(string s) {
    for (int i = 0; i < gotos.size(); i++) {
      if (s == gotos[i]) return i;
    }
    return -1;
  }
};

pair<int, int> s(int t) { return {S, t}; }
pair<int, int> r(int t) { return {R, t}; }
pair<int, int> err = {ERROR, 0};
pair<int, int> acc = {ACC, 0};

class LR {
 public:
  class stack_item {
   public:
    int state;
    string symble;
  };
  string output;
  vector<stack_item> s;
  int step;
  int pos;

  string format(int width, string s) {
    char ret[10];
    sprintf(ret, "%-*s", width, s.c_str());
    return string(ret);
  }

  void out(vector<string> &input) {
    string stack_state, stack_symble, input_string;
    for (int i = pos; i < input.size(); i++) {
      input_string += input[i] + " ";
    }
    for (auto &i : s) {
      stack_state += format(4, to_string(i.state));
      stack_symble += format(4, i.symble);
    }
    printf("%5d|%-30s|%30s|%20s\n", ++step, stack_state.c_str(),
           input_string.c_str(), output.c_str());
    printf("%5s|%-30s|%30s|%20s\n", "", stack_symble.c_str(), "", "");
  }
  void init() {
    step = 0;
    s.clear();
    s.push_back({0, ""});
    pos = 0;
    printf("%5s|%-30s|%30s|%20s\n", "Step", "Stack", "Input", "Action");
    output="";
  }
  void analysis(Table &table, vector<string> input) {
    init();
    for (;;) {
      out(input);
      output = "";
      auto top = s.back();
      int action_pos = table.action_pos(input[pos]);
      if (action_pos == -1 ||
          table.states[top.state].actions[action_pos].first == ERROR) {
        output = "ERROR";
        break;
      } else if (table.states[top.state].actions[action_pos].first == S) {
        s.push_back(
            {table.states[top.state].actions[action_pos].second, input[pos]});
        pos++;
        output = "Shift " + to_string(table.states[top.state].actions[action_pos].second);
      } else if (table.states[top.state].actions[action_pos].first == R) {
        auto reduce = table.reduce_action
                          [table.states[top.state].actions[action_pos].second];
        for (int i = 0; i < reduce.second.size(); i++) {
          s.pop_back();
        }
        top = s.back();
        int goto_pos =
            table.states[top.state].gotos[table.goto_pos(reduce.first)];
        if (goto_pos == 0) {
          output = "ERROR";
          break;
        }
        s.push_back({goto_pos, reduce.first});
        output = "reduce by " + reduce.first;
        output += "->";
        for (auto &i : reduce.second) {
          output += i;
        }
      } else if (table.states[top.state].actions[action_pos].first == ACC) {
        output = "ACC";
        break;
      }
    }
    out(input);
  }
};

int main() {
  Table slr_table = {
      {{{"E"}, {"E", "+", "T"}},
       {{"E"}, {"E", "-", "T"}},
       {{"E"}, {"T"}},
       {{"T"}, {"T", "*", "F"}},
       {{"T"}, {"T", "/", "F"}},
       {{"T"}, {"F"}},
       {{"F"}, {"(", "E", ")"}},
       {{"F"}, {"num"}}},
      {"+", "-", "*", "/", "(", ")", "num", "$"},
      {"E", "T", "F"},
      {{{err, err, err, err, s(4), err, s(5), err}, {1, 2, 3}},
       {{s(6), s(7), err, err, err, err, err, err}, {0, 0, 0}},
       {{r(2), r(2), s(8), s(9), err, r(2), err, r(2)}, {0, 0, 0}},
       {{r(5), r(5), r(5), r(5), err, r(5), err, r(5)}, {0, 0, 0}},
       {{err, err, err, err, s(4), err, s(5), err}, {10, 2, 3}},
       {{r(7), r(7), r(7), r(7), err, r(7), err, r(7)}, {0, 0, 0}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 11, 3}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 12, 3}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 0, 13}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 0, 14}},
       {{s(6), s(7), err, err, err, s(15), err, err}, {0, 0, 0}},
       {{acc, acc, s(8), s(9), err, acc, err, acc}, {0, 0, 0}},
       {{r(1), r(1), s(8), s(9), err, r(1), err, r(1)}, {0, 0, 0}},
       {{r(3), r(3), r(3), r(3), err, r(3), err, r(3)}, {0, 0, 0}},
       {{r(4), r(4), r(4), r(4), err, r(4), err, r(4)}, {0, 0, 0}},
       {{r(6), r(6), r(6), r(6), err, r(6), err, r(6)}, {0, 0, 0}}}};

  Table lr1_table = {
      {{{"E"}, {"E", "+", "T"}},
       {{"E"}, {"E", "-", "T"}},
       {{"E"}, {"T"}},
       {{"T"}, {"T", "*", "F"}},
       {{"T"}, {"T", "/", "F"}},
       {{"T"}, {"F"}},
       {{"F"}, {"(", "E", ")"}},
       {{"F"}, {"num"}}},
      {"+", "-", "*", "/", "(", ")", "num", "$"},
      {"E", "T", "F"},
      {{{err, err, err, err, s(4), err, s(5), err}, {1, 2, 3}},
       {{s(6), s(7), err, err, err, err, err, err}, {0, 0, 0}},
       {{r(2), r(2), s(8), s(9), err, err, err, err}, {0, 0, 0}},
       {{r(5), r(5), r(5), r(5), err, err, err, err}, {0, 0, 0}},
       {{err, err, err, err, s(13), err, s(14), err}, {10, 11, 12}},
       {{r(7), r(7), r(7), r(7), err, err, err, err}, {0, 0, 0}},
       {{err, err, err, err, s(17), err, s(18), err}, {0, 15, 16}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 19, 3}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 0, 20}},
       {{err, err, err, err, s(4), err, s(5), err}, {0, 0, 21}},
       {{s(23), s(24), err, err, err, s(22), err, err}, {0, 0, 0}},
       {{r(2), r(2), s(25), s(26), err, r(2), err, err}, {0, 0, 0}},
       {{r(5), r(5), r(5), r(5), err, r(5), err, err}, {0, 0, 0}},
       {{err, err, err, err, s(13), err, s(14), err}, {27, 11, 12}},
       {{r(7), r(7), r(7), r(7), err, r(7), err, err}, {0, 0, 0}},
       {{acc, acc, s(28), s(29), err, err, err, acc}, {0, 0, 0}},
       {{r(5), r(5), r(5), r(5), err, err, err, r(5)}, {0, 0, 0}},
       {{err, err, err, err, s(13), err, s(14), err}, {30, 11, 12}},
       {{r(7), r(7), r(7), r(7), err, err, err, r(7)}, {0, 0, 0}},
       {{r(1), r(1), s(8), s(9), err, err, err, err}, {0, 0, 0}},
       {{r(3), r(3), r(3), r(3), err, err, err, err}, {0, 0, 0}},
       {{r(4), r(4), r(4), r(4), err, err, err, err}, {0, 0, 0}},
       {{r(6), r(6), r(6), r(6), err, err, err, err}, {0, 0, 0}},
       {{err, err, err, err, s(13), err, s(14), err}, {0, 31, 12}},
       {{err, err, err, err, s(13), err, s(14), err}, {0, 32, 12}},
       {{err, err, err, err, s(13), err, s(14), err}, {0, 0, 33}},
       {{err, err, err, err, s(13), err, s(14), err}, {0, 0, 34}},
       {{s(23), s(24), err, err, err, s(35), err, err}, {0, 0, 0}},
       {{err, err, err, err, s(17), err, s(18), err}, {0, 0, 36}},
       {{err, err, err, err, s(17), err, s(18), err}, {0, 0, 37}},
       {{s(23), s(24), err, err, err, s(38), err, err}, {0, 0, 0}},
       {{acc, acc, s(25), s(26), err, acc, err, err}, {0, 0, 0}},
       {{r(1), r(1), s(25), s(26), err, r(1), err, err}, {0, 0, 0}},
       {{r(3), r(3), r(3), r(3), err, r(3), err, err}, {0, 0, 0}},
       {{r(4), r(4), r(4), r(4), err, r(4), err, err}, {0, 0, 0}},
       {{r(6), r(6), r(6), r(6), err, r(6), err, err}, {0, 0, 0}},
       {{r(3), r(3), r(3), r(3), err, err, err, r(3)}, {0, 0, 0}},
       {{r(4), r(4), r(4), r(4), err, err, err, r(4)}, {0, 0, 0}},
       {{r(6), r(6), r(6), r(6), err, err, err, r(6)}, {0, 0, 0}}}};
  LR lr;

  cout << "Please input text (splite with space or enter, end with $):" << endl;
  vector<string> input;
  for (;;) {
    string tmp;
    cin >> tmp;
    input.push_back(tmp);
    if (tmp == "$") break;
  }
  cout << "slr result:" << endl;
  lr.analysis(slr_table, input);
  cout << "lr1 result:" << endl;
  lr.analysis(lr1_table, input);
}
/*
num + num * num $
*/
