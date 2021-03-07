#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("bendin.txt","r",stdin);
    freopen("bendout.txt","w",stdout);

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;
    int area1 = (x2-x1)*(y2-y1);
    int area2 = (x4-x3)*(y4-y3);

    int left_inter = max(x1,x3);
    int right_inter = min(x2,x4);
    int bottom_inter = max(y1,y3);
    int top_inter = min(y2,y4);

    int Aintr=0;
    if((left_inter<right_inter)&&(bottom_inter<top_inter))
    {
        Aintr = (right_inter-left_inter)*(top_inter-bottom_inter);
    }
    int ans = area1+area2 -Aintr;
    cout<<ans;
    // There area here will be the area of the first rectangle+area of the second rectangle-area of the intersection of both the recetangles.
    // We need to consider all the inputs with us using those we will be able to find the coordinates of the
    // left intersection and the right intersection.


}