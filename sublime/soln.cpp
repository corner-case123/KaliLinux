#include <bits/stdc++.h>
#define ln endl
#define ull unsigned  long long
#define ll  long long
#define vll vector<ll>
#define ff first
#define ss second
#define vpll vector<pair<ll,ll>>
#define pll pair<ll,ll>
using namespace std;


void setIO(const string io = "a") {
    freopen("a.in", "r", stdin) ;
    freopen("a.out", "w", stdout) ;
}

ll n ; 
void solve(){
    cin >> n ;
    cout << n << ln ;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     setIO() ;
//     ll t = 1 ; //cin >> t ;
//     while(t--) solve() ;
//     return  0 ;
// }
int main(){
    setIO() ;
  int a,b,option;
  printf("Enter the first Integer :");
  scanf("%d",&a);
  printf("Enter the second Integer :");
  scanf("%d",&b);
  printf("Input your option:\n");
  printf("1-Addition.\n2-Substraction.\n3-Multiplication.\n4-Division.\n5-Exit.\n");
  scanf("%d",&option);

  switch(option)
  {
    case 1:
      printf("The Addition of  %d and %d is: %d\n",a,b,a+b);
      break;
    case 2:
      printf("The Substraction of %d  and %d is: %d\n",a,b,a-b);
      break;
    case 3:
      printf("The Multiplication of %d  and %d is: %d\n",a,b,a*b);
      break;
    case 4:
      if(b==0)
        {
        printf("The second integer is zero. Divide by zero.\n");
        }
      else
    {
        float div=(float)a/b;
        printf("The Division of %d  and %d is : %f\n",a,b,div);
      }
      break;
    default:
      printf("Incorrect option\n");
      break;
  }
  return 0; 
}