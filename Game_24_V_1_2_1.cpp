#include <bits/stdc++.h>
using namespace std;



bool checkdiv24(int x,int y,int z,int w) {
    if ((24%x)*(24%y)*(24%z)*(24%w) != 0) {
        return 0;
    }
    return 1;
} // just check devide not important

float ope_a(float x,float y,int i){
    // x>y
    float p=x+y;
    if (i==0){
        return p;
    }
    if (i==1){
        p=x-y;
        return p;
    }
    if (x*y==0){
        return 0;
    }
    if (i==2){
        p=x*y;
        return p;
    }
    if (i==3){
        p=x/y;
        return p;
    }
    p=y/x;
    return p;
}




int main()
{
    float a,b,c,d,op_1,op_2,op_3,last_num; // a,b,c,d input op_1=after operation
    cin >> a >> b >> c >> d;

    if (a+b+c+d == 24) {
        cout << "\n" << a << "+" << b << "+" << c << "+" << d << "=" << 24 ;
        return 0;
    }
    if (a*b*c*d == 24) {
        cout << "\n" << a << "*" << b << "*" << c << "*" << d << "=" << 24 ;
        return 0;
    }

    int az = int(a);
    int bz = int(b);
    int cz = int(c);
    int dz = int(d);
    float arr[4]={a,b,c,d};
    sort(arr,arr+4);
    float arr_temp[4]={arr[0],arr[1],arr[2],arr[3]}; 
    //cout << arr[0] << arr[1] << arr[2] << arr[3]; // 0--> min 3-->> max
    //annoy
    arr[0]=arr_temp[3];
    arr[1]=arr_temp[2];
    arr[2]=arr_temp[1];
    arr[3]=arr_temp[0];
    float pair_1[6][2]={{arr[0],arr[1]}
                        ,{arr[0],arr[2]}
                        ,{arr[0],arr[3]}
                        ,{arr[1],arr[2]}
                        ,{arr[1],arr[3]}
                        ,{arr[2],arr[3]}};
    float pair_2[6][2]={{arr[2],arr[3]}
                        ,{arr[1],arr[3]}
                        ,{arr[1],arr[2]}
                        ,{arr[0],arr[3]}
                        ,{arr[0],arr[2]}
                        ,{arr[0],arr[1]}};
    float temp_trip[3]={0,0,0};
    float temp2_trip[3][2]={{temp_trip[2],temp_trip[1]}
                            ,{temp_trip[2],temp_trip[0]}
                            ,{temp_trip[1],temp_trip[0]}};
                            
    float temp3_trip[3]={0,0,0};
    // next loop
    //cout << pair_1[1][0];
    for (int i=0;i<6;i++){
        // run 6 pair
        for (int j=0;j<5;j++){
            //run operation
            op_1=ope_a(pair_1[i][0],pair_1[i][1],j);
            //cout << op_1 << "\n";
            temp_trip[2]=op_1;
            temp_trip[0]=pair_2[i][0];
            temp_trip[1]=pair_2[i][1];
            sort(temp_trip,temp_trip+3);
            temp2_trip[0][0]=temp_trip[2];
            temp2_trip[0][1]=temp_trip[1];
            temp2_trip[1][0]=temp_trip[2];
            temp2_trip[1][1]=temp_trip[0];
            temp2_trip[2][0]=temp_trip[1];
            temp2_trip[2][1]=temp_trip[0];

            temp3_trip[0]=temp_trip[0];
            temp3_trip[1]=temp_trip[1];
            temp3_trip[2]=temp_trip[2];
            // finish set up number
            
            for (int i_a=0;i_a<3;i_a++){
                for (int j_a=0;j_a<5;j_a++){
                    //run operation again
                    op_2=ope_a(temp2_trip[i_a][0],temp2_trip[i_a][1],j_a);
                    //cout << op_2 << "\n";
                    last_num=temp3_trip[i];
                    for (int k=0;k<4;k++){
                        if (last_num > op_2){
                            op_3=ope_a(last_num,op_2,k);

                        }else if (last_num < op_2){
                            op_3=ope_a(op_2,last_num,k);

                        }else{
                            op_3=op_2*2;
                        }
                        if (op_3==24){
                            cout << "yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }


}





/*


a b c d

first

no divide check

do simple

a+b+c+d
a*b*c*d


*/

/*float x,y,z,w ;
    cin >> x >> y;
    z=x/y;
    w=(z+1)*y;
    cout << w << "\n";
    cout << z ;
    cout << "\n" << (((5/9)*2)/7)*126 ;*/