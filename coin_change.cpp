#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int minimumCoins(const vector<int>& coins, int amount, vector<int>& chosenCoin) {
    const int INF = numeric_limits<int>::max() / 2;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    chosenCoin.assign(amount + 1, -1);

    for (int a = 1; a <= amount; ++a) {
        for (int coin : coins) {
            if (coin <= a && dp[a - coin] != INF && dp[a - coin] + 1 < dp[a]) {
                dp[a] = dp[a - coin] + 1;
                chosenCoin[a] = coin;
            }
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of denominations: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of denominations.\\n";
        return 1;
    }

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> coins[i]) || coins[i] <= 0) {
            cout << "Coins must be positive integers.\\n";
            return 1;
        }
    }

    cout << "Enter target amount: ";
    if (!(cin >> amount) || amount < 0) {
        cout << "Amount must be a non-negative integer.\\n";
        return 1;
    }

    vector<int> chosenCoin;
    int result = minimumCoins(coins, amount, chosenCoin);
    if (result == -1) {
        cout << "Target amount cannot be formed.\\n";
        return 0;
    }

    cout << "Minimum number of coins: " << result << '\\n';
    cout << "Coins used: ";
    if (amount == 0) cout << "None";
    while (amount > 0) {
        int coin = chosenCoin[amount];
        cout << coin;
        amount -= coin;
        if (amount > 0) cout << " + ";
    }
    cout << '\\n';
    return 0;
}
