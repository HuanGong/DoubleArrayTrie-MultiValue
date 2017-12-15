/* bug found my Naoki Yoshinaga */

#include <cassert>
#include <string>

#include <iostream>
#include "trie_impl.h"
#include <fstream>
#include <sstream>
#include <memory>

using namespace dutil;

int main () {
  trie::key_type key;
  trie::value_type val = 0;

#if 1

  int loop = 4;
  std::shared_ptr<dutil::double_trie> double_trie;
  while(loop--) {

    double_trie.reset(new dutil::double_trie());

    std::ifstream in("./dict.txt");
    if (! in.is_open())  {
      std::cout << "Error opening file" << std::endl;
      exit (1);
    }


    int count = 0;
    while (!in.eof() ) {
      std::vector<char> buffer(64, 0);
      in.getline(&buffer[0], 64);
      std::string line(&buffer[0]);

      int pos = line.find("#");
      if (pos != std::string::npos) {
        std::string ss(line.begin(), line.begin() + pos);

        int n2 = line.find(",", pos);
        int var1 = std::atoi(std::string(line.begin() + pos + 1, line.begin() + n2).c_str());
        int var2 = std::atoi(std::string(line.begin() + n2 + 1, line.end()).c_str());

        key.assign(ss.c_str(), ss.size());
        double_trie->insert(key, var1);
        double_trie->insert(key, var2);

        count ++;
      }
    }
    std::cout << "count:" << count << std::endl;
    in.close();
  }

  int32_t search_count = 10000;
  while (search_count--) {
    val = 0;

    dutil::trie::value_container valc;
    dutil::trie::result_type rvec;

    key.assign("7vyeh2r", 7);
    double_trie->search(key, &valc);
    valc.clear();

    double_trie->prefix_search(key, &rvec);
    rvec.clear();

    key.assign("7vy", 3);
    double_trie->search(key, &valc);
    valc.clear();

    double_trie->prefix_search(key, &rvec);
    rvec.clear();
  }

  double_trie.reset();
#endif

#if 0
dynamic_cast<dutil::double_trie *>(double_trie)->trace_table(0, 0);
    std::cout << "FRONT: \n";
dynamic_cast<dutil::double_trie *>(double_trie)->front_trie()->trace(1);
    std::cout << "REAR: \n";
dynamic_cast<dutil::double_trie *>(double_trie)->rear_trie()->trace(1);
#endif

    //delete double_trie;
    return 0;
}
