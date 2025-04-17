//https://leetcode.com/problems/sqrtx/
//2025.3.29创建文件并AC（非第一次），看了两种高效做法题解
//2种高效做法：二分查找和牛顿迭代法(https://www.cnblogs.com/Allen-rg/p/13602550.html)

//牛顿法利用导数逐步逼近方程的根,,时间复杂度为 O(log⁡x)，在实际运算中通常比二分查找快一些，尤其是对于大数计算时。
//求sqrt(m)的解x^2=m, 那么也就是f(x)=x^2-m=0的解x。问题转换为求解方程f(x)=x^2-m=0。牛顿法是一种迭代求方程解f(x)=0的方法
//f'(x) = 2x, 则f(x) 函数的曲线在 (xn，xn^2 - m) 处的切线的斜率是：2xn, 切线方程是：y = 2xn (x - xn) + xn2 - m
//故切线与x轴的交点/方程f(x)=0的解是：xn+1 = (xn + m / xn ) / 2, 即yn+1 = (yn + (x / yn)) / 2
class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<2)
            return x;
        long long int y = x; //先随便找一点作为解，然后不断迭代减小解y
        while (y*y>x) //f(y) = y^2-x >0, 此时y是最大的小于等于x的平方根
        {
            y = (y + x/y) / 2;
        }
        return y;
    }
};

//二分查找法在[0,x]之间查找平方根,时间复杂度为 O(log⁡x)
class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<2)
            return x;
        int beg = 0, end= x, ans;
        while (beg<=end)
        {
            int mid = beg+(end-beg)/2; //为了避免超过int范围，不写(end+beg)/2
            if (mid<=x/mid) //为了避免超过int范围，不写mid*mid<=x
            {
                ans = mid; //只在mid<=根号x时保存，这样一定符合要求。否则x可能是根号x向上约的值
                beg = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
    }
};