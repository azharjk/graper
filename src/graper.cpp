#include "src/graper.h"

#include <iostream>
#include <algorithm>

namespace graper {

VectorString ParseSignature(const std::string& s) {
  VectorString ret{};
  VectorString clear_tokens{};
  VectorString tokens{};
  std::string signature{};

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '-') {
      if ((i + 1) < s.size() && s[i + 1] == '>') {
        tokens.push_back(signature);
        signature.clear();
        i += 2;
      }
    }

    signature += s[i];
  }

  tokens.push_back(signature);

  for (auto tok : tokens) {
    if (tok[0] == ' ')
      tok.erase(0, 1);

    if (tok[tok.size() - 1] == ' ')
      tok.erase(tok.size() - 1, 1);

    clear_tokens.push_back(tok);
  }

  std::string ntok{};
  for (size_t i = 0; i < clear_tokens.size(); i++) {
    if (clear_tokens[i][0] == '(') {
      ntok = clear_tokens[i] + " -> " + clear_tokens[i + 1];
      i += 1;
    }
    else
      ntok = clear_tokens[i];
    ret.push_back(ntok);
  }

  return ret;
}

} // namespace graper
