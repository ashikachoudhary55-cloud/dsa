class Solution {
public:
    void buildSegmentTree(vector<int> &heights, int segmentTree[], int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(heights, segmentTree, 2*i+1, l, mid);
        buildSegmentTree(heights, segmentTree, 2*i+2, mid+1, r);
        int leftIdx = segmentTree[2*i + 1];
        int rightIdx = segmentTree[2*i + 2];
        if (heights[leftIdx] > heights[rightIdx]) {
            segmentTree[i] = leftIdx;
        } else {
            segmentTree[i] = rightIdx;
        }
    }

    int *constructST(int n, vector<int> &heights) {
        int *segmentTree = new int[4*n];
        buildSegmentTree(heights, segmentTree, 0, 0, n-1);
        return segmentTree;
    }

    int x(int start, int end, int i, int l, int r, int segmentTree[], vector<int> &heights) {
        if (l > end || r < start) {
            return -1;
        }
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        int leftIdx = x(start, end, 2*i+1, l, mid, segmentTree, heights);
        int rightIdx = x(start, end, 2*i+2, mid+1, r, segmentTree, heights);
        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;

        if (heights[leftIdx] > heights[rightIdx]) {
            return leftIdx; 
        } 
        return rightIdx;
    }

    int RMIQ (int segmentTree[], vector<int> &heights, int n, int start, int end) {
        return x(start, end, 0, 0, n-1, segmentTree, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int *segmentTree = constructST(n, heights);
        vector <int> result;
        for (auto query : queries) {
            int min_idx = min (query[0], query[1]);
            int max_idx = max (query[0], query[1]);

            if (min_idx == max_idx) {
                result.push_back(max_idx);
                continue;
            } else if (heights[max_idx] > heights[min_idx]) {
                result.push_back (max_idx);
                continue;
            }

            int l = max_idx + 1;
            int r = n-1;
            int result_idx = INT_MAX;

            while (l <= r) {
                int mid = l + (r-l)/2;
                int idx = RMIQ(segmentTree, heights, n, l, mid);
                if (heights[idx] > heights[min_idx] && heights[idx] > heights[max_idx]) {
                    result_idx = min(result_idx, idx);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (result_idx == INT_MAX) {
                result.push_back (-1);
            } else {
                result.push_back (result_idx);
            }
        }
        return result;
    }    
    
};