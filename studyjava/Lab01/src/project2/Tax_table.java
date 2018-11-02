package project2;

public class Tax_table {
	static double getXTax(int income) {
		if (income>326450)return 94727.5+(income-326450)*0.35;
		if (income>150150)return 36548.5+(income-150150)*0.33;
		if (income>71950)return 14652.5+(income-71950)*0.28;
		if (income>29700)return 4090+(income-29700)*0.25;
		if (income>7300)return 730+(income-7300)*0.15;
		return income*0.10;
	}
	static double getY_1Tax(int income) {
		if (income>326450)return 88320+(income-326450)*0.35;
		if (income>182800)return 40915.5+(income-182800)*0.33;
		if (income>119950)return 23317.5+(income-119950)*0.28;
		if (income>59400)return 8180+(income-59400)*0.25;
		if (income>14600)return 1460+(income-14600)*0.15;
		return income*0.10;
	}
	static double getY_2Tax(int income) {
		if (income>163225)return 44160+(income-163225)*0.35;
		if (income>91400)return 20457.75+(income-91400)*0.33;
		if (income>59975)return 11658.75+(income-59975)*0.28;
		if (income>29700)return 4090+(income-29700)*0.25;
		if (income>7300)return 730+(income-7300)*0.15;
		return income*0.10;		
	}
	static double getZTax(int income) {
		if (income>326450)return 91819.5+(income-326450)*0.35;
		if (income>166450)return 39019.5+(income-166450)*0.33;
		if (income>102800)return 21197.5+(income-102800)*0.28;
		if (income>39800)return 5447.5+(income-39800)*0.25;
		if (income>10450)return 1045+(income-10450)*0.15;
		return income*0.10;		
	}
	public static void main(String args[]) {
		System.out.printf("%7s%9s%9s%9s%9s\n","taxable","Single","Married","Married","Head of" );
		System.out.printf("%7s%9s%9s%9s%9s\n","Income","","Joint","Separate","a House" );
		for (int i=50000;i<=60000;i+=50) {
			System.out.printf("%7d%9.1f%9.1f%9.1f%9.1f\n", i,getXTax(i),getY_1Tax(i),getY_2Tax(i),getZTax(i));
		}
	}
}
