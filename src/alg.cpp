// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char ch) {
  switch (ch) {
    case '(':
      return 0;
    case '+': case '-':
      return 1;
    case '*': case '/':
      return 2;
  }
  return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack1;
  std::string s = "";
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      s += inf[i];
      s += " ";
    } else if (inf[i] == '(')
      stack1.push(inf[i]);
    else if (inf[i] == ')') {
      while (!stack1.isEmpty() && getPrior(stack1.getValue()) >= getPrior(inf[i])) {
        s += stack1.getValue();
        s += " ";
        stack1.pop();
      }
      stack1.push(inf[i]);
    }
    else if (inf[i] == '+' || inf[i] == '+' || inf[i] == '*' || inf[i] == '/') {
      while (!stack1.isEmpty() && getPrior(inf[i]) <= getPrior(stack1.getValue())) {
        s += stack1.getValue();
        s += " ";
        stack1.pop();
      }
      stack1.push(inf[i]);
    }

  }
  while (!stack1.isEmpty()) {
    s += stack1.getValue();
    s += " ";
    stack1.pop();
  }

  return s;
}

int eval(std::string pref) {
  TStack<int, 100> stack2;
  int k, l ,g;
  for (int i = 0; i < pref.length(); i++) {
    if (pref[i] == ' ')
      continue;
    else if (pref[i] >= '0' && pref[i] <= '9') {
      k = pref[i] - '0';
      stack2.push(k);
    } else if (pref[i] == '+' || pref[i] == '-' || pref[i] == '*' ||
               pref[i] == '/') {
      l = stack2.getValue();
      stack2.pop();
      g = stack2.getValue();
      stack2.pop();
      if (pref[i] == '+') stack2.push(g + l);
      else if (pref[i] == '-')
        stack2.push(g - l);
      else if (pref[i] == '*')
        stack2.push(g * l);
      else if (pref[i] == '/')
        stack2.push(g / l);
    }
        
  }
  return stack2.getValue();
}
