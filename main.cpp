#include <iostream>
using namespace std;
using ll = long long int;
bool isNumberValid(ll acc)
{
    string s = to_string(acc);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > '9' || s[i] < '0')
            return false;
    }
    return true;
}
bool isValidCC(ll acc)
{
    string s = to_string(acc);
    int sum = 0;
    bool isSecond = false;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int n = s[i] - '0';
        if (isSecond)
        {
            n = n * 2;
        }
        sum += n / 10 + n % 10;
        isSecond = !isSecond;
    }
    return (sum % 10 == 0);
}
int main()
{
    ll accnumber;
    cout << "This program uses the Luhn Algorigthm to validate a CC number." << endl;

    cout << "Please enter a Credit Card number to validate: ";
    cin >> accnumber;
    if (to_string(accnumber) == "exit")
        return 0;
    else if (!isNumberValid(accnumber))
    {
        cout << "Bad input! ";
        return 0;
    }
    if (isValidCC(accnumber))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}
