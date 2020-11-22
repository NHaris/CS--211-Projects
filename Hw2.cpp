#include <bits/stdc++.h>
using namespace std;

//Figure out how to find the sum of two numbers

string addSum(string stra, string strb)
{
  //String b is the larger integer

  if (stra.length() > strb.length())
    swap(stra, strb);

  string str = "";

  int s1 = stra.length(), s2 = strb.length();

  // now reverse both strings
  reverse(stra.begin(), stra.end());
  reverse(strb.begin(), strb.end());

  int carryover = 0;
  for (int i = 0; i < s1; i++)
  {
    int sum = ((stra[i] - '0') + (strb[i] - '0') + carryover);
    str.push_back(sum % 10 + '0');
    carryover = sum / 10;
  }
  for (int i = s1; i < s2; i++)
  {
    int sum = ((strb[i] - '0') + carryover);
    str.push_back(sum % 10 + '0');
    carryover = sum / 10;
  }
  if (carryover)
    str.push_back(carryover + '0');

  reverse(str.begin(), str.end());

  return str;
}
int main()
{
  string stra = " ", strb = "";
  while (true)
  {
    cout << "Write the first number or type 'done' to terminate the program: ";
    cin >> stra;
    if (stra == "done")
      break;
    cout << "Please enter the second number : ";
    cin >> strb;
    cout << "The answer is: " << addSum(stra, strb) << "\n\n";
  }
  return 0;
}