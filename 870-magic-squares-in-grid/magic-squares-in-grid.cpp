class Solution {
public:
    bool is_unique(int &i,int &j,vector<vector<int>>&g){
        int a = i+3-1,b = j+3-1;
        vector<int>v(10,0);
        while(a>=i){
            b = j+3-1;
            while(b>=j){
                if(g[a][b]>=10 || g[a][b] == 0)return false;
                v[g[a][b]]++;
                b--;
            }
            a--;
        }
        for(int i = 1;i<10;i++){if(v[i] != 1)return false;}
        return true;
    }
    int magic_square(int &m,int &n,int k,vector<vector<int>>&r,vector<vector<int>>&c,vector<vector<int>>&d1,vector<vector<int>>&d2,vector<vector<int>>& g){
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i+k-1 >= n)break;
            for(int j = 0;j<m;j++){
                if(j+k-1 >= m)break;
                if(!is_unique(i,j,g))continue;
                bool f = true;
                int sum = (r[i][j+k-1]-(j == 0?0:r[i][j-1]));
                // ROW CHECKING
                for(int a = i+1;a<=i+k-1;a++){
                    if(r[a][j+k-1]-(j == 0?0:r[a][j-1]) != sum){f = false;break;}
                }
                if(!f)continue;
                // COLUMN CHECKING 
                for(int a = j;a<=j+k-1;a++){
                    if(c[i+k-1][a]-(i == 0?0:c[i-1][a]) != sum){f = false;break;}
                }
                if(!f)continue;
                // diagonal 1 checking
                if(d1[i+k-1][j+k-1]-(i == 0?0:(j == 0?0:d1[i-1][j-1])) != sum){f = false;}
                if(!f)continue;
                // diagonal 2 checking
                if(d2[i+k-1][j]-(i == 0?0:(j+k-1 == m-1?0:d2[i-1][j+k])) != sum)f = false;
                if(f) ans++;
            }
        }
        return ans;
    }
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        vector<vector<int>>r = g;
        vector<vector<int>>c = g;
        vector<vector<int>>d1 = g;
        vector<vector<int>>d2 = g;
        // row wise prefix sum
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                r[i][j] += r[i][j-1];
            }
        } 
        //column wise prefix sum
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                c[i][j]+=c[i-1][j];
            }
        }
        // diagonal 1 -> top left to bottom right
        for(int i = n-1;i>=0;i--){
            for(int j = 1;j+i<n && j<m;j++){
                d1[j+i][j] += d1[j+i-1][j-1];
            }
        }
        for(int j = 1;j<m;j++){
            for(int i = 1;i+j<m && i<n;i++){
                d1[i][i+j] += d1[i-1][i+j-1];
            }
        }
        // diagonl 2 -> top right to bottom left
        for(int i = 1;i<n;i++){
            int a = i;
            for(int j = m-2;j>=0;j--){
                if(a>=n)break;
                d2[a][j] += d2[a-1][j+1];
                a++;
            }
        }
        for(int j = m-3;j>=0;j--){
            int a = j;
            for(int i = 1;i<n;i++){
                if(a<0)break;
                d2[i][a] += d2[i-1][a+1];
                a--;
            }

        }
        int k = 3;
        return magic_square(m,n,k,r,c,d1,d2,g);
    }
};