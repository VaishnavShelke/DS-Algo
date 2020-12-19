
class point{
    public:
    int x,y;
    point(){ cout << "\n" << "Oops You forgot to feed me with values \nI am your default POINT in case you forget to initialise me I will remind you \n";}
    point(int x_cord,int y_cord){
        x = x_cord;
        y = y_cord;
    }
};
class line{
    public:
        int a,b,c;
    line(){ cout << "\n" << "Oops You forgot to feed me with values \nI am your default LINE in case you forget to initialise me I will remind you \n";}

    line(int a_pt,int b_pt,int c_pt){
        a = a_pt;
        b = b_pt;
        c = c_pt;
        }
};
double computedist(point p[],double x,line l){
    double y =  -1 * (l.c + l.a*x) / (l.b*1);
    double sum = 0;
    int siz = 5 ;
    for (int i = 0; i < siz;i++){
        sum += sqrt(sq(x-p[i].x)+sq(y-p[i].y));
    }
    return sum;
}
double findshortestdistance(point p[],line l,int low,int high){
    double mid1 = low + (high-low)/3;
    double mid2 = high - (high-low)/3;

    if ((high - low) > EPS){
    double compuH,compuh,compul,compuL;

    //compuH = computedist(p,high,l);
    compuh = computedist(p,mid2,l);
    compul = computedist(p,mid1,l);
    //compuL = computedist(p,low,l);

    if (compuh > compul){
        return findshortestdistance(p,l,low,mid2);
    }

    else{
        return findshortestdistance(p,l,mid1,high);
    }
    }
    else{
        return computedist(p,low,l);
    }

}
int main(){
    int a,b,c;
    cout << 3/4 <<"\n";
    int points[5][2] = {{-3, -2}, {-1, 0}, {-1, 2}, {1, 2}, {3, 4}};
    point p[5];
    for (int i = 0;i<5;i++){p[i] = point(points[i][0],points[i][1]);}
    line l(1,-1,-3);
    double low = -1e6;
    double high = 1e6;
    cout << computedist(p,3,l);
    cout << findshortestdistance(p,l,low,high) <<"\n\n\n";
}
