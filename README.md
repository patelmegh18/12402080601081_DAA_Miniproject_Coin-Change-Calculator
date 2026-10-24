# Coin Change Calculator Using Dynamic Programming

**DAA Mini Project — Design and Analysis of Algorithms**

A C++ command-line utility that demonstrates the Dynamic Programming paradigm by finding the minimum number of coins required to form a target amount. It also reconstructs one coin combination and reports when the target cannot be formed.

## ⚡ Quick Start: Compile and Run

Requirements: a C++ compiler such as `g++` and a terminal (VS Code is suitable).

### 1. Compile

```bash
g++ -std=c++17 -O2 -Wall -Wextra coin_change.cpp -o coin_change
```

On Windows, run the resulting executable as:

```powershell
.\coin_change.exe
```

On Linux or macOS:

```bash
./coin_change
```

### 2. Enter an example

```text
Enter number of denominations: 3
Enter coin denominations: 1 3 4
Enter target amount: 6
Minimum number of coins: 2
Coins used: 3 + 3
```

## 🧠 Algorithmic Paradigm: Dynamic Programming

The implementation uses **bottom-up tabulation**. It computes the best answer for every amount from `0` through the target amount, reusing results for smaller amounts.

- **Optimal substructure:** an optimal solution for amount `a` can be formed by adding one coin `c` to an optimal solution for `a - c`.
- **Overlapping subproblems:** many candidate solutions depend on the same smaller amounts. The DP array stores each result so it is reused instead of recalculated.
- **Solution reconstruction:** a `chosenCoin` array records the coin that improved each DP state, allowing the program to print one optimal combination.

## 📐 Recurrence Relation

Let `dp[a]` be the minimum number of coins required to form amount `a`, and let `C` be the set of denominations.

\[
dp[0] = 0
\]

For each amount \(a > 0\):

\[
dp[a] = 1 + \min_{c \in C,\ c \le a} dp[a-c]
\]

Only reachable predecessor states are considered. If no coin can produce a reachable state for the target, the target cannot be formed.

## 🔢 Example Walkthrough

For denominations `1, 3, 4` and target `6`:

| Amount | Minimum coins | One optimal combination |
|---:|---:|---|
| 0 | 0 | None |
| 1 | 1 | 1 |
| 2 | 2 | 1 + 1 |
| 3 | 1 | 3 |
| 4 | 1 | 4 |
| 5 | 2 | 4 + 1 |
| 6 | 2 | 3 + 3 |

The greedy strategy may choose `4 + 1 + 1` (three coins), while Dynamic Programming finds `3 + 3` (two coins).

## 🛠️ How the Program Works

1. Read the number of denominations, the denominations, and the target amount.
2. Validate that there is at least one denomination, all coins are positive integers, and the target is non-negative.
3. Initialize `dp[0] = 0`; mark other amounts as unreachable.
4. For every amount from `1` to the target, examine every denomination that does not exceed it.
5. Update the DP value and record the chosen coin whenever a smaller count is found.
6. If the target is unreachable, print a message. Otherwise, print the minimum count and reconstruct the combination.

## 📊 Complexity Analysis

Let `A` be the target amount and `m` be the number of denominations.

- **Time complexity:** \(O(A \times m)\)
- **Auxiliary space complexity:** \(O(A)\) for the DP and choice arrays.
- **Reconstruction:** at most \(O(A)\), since each chosen coin is a positive integer.

## 🧪 Test Cases

The accompanying [`test_cases.txt`](test_cases.txt) lists expected outcomes, including a non-greedy optimal solution, an impossible target, a zero target, invalid denominations, and a larger amount. Run the program with each input to verify the expected result.

## ⚠️ Assumptions and Limitations

- Coin denominations are positive integers.
- The target amount is a non-negative integer.
- Each denomination can be used unlimited times.
- The program returns one optimal combination; other optimal combinations may exist.
- Very large target amounts can require substantial memory because arrays have `A + 1` entries.
- The program is a command-line educational demonstration, not a payment-processing system.

## 🚀 Future Enhancements

- Visualize the DP table as it is filled.
- Add a comparison mode for Greedy, memoization, and tabulation.
- Record runtime for different target amounts and denomination counts.
- Add a graphical interface or a Streamlit front end.
- Extend the program to count combinations or support limited coin supplies.

## 🧰 Technologies

- C++ (STL `vector`, loops, and input/output)
- Dynamic Programming / bottom-up tabulation
- `g++` compiler
- Visual Studio Code (optional development environment)

## 📚 References

1. Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein, *Introduction to Algorithms*, MIT Press.
2. Richard Bellman, *Dynamic Programming*, Princeton University Press, 1957.
3. C++ reference: https://en.cppreference.com/

---
**Project:** Coin Change Calculator Using Dynamic Programming  
**Subject:** Design Analysis of Algorithm (DAA)
