class NumArray {
public:
    vector<int> ST;
    vector<int> nums;
    int n;

    void Build(int idx, int l, int r)
    {
        if(l == r)
        {
            ST[idx] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        Build(2*idx+1, l, mid);
        Build(2*idx+2, mid+1, r);
        ST[idx] = ST[2*idx+1] + ST[2*idx+2];
    }

    void Update(int pos, int value, int idx, int l, int r)
    {
        if(l == r)
        {
            ST[idx] = value;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid)
        {
            Update(pos, value, 2*idx+1, l, mid);
        }
        else
        {
            Update(pos, value, 2*idx+2, mid+1, r);
        }
        ST[idx] = ST[2*idx+1] + ST[2*idx+2];
    }

    int RSQuery(int start, int end, int idx, int l, int r)
    {
        if(l > end || r < start)
        {
            return 0;
        }
        if(l >= start && r <= end)
        {
            return ST[idx];
        }
        int mid = (l+r)/2;
        return RSQuery(start, end, 2*idx+1, l, mid)
             + RSQuery(start, end, 2*idx+2, mid+1, r);
    }

    NumArray(vector<int>& nums)
    {
        this->nums = nums;
        n = nums.size();
        ST.resize(4*n);
        Build(0, 0, n-1);
    }
    
    void update(int index, int val)
    {
        Update(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right)
    {
        return RSQuery(left, right, 0, 0, n-1);
    }
};