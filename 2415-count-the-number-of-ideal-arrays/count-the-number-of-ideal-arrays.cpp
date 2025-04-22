class Solution {
public:
    using ll = long long;
    vector<int> spf;
    vector<ll> fact;
    int mod = 1e9 + 7;
    /* Precompute smallest prime factors (spf) and
       factorials up to 1e5 */
    void pre() {
        iota(spf.begin(), spf.end(), 0);
        for (ll i = 2; i < 1e5 + 5; ++i) {
            if (spf[i] != i)
                continue;
            for (ll j = i * i; j < 1e5 + 5; j += i) {
                spf[j] = i;
            }
        }
        fact[0] = 1;
        for (int i = 1; i <= 1e5; ++i) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= mod;
        }
    }
    
    // Fast exponentiation to calculate a^b % mod
    ll fastPow(ll a, ll b) {
        ll ret = 1;
        while (b) {
            if (1 & b) {
                ret *= a;
                ret %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return ret;
    }
    // Calculate modular inverse of a using Fermat's Little Theorem: a^(mod-2)
    ll inv(int a) { return fastPow(a, mod - 2); }
    
    // Factorize the number x using the smallest prime factor array (spf)
    map<int, int> factorize(int x) {
        map<int, int> frq; // To store the prime factors and their frequencies
        while (x > 1) {
            frq[spf[x]]++;
            x /= spf[x];
        }
        return frq;
    }

    ll C(int a, int b) {
        if (a < b)
            return 0;
        return fact[a] * inv(fact[b]) % mod * inv(fact[a - b]) % mod;
    }

    int idealArrays(int n, int maxValue) {
        spf.resize(1e5 + 5);
        fact.resize(1e5 + 5);
        pre();
        ll ret = 0;
        // Iterate through each possible value of arr[n-1] from 1 to maxValue
        for(int i = 1; i <= maxValue; ++i) {
            map<int, int> primes = factorize(i);
            ll ans = 1;
            // For each prime factor of i, calculate how many ways we can distribute it
            for(auto [a, b]: primes) {
                ans *= C(b + n - 1, n - 1);
                ans %= mod;
            }
            ret += ans;
            ret %= mod;
        }
        return ret;
    }
};