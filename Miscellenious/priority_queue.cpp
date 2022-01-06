struct data
{
    int indx,cost,fuel;
    data() {}
    data(int a , int b , int c) {indx=a;cost=b;fuel=c;}
    bool operator<(const data & x)const
    {
        return cost>x.cost; /// minimum priority_queue
    }
};

priority_queue<int> Q; /// maximum priority queue
priority_queue<int, vector<int>, greater<int> >Q; ///minimum priority queue


