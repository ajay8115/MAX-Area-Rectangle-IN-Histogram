// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    long long getMaxArea(long long heights[], int n)
    {
        // int n = heights.size();
        vector<long long> left(n), right(n);

        stack<long long> st;
        for (int i = 0; i < n; ++i) // Fill left
        {
            if (st.empty())
            {
                left[i] = 0;
                st.push(i);
            }
            else
            {
                while (!st.empty() and heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                // left[i] = st.empty() ? 0 : st.top() + 1;
                // st.push(i);

                if (st.empty())
                {
                    left[i] = 0;
                    st.push(i);
                }
                else
                {
                    left[i] = st.top() + 1;
                    st.push(i);
                }
            }
        }

        while (!st.empty()) // Clear stack
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; --i) // Fill right
        {
            if (st.empty())
            {
                right[i] = n - 1;
                st.push(i);
            }
            else
            {
                while (!st.empty() and heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                // right[i] = st.empty() ? n - 1 : st.top() - 1;
                // st.push(i);
                if (st.empty())
                {
                    right[i] = n - 1;
                    st.push(i);
                }
                else
                {
                    right[i] = st.top() - 1;
                    st.push(i);
                }
            }
        }

        long long mx_area = 0;
        for (int i = 0; i < n; ++i)
        {
            mx_area = max(mx_area, heights[i] * (right[i] - left[i] + 1));
        }
        return mx_area;
    }
};
