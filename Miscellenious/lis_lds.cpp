
int lids[MAX];
int getLids(int _n , int _arr[] ,bool _lis) /// array is 0 based
{
    if(_lis==false) /// lds is wanted
        reverse(_arr , _arr+ _n);

    vector<int>aux;
    aux.pb( -1*oo );
    for(int i=1;i<=_n;i++) aux.pb(oo);

    vector<int>::iterator it;
    int pos , mxLength=0;
    for(int i=0;i<_n;i++)
    {
        it = upper_bound(aux.begin(),aux.end() , _arr[i] ); /// not strictly increasing
//        it = lower_bound(aux.begin(),aux.end() , _arr[i] ); /// strictly increasing

        pos = it - aux.begin();
        lids[i]=pos;

        mxLength = max(lids[i],mxLength);
        aux[pos] = min(aux[pos],_arr[i]);
    }
    if(_lis==false)
        reverse(_arr,_arr + _n) , reverse(lids, lids + _n);

    return mxLength;
}
