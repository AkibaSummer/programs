#include <bits/stdc++.h>
using namespace std;
class Lexical_analysis {
 private:
  string input;
  vector<pair<string, string> > result;
  inline bool isnull(char c) { return c == ' ' || c == '\n' || c == '\t'; }
  inline bool isnum(char c) { return c >= '0' && c <= '9'; }
  inline bool ischar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
  }
  inline bool isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
           c == '!' || c == '^' || c == '&' || c == '|' || c == '?' ||
           c == ':' || c == '>' || c == '<' || c == '~' || c == '=';
  }
  inline bool isbracket(char c) {
    return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
  }
  static const string keywords[], operators[];
  enum Stat { BEGIN, NUMBER, VAR, EXPR };

 public:
  void ERROR(string message) {
    cout << "ERROR: " << message << endl;
    exit(0);
  }
  void input_text() {
    input.clear();
    string tmp;
    while (getline(cin, tmp)) {
      input += tmp + "\n";
    }
  }
  void format_code() {
    string tmp;
    swap(tmp, input);
    int flag = 1;
    for (auto &i : tmp) {
      if (isnull(i)) {
        if (flag) {
          continue;
        } else {
          flag++;
        }
      } else {
        if (flag) {
          flag = 0;
          input.push_back(' ');
        }
        input.push_back(i);
      }
    }
  }
  void output_text() { cout << input << endl; }
  void output_result() {
    for (auto &i : result) {
      cout << "< " << i.first << " , " << i.second << " >" << endl;
    }
  }
  void analysis() {
    Stat stat = BEGIN;
    string nowstr;
    for (int i = 0; i < input.size(); i++) {
      auto c = input[i];
      if (stat == BEGIN) {
        if (isnull(c))
          continue;
        else if (isnum(c)) {  // number
          i++;
          nowstr.push_back(c);
          while (isnum(input[i]) || input[i] == '.') {
            nowstr.push_back(input[i]);
            i++;
            if (i == input.length()) ERROR("number ERROR");
          }
          i--;
          result.push_back({"number", nowstr});
          nowstr.clear();
        } else if (ischar(c)) {  // var or keyword
          i++;
          nowstr.push_back(c);
          while (ischar(input[i])) {
            nowstr.push_back(input[i]);
            i++;
            if (i == input.length()) ERROR("variable or keyword ERROR");
          }
          i--;
          int flag = 1;
          for (int i = 0; keywords[i] != ""; i++) {
            if (keywords[i] == nowstr) {
              flag = 0;
              result.push_back({"keyword", nowstr});
              break;
            }
          }
          if (flag) result.push_back({"variable", nowstr});
          nowstr.clear();
        } else if (c == '/' && i < input.length() - 1 &&
                   input[i + 1] == '*') {  // comment1
          i += 2;
          while (!(input[i] == '*' && input[i + 1] == '/')) {
            i++;
            if (i == input.length() - 1) ERROR("comment ERROR");
          }
        } else if (c == '/' && i < input.length() - 1 &&
                   input[i + 1] == '/') {  // comment2
          i += 2;
          while (input[i] != '\n' && i < input.length()) {
            i++;
          }
        } else if (c == '"') {  // string
          i++;
          nowstr.push_back(c);
          while (input[i] != '"' || (input[i] == '"' && input[i - 1] == '\\')) {
            nowstr.push_back(input[i]);
            i++;
            if (i == input.length() - 1) ERROR("string ERROR");
          }
          nowstr.push_back(input[i]);
          result.push_back({"const string", nowstr});
          nowstr.clear();
        } else if (isbracket(c)) {
          nowstr.push_back(c);
          result.push_back({"bracket", nowstr});
          nowstr.clear();
        } else if (isoperator(c)) {  // operator
          i++;
          nowstr.push_back(c);
          while (isoperator(input[i])) {
            nowstr.push_back(input[i]);
            i++;
          }
          i--;
          int flag = 1;
          for (int i = 0; keywords[i] != ""; i++) {
            if (operators[i] == nowstr) {
              flag = 0;
              result.push_back({"operator", nowstr});
              break;
            }
          }
          if (flag) ERROR("operator ERROR");
          nowstr.clear();
        } else if (c == '#' || c == ';' || c == ',' || c == '.') {
          nowstr.push_back(c);
          result.push_back({"special", nowstr});
          nowstr.clear();
        }
      }
    }
  }
};

const string Lexical_analysis::keywords[] = {
    "auto",     "break",  "case",    "char",   "const",    "continue",
    "default",  "do",     "double",  "else",   "enum",     "extern",
    "float",    "for",    "goto",    "if",     "int",      "long",
    "register", "return", "short",   "signed", "sizeof",   "static",
    "struct",   "switch", "typedef", "union",  "unsigned", "void",
    "volatile", "while",  ""};
const string Lexical_analysis::operators[] = {
    "+",  "-",  "*",  "/",  "%",  "++", "--",  "==",  "!=", ">",  "<",
    ">=", "<=", "&&", "||", "!",  "&",  "|",   "^",   "~",  "<<", ">>",
    "=",  "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|="};

int main() {
  Lexical_analysis lexical_analysis;
  lexical_analysis.input_text();
  // lexical_analysis.format_code();
  // lexical_analysis.output_text();
  try {
    lexical_analysis.analysis();
  } catch (exception e) {
    lexical_analysis.ERROR("unknown ERROR");
  }
  lexical_analysis.output_result();
}