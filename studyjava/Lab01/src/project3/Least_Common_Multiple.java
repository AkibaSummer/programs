package project3;

import java.util.Scanner;

public class Least_Common_Multiple {
	private static int[][] getPrimeFactors(int number) {
		int temp[][]=new int[2][20];
		temp[0][0]=0;
		temp[1][0]=1;
		for (int i=2;i<=number;i++) {
			if (number%i==0) {
				++temp[0][0];
				while (number%i==0) {
					temp[0][temp[0][0]]=i;
					++temp[1][temp[0][0]];
					number/=i;
				}
			}
		}
		return temp;
	}
	public static int getAns(int a,int b) {
		int primeA[][]=getPrimeFactors(a);
		int primeB[][]=getPrimeFactors(b);
		int ret=1;
		while (primeA[1][0]<=primeA[0][0]||primeB[1][0]<=primeB[0][0]) {
			if (primeA[1][0]==primeA[0][0]+1) {
				ret*=Math.pow(primeB[0][primeB[1][0]],primeB[1][primeB[1][0]]);
				primeB[1][0]++;
			}
			else if (primeB[1][0]==primeB[0][0]+1) {
				ret*=Math.pow(primeA[0][primeA[1][0]],primeA[1][primeA[1][0]]);
				primeA[1][0]++;
			}
			else {
				if (primeA[0][primeA[1][0]]==primeB[0][primeB[1][0]]) {
					ret*=Math.pow(primeA[0][primeA[1][0]],Math.max(primeA[1][primeA[1][0]],primeB[1][primeB[1][0]]));
					primeA[1][0]++;primeB[1][0]++;
				}
				else if (primeA[0][primeA[1][0]]<primeB[0][primeB[1][0]]) {
					ret*=Math.pow(primeA[0][primeA[1][0]],primeA[1][primeA[1][0]]);
					primeA[1][0]++;					
				}
				else if (primeA[0][primeA[1][0]]>primeB[0][primeB[1][0]]) {
					ret*=Math.pow(primeB[0][primeB[1][0]],primeB[1][primeB[1][0]]);
					primeB[1][0]++;					
				}
			}
		}
		return ret;		
	}
	public static void main(String args[]) {
		int a=0,b=0;
		Scanner orz=new Scanner(System.in);
		for (;;) {
			try {
				System.out.print("Please input two number separated by spaces:");
				a=orz.nextInt();
				b=orz.nextInt();
				orz.close();
				System.out.println("The LCM of "+a+" and "+b+" is "+getAns(a,b));
				break;
			}
			catch(Exception e) {
				System.out.println("Input ERROR!");
				orz.nextLine();
			}}
	}
}
