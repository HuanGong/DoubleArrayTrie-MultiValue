/* bug found my Naoki Yoshinaga */

#include <cassert>

#include <iostream>
#include "trie_impl.h"

using namespace dutil;

int main () {
    dutil::trie* trie = dutil::trie::create_trie (dutil::trie::DOUBLE_TRIE);

    const char prefix[] = "back!";
    const char *dict[] = {"bachelor", "back", "badge", "badger", "badness", "bcs", "backbone"};

    for (int i = 0; i < sizeof(dict) / sizeof(char *); i++) {
      trie::key_type key;
      key.assign(dict[i], strlen(dict[i]));
      trie->insert(key, i + 1);
      trie->insert(key, i + 100);
    }

    dutil::trie::result_type result;

    trie::key_type key;
    key.assign("bac", 3);
    trie->prefix_search(key, &result);
    for (const auto& pair : result) {
      std::cout << "key:" << pair.first.c_str() << " ";
      for (int val : pair.second) {
        std::cout << val << " -";
      }
      std::cout << std::endl;
    }

dynamic_cast<dutil::double_trie *>(trie)->trace_table(0, 0);
    std::cout << "FRONT: \n";
dynamic_cast<dutil::double_trie *>(trie)->front_trie()->trace(1);
    std::cout << "REAR: \n";
dynamic_cast<dutil::double_trie *>(trie)->rear_trie()->trace(1);

    delete trie;
    return 0;
}
