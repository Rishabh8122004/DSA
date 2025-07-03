class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>v;
        int n = arr.size();
        // my solution : below this there is also a solution using maxheap ;
        // if(x<=arr[0])
        // {
        //     for(int i = 0;i<k;i++)
        //     {
        //         v.push_back(arr[0+i]);
        //     }
        // }
        // else if(x>=arr[n-1])
        // {
        //     for(int i = 0;i<k;i++)
        //     {
        //         v.push_back(arr[n-1-i]);
        //     }
        //     reverse(v.begin(),v.end());
        // }
        // else{
        //     int lo = 0,hi = n-1;
        //     bool check = false;
        //     int lb,ub,idx;
        //     while(lo <= hi)
        //     {
        //         int mid = lo+(hi-lo)/2;
        //         if(arr[mid] == x){check = true;idx = mid; lb=mid-1;ub =mid+1;break;}
        //         else if(arr[mid]<x){lo = mid+1;}
        //         else{hi = mid-1;}
        //     }
        //     if(check == true)
        //     {
        //         v.push_back(arr[idx]);
        //          for(int i = 0;i<k-1;i++)
        //         {
        //             if(abs(arr[lb]-x)==abs(arr[ub]-x))
        //             {
        //             v.push_back(arr[lb]);
        //             lb--;
        //             if(lb<0)
        //             {
        //                while(v.size()<k)
        //                {
        //                 v.push_back(arr[ub]);ub++;
        //                }
        //                break;
        //             }
        //             }
        //             else if(abs(arr[lb]-x)>abs(arr[ub]-x)){
        //             if(v.size()==k){break;}
        //             v.push_back(arr[ub]);
        //             ub++;
        //             if(ub>n-1)
        //             {
        //                 while(v.size()<k)
        //                 {
        //                     v.push_back(arr[lb]);lb--;
        //                 }
        //                 break;
        //             }
        //             }
        //             else if(abs(arr[lb]-x)<abs(arr[ub]-x))
        //             {
        //             v.push_back(arr[lb]);
        //             lb--;
        //             if(lb<0)
        //             {
        //                while(v.size()<k)
        //                {
        //                 v.push_back(arr[ub]);ub++;
        //                }
        //                break;
        //             }
        //             }
        //         }
        //         sort(v.begin(),v.end());
        //     }
        //     else{
        //         ub = lo;lb = hi;
        //        for(int i = 0;i<k;i++)
        //         {
        //             if(abs(arr[lb]-x)==abs(arr[ub]-x))
        //             {
        //             v.push_back(arr[lb]);
        //             lb--;
        //             if(lb<0)
        //             {
        //                while(v.size()<k)
        //                {
        //                 v.push_back(arr[ub]);ub++;
        //                }
        //                 break;
        //             }
        //             }
        //             else if(abs(arr[lb]-x)>abs(arr[ub]-x))
        //             {
        //             if(v.size()==k){break;}
        //             v.push_back(arr[ub]);
        //             ub++;
        //             if(ub>n-1)
        //             {
        //                 while(v.size()<k)
        //                 {
        //                     v.push_back(arr[lb]);lb--;
        //                 }
        //                 break;
        //             }
        //             }
        //             else if(abs(arr[lb]-x)<abs(arr[ub]-x))
        //             {
        //             v.push_back(arr[lb]);
        //             lb--;
        //             if(lb<0)
        //             {
        //                while(v.size()<k)
        //                {
        //                 v.push_back(arr[ub]);ub++;
        //                }
        //                 break;
        //             }
        //             }
        //         }
        //         sort(v.begin(),v.end());
        //     }
        // }
        // max heap solution : 
        priority_queue<pair<int,int>>pq;
        for(int i = 0;i<n;i++){
            pair<int,int> pi = {abs(x-arr[i]),arr[i]};
            pq.push(pi);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};