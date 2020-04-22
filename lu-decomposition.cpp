#include<bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream input("input.txt",ios::in);ofstream output("output.txt",ios::out);
	int M,N,n;bool flag;
	
	input>>n;
	output<<n<<endl;
	//loop n times-------------------------	
	for(int i=0;i<n;i++){
		flag=true;

		//input M N------------------------	
		input>>M>>N;
		
		//create MxN matrix----------------	
		double matrix[M][N],P[M][M],L[M][M];
		
		//load matrix data-----------------	
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				input>>matrix[j][k];
			}

			for(int k=0;k<M;k++){
				if(j==k){L[j][k]=1;P[j][k]=1;}
				else {L[j][k]=0;P[j][k]=0;}
				
			}
			
		}
		
		//decomposition loop---------------
		for(int j=0;j<M-1;j++){

			if(matrix[j][j]!=0){
				for(int k=j+1 ; k<M ; k++){
					L[k][j] = matrix[k][j]/matrix[j][j];
					for(int l=0;l<N;l++){
						matrix[k][l] -= matrix[j][l]*L[k][j];
					}

				}
			}

			else{
				for(int k=j+1;k<M;k++){
					if(matrix[k][j]!=0){
						for(int l=0;l<N;l++){
							swap(matrix[j][l],matrix[k][l]);
						}
						P[j][j]=0;P[k][k]=0;
						P[j][k]=1;P[k][j]=1;
						j--;
						flag=false;
						break;
					}
				}
			}
		}
		
		//output data in format-----------------
		if(flag==false){
			output<<"False\n"<<M<<' '<<M<<endl;
			for(int j=0;j<M;j++){
				for(int k=0;k<M;k++){
					output<<P[j][k]<<' ';
				}
				output<<endl;
			}	
		}
		else output<<"True\n";
		
		output<<M<<' '<<M<<endl;
		
		for(int j=0;j<M;j++){
			for(int k=0;k<M;k++){
				output<<setprecision(2)<<fixed<<L[j][k]<<' ';
			}
			output<<endl;
		}
		
		output<<M<<' '<<N<<endl;
		
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				output<<setprecision(2)<<fixed<<matrix[j][k]<<' ';
			}
			output<<endl;
		}
	}
	
	//close files----------------------------------------
	input.close();
	output.close();
	
	return 0;
}
