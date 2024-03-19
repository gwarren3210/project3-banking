#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <semaphore.h>
#include <time.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iomanip>
#include <stdexcept>

#include "ledger.h"


using namespace std;

Bank *bank_t;
sem_t glock;

// test correct init accounts and counts
TEST(BankTest, TestBankConstructor) {
    bank_t = new Bank(10);

    stringstream output;
    streambuf* oldCoutStreamBuf = cout.rdbuf(); // save cout's streambuf
    cout.rdbuf(output.rdbuf()); // redirect cout to stringstream
    bank_t->print_account(); // call the print method
    cout.rdbuf(oldCoutStreamBuf); // restore cout's original streambuf

    string line = "";
    string stats("Success: 0 Fails: 0");

    int init_account_balance_to_zero = 0;
    int init_stats_to_0 = 0;
    
    while (getline(output, line)) {
      if (line.compare(8, 9, "0") == 0) { init_account_balance_to_zero++;}

      if (line.compare(0, 19, stats) == 0) {init_stats_to_0++;}
    }

    EXPECT_EQ(init_account_balance_to_zero, 10) << "Make sure to initialize the account balance to 0";
    EXPECT_EQ(init_stats_to_0, 1) << "Make sure to initialize num_succ, num_fail";
    delete bank_t;
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
