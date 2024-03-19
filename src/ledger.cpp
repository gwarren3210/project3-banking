#include <ledger.h>

using namespace std;


pthread_mutex_t ledger_lock;

list<struct Ledger> ledger;
Bank *bank;

/**
 * @brief Initializes a banking system with a specified number of worker threads
 * and a ledger file.
 *
 * This function sets up a banking system with a specified number of worker
 * threads and loads a ledger from the given file. It then creates and
 * initializes the necessary threads to perform banking operations concurrently.
 * After all threads have completed their tasks, it prints the final state of
 * the bank's accounts.
 *
 * @attention
 * - Initialize the bank with 10 accounts.
 * - If `load_ledger()` fails, exit and free allocated memory.
 * - Be careful how you pass the thread ID to ensure the value does not get
 * changed.
 * - Don't forget to join all created threads.
 *
 * @param num_workers The number of worker threads to be created for concurrent
 * operations.
 * @param filename    The name of the file containing the ledger to be loaded
 * into the bank.
 */
void InitBank(int num_workers, char *filename) {
}

/**
 * @brief Loads a ledger from a specified file into the banking system.
 *
 * This function reads transaction data from the given file, where each line
 * represents a ledger entry. The format is as follows:
 *   - Account (int): the account number
 *   - Other (int): for transfers, the other account number; otherwise not used
 *   - Amount (int): the amount to deposit, withdraw, or transfer
 *   - Mode (Enum): 0 for deposit, 1 for withdraw, 2 for transfer
 * The function then creates ledger entries and appends them to the ledger list
 * of the banking system.
 *
 * @attention
 * - If the file cannot be opened, the function returns -1, indicating failure.
 * - The function expects a specific file format as indicated above.
 * - Each line in the file corresponds to a ledger entry.
 * - The ledgerID starts with 0.
 *
 * @param filename The name of the file containing the ledger data.
 * @return 0 on success, -1 on failure to open the file.
 */
int load_ledger(char *filename) {
  int ledgerID = 0;
}

/**
 * @brief Worker function for processing ledger entries concurrently.
 *
 * This function represents a worker thread responsible for processing ledger
 * entries from the global ledger list. Each worker is assigned a unique ID, and
 * they dequeue ledger entries one by one, performing deposit, withdraw, or
 * transfer operations based on the entry's mode. Workers continue processing
 * until the ledger is empty.
 *
 * @attention
 * - The workerID is a unique identifier assigned to each worker thread. Ensure
 * proper dereferencing.
 * - The function uses a mutex (ledger_lock) to ensure thread safety while
 * accessing the global ledger.
 * - It continuously dequeues ledger entries, processes them, and updates the
 * bank's state accordingly.
 * - The worker handles deposit (D), withdraw (W), and transfer (T) operations
 * based on the ledger entry's mode.
 *
 * @param workerID A pointer to the unique identifier of the worker thread.
 * @return NULL after completing ledger processing.
 */
void *worker(void *workerID) {
}
