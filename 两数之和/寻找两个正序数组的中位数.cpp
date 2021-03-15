#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int h1 = 0;
        int h2 = 0;
        int t1 = nums1.size()-1;
        int t2 = nums2.size()-1;
        int l1 = nums1.size();
        int l2 = nums2.size();
        double result = 0.0;
        pair<int,int> m1(-1,0);
        pair<int,int> m2(l1+l2,0);
        while (m2.first-m1.first>1)
        {
            if (t1 - h1 >= 0 && t2 - h2 >= 0)
            {
                if (nums1[h1] <= nums2[h2])
                {
                    m1.second = nums1[h1];
                    h1++;
                }
                else
                {
                    m1.second = nums2[h2];
                    h2++;
                }
                m1.first++;

                if (t1 - h1 >= 0 && t2 - h2 >= 0)
                {
                    if (nums1[t1] > nums2[t2])
                    {
                        m2.second = nums1[t1];
                        t1--;
                    }
                    else
                    {
                        m2.second = nums2[t2];
                        t2--;
                    }
                    m2.first--;
                }
                else if (t1 - h1 >= 0)
                {
                    m2.second = nums1[t1];
                    m2.first--;
                    t1--;
                }
                else if (t2 - h2 >= 0)
                {
                    m2.second = nums2[t2];
                    m2.first--;
                    t2--;
                }
            }
            else if (t1 - h1 >= 0)
            {
                m1.second = nums1[h1];
                m1.first++;
                h1++;
                m2.second = nums1[t1];
                m2.first--;
                t1--;
            }
            else if (t2 - h2 >= 0)
            {
                m1.second = nums2[h2];
                m1.first++;
                h2++;
                m2.second = nums2[t2];
                m2.first--;
                t2--;
            }



            cout << m1.first << " " << m1.second << " " << m2.first << " " << m2.second << endl;

        }
        //cout << m1.first << " " << m1.second << " " << m2.first << " " << m2.second << endl;
        result = double(m1.second + m2.second) / 2;
        cout << result << endl;
        return result;
    }
};

/*
int main()
{
    vector<int> a1 = { 1,3 };
    vector<int> a2 = { 2 };
    Solution su;
    double a = su.findMedianSortedArrays(a1, a2);
    return 0;
}
*/