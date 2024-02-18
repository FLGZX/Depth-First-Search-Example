#include<bits/stdc++.h>
using namespace std;
char maze[18][24]= {"************** ********",//1 The default setting is' * 'as the obstacle symbol,
											  //'$'as the target point, and the position is determined by the user.
                    "*            * *      *",//2
                    "* ************ * ** * *",//3
                    "*            * **** * *",//4
                    "* ********** * *    * *",//5
                    "* **       *   * ******",//6
                    "* ** ***** ***** * ** *",//7
                    "*        *          * *",//8
                    "****** * **********   *",//9
                    "*    * * *        *$  *",//10
				 	"* **** * * ****** *****",//11
				 	"* *    * * *    * *   *",//12
				 	"* * ****** * ** * * * *",//13
				 	"* *        * ** * * * *",//14
				 	"* ********** **     * *",//15
				 	"*          ******     *",//16
				 	"*************** *******",//17 
				 	"***********************"
				 	};//18
int vis[18][24],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},flag=0,ans=0,anses=0;
void dfs(int x,int y,int ans_){
    if(maze[x][y]=='$'){
        flag=1;
        anses++;
        ans=ans_;
        return ;
    }
    for(int i=0;i<4;i++){
        if(maze[x+dx[i]][y+dy[i]]!='*'&&vis[x+dx[i]][y+dy[i]]==0){
            vis[x][y]=1;
            dfs(x+dx[i],y+dy[i],ans_+1);
            vis[x][y]=0;
        }
    }
}
int main(void){
    int x,y;
    cin>>x>>y;
    dfs(x,y,0);
    if(flag) cout<<"yes"<<" "<<ans<<" "<<anses;//Is it possible to reach+required steps+total number of plans. 
    else cout<<"no"<<" "<<ans<<" "<<anses;
    return 0;
}
