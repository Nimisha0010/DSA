class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size() - 1;
        int mx_area = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            mx_area = max(mx_area, area);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return mx_area;
    }
};