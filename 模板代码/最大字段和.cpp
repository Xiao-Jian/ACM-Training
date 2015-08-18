/*简单算法:
**v[0]不保存数据
**T(n)=O(n^2).
*/
int MaxSum(int *v,int n,int *besti,int *bestj)
{
    int sum=0;
    int i,j;
    for (i=1;i<=n;i++)
    {
        int thissum=0;
        for (j=i;j<=n;j++)
        {
            thissum+=v[j];
            if (thissum>sum)
            {
                sum=thissum;
                *besti=i;
                *bestj=j;
            }
        }
    }
    return sum;
}
/*分治法:
**将a[1n]分成a[1n/2]和a[n/2+1n],则a[1n]的最大字段和有三种情况:
**(1)a[1n]的最大子段和与a[1n/2]的最大子段和相同
**(2)a[1n]的最大子段和与a[n/2n]的最大子段和相同
**(3)a[1n]的最大子段和为ai++aj,1<=i<=n/2,n/2+1<=j<=n
**T(n)=2T(n/2)+O(n)
**T(n)=O(nlogn)
*/
int MaxSum_DIV(int *v,int l,int r)
{
    int k,sum=0;
    if(l==r)
        return v[l]>=0?v[l]:0;
    else
    {
        int center=(l+r)/2;
        int lsum=MaxSum_DIV(v,l,center);
        int rsum=MaxSum_DIV(v,center+1,r);

        int s1=0;
        int lefts=0;
        for (k=center;k>=l;k--)
        {
            lefts+=v[k];
            if(lefts>s1)
                s1=lefts;
        }

        int s2=0;
        int rights=0;
        for (k=center+1;k<=r;k++)
        {
            rights+=v[k];
            if(rights>s2)
                s2=rights;
        }
        sum=s1+s2;
        if(sum<lsum)
            sum=lsum;
        if(sum<rsum)
            sum=rsum;
    }
    return sum;
}
/*动态规划算法:
**b[j]=max{a[i]++a[j]},1<=i<=j,且1<=j<=n,则所求的最大子段和为max b[j]，1<=j<=n。
**由b[j]的定义可易知，当b[j-1]>0时b[j]=b[j-1]+a[j]，否则b[j]=a[j]。故b[j]的动态规划递归式为:
**b[j]=max(b[j-1]+a[j],a[j])，1<=j<=n。
**T(n)=O(n)
*/
int MaxSum_DYN(int *v,int n)
{
    int sum=0,b=0;
    int i;
    for (i=1;i<=n;i++)
    {
        if(b>0)
            b+=v[i];
        else
            b=v[i];
        if(b>sum)
            sum=b;
    }
    return sum;
}
