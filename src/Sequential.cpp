#include<bits/stdc++.h>
using namespace std;


/*

@author Nitin Bindal

This class contains the implementation of Sequential 
convex hull algortihm.

*/


void print(const vector<pair<int,int>>&vect){

    cout<<"--------------------------\n\n";

    for(int i=0;i<vect.size();i++){
        cout<<vect[i].first<<" --- "<<vect[i].second<<"\n";
    }

    cout<<"\n--------------------------\n\n";
}


int find_x(const pair<int,int>points[] , int parity, int n){

    int idx =0;
    pair<int,int>val = points[0];

    if(parity == 0){

        for(int i=0;i<n;i++){
            if(val.first > points[i].first){
                idx =i;
                val = points[i];
            }

            else if(val.first == points[i].first && val.second<points[i].second){
                idx = i;
                val = points[i];
            }

        }

    }

    else{

    for(int i=0;i<n;i++){
            if(val.first < points[i].first){
                idx =i;
                val = points[i];
            }

            else if(val.first == points[i].first && val.second>points[i].second){
                idx =i;
                val = points[i];
            }

        }

    }

    return idx;

}

int find_y(const pair<int,int>points[] , int parity, int n){

    int idx =0;
    pair<int,int> val = points[0];

    if(parity == 0){

        for(int i=0;i<n;i++){

            if(val.second > points[i].second){
                idx =i;
                val = points[i];
            }

            else if(val.second == points[i].second && val.first>points[i].first){
                    idx =i;
                    val = points[i];
            }

        }

    }

    else{

    for(int i=0;i<n;i++){

            if(val.second < points[i].second){
                idx =i;
                val = points[i];
            }

            else if(val.second == points[i].second && val.first < points[i].first){
                idx =i;
                val = points[i];
            }
        }

    }

    return idx;

}

pair<int,int> operator- (pair<int,int>f,pair<int,int>s){

    return {f.first-s.first , f.second -s.second};

}

int   crossProduct(pair<int,int>f , pair<int,int>s){

    int val = f.first * s.second - f.second*s.first;

    return (val>=0) ? 1 : -1;

}


void distribute( const vector<pair<int,int>>&extreme_points, const pair<int,int> points[],
vector<pair<int,int>>&ll,vector<pair<int,int>>&lr,vector<pair<int,int>>&ul,vector<pair<int,int>>&ur,int n)
{


    for(int i=0;i<n;i++){

//         cout<<points[i].first<<" ---- "<<points[i].second<<"\n";

    if(crossProduct(extreme_points[2]-extreme_points[0],points[i]-extreme_points[2])<0){
        ll.push_back(points[i]);
    }

    else if(crossProduct(extreme_points[1]-extreme_points[2],points[i]-extreme_points[1])<0){
        lr.push_back(points[i]);
    }

    else if(crossProduct(extreme_points[3]-extreme_points[1],points[i]-extreme_points[3])<0){
        ur.push_back(points[i]);
    }

    else if(crossProduct(extreme_points[0]-extreme_points[3],points[i]-extreme_points[0])<0){
        ul.push_back(points[i]);
    }


    }

    return ;


}



bool x_a(const pair<int,int>&a,const pair<int,int>&b){


    if(a.first==b.first){
        return (a.second)>(b.second);
    }

    return a.first<=b.first;


}

bool x_d(const pair<int,int>&a,const pair<int,int>&b){

    if(a.first == b.first){
        return a.second < b.second;
    }

    return a.first>=b.first;

}


bool y_a(const pair<int,int>&a,const pair<int,int>&b){


    if(a.second==b.second){
        return a.first<b.first;
    }

    return a.second<=b.second;


}


bool y_d(const pair<int,int>&a,const pair<int,int>&b){


    if(a.second==b.second){
        return a.first > b.first;
    }

    return a.second>=b.second;

}


void ll_rule( const vector<pair<int,int>>&vect,vector<pair<int,int>>&target){

    int n = vect.size();

    int val = vect[0].second;

    target.push_back(vect[0]);
    for(int i=1;i<n;i++){

        if(vect[i].second>val){
            continue;
        }
        else{
            val = vect[i].second;
        }
        target.push_back(vect[i]);

    }


    return ;

}


void lr_rule(const vector<pair<int,int>>&vect,vector<pair<int,int>>&target){

    int n = vect.size();

    int val = vect[0].first;
    target.push_back(vect[0]);

    for(int i=1;i<n;i++){

        if(vect[i].first<val){
            continue;
        }

        else{
            val = vect[i].first;
        }
        target.push_back(vect[i]);

    }


    return ;

}

