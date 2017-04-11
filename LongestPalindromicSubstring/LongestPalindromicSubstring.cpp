#include<iostream>
#include<string>
using namespace std;

const string ExpandFromCenter(const string& str, int l, int r)
{
	int left = l, right = r;
	const size_t N = str.size();
	while (left >= 0 && right <=  N- 1 && str[left] == str[right])
	{
		--left;
		++right;
	}
	return string(str, left + 1, right - left - 1);
}

const string LongestPalindromicSubstring(const string& str)
{
	const size_t N = str.size();
	string longest = str.substr(0, 1);
	for (int i = 0; i < N - 1; ++i)
	{
		string tmpstr = ExpandFromCenter(str, i, i);
		if (tmpstr.size() > longest.size())
			longest = tmpstr;
		string tmpstr2 = ExpandFromCenter(str, i, i + 1);
		if (tmpstr2.size() > longest.size())
			longest = tmpstr2;
	}
	return longest;
}

int main(int argc, char** argv)
{
	string str;
	cout << "Please input a string to find its longest palindromic substring: ";
	getline(cin, str);
	cout << "Its longest palindromic substring is " << LongestPalindromicSubstring(str) << endl;
	return EXIT_SUCCESS;
}