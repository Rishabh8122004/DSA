class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m, vector<int>(n, -1));
        ListNode* temp = head;
        int x = 0;
        
        // Define boundaries
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (x < (m * n)) {
            // Left to Right
            for (int i = left; i <= right && temp; i++) {
                v[top][i] = temp->val;
                temp = temp->next;
                if(temp == NULL)return v;
                x++;
            }
            top++; // Shrink top boundary
            
            // Top to Bottom
            for (int i = top; i <= bottom && temp; i++) {
                v[i][right] = temp->val;
                temp = temp->next;
                if(temp == NULL)return v;
                x++;
            }
            right--; // Shrink right boundary
            
            // Right to Left
            for (int i = right; i >= left && temp; i--) {
                v[bottom][i] = temp->val;
                temp = temp->next;
                if(temp == NULL)return v;
                x++;
            }
            bottom--; // Shrink bottom boundary
            
            // Bottom to Top
            for (int i = bottom; i >= top && temp; i--) {
                v[i][left] = temp->val;
                temp = temp->next;
                if(temp == NULL)return v;
                x++;
            }
            left++; // Shrink left boundary
        }
        
        return v;
    }
};