void ul_rule(const vector<pair<int,int>>&vect,vector<pair<int,int>>&target){

    int n = vect.size();

    int val = vect[0].first;
    target.push_back(vect[0]);

    for(int i=1;i<n;i++){

        if(vect[i].first>val){
            continue;
        }

        else{
            val = vect[i].first;
        }
        target.push_back(vect[i]);

    }


    return ;

}


void ur_rule(const vector<pair<int,int>>&vect,vector<pair<int,int>>&target){

    int n = vect.size();
    

    int val = vect[0].second;
    target.push_back(vect[0]);

    for(int i=1;i<n;i++){

        if(vect[i].second<val){
            continue;
        }

        else{
            val = vect[i].second;
        }
        target.push_back(vect[i]);

    }


    return ;

}




void form_chain(const vector<pair<int,int>>&vect,vector<pair<int,int>>&target,
pair<int,int>p1,pair<int,int>p2){
    

    if(vect.size()<=1){
        return;
    }


    for(int i=1;i<vect.size();i++){

        if(crossProduct(p1-p2,vect[i]-p1)>=0){
            target.push_back(vect[i]);
            p2 =  p1;
            p1 = vect[i];
        }

    }

    return ;

}



int main(){

    int n;
    cin>>n;

    pair<int,int> points[n];

    int x,y;

    for(int i=0;i<n;i++){
        cin>>x>>y;

        points[i] = {x,y};

    }

    clock_t tStart = clock();


    pair<int,int>x_min    = points[find_x(points,0,n)];
    pair<int,int>x_max    = points[find_x(points,1,n)];
    pair<int,int>y_min    = points[find_y(points,0,n)];
    pair<int,int>y_max    = points[find_y(points,1,n)];

    vector<pair<int,int>>extreme_points;

     extreme_points.push_back(x_min);    
     extreme_points.push_back(x_max);
     extreme_points.push_back(y_min);
     extreme_points.push_back(y_max);

    // cout<<"Extreme points\n";
    // print(extreme_points);
    // cout<<"\n----------------------------------EEE\n";
    



    vector<pair<int,int>>lower_left;
    vector<pair<int,int>>lower_right;
    vector<pair<int,int>>upper_left;
    vector<pair<int,int>>upper_right;

    lower_left.push_back(extreme_points[0]);
    lower_right.push_back(extreme_points[2]);
    upper_right.push_back(extreme_points[1]);
    upper_left.push_back(extreme_points[3]);
    

    distribute(extreme_points,points,lower_left,lower_right,upper_left,upper_right,n);

    if(lower_left.size()>1){
    sort(lower_left.begin(),lower_left.end(),x_a);

    }

    if(lower_right.size()>1){
    sort(lower_right.begin(),lower_right.end(),y_a);

    }

    if(upper_left.size()>1){

    sort(upper_left.begin(),upper_left.end(),y_d);
    }


    if(upper_right.size()>1){
    sort(upper_right.begin(),upper_right.end(),x_d);

    }

    // print(lower_left);
    // print(lower_right);
    // print(upper_right);
    // print(upper_left);


    vector<pair<int,int>>ll;
    vector<pair<int,int>>lr;
    vector<pair<int,int>>ul;
    vector<pair<int,int>>ur;



    ll_rule(lower_left,ll);
    lr_rule(lower_right,lr);
    ul_rule(upper_left,ul);
    ur_rule(upper_right,ur);

    // print(ll);
    // print(lr);
    // print(ur);
    // print(ul);


    lower_left.clear();
    lower_right.clear();
    upper_left.clear();
    upper_right.clear();


    lower_left.push_back(extreme_points[0]);
    lower_right.push_back(extreme_points[2]);
    upper_right.push_back(extreme_points[1]);
    upper_left.push_back(extreme_points[3]);


    form_chain(ll,lower_left,extreme_points[0],extreme_points[2]);
    form_chain(lr,lower_right,extreme_points[2],extreme_points[1]);
    form_chain(ur,upper_right,extreme_points[1],extreme_points[3]);
    form_chain(ul,upper_left,extreme_points[3],extreme_points[0]);


    // print(lower_left);
    // print(lower_right);
    // print(upper_right);
    // print(upper_left);

    vector<pair<int,int>>simple_polygon;

    simple_polygon.insert(simple_polygon.end(),lower_left.begin(),lower_left.end());
    simple_polygon.insert(simple_polygon.end(),lower_right.begin(),lower_right.end());
    simple_polygon.insert(simple_polygon.end(),upper_right.begin(),upper_right.end());
    simple_polygon.insert(simple_polygon.end(),upper_left.begin(),upper_left.end());

    cout<<"\nPoints in Simple Polygon are ---\n \n";
    print(simple_polygon);

    /*
        Note if you un-comment bwlow line and run the ex.sh shell then files will be different.
    */

    // cout<<"Time taken :  \n"<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<"\n";


    return 0;

}
